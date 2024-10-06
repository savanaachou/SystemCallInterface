#include <sys/syscall.h>
#include <fcntl.h>
#include <stdio.h>
#include "fops.h"

// Create a new file
int create_file(const char *filename, int flags, mode_t mode) {
    int fd = syscall(SYS_open, filename, flags, mode);
    
    if (fd == -1) {
        perror("Error");
    }
    return fd;
}

// Write data to a file
ssize_t write_to_file(int fd, const void *buf, size_t count) {
    ssize_t written = syscall(SYS_write, fd, buf, count);
    if (written == -1) {
        perror("Error writing to file");
    }
    return written;
}

// Read data from a file
ssize_t read_from_file(int fd, void *buf, size_t count) {
    ssize_t bytes_read = syscall(SYS_read, fd, buf, count);
    if (bytes_read == -1) {
        perror("Error reading from file");
    }
    return bytes_read;
}

// Close the file
int close_file(int fd) {
    int result = syscall(SYS_close, fd);
    if (result == -1) {
        perror("Error closing file");
    }
    return result;
}

// Delete a file
int delete_file(const char *filename) {
    int result = syscall(SYS_unlink, filename);
    if (result == -1) {
        perror("Error deleting file");
    }
    return result;
}
