#include "miniRT.h"


int main() {

	void **entities = malloc(10 * sizeof(void *));
	if (!get_ambient_light("A 0 255,255,255", entities))
		return (0);

	
	printf("ratio\t= %f|\n", ((t_ambient *)entities[1])->ratio);
	printf("red\t= %d|\n", ((t_ambient *)entities[1])->red);
	printf("green\t= %d|\n", ((t_ambient *)entities[1])->green);
	printf("blue\t= %d|\n", ((t_ambient *)entities[1])->blue);

	return 0;
}
