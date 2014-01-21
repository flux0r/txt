#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include <stdlib.h>

struct Text {
	uint32_t *arr;
	int off;
	int len;
};

struct Text *mk_text(uint32_t *arr, int off, int len)
{
	struct Text *cs = malloc(sizeof(struct Text));
	*cs = (struct Text){.off=0, .len=0};
	cs->arr = memcpy(cs->arr, arr, 8*len);
	cs->off = off;
	cs->len = len;
	return cs;
}

void u_mk_text(struct Text *cs)
{
	assert(cs != NULL);
	free(cs->arr);
	free(cs);
}

void show_text(struct Text *cs)
{
	printf("Array location: %p\n", cs->arr);
	printf("\tOffset: %u\n", cs->off);
	printf("\tLength: %u\n", cs->len);
}

int main(int argc, char *argv[])
{
	uint32_t arr0[] = {5, 3, 2, 1};
	struct Text *text0 = mk_text(*arr0, 0, 4);
	u_mk_text(text0);
}
