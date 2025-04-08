/*
Implement cat command using fread and fwrite.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {

    if (argc < 2) {

        perror(argv[0]);

        exit(1);
    }

    unsigned char buf[2048];

    for (int i = 1; i < argc; i++) {

        FILE *f = fopen(argv[i], "r");

        if (!f) {

            perror(argv[i]);

            exit(1);
        }

        while (1) {

            size_t n = fread(buf, 1, 1, f);

            if (ferror(f)) {

                perror(argv[i]);

                fclose(f);

                exit(1);
            }

            if (feof(f)) {

                fclose(f);

                break;
            }

            fwrite(buf, 1, 1, stdout);
       }
    }

    exit(0);
}
