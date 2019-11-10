#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	if (argc > 0) {
		FILE *file_pointer = fopen(argv[1], "r");  

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

	} else {
		printf("Usage : %s <file_name>\n",argv[0]);
	}

	return 0;
}

