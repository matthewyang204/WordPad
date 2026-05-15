#include "rr.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

static void RRLogFailure(const char* expr, const char* file, int line)
{
    fprintf(stderr, "[RRAssert] Failed: %s (%s:%d)\n", expr, file, line);
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