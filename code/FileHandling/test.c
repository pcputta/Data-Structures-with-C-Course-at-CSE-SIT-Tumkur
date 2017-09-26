#include <stdio.h>

int main()
{
	char *str = "abcdef";
	*(str+1) = 'x';

	printf("%s", str);
	return 0;
}
