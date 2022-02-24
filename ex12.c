#include <stdio.h>

int main()
{
	int areas[] = {10, 20, 30, 40};
	char name[] = "Zed";
	char full_name[] = {
		'Z','e','d',
		' ','A','.',' ',
		'S','h','a','w','\0'
	};
	printf("The size of an int: %ld\n", sizeof(int));
	printf("The size of an areas(int[]): %ld\n", sizeof(areas));
	printf("The size of an ints of areas: %ld\n", sizeof(areas)/sizeof(int));
	printf("The first arear is %d, the 2nd %d.\n", areas[0], areas[1]);

	printf("The size of a char : %ld\n", sizeof(char));
	printf("The size of name : %ld\n", sizeof(name));
	printf("The number of chars : %ld\n", sizeof(name)/sizeof(char));

	printf("The size of full_name(char[])%ld\n", sizeof(full_name));
	printf("The number of chars : %ld\n", sizeof(full_name)/sizeof(char));
	printf("name =\"%s\" and full_name=\"%s\"\n", name, full_name);

	return 0;
}
