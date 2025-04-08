/*
Implement "cat" command using symstem calls.

If file paths are not provided, it takes inputs from stdin.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void do_cat(int fd, const char *path);
void do_cat_path(const char *path);
void print_error(const char *path);

int main(int argc, char *argv[]) {

    if (argc < 2) {

        do_cat(STDIN_FILENO, "stdin");

        exit(0);
    }

    for (int i = 1; i < argc; i++) {

        do_cat_path(argv[i]);
    }
    
    exit(0);
}

#define BUFFER_SIZE 2048

void do_cat(int fd, const char *path) {

    unsigned char buf[BUFFER_SIZE];

    while (1) {

        int n = read(fd, buf, sizeof buf);

        if (n == 0) {
            
            // reach the end of a file
            break;
        }
        else if (n < 0) {

            print_error(path);

            exit(1);
        }
        else if (write(STDOUT_FILENO, buf, n) < 0) {

            print_error(path);

            exit(1);
        }
    }
}


void do_cat_path(const char *path) {

    int fd = open(path, O_RDONLY);
    
    if (fd < 0) {

        print_error(path);

        exit(1);
    }

    do_cat(fd, path);

    if (close(fd) < 0) {

        print_error(path);
    }

    exit(0);
}

void print_error(const char *path) {

    perror(path);

    exit(1);
}
