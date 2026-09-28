/* Minimal Wine compatibility shims used by the riched20 sources.
 * Provides stub definitions for debug macros and simple red-black tree
 * entry used in the original Wine implementation so the code can build
 * without depending on Wine headers.
 */
#pragma once

#include <stdio.h>

/* Debug channel macro used at file scope in Wine sources. Make it a no-op. */
#define WINE_DEFAULT_DEBUG_CHANNEL(x)

/* Simple logging macros used in the codebase. Map to fprintf to stderr. */
#define ERR(fmt, ...) do { fprintf(stderr, "ERR: " fmt "\n", ##__VA_ARGS__); } while (0)
#define FIXME(fmt, ...) do { fprintf(stderr, "FIXME: " fmt "\n", ##__VA_ARGS__); } while (0)
#define WARN(fmt, ...) do { fprintf(stderr, "WARN: " fmt "\n", ##__VA_ARGS__); } while (0)

/* Minimal wine red-black tree entry placeholder used by structures in
 * editstr.h. The real implementation is not required for a build. */
struct wine_rb_entry {
    void *rb_left;
    void *rb_right;
    void *rb_parent;
    int rb_color;
};
