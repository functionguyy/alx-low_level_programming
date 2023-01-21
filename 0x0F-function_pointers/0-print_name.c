/**
* print_name - A function that prints a name to stdout
* @name: pointer to the name to be printed
* @f: function pointer to function that returns void and takes a character
* pointer
*
*
*/

void print_name(char *name, void (*f)(char *s))
{
	if (name && f)
	{
		(*f)(name);
	}
}
