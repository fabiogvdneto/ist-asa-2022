#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	unsigned i, j, n;

	if(argc == 1) {
		printf("\nDense Graph Generator\n\n");
		printf("Generates an undirected graph with n vertices, numbered 1 to n, where vertex i is connected to vertices i+1 to n with edges of weight i.\n\n");
		printf("   Usage: %s n\n\n", argv[0]);
	}
	else {
		n = atoi(argv[1]);
		printf("%u\n%u\n", n, n*(n-1)/2);
		for(i = 1; i <= n; i++)
			for(j = i+1; j <= n; j++)
				printf("%u %u %u\n", i, j, i);
	}

	return 0;
}
