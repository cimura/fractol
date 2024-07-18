#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char *memory = malloc(1);
	memory = NULL;
	free(memory);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}