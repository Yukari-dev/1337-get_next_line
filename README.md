*This project has been created as part of the 42 curriculum by maoulad.*

# get_next_line

## Description

The get_next_line project is a fundamental C programming exercise at 42. Its goal is to create a function that reads a single line ending with a newline character (\n) or EOF (End of File) from a file descriptor (fd), one line at a time.

Calling get_next_line repeatedly in a loop allows reading the contents of a text file line-by-line without loading the entire file into memory at once. This project introduces key programming concepts such as:

- Static variables in C to retain state between function calls.

- Dynamic memory management (malloc, free) to prevent memory leaks.

- Handling arbitrary BUFFER_SIZE values set at compile-time.

- Supporting multiple file descriptors simultaneously.

## Instructions

### Prerequisites

You need a C compiler (gcc or clang) and standard Unix build tools.

#### Compilation

To use get_next_line in your own C project, include the header file #include "get_next_line.h" and compile your code along with the project files:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
```

**Note**: You can adjust the BUFFER_SIZE macro atusing the -D BUFFER_SIZE=n flag.

Execution Example
```bash
./gnl
```

## Usage Example
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("sample.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## DESCRIPTION DETAILS

### Core Logic

get_next_line relies on a multi-step buffering algorithm designed around a static variable array: static char *chunks[1024].

Reading and Accumulation (read_and_get):
The function continuously calls read() with a buffer of size BUFFER_SIZE and appends the read string into chunks[fd] using ft_strjoin. It stops reading as soon as a newline character (\n) is encountered in the accumulated string or when read() reaches EOF/returns 0.

Line Extraction (get_line):
Once a newline or EOF is found in chunks[fd], get_line isolates everything up to and including the first \n character (or EOF), allocates memory for it, and returns this extracted line to the user.

State Preservation (go_to_next_chunk):
The remaining characters after the newline are extracted and saved back into chunks[fd] for the next call of get_next_line. The old pointer is freed to avoid leaks.

# Resources

### References & Documentation

- ##### Man page for read(2)

- ##### Understanding Static Variables in C - [GeeksforGeeks](https://www.geeksforgeeks.org/)

### Use of AI:

AI was used in this project for the following tasks:

- **Testing and explaining: Generating test scripts (main.c) and test files (test.txt, file1.txt, file2.txt) to verify memory handling and multi-FD reading capabilities.**
