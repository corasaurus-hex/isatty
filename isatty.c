#include <janet.h>
#include <stdio.h>

#ifdef JANET_WINDOWS
#include <io.h>
#else
#include <unistd.h>
#endif

static Janet ttycheck(int32_t argc, Janet *argv) {
    janet_fixarity(argc, 1);
    FILE *file = janet_getfile(argv, 0, NULL);
    int fd = fileno(file);
#ifdef JANET_WINDOWS
    return janet_wrap_boolean(_isatty(fd));
#else
    return janet_wrap_boolean(isatty(fd));
#endif
}

static const JanetReg cfuns[] = {
    {"isatty", ttycheck, "(isatty/isatty file)\n\nReturns true if file is a tty, false otherwise."},
    {NULL, NULL, NULL}
};

JANET_MODULE_ENTRY(JanetTable *env) {
    janet_cfuns(env, "isatty", cfuns);
}
