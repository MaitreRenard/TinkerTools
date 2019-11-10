#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <capstone/capstone.h>
#include <elf.h>

char* read_section64(FILE* file_pointer, Elf64_Shdr section_header)
{
	char* buff = malloc(section_header.sh_size);

	fseek(file_pointer, section_header.sh_offset, SEEK_SET);
	fread((void *)buff, section_header.sh_size, 1, file_pointer);

	return buff;
}


void print_elf_header(Elf64_Ehdr elf_header)
{

	/* Storage capacity class */
	printf("Arch : \t\t");
	switch(elf_header.e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("32 bits.\n");
			break;

		case ELFCLASS64:
			printf("64 bits.\n");
			break;

		default:
			printf("invalide.\n");
			break;
	}

	/* Data Format */
	printf("Endianess : \t");
	switch(elf_header.e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("Little endian\n");
			break;

		case ELFDATA2MSB:
			printf("Big endian\n");
			break;

		default:
			printf("Invalid format\n");
			break;
	}

	printf("\n");	/* End of ELF header */
}

void print_section_headers64(FILE* fd, Elf64_Ehdr eh, Elf64_Shdr sh_table[])
{
	uint32_t i;
	char* sh_str;	/* section-header string-table is also a section. */

	/* Read section-header string-table */
	sh_str = read_section64(fd, sh_table[eh.e_shstrndx]);

	printf("========================================");
	printf("========================================\n");
	printf(" idx offset     load-addr  size       algn"
			" flags      type       section\n");
	printf("========================================");
	printf("========================================\n");

	for(i=0; i<eh.e_shnum; i++) {
		printf(" %03d ", i);
		printf("0x%08lx ", sh_table[i].sh_offset);
		printf("0x%08lx ", sh_table[i].sh_addr);
		printf("0x%08lx ", sh_table[i].sh_size);
		printf("%4ld ", sh_table[i].sh_addralign);
		printf("0x%08lx ", sh_table[i].sh_flags);
		printf("0x%08x ", sh_table[i].sh_type);
		printf("%s\t", (sh_str + sh_table[i].sh_name));
		printf("\n");
	}
	printf("========================================");
	printf("========================================\n");
	printf("\n");	/* end of section header table */
}

int main(int argc, char **argv) {

	if (argc > 1) {
		FILE *file_pointer = fopen(argv[1], "r");  

		//Check if the file is opened
		if (file_pointer == NULL)
		{
			perror("Error while opening the file.\n");
			exit(EXIT_FAILURE);
		}

		//Get header from file
		Elf64_Ehdr elf_header;
		fread((void *)&elf_header, sizeof(elf_header), 1, file_pointer);
		//display it
		print_elf_header(elf_header);

		//Allocate memory for section header table of size : section header entry size * nb section
		Elf64_Shdr* section_header_table = malloc(elf_header.e_shentsize * elf_header.e_shnum);
		fseek(file_pointer, elf_header.e_shoff, SEEK_SET);
		
		for(int i=0; i < elf_header.e_shnum; i++) {
			//Populate the section header table
			fread((void *)&section_header_table[i], elf_header.e_shentsize, 1, file_pointer);
		}

		//Get section header string table
		unsigned char* section_header_string_table = read_section64(file_pointer, section_header_table[elf_header.e_shstrndx]);
		int text_section_idx = 0;
		while (strcmp(".text", (section_header_string_table + section_header_table[text_section_idx].sh_name))) {	
			text_section_idx++;
		} 

		printf("Section chosen : %s\n",(section_header_string_table + section_header_table[text_section_idx].sh_name));
		//Go to text section
		fseek(file_pointer, section_header_table[text_section_idx].sh_offset, SEEK_SET);
		//And get the data
		unsigned char* text_section = malloc(section_header_table[text_section_idx].sh_size);
		if(!text_section) {
			printf("Failed to allocate some bytes!!\n");
			exit(1);
		}
		fread((void *)&text_section,section_header_table[text_section_idx].sh_size,1,file_pointer);
		//printf("%d",(section_header_string_table + section_header_table[text_section_idx].sh_size));

		//Initialize capstone
		csh handle;
		cs_insn *insn;
		size_t count;
		if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle) != CS_ERR_OK)
			return -1;

		count = cs_disasm(handle, &text_section, 200, 0, 0, &insn);
		if (count > 0) {
			size_t j;
			for (j = 0; j < count; j++) {
				printf("0x%"PRIx64":\t%s %s\n", insn[j].address, insn[j].mnemonic, insn[j].op_str);
			}

			cs_free(insn, count);
		} else
			printf("ERROR: Failed to disassemble given code!\n");

		printf("Check !\n");
		cs_close(&handle);
		fclose(file_pointer);  
	} else {
		printf("Usage : %s <file_name>\n",argv[0]);
	}

	return 0;
}

