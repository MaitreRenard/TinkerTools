#include <stdio.h>
#include <stdlib.h>
#include <argp.h>

int parse_options(int key, char *arg, struct argp_state *state) {
	switch (key) {
		case 'd':
			for (int i=0; i<atoi(arg); i++)
				printf("%d ",i);
			printf("\n");
			break;

		case 'q':
			printf("Chhhhh\n");
			break;
	}

	return 0;
}

int main(int argc, char **argv) {
	struct argp_option options[] =
	{
		{ "quiet", 'q', 0, 0, "Dont show progress or errors." },
		{ "digit", 'd', "NUMBER", 0, "Print from 0 to NUMBER." },
		{ 0 }
	};

	struct argp argp = { options, parse_options };

	return argp_parse(&argp, argc, argv, 0, 0, 0);
}
