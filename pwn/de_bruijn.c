#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Can only go up to 20-ish
long long fact(const int n) {
	long long factorial = -1;

	if (n >= 0) {
		factorial = 1;

		if (n >= 2) {
			for (int i=1; i <= n; i++)
				factorial = i * factorial;
		}
	}

	return factorial;
}

/*
char* de_bruijn(int length, char* alphabet) {
}
*/

long check_de_bruijn(int uniqueLength, char* alphabet) {
	//pow(base,power);
	long numerateur, denominateur;
	int nb_elt = strlen(alphabet);

	numerateur = pow(fact(nb_elt),pow(nb_elt,uniqueLength - 1));
	denominateur = pow(nb_elt,uniqueLength);

	return numerateur / denominateur;
}

int main(int argc, char **argv) {

	if (argc > 2) {
		if (!strcmp(argv[1],"generate")) {
		} else if (!strcmp(argv[1],"find")) {
			printf("Cette fonctionnalité n'a pas encore été implémentée\n");
		}
		//char* tab = {'A','B','C'};
		//printf("%ld\n",check_de_bruijn(1,tab));
	} else if (argc == 2) {
		if (!strcmp(argv[1],"generate")) {
			printf("Usage: %s generate size_of_string\n",argv[0]);
		} else if (!strcmp(argv[1],"find")) {
			printf("Usage: %s find string_to_search_for\n",argv[0]);
		} else 
			printf("Usage: %s <generate/find> <number/string>\n",argv[0]);
	} else
		printf("Usage: %s <generate/find> <number/string>\n",argv[0]);


	return 0;
}
