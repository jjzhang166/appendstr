# appendStr()

appendStr is a C function which increases the size of buffer to append formated string.

#### Documentation

    // appendStr increases the size of buffer to append formated string.
    // Params:
    //   buf: pointer to the existed allocaled buffer which stores original string or NULL(for 1st time).
    //   fmt: format like the one in printf().
    // Return:
    //   Pointer to the buffer stored new string.
    //   It'll call realloc() to change the buffer size internally.
    //   Old buffer will be released during realloc() after memory block is moved if it's not large enough.
    //   So caller should free the returned buffer after use.
    // Example:
    //   int main() {
    //       char *buf = NULL;
    //
    //       // Pass NULL pointer for the 1st time.
    //       buf = appendStr(NULL, "%d", 1);
    //       buf = appendStr(buf, "%f", 3.14);
    //       buf = appendStr(buf, "Hello World!")
    //
    //       free(buf);
    //   }
    char *appendStr(char *buf, char *fmt, ...)

#### Example

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

#### Build Example
 
    ./autogen.sh
    ./configure
    ./make

#### LICENSE
* [MIT License](./LICENSE)

#### References
* Thanks Andrew Henle and Ingo Leonhardt's answer in [C variadic wrapper](http://stackoverflow.com/questions/37947200/c-variadic-wrapper)

