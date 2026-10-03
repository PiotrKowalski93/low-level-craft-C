#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Incomplete starter — implement the required behavior.
 * Stdin modes (if any): alloc, free, merge, edge, multi
 * Match the sample test output exactly. Hidden tests use more modes/inputs.
 */

/* Core types from the exercise (keep these) */
#define HEAP_SIZE 4096
typedef struct Block {
    size_t size;        // 8 bytes
    int used;           // 8 bytes
    struct Block* next; // 8 bytes
} Block;

int HEAP_CURRENT_SIZE = 4096;

Block* init_heap(){
    // Init with header
    struct Block *header = {
        .size = 0,
        .used = 0,
        .next = nullptr
    }

    HEAP_CURRENT_SIZE -= 24; 
    return header;
}

/* TODO: implement my_malloc */

/* TODO: implement my_free */

void print_heap(const Block *header){
    const Block *b = header;
    int count = 0;

    while(b != nullptr ){
        printf("Block %zu: used=%zu size=%zu", count, b->used, b->size);
        count++;
        b = b->next;
    }

    return count;
}

int count_free_blocks(const Block *header){
    const Block *b = header;
    int count = 0;

    while(b != nullptr ){
        if(b->used == 0) count++;
        b = b->next;
    }

    return count;
}

int main(void) {
    char mode[64] = "";
    if (scanf("%63s", mode) != 1) {
        mode[0] = '\0';
    }
    (void)mode;




    return 0;
}
