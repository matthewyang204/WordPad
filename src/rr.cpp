#include "stdafx.h"

#include "rr.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

static BOOL WriteToLogFile(const char* message, char* path, size_t pathSize)
{
    DWORD pathLength = GetTempPathA((DWORD)pathSize, path);
    if (pathLength == 0 || pathLength >= pathSize ||
        strcat_s(path, pathSize, "wordpad-crash-log.txt") != 0)
    {
        return FALSE;
    }

    FILE* f = NULL;
    if (fopen_s(&f, path, "a") != 0)
        return FALSE;

    fputs(message, f);
    fclose(f);
    return TRUE;
}

static void RRLogFailure(const char* expr, const char* file, int line)
{
    char msg[512];
    _snprintf_s(
        msg,
        512,
        _TRUNCATE,
        "[RRAssert] Failed: %s (%s:%d)\n",
        expr,
        file,
        line
    );

    fputs(msg, stderr);

    char path[MAX_PATH];
    if (WriteToLogFile(msg, path, _countof(path)))
    {
        ShellExecuteA(
            NULL,
            "open",
            "notepad.exe",
            path,
            NULL,
            SW_SHOW
        );
    }
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
