/* This file is part of regetopt.
   reGetopt is licensed under GNU GPL v3 or MIT License. */

#ifndef MLIB
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define REGETOPT_INTERNAL 1
#include "include/regetopt.h"
#endif


char *re_optarg;
int re_optind = 1;
int re_opterr = 1;
int re_optopt;

/* internal storage to store current position in concatenated short option (e.g.
 * -abc). */
static size_t optchar_index = 1;
/* internal storage to store the number of arguments we should parse as options.
 */
static int option_argc = -1;

static int regetopt_short(int argc, char **argv, const char *optstring) {
    char *cur = argv[re_optind];
    size_t opt_len = strlen(cur);

    re_optopt = cur[optchar_index];

    size_t optstr_len = strlen(optstring);
    for (size_t i = 0; i < optstr_len; ++i) {
        if (optstring[i] == re_optopt) {
            /* if it is a option with argument, put it in re_optarg. */
            if (i + 1 < optstr_len && optstring[i + 1] == ':') {
                if (optchar_index + 1 < opt_len) {
                    /* if there are subsequent characters, regard it as
                     * argument. */
                    re_optarg = cur + optchar_index + 1;
                    ++re_optind;
                } else {
                    /* otherwise, take next argument. */
                    if (re_optind + 1 < argc) {
                        re_optarg = argv[re_optind + 1];
                        re_optind += 2;
                    } else {
                        if (re_opterr) {
                            fprintf(stderr,
                                    "%s: option requires an argument -- '%c'\n",
                                    argv[0], re_optopt);
                        }
                        return ':';
                    }
                }
                /* reset option char index for next option parsing. */
                optchar_index = 1;
            } else {
                /* if this option don't take argument, proceed option char
                 * index. */
                ++optchar_index;
            }
            return re_optopt;
        }
    }

    if (re_opterr) {
        fprintf(stderr, "%s: invalid option -- '%c'\n", argv[0], re_optopt);
    }
    return '?';
}

static void print_possibilities(const char *option, size_t option_len,
                                struct re_option *longopts) {
    for (struct re_option *opt = longopts; opt->name; ++opt) {
        if (!strncmp(option + 2, opt->name, option_len)) {
            fprintf(stderr, " '--%s'", opt->name);
        }
    }
    fputs("\n", stderr);
}

static int regetopt_long(int argc, char **argv, struct re_option *longopts,
                         int *longindex) {
    char *cur = argv[re_optind];
    size_t cur_len;
    char *eq = strchr(cur, '=');
    /* here, cur must be longer than 2 */
    if (eq) {
        cur_len = (size_t)(eq - cur) / sizeof(char) - 2;
    } else {
        cur_len = strlen(cur) - 2;
    }
    int index = 0;
    int match_index = -1;
    for (struct re_option *opt = longopts; opt->name; ++opt) {
        size_t opt_len = strlen(opt->name);

        if (opt_len == cur_len && !strncmp(cur + 2, opt->name, opt_len)) {
            /* exect match */
            match_index = index;
            break;
        } else if (cur_len < opt_len && !strncmp(cur + 2, opt->name, cur_len)) {
            /* ambiguous match. if any other options match, it fails. */
            if (match_index >= 0) {
                if (re_opterr) {
                    fprintf(stderr,
                            "%s: option '%.*s' is ambiguous; possibilities:",
                            argv[0], (int)cur_len + 2, argv[re_optind]);
                    print_possibilities(cur, cur_len, longopts);
                }
                return '?';
            }
            match_index = index;
        }
        ++index;
    }

    /* if no option match, err here. */
    if (match_index < 0) {
        fprintf(stderr, "%s: unrecognized option '%.*s'\n", argv[0],
                (int)cur_len + 2, cur);
        return '?';
    }

    if (longopts[match_index].has_arg == re_required_argument) {
        /* required argumet can be take "--foo=bar" form or "--foo bar" form. */
        if (eq) {
            re_optarg = eq + 1;
        } else {
            /* if there is remaining argument, take it as an argument. */
            if (re_optind + 1 < argc) {
                re_optarg = argv[re_optind + 1];
                ++re_optind;
            } else {
                /* ...otherwise, error. */
                if (re_opterr) {
                    fprintf(stderr, "%s: option '--%s' requires an argument\n",
                            argv[0], longopts[match_index].name);
                }
                return '?';
            }
        }
    } else if (longopts[match_index].has_arg == re_optional_argument) {
        /* format of optional argument is --foo=bar only. */
        if (eq) {
            re_optarg = eq + 1;
        } else {
            re_optarg = NULL;
        }
    }

    ++re_optind;

    /* if longindex is not NULL, store matched index to the storage. */
    if (longindex) {
        *longindex = match_index;
    }

    /* if re_option::flag is not null, store re_option::val there and return 1.
       otherwise, return re_option::val. */
    if (!longopts[match_index].flag) {
        return longopts[match_index].val;
    } else {
        *longopts[match_index].flag = longopts[match_index].val;
        return 1;
    }
}

static void reorder_option(int argc, char **argv) {
    char *cur = argv[re_optind];
    for (int i = re_optind + 1; i < argc; ++i) {
        argv[i - 1] = argv[i];
    }
    argv[argc - 1] = cur;
}

int regetopt(int argc, char **argv, const char *optstring,
             struct re_option *longopts, int *longindex) {
    /* if internal argument count is not initialized (i.e. first call of this
       function), initialize it. */
    if (option_argc < 0) {
        option_argc = argc;
    }

begin_parse:
    if (re_optind >= option_argc) {
        return -1;
    }

    char *cur = argv[re_optind];
    size_t len = strlen(argv[re_optind]);

    /* options after "--" should be ignored. */
    if (!strcmp(cur, "--")) {
        ++re_optind;
        return -1;
    }

    /* check if option's format is --foo or -f. */
    bool is_option = (len > 2 && cur[0] == '-') ||
                     (len == 2 && cur[0] == '-' && cur[1] != '-');

    /* if it is not option, move it to the last. */
    if (!is_option) {
        reorder_option(argc, argv);
        --option_argc;
        goto begin_parse;
    }

    bool is_long = len > 2 && (cur[0] == '-' && cur[1] == '-');
    if (!is_long) {
        /* -abc is equivalent to -a -b -c.
           if all chars in this option are parsed, continue to next option. */
        if (optchar_index >= len) {
            optchar_index = 1;
            ++re_optind;
            goto begin_parse;
        }

        return regetopt_short(option_argc, argv, optstring);
    }

    return regetopt_long(option_argc, argv, longopts, longindex);
}
