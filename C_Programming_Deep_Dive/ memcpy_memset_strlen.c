#include <stdio.h>
#include <stdint.h>
#include <string.h>

void *my_memcpy(void *dest, const void *src, size_t n){

    unsigned char* d = (unsigned char*)dest;
    const unsigned char* s = (const unsigned char*)src;

    for(size_t i = 0; i < n; i++){
        *(d + i) = *(s + i);
    }

    return dest;
}

void *my_memset(void *ptr, int value, size_t n){
    unsigned char* p = (unsigned char*)ptr;
    char c = (char)value;

    for(size_t i = 0; i < n; i++){
        *(p + i) = c;
    }

    return ptr;
}

size_t my_strlen(const char *s){
    size_t i = 0;
    while(*(s + i) != '\0'){
        i++;
    }
    return i;
}

void print_buffer(const void *src, size_t n){
    const unsigned char* s = (const unsigned char*)src;

    for(size_t i = 0; i < n; i++){
        printf("%c", s[i]); 
    }
}

int main(void) {
    char mode[64] = "";
    if (scanf("%63s", mode) != 1) {
        mode[0] = '\0';
    }

    (void)mode;

    void *src = "Hello, World!";
    void *dest[13];
    void *src_memset[9];

    if (strcmp(mode, "memcpy") == 0) {
        my_memcpy(dest, src, 13);
        printf("memcpy: ");
        print_buffer(dest, 13);
        printf("\n");
    } else if (strcmp(mode, "memset") == 0) {
        my_memset(src_memset, 88, 9);
        printf("memset: ");
        print_buffer(src_memset, 9);
        printf("\n");
    }else if (strcmp(mode, "strlen") == 0) {
        size_t len = my_strlen(src);
        printf("strlen: %zu\n", len);
    }else if (strcmp(mode, "zero") == 0) {
        my_memcpy(dest, src, 0);
        my_memset(src_memset, 88, 0);
        printf("Zero size: OK\n");
    }

    return 0;
}
