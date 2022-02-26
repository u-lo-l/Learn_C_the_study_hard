#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char	*name;
	int		age;
	int		height;
	int		weight;
};

struct Person *Person_create(char *name,
							int age,
							int height,
							int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who != NULL);
	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("NAME : %s\n",who->name);
	printf("\tAGE : %d\n",who->age);
	printf("\tHEIGHT : %d\n",who->height);
	printf("\tWEIGHT : %d\n",who->weight);
}

int main ()
{
	struct Person *Joe = Person_create("Joe",32,64,140);
	struct Person *Frank = Person_create("Frank",20,72,180);

	printf("Joe's memory location : %p\n", Joe);
	Person_print(Joe);

	printf("Frank's memory location : %p\n", Frank);
	Person_print(Frank);
	
	Person_destroy(Joe);
	Person_destroy(Frank);
}
