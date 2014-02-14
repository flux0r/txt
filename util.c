#include <stdint.h>             /* uint_least32_t */
#include <stddef.h>             /* size_t */

typedef uint32_t Cp;                    /* Unicode code point. */
typedef size_t  Len;                    /* Length in code points. */
typedef size_t  Off;                    /* Offset in code points. */

enum Ordering {LT, GT, EQ};
