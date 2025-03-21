# EPITECH-x86-64-Assembly
{ EPITECH } -B-ASM-400-x86-64-Assembly

# MiniLibC

**Binary Name:** `libasm.so`
**Language:** x86-64 Assembly
**Compilation:** Makefile (includes `re`, `clean`, and `fclean` rules)

---

## Project Overview

The objective of this project is to create a dynamic ELF library that mimics certain functions of the standard C library used in your system. This library will be implemented in x86-64 assembly language, offering the opportunity to replace specific standard library functions with your own implementations. The project focuses on dynamic linking and uses weak binding via `LD_PRELOAD`.

By completing this project, you will gain a deeper understanding of low-level assembly programming, dynamic linking, and how the standard library functions are implemented under the hood.

---

## Functions to Implement

You are required to implement the following functions as part of your **MiniLibC** library:

- `strlen`
- `strchr`
- `strrchr`
- `memset`
- `memcpy`
- `strcmp`
- `memmove`
- `strncmp`
- `strcasecmp`
- `strstr`
- `strpbrk`
- `strcspn`

---

## Bonus Functions

In addition to the mandatory functions, the following bonus functions will be checked by the autograder:

- `ffs`
- `index`
- `rindex`
- `strfry`
- `memfrob`
- `syscall`
