#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <capstone/capstone.h>
#include <elf.h>

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

		count = cs_disasm(handle, file_content, file_size*100, 0, 0, &insn);
		if (count > 0) {
			size_t j;
			for (j = 0; j < count; j++) {
				printf("0x%"PRIx64":\t%s %s\n", insn[j].address, insn[j].mnemonic, insn[j].op_str);
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
