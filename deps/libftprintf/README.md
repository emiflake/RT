# ft_printf
42 C: printf

A simple printf clone written in Norm-compliant C.

> :warning: Please don't actually use this in production

# Building
To build our project, make sure to recursively clone the submodules by passing `--recurse`.
Other than that, simple run `make` in the project's root. This will make the `libftprintf.a` library file.

# Modularity
This printf writes through a writer struct in order to allow for creation of modular printf derivatives.
This allows us to write not only to the output, but also to: files, strings, sockets, mail pidgeons, etc!
A writer looks like this:
```c
struct {
    / How many bytes we wrote
    |                      / A reference to the state pointer
    |                      |                   / The string  / The string length
    v                      v                   v             v
  ssize_t  (*write)(struct s_writer *self, char *str, size_t length);

  // Internal state to be passed to the write call.
  void  *state;
};
```
# Functions
### I/O
```c
// Writes to standard output (is call to fprintf)
int ft_printf(char *fmt, ...);

// Writes to a file descriptor.
int ft_dprintf(int fd, char *fmt, ...);
```


### Strings
```c
// Writes to a *new* string see example 1.
int ft_asprintf(char **dest, char *fmt, ...);

// Writes to a string (does not check size, dangerous!)
int ft_sprintf(char *dest, char *fmt, ...);

// Writes to a string, taking a limit.
int ft_snprintf(char *dest, size_t len, char *fmt, ...);
```

# Examples
### Example 1.
```c
char *str;

str = NULL;
ft_aprintf(&str, "Hello, %s", "world!");
// `str' will now have `Hello, world!'
```

# Tests
### Testing framework
Our printf uses [criterion](https://github.com/Snaipe/Criterion) for tests. All of our tests are ran on the `snprintf` writer and the `asprintf` writer only. As well as some internal tests.
### Running them
To run the tests, go into `test/`, and run the following command: `make test`.
This will run the tests.

# Debugging

Snippet to print the current output string when in lldb and you are in a
ft_asprintf formatter:

```
p *((struct s_writer_alloc_state *)((t_writer *)writer)->state)->str_ptr
```
