*Este proyecto ha sido creado como parte del currículo de 42 por \<alvicent>.*

# ft_printf

## Description

A reimplementation of the C standard library `printf()` function, built as a static library `libftprintf.a`. The goal is to understand variadic functions in C and produce a well-structured, extensible codebase.

The function handles the following conversions:

| Specifier | Description |
|-----------|-------------|
| `%c` | Single character |
| `%s` | String (prints `(null)` if pointer is NULL) |
| `%p` | Pointer address in hexadecimal (prints `(nil)` if NULL) |
| `%d` | Signed decimal integer |
| `%i` | Signed integer in base 10 |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hexadecimal integer (lowercase) |
| `%X` | Unsigned hexadecimal integer (uppercase) |
| `%%` | Literal percent sign |

Returns the number of characters written, or `-1` on write error.

## Algorithm and Data Structure Choices

The format string is traversed character by character using a pointer. When a `%` is detected, the next character is passed to a dispatcher (`select_format`) that calls the appropriate print function. No buffer is used — every character is written directly to stdout via `write()`.

A single `int *len` counter is threaded through all print functions to accumulate the total number of characters written and propagate write errors (by setting `len` to `-1` and stopping early).

Numbers are printed using recursive digit extraction: divide by the base, recurse, then print the remainder. This avoids needing any intermediate string allocation.

`long` is used in `print_nbr` to safely negate `INT_MIN` without integer overflow.
`unsigned long` is used in `print_ptr_hex` to correctly handle 64-bit pointer addresses.

## File Structure

```
ft_printf/
├── Makefile
├── ft_printf.h
├── ft_printf.c        → ft_printf, print_all, select_format
├── ft_print_char.c    → print_char, print_str
├── ft_print_nbr.c     → print_nbr, print_unbr, print_hex, print_ptr
└── libft/             → base library
```

## Instructions

### Build the library

```bash
make
```

This compiles `libft` first, then builds `libftprintf.a` in the project root.

### Use in your project

```bash
cc your_file.c -L. -lftprintf -o your_program
./your_program
```

### Clean

```bash
make clean    # removes object files
make fclean   # removes object files and libftprintf.a
make re       # fclean + all
```

## Resources

- [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Tutorial C - 45 Funciones variaticas](https://youtu.be/yPrOq2Io4D8?si=Tc6a7X_bXZBiS23I)
- [42 Norm](https://github.com/42School/norminette)

### AI usage

Claude was used occasionally as a debugging and code review tool, mainly to help identify small mistakes, review edge cases, and clarify specific C concepts.