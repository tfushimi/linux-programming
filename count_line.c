/*
Count the number of lines in a file.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int count_line(const char *path);
void print_error(const char *path);

int main(int argc, char *argv[]) {

    if (argc != 2) {

        print_error(argv[0]);

        exit(1);
    }

    int count = count_line(argv[1]);

    printf("\t%d %s\n", count, argv[1]);

    exit(0);
}

#define BUFFER_SIZE 2048

int count_line(const char *path) {

    int fd = open(path, O_RDONLY);

    if (fd < 0) {

        print_error(path);

        exit(1);
    }

    unsigned char buf[BUFFER_SIZE];

    int count = 0;

    while (1) {

        int n = read(fd, buf, sizeof buf);

        if (n == 0) {

            break;
        }
        else if (n < 0) {

            print_error(path);

            exit(1);
        }
        else {

            for (int i = 0; i < n; i++) {

                if (buf[i] == '\n') {

                    count++;
                }
            }            
        }
    }

    return count;
}


void print_error(const char *path) {

    perror(path);

    exit(1);
}