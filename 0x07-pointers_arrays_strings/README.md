Even more pointers and arrays
Difference between using pointer arithmetic or array subscripting is
that with pointer arithmetic you can use the same notation to extract
the address of the byte in memory `(var_name + i)` or the value of the
byte in memory `*(var_name + i)` but with array subscripting
`var_name[i]` notation you can only extract the value of the byte in
memory.
