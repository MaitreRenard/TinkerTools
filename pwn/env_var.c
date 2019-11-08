#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	//Check if environment variable name is provided
	if (argc > 1) {
		//Get the adress
		char* ptr;
		ptr = getenv(argv[1]);

		//Print its adress if we found it
		if( ptr == NULL ) {
			printf("%s not found\n", argv[1]);
		} else {
			printf("%s : 0x%08x\n", argv[1], (unsigned) ptr);
		}

	} else {
		printf("%s <ENV_VAR_NAME>\n",argv[0]);
	}

	return 0;
}
