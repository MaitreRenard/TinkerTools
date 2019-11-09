#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <capstone/capstone.h>
#include <elf.h>

#define CODE "\x55\x48\x8b\x05\xb8\x13\x00\x00"

unsigned char* readFileBytes(char *name)  
{  
	FILE *file_pointer = fopen(name, "r");  

	if (file_pointer == NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	//Get file size
	fseek(file_pointer, 0, SEEK_END);  
	long file_length = ftell(file_pointer);  

	unsigned char *file_content = malloc(file_length);  
	//Go to start and read all the file content
	fseek(file_pointer, 0, SEEK_SET);  
	fread(file_content, 1, file_length, file_pointer);  

	fclose(file_pointer);  
	return file_content;  
}  

unsigned char* readElfHeader(char *name)  
{  
	FILE *file_pointer = fopen(name, "r");  

	if (file_pointer == NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	//Go to start and read all the file content
	int header_length = 4 + 1 + 1 + 1;
	unsigned char *header_content = malloc(header_length);  

	//fseek(file_pointer, 0, SEEK_SET);  
	fread(header_content, 1, header_length, file_pointer);  

	if (header_content[0] != 0x7f ||header_content[1] != 'E' ||header_content[2] != 'L' ||header_content[3] != 'F') {
		printf("Ce n'est pas un fichier ELF\n");
	} else {
		printf("C'est un fichier ELF");
		if (header_content[4] == 2) {
			printf(" en 64 bits");
		} else if (header_content[4] == 1) {
			printf(" en 32 bits");
		}
		if (header_content[5] == 1) {
			printf(" en little endian");
		} else if (header_content[4] == 1) {
			printf(" en big endian");
		}
		printf("\n");
	}

	fclose(file_pointer);  
	return header_content;  
}  


int main(int argc, char **argv) {
	if (argc > 1) {
		FILE *file_pointer = fopen(argv[1], "r");  
		
		if (file_pointer == NULL)
		{
			perror("Error while opening the file.\n");
			exit(EXIT_FAILURE);
		}

		//Get file size
		fseek(file_pointer, 0, SEEK_END);  
		long file_size = ftell(file_pointer);  


		unsigned char *file_content = malloc(file_size);  
		//Go to start and read all the file content
		fseek(file_pointer, 0, SEEK_SET);  
		fread(file_content, 1, file_size, file_pointer);  

		//Initialize capstone
		csh handle;
		cs_insn *insn;
		size_t count;

		if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle) != CS_ERR_OK)
			return -1;

		count = cs_disasm(handle, file_content, file_size, 0, 0, &insn);
		if (count > 0) {
			size_t j;
			for (j = 0; j < count; j++) {
				printf("0x%"PRIx64":\t%s\t\t%s\n", insn[j].address, insn[j].mnemonic, insn[j].op_str);
			}

			cs_free(insn, count);
		} else
			printf("ERROR: Failed to disassemble given code!\n");

		cs_close(&handle);
		fclose(file_pointer);  
	} else {
		printf("Usage: %s <file_name>\n",argv[0]);
	}

	return 0;
}
