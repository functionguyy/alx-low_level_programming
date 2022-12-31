0x06. C - More pointers, arrays and strings

A `for` statement in `C` has the form:
```c
for (expression1; expression2; expression3){
	statement;
}
```

The `for` statement is closely related to the `while` statement. In
fact, except in a few rear cases, a `for` loop can always be replaced by
an equivalent `while` loop:
```c
expression1;
while (expression2){
	statement;
	expression3;
}
```


So the `for` statement in the
[7-leet.c](https://github.com/10xDatabro/alx-low_level_programming/blob/master/0x06-pointers_arrays_strings/7-leet.c)
can be written as: 
```c
check_idx = 0;
while (leet_arr[check_idx] != '\0'){
	if (s[loop_idx] == leet_arr[check_idx])
		s[loop_idx] = arr[check_idx];
	check_idx++;
}
```
this loops through all the characters of the `leet_arr` string literals
for every loop cycle even if it has found a match.
### ROT13
ROT13 is a simple letter subsitution cipher that replaces each alphabetic
characters with the 13th letter after it in the alphabet wrapping back
to the beginning if necessary. The look up table below shows the
substition letter of each letter in the alphabet.
|Parameter | Representation |
| :--- | :----: |
| input | `ABCDEFGHIJKLMNOPQRSTUVWXYZabcefghijklmnopqrstuvwxyz` |
| Output | `NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm` |

Because there are 26 letters in the basic latin alphabet, ROT13 is its
own inverse and when writing the code I add a way to indentify that a
subsitution had already happened inorder for the algorithm to inverse it
self. Hence I added the `found_idx` variable which remains initialized
to zero until a substition has occured and then it value is set to the
index where the subsition occured. The second condition in the `if` acts
the subsitution control: 
### 101-print-number.c
When I used an `int` type for a very large negative number in a modulo
arithmetic my code generated undefined results when an overflow
occurs. Then I read a code somewhere that used an unsigned int type to
perform the same task to get the expected result. 

In C programming language, `unsigned int` is much better than `signed
int` as the range for `unsigned int` is larger than `signed int` and the
modulus operation is defined for `unsigned int` and not for `signed
int`. The following links give more details:

- [link 1](https://embeddedgurus.com/stack-overflow/2009/05/signed-versus-unsigned-integers/)

- [link
2](https://embeddedgurus.com/stack-overflow/2009/08/a-tutorial-on-signed-and-unsigned-integers/#:~:text=To%20convert%20a%20signed%20integer%20to%20an%20unsigned,c%3B%20b%20%3D%20%28unsigned%20int%29a%3B%20c%20%3D%20%28int%29b%3B)
end file
