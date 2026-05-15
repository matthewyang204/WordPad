#include "rr.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

char* writeToLogFile(const char* expr)
{
    char* path = new char[MAX_PATH];

    GetTempPathA(MAX_PATH, path);
    lstrcatA(path, "wordpad-crash-log.txt");

    FILE* f = fopen(path, "a");
    if (f)
    {
        fprintf(f, expr);
        fclose(f);
    }

    return path;
}

static void RRLogFailure(const char* expr, const char* file, int line)
{
    char* msg = new char[512];
    _snprintf_s(
        msg,
        512,
        _TRUNCATE,
        "[RRAssert] Failed: %s (%s:%d)\n",
        expr,
        file,
        line
    );

    fprintf(stderr, msg);
    char* path = writeToLogFile(msg);

    ShellExecuteA(
        NULL,
        "open",
        "notepad.exe",
        path,
        NULL,
        SW_SHOW
    );
}

void RRAssertFail(const char* expr, const char* file, int line)
{
    RRLogFailure(expr, file, line);
    if (IsDebuggerPresent())
    {
        DebugBreak();
    }
    ExitProcess(1);
}
