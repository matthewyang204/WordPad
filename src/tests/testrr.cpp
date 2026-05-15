#include <windows.h>
#include <stdio.h>

#include "rr.h"

int main()
{
    printf("BEFORE RRAssert\n");

    RRAssert(false);

    printf("AFTER RRAssert (SHOULD NEVER PRINT)\n");

    return 0;
}