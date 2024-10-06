#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "fops.h"

int main(int argc, char *argv[]) {

    // Check if there are at least 3 arguments: operation and filename are mandatory
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <operation> <filename> [data]\n", argv[0]);
        return 1; // Return error code if usage is incorrect
    }

    // Store the operation type and filename from the command line arguments
    const char *operation = argv[1];
    const char *filename = argv[2];

    // If the operation is 'create', create the specified file
    if (strcmp(operation, "create") == 0) {
        int fd = create_file(filename, O_CREAT | O_WRONLY, 0644); // Create a new file with write permissions
        if (fd >= 0) {
            printf("File '%s' created successfully.\n", filename);
        }
    } 
    // If the operation is 'write', write data to the file
    else if (strcmp(operation, "write") == 0 && argc >= 4) {
        const char *data = argv[3]; // Get the data to write from the command line argument
        int fd = create_file(filename, O_WRONLY | O_APPEND, 0644); // Open the file in append mode
        if (fd >= 0) {
            ssize_t written = write_to_file(fd, data, strlen(data)); // Write data to the file
            if (written >= 0) {
                printf("Wrote %ld bytes to '%s'.\n", written, filename);
            }
        }
    } 
    // If the operation is 'read', read data from the file
    else if (strcmp(operation, "read") == 0) {
        int fd = create_file(filename, O_RDONLY, 0); // Open the file in read-only mode
        if (fd >= 0) {
            char buffer[1024]; // Buffer to store the read data
            ssize_t bytes_read = read_from_file(fd, buffer, sizeof(buffer) - 1); // Read data from the file
            if (bytes_read >= 0) {
                buffer[bytes_read] = '\0'; // Null-terminate the string
                printf("Read %ld bytes from '%s': %s\n", bytes_read, filename, buffer); // Print the read data
            }
        }
    } 
    // If the operation is 'delete', delete the specified file
    else if (strcmp(operation, "delete") == 0) {
        if (delete_file(filename) == 0) { // Delete the file
            printf("File '%s' deleted successfully.\n", filename);
        }
    } 
    // If the operation is 'close', close the file after opening it
    else if (strcmp(operation, "close") == 0) {
        int fd = create_file(filename, O_RDONLY, 0); // Open the file in read-only mode to get a file descriptor
        if (fd >= 0) {
            if (close_file(fd) == 0) { // Close the file
                printf("File '%s' closed successfully.\n", filename);
            } else {
                fprintf(stderr, "Error closing file '%s'.\n", filename);
            }
        } else {
            fprintf(stderr, "Error opening file '%s' to close.\n", filename);
        }
    } 
    // If an unknown operation is provided, print an error message
    else {
        fprintf(stderr, "Unknown operation: %s\n", operation);
    }

    return 0;
}
