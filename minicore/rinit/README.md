work in progress, not finished.


A minimal init. 

The small size (2.2kB) and using vfork do spare some resources.
Especially, when considering context switches for reaping subprocesses.
(Everytime, a child process exits, there's a task switch to init,
in order to "reap" the children's process state.
Having a tiny init (or another subreaper process) has real performance advantages)

Readahead should be implemented by the stages.

I'm about to convert the init scripts to C files,
and I'm heavily tempted to rule an init language.
Atm the kernel's init phase takes most time.
However, I'd like to have the system ready within <1 second.
(Ready in the meaning of, the X server is started and ready for input)

Yet this might be around 3 seconds, maybe five.

Harddisk mounts, and module loads are done in the background,
after X and the desktop manager(i3) has been started.

As soon as this get's closer to 1 second, it will be possible 
to measure the script's parsing overhead.
Atm, it is neglectible.


(2020/06)
.. finished a first version of init, seems to work fine.

Subject to change.

For now, init starts 
/etc/rinit/1 

and runs and restarts when exiting
/etc/rinit/2

Halt/reboot is /etc/rinit/3

This follows the runit scheme.


on signals SIGINT, Ctrl+Alt+Del (->reboot) and SIGTERM (->shutdown)
/etc/rinit/2 is sent SIGTERM, when not responding SIGKILL,
and after it's termination
/etc/rinit/3 is executed.


For a shutdown do "killall init",
for a reboot "killall -s SIGINT init" (or Ctrl-Alt-Del)

When sent SIGQUIT, the currently running stage is signalled with SIGTERM.
When the currently running stages are either 1 or 2, when the processes exit,
stage 2 is (re)started.

On shutdown, after a timeout of (default, change "WAITTIME" within the source) 
30 seconds past the sent SIGTERM,
the currently running stage is sent a SIGKILL.
When still not responding within 30 seconds, 
it's assumed the process is zombified and stage 3 or
the reboot/halt executed.


The scripts 1,2,3 and the init scripts I'm using, are working, but subject to change.
I'm using a stripped down sh interpreter of busybox.

However, the forks for every executed program on boot seem to have their price.
Albite bootup time is below 1 second. (Notebook Amd Turion 2GHz, built 2005)

I guess I'm going to integrate the minicore tools into the start scripts, 
and rewrite 1 and 2 as C programs. 

The bootscripts aren't tidied, there are some instructions left, 
I fiddled around with syncronization.
Showed up, no sync is needed.
To be more exact, even stage 2 is not really needed.
I leave this as it is for now.
And upload this into the branch devel of minilib,
since it is in development.




notes

Seems to me, a modular kernel would be advantegeous in matters of boottime.

the modules can initialize the hardware in parallel to the boot process.

(Now, the kernel needs about x seconds to initialize here)

Ok. Mdularizing the kernel, and loading
all modules in parallel saves a lot of time.


scripts/process starters: async, delayed, lazy.

Start(run)   Boot
Service      Daemon
Shutdown     Halt

---- 


Executables within rinit/rc.boot are 
executed first.

Then follows rc.runlevel (default: rc.default)

On Shutdown rc.shutdown is scanned.
 / rc.default/S\* (S for shutdown)


rinit.boot is there for rc.boot.



rinit.run needs one argument, 
empty spaces.

On boot, rinit.run reads the kernel command line
and looks for a parameter runlevel= 
When found, or 
when the runlevel is changed,
 rinit.run writes into it's own argument the new runlevel.
 (so the current runlevel shows up with ps)

On SIGUSR1 the runlevel should be read from the shared directory within the init ramdisk,
and changed to, when needed.
 (/rd/run/runlevel)

 For changing the runlevel, 
 signal either init (1) or rinit.run with SIGUSR1





rinit.shutdown scans and runs rc.shutdown,
as well as rc.runlevel/S\*








