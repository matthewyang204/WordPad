#pragma once

void RRAssertFail(const char* expr, const char* file, int line);
void RRShowFailureBox();

#define RRAssert(expr) \
    do { if (!(expr)) RRAssertFail(#expr, __FILE__, __LINE__); } while (0)