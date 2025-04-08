/*
Count the number of lines in a file using stdio.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {

        perror("Only one file should be provided");

        exit(1);
    }

    FILE *f = fopen(argv[1], "r");

    if (!f) {

        perror(argv[1]);

        exit(1);
    }

    int count = 0;
    char c;

    while ((c = fgetc(f)) != EOF) {
        
        if (c == '\n') {

            count++;
        }
    }

    fclose(f);

    printf("\t%d %s\n", count, argv[1]);

    exit(0);
}