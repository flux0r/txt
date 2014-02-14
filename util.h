#include <stdint.h>
#include <stddef.h>

typedef uint32_t Cp;                    /* Unicode code point. */
typedef size_t  Len;                    /* Length in code points. */
typedef size_t  Off;                    /* Offset in code points. */

enum Ordering {LT, GT, EQ};
