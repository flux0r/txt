#include <stdlib.h>

struct BlockAllocator {
        uint8_t *base;
        uint8_t *free_off;
};

struct Block {
        struct Block    *next;
        struct Block    *next_addr;
        struct Block    *prev_addr;
        unsigned int    page_count;
        unsigned int    free;
        struct Block    *prev;
};

struct Allocator {
        struct BlockAllocator   lil;
        struct BlockAllocator   big;
        struct Block            *used_pages;
        struct Block            *used_blocks;
};

struct Rgn {
        unsigned int            refs;
        unsigned int            current;
        unsigned int            next;
        struct Allocator        norm;
        struct Allocator        qualified;
        struct Rgn              *parent;
        struct Rgn              *sibling;
        struct Rgn              *child;
};

int main()
{

}
