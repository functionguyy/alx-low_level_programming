## 0x0A. C - argc, argv
### Command-line Arguments
To obtain access to **command-line** arguments ( called program parameters in 
the C standard) we must define the `main` function of our C program as a
function with two parameters, which are customarily named `argc` and `argv`:
```C
int main(int argc, char *argv[])
{
	/* code block */
}
```

`argc`("argument count") is the number of command-line arguments(including the
name of program itself).

`argv`("argument vector") is an array of pointers to the command line
arguments which are stored in string literal form.


`argv[0]` points to the name of the program, while `argv[1]` through
`argv[argc - 1]` points to the remaining command-line arguments.

`argv` has one addition element, `argv[argc]`, which is always a **NULL
pointer**


So lets say we have a file named `remind.c` in our current directory and we
enter this command-line into our bash shell
```shell
ls -l remind.c
```
then `argc` will be $3$. 

`argv[0]` will point to the string literal containing the program name.
`argv[1]` will point to the string `"-l"`, `argv[2]` will point to the
`"remind.c"`, and `argv[3]` will be a **NULL pointer**


The value of `argc` is generated considering $0$ as the first
number as opposed to the usual arithmetic count that starts with $1$ as the
first number.

### [0-whatsmyname.c](https://github.com/10xDatabro/alx-low_level_programming/blob/master/0x0A-argc_argv/0-whatsmyname.c)

I learned to suppress unused variable warning which is raised by gcc compilers
when a variable is declared in a C program but not used in any part of program. 


Assuming we have a variable `bar` declared as an argument of a function `foo`, if
variable `bar` is a necessary part of the function argument list even though
it not going to used in the program, the unused variable warning that would be
raised by the compiler during compilation of the C program can be suppressed
like this:

```C
void foo(int __attribute__((__unused__)) bar){
	/* code block */
}
```

###
[3-mul.c](https://github.com/10xDatabro/alx-low_level_programming/blob/master/0x0A-argc_argv/3-mul.c)

I used the C standard library function `atoi()` to convert the string number
recieved as command line argument to integer. 

`atoi()` accepts a pointer to `char` type as its argument and returns an `int` type
 
