/*
Print out a file and replace
- '\t' by '\' and 't'
- '\n' by '$' and '\n'
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {

        perror("Input should be a file");

        exit(1);
    }

    FILE *f = fopen(argv[1], "r");

    if (!f) {
        
        perror(argv[1]);

        exit(1);
    }

    int c;

    while ((c = fgetc(f)) != EOF) {

        if (c == '\t') {

            if (printf("/\t") < 0) {

                perror(argv[1]);

                fclose(f);

                exit(1);
            }
        }
        else if (c == '\n') {

            if (printf("/$/\\n", stdout) < 0) {

                perror(argv[1]);

                fclose(f);

                exit(1);
            }
        }
        else if (fputc(c, stdout) < 0) {

            perror(argv[1]);

            fclose(f);

            exit(1);
        }
    }

    fclose(f);

    exit(1);
}