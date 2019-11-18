#include <stdio.h>
#include <stdlib.h>
#include <argp.h>

unsigned char read_file(char *filename) {
		FILE *file_pointer = fopen(filename, "r");  

		//Check if the file is opened
		if (file_pointer == NULL)
		{
			perror("Error while opening the file.\n");
			exit(EXIT_FAILURE);
		}

		//Get file size
		fseek(file_pointer, 0, SEEK_END);  
		long file_size = ftell(file_pointer);  

		//Allocate some memory to store the file data
		unsigned char *file_content = malloc(file_size);  

		//Go to start and read all the file content
		fseek(file_pointer, 0, SEEK_SET);  
		fread(file_content, 1, file_size, file_pointer);  

		fclose(file_pointer);  

		//Print the file content
		int i = 0;
		while (i < file_size) {
			printf("%c",file_content[i]);
			i++;
		}

	return 0;
}

int parse_options(int key, char *arg, struct argp_state *state) {
	switch (key) {
		case 'f':
			unsigned char *file_content;
			read_file(arg);
			break;
	}

	return 0;
}

int main(int argc, char **argv) {
	struct argp_option options[] =
	{
		{ "file", 'f', "csv_file", 0, "CSV File to parse." },
		{ 0 }
	};

	struct argp argp = { options, parse_options };

	return argp_parse(&argp, argc, argv, 0, 0, 0);

}
