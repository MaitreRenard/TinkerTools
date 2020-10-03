#include <stdio.h>
#include <stdlib.h>
#include <argp.h>
#include <math.h>

static char doc[] = "Extract least significant bit from file.";
static char args_doc[] = "FILE";

struct arguments
{
	char *file;
	int nb_bits;
};

FILE* open_file(const char* filename) {
	FILE *file_pointer = fopen(filename, "r");  

	//Check if the file is opened
	if (file_pointer == NULL)
	{
		perror(filename);
		exit(EXIT_FAILURE);
	}

	return file_pointer;
}

unsigned char* read_file(FILE* file_pointer, const long file_size) {
	//Allocate some memory to store the file data
	unsigned char *file_content = malloc(file_size);  

	//Go to start and read all the file content
	rewind(file_pointer);  
	fread(file_content, 1, file_size, file_pointer);  

	return file_content;
}

void get_lsb(const unsigned char* file_content, const long file_size, const int nb_bits) {
	//Print the file LSB
	int i = 0, mask = (int)(pow(2, nb_bits) - 1);
	unsigned char c = 0;

	while (i < file_size) {
		if (i % ((int)8/nb_bits) == 0 && i != 0) {
			printf("%c",c);
			c = 0;
		} else {
			c = c << nb_bits;
			c += file_content[i] & mask;
		}
		i++;
	}
}

int parse_options(int key, char *arg, struct argp_state *state) {
	struct arguments *arguments = state->input;

	switch (key) {
		case 'd':
			arguments->nb_bits = atoi(arg);
			break;

		case ARGP_KEY_ARG:
			/* Too many arguments.  */
			if (state->arg_num > 0) {
				argp_usage(state);
			}
			arguments->file = arg;
			break;


		case ARGP_KEY_END:
			/* Not enough arguments.  */
			if (state->arg_num < 1) {
				argp_usage (state);
			}
			break;

		default:
			return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

int main(int argc, char **argv) {
	struct arguments arguments;

	/* Default values.  */
	arguments.nb_bits = 1;
	arguments.file = argv[0];

	struct argp_option options[] =
	{
		{ "digit", 'd', "NUMBER", 0, "Extract NUMBER bits from lsb" },
		{ 0 }
	};

	struct argp argp = { options, parse_options, args_doc, doc };
	argp_parse(&argp, argc, argv, 0, 0, &arguments);

	//Get file size
	FILE* f = open_file(arguments.file);
	fseek(f, 0, SEEK_END);  
	const long file_size = ftell(f);  

	unsigned char* file_content =  read_file(f, file_size);
	fclose(f);  

	get_lsb(file_content, file_size, arguments.nb_bits);

	return 0;
}

