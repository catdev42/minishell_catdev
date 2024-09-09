#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void print_fd_info(int fd) {
    char path[256];
    char link[256];
    ssize_t len;

    // Construct the path to the file descriptor link
    snprintf(path, sizeof(path), "/proc/self/fd/%d", fd);

    // Read the symbolic link
    len = readlink(path, link, sizeof(link) - 1);
    if (len == -1) {
        perror("readlink");
        exit(EXIT_FAILURE);
    }
    link[len] = '\0';

    // Print the file descriptor information
    printf("File descriptor %d points to: %s\n", fd, link);
}

void print_fd_contents(int fd) {
    char buffer[256];
    ssize_t bytes_read;

    // Seek to the beginning of the file descriptor
    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("lseek");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file descriptor
    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    int fd = 4;

    // Print information about the file descriptor
    print_fd_info(fd);

    // Print the contents of the file descriptor
    print_fd_contents(fd);

    return 0;
}