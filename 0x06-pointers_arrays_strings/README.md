0x06. C - More pointers, arrays and strings


The `for` statement is closely related to the `while` statement. In
fact, except in a few rear cases, a `for` loop can always be replaced by
an equivalent `while` loop. so the `for` in the `7-leet.c` file can also
be written as: 
```c
check_idx = 0;
while (leet_arr[check_idx] != '\0'){
	if (s[loop_idx] == leet_arr[check_idx])
		s[loop_idx] = arr[check_idx];
	check_idx++;
}
```
this loops through all the characters of the `leet_arr` string literals
even after it has found a match before exit the loop. 
