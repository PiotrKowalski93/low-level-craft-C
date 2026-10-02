#include <stdio.h>
#include <string.h>

struct MyStruct {
    int a;
    char b;
};

void printBasic(){
    printf("char: %zu bytes\n", sizeof(char));
    printf("short: %zu bytes\n", sizeof(short));
    printf("int: %zu bytes\n", sizeof(int));
    printf("long: %zu bytes\n", sizeof(long));
    printf("long long: %zu bytes\n", sizeof(long long));
    printf("float: %zu bytes\n", sizeof(float));
    printf("double: %zu bytes\n", sizeof(double));
}

void printPointers(){
    printf("int*: %zu bytes\n", sizeof(int*));
    printf("char*: %zu bytes\n", sizeof(char*));
    printf("double*: %zu bytes\n", sizeof(double*));
}

void printArrays(){
    printf("int[10]: %zu bytes\n", sizeof(int[10]));
    printf("char[10]: %zu bytes\n", sizeof(char[10]));
    printf("double[5]: %zu bytes\n", sizeof(double[5]));
}

void printStruct(){
    printf("struct: %zu bytes\n", sizeof(struct MyStruct));
    printf("sizeof(2 + 3.5): %zu\n", sizeof(2 + 3.5));
    printf("sizeof(\"hello\"): %zu\n", sizeof("hello"));
}

int main(void) {
    char mode[64] = "";
    if (scanf("%63s", mode) != 1) {
        mode[0] = '\0';
    }
    (void)mode;

    if (strcmp(mode, "basic") == 0)
    {
        printBasic();
    }
    else if (strcmp(mode, "pointers") == 0)
    {
        printPointers();
    }
    else if (strcmp(mode, "arrays") == 0)
    {
        printArrays();
    }
    else if (strcmp(mode, "struct") == 0)
    {
        printStruct();
    }
    else if (strcmp(mode, "all") == 0)
    {
        printBasic();
        printPointers();
        printArrays();
        printStruct();
        printf("All sizes printed correctly");
    }
    else
    {
        printf("Unknown mode: %s\n", mode);
    }

    return 0;
}
