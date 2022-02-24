#include <stdio.h>
#include <ctype.h>

int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int ac, char *av[])
{
	int i = 0;

	for (; i < ac; i++) {
		print_letters(av[i]);
	}
}

void print_letters(char av[])
{
	int i = 0;

	for (; av[i] != '\0'; i++)	{
		char ch = av[i];
		if (can_print_it(ch))
			printf("'%c' = %d ", ch, ch);
	}

	printf("\n");
}

int can_print_it(char ch)
{
	return (isalpha(ch)||isblank(ch));
}

int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}
