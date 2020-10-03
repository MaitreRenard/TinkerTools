#include <stdio.h>
#include <stdlib.h>
#include <keystone/keystone.h>

int main(int argc, char **argv) {
	if (argc > 2) {
		int nbOps = atoi(argv[1]);
		int op = strtol(argv[2], NULL, 16);

		for (int i = 0; i < nbOps; i++) {
			//printf("\\x%02x",op);
			printf("%c",op);
		}
	} else {
		printf("%s <number_of_ops> <op>\n",argv[0]);
	}

	return 0;
}
