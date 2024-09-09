#include <stdio.h>

int	main(void)
{
	float temp, temp2;
	//  printf("\e");
	//  printf("\x1B");
	temp = 5 * 65 / 9.0;
	temp2 = 65 * (5 / 9.0);
	printf("\e[45m");
	printf("%10.1f, %10.1f", temp, temp2);
	// printf("%i\n", temp);
	printf("\n");
}
