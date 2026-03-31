*This project has been created as part of the 42 curriculum by bayseven.*

# Description

`ft_printf` is a simplified reimplementation of the C standard library function `printf` for the 42 school project. The goal is to parse a format string and print arguments using only low-level system calls (`write`) and variadic argument handling (`stdarg.h`).

This repository provides a beginner-friendly implementation covering essential format specifiers.

Supported format specifiers:
- `c` (char)
- `s` (string)
- `p` (pointer, shown as `0x...`)
- `d`, `i` (signed integer)
- `u` (unsigned integer)
- `x`, `X` (hexadecimal, lower/upper)
- `%%` (literal percent)

# Project structure

- `ft_printf.c`: main dispatcher, scans format string, handles literals and `%` conversions.
- `ft_print_simple.c`: helper functions for char/string/signed/unsigned integers.
- `ft_print_hex.c`: helper functions for hexadecimal and pointer formatting.
- `ft_printf.h`: API declarations and required includes.
- `Makefile`: standard targets: `all`, `clean`, `fclean`, `re`.

# Implementation overview

1. `ft_printf` scans input characters one by one.
2. Normal characters are printed directly with `write` and counted.
3. Upon `%`, it reads next specifier and calls `ft_check_format`.
4. `ft_check_format` calls:
   - `ft_print_char` for `%c`
   - `ft_print_str` for `%s`
   - `ft_print_ptr` for `%p`
   - `ft_print_nbr` for `%d` / `%i`
   - `ft_print_unsigned` for `%u`
   - `ft_print_hex` for `%x` / `%X`
   - `%` prints `%`
5. Each helper returns number of bytes printed.

`ft_print_nbr` and `ft_print_unsigned` use recursion to print each digit directly.

# Instructions

1. Clone repository:
   - `git clone <repo-url>`
2. Change directory:
   - `cd intranewprintf`
3. Build:
   - `make`
4. Build a test binary (if no test is provided):
   - Create `main.c` with sample `ft_printf` calls.
   - Compile: `gcc -Wall -Wextra -Werror ft_printf.c ft_print_simple.c ft_print_hex.c main.c -o test_ft_printf`
   - Run: `./test_ft_printf`

Example:
```c
#include "ft_printf.h"

int main(void)
{
    int n = ft_printf("Hello %s %d %x %p %%\n", "world", 42, 255, (void *)1234);
    ft_printf("%d chars printed\n", n);
    return 0;
}
```

# Algorithm and data structure

- Single-pass parser of the format string.
- `va_list` for variadic argument extraction.
- Recursive numeric conversion avoids temporary buffers.
- `write` is the only output primitive, matching 42 constraints.

# Resources

- [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [va_start man page](https://man7.org/linux/man-pages/man3/va_start.3.html)
- [va_arg man page](https://man7.org/linux/man-pages/man3/va_arg.3.html)
- [va_end man page](https://man7.org/linux/man-pages/man3/va_end.3.html)
- [Youtube](https://www.youtube.com/watch?v=7hna28umZwc)
- [C stdio printf() Function](https://www.w3schools.com/c/ref_stdio_printf.php)

AI usage:
- Drafting and structuring this README was assisted by ChatGPT (Raptor mini).
- Implementation details were derived from the source code in this repo.

# Notes

- Width, precision, flags, and length modifiers are not implemented.
- Handles `NULL` string by printing `(null)`.
- Handles `-2147483648` special integer case explicitly.
- Good base for adding precision, field width, and flags later.

# Makefile targets

- `all`: compile source files and create executable or library.
- `clean`: remove object files.
- `fclean`: remove object files and executable/library.
- `re`: run `fclean` then `all`.
