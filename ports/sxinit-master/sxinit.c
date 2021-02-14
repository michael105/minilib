#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define LENGTH(A) (sizeof(A) / sizeof((A)[0]))

static char displayfd[7] = "?";
static char *xserv_cmd[] = {"X", "-displayfd", displayfd, "-noreset", NULL};
static char *xinit_cmd[] = {"sh", ".xinitrc", NULL};
static pid_t xserv_pid = 0;
static pid_t xinit_pid = 0;
static sigset_t oldset;
static int signals[] = {SIGTERM, SIGINT, SIGCHLD};

void handler(int s) {
	return;
}

static void cleanup() {
	if (xserv_pid > 0) kill(xserv_pid, SIGTERM);
	if (xinit_pid > 0) kill(xinit_pid, SIGTERM);
	if (xserv_pid > 0) waitpid(xserv_pid, NULL, 0);
	if (xinit_pid > 0) waitpid(xinit_pid, NULL, 0);
}

static void die(const char *msg) {
	int t = errno;
	fputs(msg, stderr);
	if (msg[0] && msg[strlen(msg)-1] == ':') {
		fputc(' ', stderr);
		errno = t;
		perror(NULL);
	} else {
		fputc('\n', stderr);
	}
	
	cleanup();
	exit(EXIT_FAILURE);
}

static void start_xserv(int argc, char *argv[]) {

	char *cmd[LENGTH(xserv_cmd) + argc];
	int i = 0, j = 0;
	for (i = 0; xserv_cmd[i]; i++)	
		cmd[i] = xserv_cmd[i];
	for (j = 0; argv[j]; j++)
		cmd[i + j] = argv[j];
	cmd[i + j] = NULL;

	int fd[2];
	if (pipe(fd))
		die("pipe:");

	snprintf(displayfd, sizeof(displayfd), "%d", fd[1]);

	switch (xserv_pid = fork()) {
	case -1:
		die("fork:");
	case 0:
		close(fd[0]);
		sigprocmask(SIG_SETMASK, &oldset, NULL);
		execvp(cmd[0], cmd);
		exit(1);
	}
	
	close(fd[1]);

	char display[10] = ":";
	int n = read(fd[0], display + 1, sizeof(display) - 1);
	if (n == -1)
		die("read:");
	
	close(fd[0]);

	int k;
	for (k = 0; k < n + 1; k++) {
		if (display[k] == '\n') {
			display[k] = '\0';
			if (setenv("DISPLAY", display, 1))
				die("setenv:");
			return;
		}
	}

	die("failed to read display number");
}

static void start_xinit() {
	switch (xinit_pid = fork()) {
	case -1:
		die("fork:");
	case 0:
		sigprocmask(SIG_SETMASK, &oldset, NULL);
		execvp(xinit_cmd[0], xinit_cmd);
		exit(1);
	}
}

int main(int argc, char *argv[]) {
	struct sigaction sa = {0};
	sa.sa_handler = handler;

	if (sigemptyset(&sa.sa_mask))
		die("sigemptyset:");

	for (int i = 0; i < LENGTH(signals); i++)
		if (sigaddset(&sa.sa_mask, signals[i]))
			die("sigaddset:");

	if (sigprocmask(SIG_BLOCK, &sa.sa_mask, &oldset))
		die("sigprocmask:");

	char *home = getenv("HOME");
	if (home == NULL)
		die("HOME enviroment variable is not set");
	
	if (chdir(home))
		die("chdir:");

	start_xserv(argc - 1, argv + 1);
	start_xinit();

	for (int i = 0; i < LENGTH(signals); i++)
		if (sigaction(signals[i], &sa, NULL))
			die("sigaction:");

	sigsuspend(&oldset);
	if (errno != EINTR)
		die("sigsuspend:");

	cleanup();

	return EXIT_SUCCESS;
}
