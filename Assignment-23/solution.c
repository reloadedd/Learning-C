#include <stdio.h>

struct SimpleStructure {
	int var;
};


int main(int argc, char const *argv[])
{
	struct SimpleStructure *ptr = NULL;
	struct SimpleStructure instance;

	// Make the pointer point to that instance
	ptr = &instance;

	/* Now, we're gonna to assign a value to the only member of our structure instance
	 * in 3 different ways. First way is using the standard dot-notation.
	 */
	instance.var = 1337;
	printf("Value of 'var' member of the SimpleStructure instance, 'instance': %d\n", instance.var);

	// Assigning a value using the 2nd method: standard dot-notation for the pointer which is
	// initialized to the instance
	(*ptr).var = 0xdead;	// 57005
	printf("Value of 'var' member of the SimpleStructure instance, 'instance': %d\n", instance.var);

	// Assigning the value using the 3rd method: -> operator
	ptr->var = 0xbeef;		// 48879
	printf("Value of 'var' member of the SimpleStructure instance, 'instance': %d\n", instance.var);

	return 0;
}