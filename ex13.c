#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 1;

	for (; i < argc; i++) {
		printf("arg %d : %s\n", i , argv[i]);
	}

	char *states[] = {
		"California","Oregon","Washington","Texas"
	};

	int num_state = 4;
	for (i = 0; i < num_state; i++) {
		printf("state %d : %s\n", i, states[i]);
	}

	return 0;
}
