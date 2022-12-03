#include "log.h"

FILE* log;

void closeLog()
{
    fclose(log);
}

void startLogging()
{
    log = fopen("log.txt", "w");

    atexit(closeLog);
}

void showExample()
{
    fprintf(stdout, "Program example:\n"
                    "MODS: -b [BASH MOD], -d [DAEMON MOD]\n"
                    "\'name.out -b 5\'\n"
                    "BASH MOD WITH PID = 5\n"
                    "\'name.out -d 13\'\n"
                    "DAEMON MOD WITH PID = 13\n"
                    "\'name.out 19\'\n"
                    "BASH MOD [BY DEFAULTS] WITH PID = 19\n");
}           