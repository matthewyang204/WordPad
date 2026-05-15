#pragma once

void RRAssertFail(const char* expr, const char* file, int line);

#define RRAssert(expr) \
    do { if (!(expr)) RRAssertFail(#expr, __FILE__, __LINE__); } while (0)