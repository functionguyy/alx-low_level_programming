0x0A. C - argc, argv

I learned to suppress unused variable warning which is raised by gcc compilers
when a variable is declared in a C program but not used in any part of program. 


Assuming we have a variable `bar` declared as an argument of a function `foo`, if
variable `bar` is a necessary part of the function argument list even though
it not going to used in the program, the unused variable warning that would be
raised by the compiler during compilation of the C program can be suppressed
like this:

```C
void foo(int __attribute__((__unused__)) bar){
	....
}
```
