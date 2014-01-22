#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

typedef uint32_t	Cp;
typedef size_t		Off;
typedef size_t		Len;

typedef struct Text {
	Cp	*arr;			/* Unicode code point data. */
	Off	off;			/* Offset in code points. */
	Len	len;			/* Length in code points. */
} Text;

enum Ordering {LT, GT, EQ};

Text *
text_mk(Cp *arr, Off off, Len len, Text *dest)
{
	*dest = (Text){.arr=arr, .off=off, .len=len};
	return dest;
}

Text *
text_copy(Text *x0, Text *dest)
{
	*dest = *x0;
	return dest;
}

void
text_unmk(Text *x)
{
	free(x);
}

size_t
size_t_min(size_t x, size_t y)
{
	return x <= y ? x : y;
}

enum Ordering
size_t_compare(size_t x, size_t y)
{
	if (x > y)
                return GT;
	if (x < y)
                return LT;
	return EQ;
}

enum Ordering
text_compare(Text *x, Text *y)
{
	if (x->len == 0 && y->len == 0)
                return EQ;
	size_t min_len = size_t_min(x->len, y->len);
	for (int i = 0; i < min_len; i++) {
		if (x->arr[i] < y->arr[i])
                        return LT;
		if (x->arr[i] > y->arr[i])
                        return GT;
	}
	return x->len == y->len ? EQ : size_t_compare(x->len, y->len);
}

char *
text_show(Text *x)
{
        char *o = strdup("Text [");
	asprintf(&o, "%s%08X", o, x->arr[x->off]);
        for (int i = 1 + x->off; i < x->len; i++) {
		char *fmt;
		if (i % 8 == 0) { 
			fmt = "%s,\n      %08X";
		} else {
			fmt = "%s, %08X";
		}
                asprintf(&o, fmt, o, x->arr[i]);
        }
	asprintf(&o, "%s]\nOffset %lu\nLength %lu\n", o, x->off, x->len);
	asprintf(&o, "%sPointer %p\n", o, x->arr);
        return o;
}

int
main()
{
	Text *x = malloc(sizeof(Text));
	Cp *in = U"Blah blah blah";
        x = text_mk(in, 0, 14, x);
        printf("%s\n", text_show(x));
	text_unmk(x);
}
