# 0x0F.C - Function pointers

A function pointer is the starting address or entry point of the block of
memory containing all the instructions in a function.

Lets say we define a function named `Add()` as follows:
```C
int Add(int a, int b)
{
	return (a + b);
}
```
we can declare a function pointer variable that can point to `Add(int a, int b)` like this:
```C
int (*p)(int, int);


```
`p` can point to any function which has two `int` type parameters and returns
an `int` type. In this case `Add()` is such a function. The parentheses `()`around
`*p` is very important in the declaration. if it is omitted in the 
declaration `*p` will not be interpreted by the C compiler as function pointer
variable but rather it is interpreted as a function that returns a pointer.


So you can make `p` point to `Add()` in the either of the following ways:
```C
p = Add; /* p points to Add(int a, int b) */

        /* If a function name is not followed by a parentheses, the C compiler
	 * produces a pointer to the function instead of generating code for a
	 * function call */
```
or 
```C
p = &Add; /* p points to Add(int a, int b) */
```
and you can call `Add(int a, int b)` by wrting either:
```C
(*p)(2,3); /* a call to Add(int a, int b) */
```
or 
```C
p(2,3) /* a call to Add(int a, int b) */
```

so a typical code snippet will be like
```C
#include <stdio.h>
/**
* Demostrating usage of a function pointer 
*/

int Add(int a, int b)
{
	int num;

	num = a + b ; 

	return (num);
}


int main()
{
	int (*p)(int, int); /* declare function pointer p that to points to
			       any function that has two int type parameter
			       and returns an int type */
	int result;

	p = &Add; /*set p the memory address of function Add */ 
	result = (*p)(2,3); 

	printf("%d\n", result);
	return (0);
}
```
**OUTPUT**
```Shell
5

```


## RETURN FUNCTION POINTERS FROM A FUNCTION

To return a function pointer from a function, the return type of function
should be a pointer to another function. But the compiler doesn't accept such
a return type for a function, so we need to define a type that represents that
particular function pointer.

To declare a function that returns a function pointer this is the syntax:
```C
return_type_of_returning_function_pointer (*function_name_which_returns_function_pointer)(actual_function_parameters)(returning_function_parameters)
```

So declare a function that takes `char` type normal pointer as its parameter and returns a function
pointer to any function that takes two `int` type parameter, you can write the
prototype of function like this:
```C
int (*Convert(char *code))(int,int);
```
A then you can define the function like this:
```C
int (*Convert(char *code))(int,int)
{
	if (code == "+") 
		return (&Add);
	if (code == "-")
		return (&Subtract);
}
```

The syntax of function pointers can sometimes be confusing. So we can use a
typedef statement to make things simpler
```C
typedef int (*f)(int,int);
```
Now we can simplify the `Convert` definition above as follows:
```C
f Convert(char *code)
{
	if (code == "+") 
		return (&Add);
	if (code == "-")
		return (&Subtract);
}

```
A typical code snippet will be like:
```C
#include <stdio.h>
/** 
* demostrating a function that returns a function pointer
*/
int main()
{
	int (*ptr)(int,int); /* or f ptr; if you have a typedef */
	char *s;

	s = "+";
	ptr = Convert(s);
	printf("%d\n", ptr(2,4));
}
```
**OUTPUT**
```Shell
6
```






