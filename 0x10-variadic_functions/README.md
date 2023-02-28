# 0x10.C - Variadic functions
Functions such as `printf()` and `scanf()` have an unusual property; they
allow any number of arguments.

The `<stdarg.h>` header file provides the tools we'll need to write our own
functions with variable-length argument lists.

`<stdarg.h>` declares one type `va_list` and defines several macros. In C89
there are three macros which can be thought

## Resources
- [Const Keyword explained](https://www.youtube.com/watch?v=1W4oyuOdXv8)
- [Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [stdarg.h](https://en.wikipedia.org/wiki/Stdarg.h)
