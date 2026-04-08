# Get Next Line

[![Language](https://img.shields.io/badge/language-C-informational?style=flat)](https://github.com/topics/c)

## Description

A C implementation of the `get_next_line` function that reads a line from a file descriptor. This project handles efficient line-by-line reading from files, with support for multiple open file descriptors simultaneously. The implementation manages dynamic memory allocation to accumulate and return complete lines, regardless of buffer size.

## Technologies & Concepts

- File descriptor handling in C
- Static variable usage for state persistence across function calls
- Dynamic memory allocation and management
- Efficient buffer handling for incremental reading
- Boundary case handling (empty files, no newline, multiple consecutive newlines)

## Installation

```bash
git clone https://github.com/fabbbiodc/get_next_line.git
cd get_next_line
```

## Usage

```bash
make        # Compile mandatory version
make bonus  # Compile bonus version (multiple fd support)
```

Include the header and call the function:

```c
#include "get_next_line.h"

char *line = get_next_line(fd);
while (line != NULL)
{
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
}
```

### Testing

The project includes built-in test targets:

```bash
make test   # Run mandatory tests
make test_b # Run bonus tests (multiple fd)
```

## Compilation

| Command | Description |
|---------|-------------|
| `make` | Compile mandatory version |
| `make bonus` | Compile bonus version (multiple fd) |
| `make clean` | Remove object files |
| `make fclean` | Remove all build artifacts |
| `make re` | Full rebuild |

## How It Works

The `get_next_line` function reads from a file descriptor one line at a time:

1. **Reading** - Uses `read()` with a configurable `BUFFER_SIZE` to fetch data incrementally
2. **Accumulating** - Stores residual data in a `static` variable to preserve state between calls
3. **Extracting** - Identifies newline boundaries and returns complete lines
4. **Cleanup** - Returns `NULL` when EOF is reached and frees remaining memory

The bonus version extends this to handle multiple file descriptors simultaneously by maintaining a separate static buffer for each fd.

## Key Features

- **Configurable Buffer Size** - Compile with `-D BUFFER_SIZE=<value>` to tune read performance
- **Multiple File Descriptor Support** - Bonus implementation reads from several open files concurrently
- **Memory Safe** - Properly handles allocation, reallocation, and cleanup of line buffers
- **Edge Case Handling** - Handles empty files, files without trailing newlines, and consecutive newlines

## Project Structure

```
get_next_line/
├── get_next_line.c             # Main implementation
├── get_next_line.h             # Header file with prototype and BUFFER_SIZE
├── get_next_line_utils.c       # Utility functions (strchr, strdup, join)
├── get_next_line_bonus.c       # Bonus implementation (multiple fd support)
├── get_next_line_bonus.h       # Bonus header
├── get_next_line_utils_bonus.c # Bonus utilities
├── test_mandatory.c            # Mandatory tests
├── test_bonus.c                # Bonus tests
├── test1.txt                   # Test file 1
├── test2.txt                   # Test file 2
└── Makefile                    # Build & test automation
```

## Tech Stack

- **Language:** C
- **System Calls:** `read()`, `malloc()`, `free()`
- **Build:** Makefile with configurable `BUFFER_SIZE`

## Resources

- [The `read()` System Call](https://man7.org/linux/man-pages/man2/read.2.html) - Core system call used for reading
- [Static Variables in C](https://en.cppreference.com/w/c/language/storage_duration) - Key concept for state persistence
- [Dynamic Memory Management](https://en.cppreference.com/w/c/memory) - malloc, realloc, and free reference
