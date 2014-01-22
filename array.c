#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Array {
	uint32_t	*data;
	size_t		len;
};

struct Array *
array_mk(struct Array *dest, uint32_t *data, size_t len)
{
	*dest = (struct Array){.data=data, .len=len};
	return dest;
}

int main()
{
	printf("Page size %i\n", getpagesize());	
}
