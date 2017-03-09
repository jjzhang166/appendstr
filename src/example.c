#include <stdio.h>
#include <malloc.h>

#include "appendstr.h"

int main(int pintArgc, char *ptstrArgv[]) { 
    char *buf = NULL;

    // Use NULL for the 1st time.
    buf = appendStr(NULL, "my int: %d\n", 1);
    buf = appendStr(buf, "my float: %f\n", 3.14);
    buf = appendStr(buf, "my string: Hello %s!\n", "World");     

    printf(buf);

    // free memory block after use.
    free(buf);
}
