/* This file is part of regetopt.
   reGetopt is licensed under GNU GPL v3 or MIT License. */

#ifndef REGETOPT_H
#define REGETOPT_H

#ifdef __cplusplus
#define BEGIN_DECL extern "C" {
#define END_DECL }
#else
#define BEGIN_DECL
#define END_DECL
#endif

#if defined(_WIN32) && defined(REGETOPT_DLL)
/* if it is Windows DLL build or about to link to DLL,
   define symbols as exported. */
#ifdef REGETOPT_INTERNAL
#define REGETOPT_API __declspec(dllexport)
#else
#define REGETOPT_API __declspec(dllimport)
#endif
#else
#define REGETOPT_API
#endif

BEGIN_DECL

#define re_no_argument 0
#define re_required_argument 1
#define re_optional_argument 2

struct re_option {
    const char *name;
    int has_arg;
    int *flag;
    int val;
};

REGETOPT_API extern char *re_optarg;
REGETOPT_API extern int re_optind, re_opterr, re_optopt;

REGETOPT_API int regetopt(int argc, char **argv, const char *optstring,
                          struct re_option *longopts, int *longindex);

END_DECL

#endif
