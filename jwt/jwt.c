#include <stdio.h>
#include <string.h>
#include <qlibc.h>

const char delim[2] = ".";

int main(int argc, char **argv) {
    if(argc > 1) {
		char* token = argv[1];
		printf("JWT token : %s\n", token);

		char* token_part = strtok(token, delim);
		if (token_part) {
			printf("First part : %s\n", token_part);
			qbase64_decode(token_part);
			printf("First part : %s\n", token_part);
		} else {
			puts("Could not parse the token.");
		}

    } else {
        printf("%s takes at least one argument.\n", argv[0]);
	}

    return 0;
}
