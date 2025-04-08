/*
Implement "cat" command using symstem calls.

If file paths are not provided, it takes inputs from stdin.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {

        // open file as read only
        FILE *f = fopen(argv[i], "r");

        if (!f) {

            perror(argv[i]);

            exit(1);
        }

        int c;

        while ((c = fgetc(f)) != EOF) {

            if (fputc(c, stdout) < 0) {

                perror(argv[i]);

                break;
            }
        }

        fclose(f);
    }

    exit(0);
}