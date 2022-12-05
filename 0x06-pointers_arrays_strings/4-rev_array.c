/**
* reverse_array - reverses the content of an array of integers
* @a: pointer to the array
* @n: number of elements of the array
*
*/
void reverse_array(int *a, int n)
{
	int loop_idx, place_holder;

	loop_idx = 0;
	while (loop_idx < n)
	{
		place_holder = a[n - 1];
		a[n - 1] = a[loop_idx];
		a[loop_idx] = place_holder;
		n--;
		loop_idx++;
	}
}
