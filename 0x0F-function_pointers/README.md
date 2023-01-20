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
an `int` type. In this case `Add()` is such a function. So you can make `p`
point to `Add()` in the either of the following ways:
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


