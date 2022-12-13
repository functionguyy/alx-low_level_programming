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
