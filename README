# File Operations Static Library Project

This project implements basic file operations such as creating, reading, writing, closing, and deleting files using the syscall interface in C. The operations are encapsulated in a static library (`libfops.a`), which is used by a test program (`fops_test.c`).

## Student Info
- Name: Savana Chou
- ID: 2428859
- Course: CPSC 380-02
- Assignment: Programming Assignment 1 - System Call Interface

## Files

- **fops.h**: Header file containing the function prototypes for the file operations.
- **libfops.c**: Implementation of the file operations using the syscall interface.
- **fops_test.c**: A main program to test the file operations by accepting command-line arguments.
- **libfops.a**: The compiled static library.
  
## Functionality

The program supports the following file operations:
- **create `<filename>`**: Create a new file.
- **write `<filename>` `<data>`**: Write data to the file.
- **read `<filename>`**: Read data from the file.
- **close `<filename>`**: Close the file.
- **delete `<filename>`**: Delete the file.

## Compilation Instructions

1. **Compile the Static Library:**

   ```bash
   gcc -c libfops.c -o libfops.o
   ar rcs libfops.a libfops.o
   gcc fops_test.c -L. -lfops -o fops_test

## Sample Output

$ ./fops_test create sample.txt
File 'sample.txt' created successfully.

$ ./fops_test write sample.txt "Hello, this is a test."
Wrote 22 bytes to 'sample.txt'.

$ ./fops_test read sample.txt
Read 22 bytes from 'sample.txt': Hello, this is a test.

$ ./fops_test close sample.txt
File 'sample.txt' closed successfully.

$ ./fops_test delete sample.txt
File 'sample.txt' deleted successfully.
