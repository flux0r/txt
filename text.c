#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array.h"

struct Text {
	Cp	*arr;		        /* Unicode code point data. */
	Off	off;			/* Offset in code points. */
	Len	len;			/* Length in code points. */
};

struct Text *
text_mk(Cp *arr, Off off, Len len, struct Text *dest)
{
	*dest = (struct Text){.arr=arr, .off=off, .len=len};
	return dest;
}

struct Text *
text_copy(struct Text *x0, struct Text *dest)
{
	*dest = *x0;
	return dest;
}

void
text_unmk(struct Text *x)
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
text_compare(struct Text *x, struct Text *y)
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
text_show(struct Text *x)
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
	struct Text *x = malloc(sizeof(struct Text));
	Cp *in = U"Blah blah blah";
        x = text_mk(in, 0, 14, x);
        printf("%s\n", text_show(x));
	text_unmk(x);
}
