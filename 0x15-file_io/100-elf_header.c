#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

/**
 * Prints an error message to stderr.
 * @param: msg the error message to print
 */
void print_error(const char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
}

int main(int argc, char* argv[]) 
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
        return 98;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        print_error("Unable to open file");
        return 98;
    }

    Elf64_Ehdr header;
    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        print_error("Unable to read ELF header");
        close(fd);
        return 98;
    }

    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
        close(fd);
        return 98;
    }

    printf("ELF Header:\n");
    printf("  Magic:                             ");
    for (int i = 0; i < SELFMAG; i++) {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\n");

    printf("  Class:                             ");
    if (header.e_ident[EI_CLASS] == ELFCLASS32) {
        printf("ELF32\n");
    } else if (header.e_ident[EI_CLASS] == ELFCLASS64) {
        printf("ELF64\n");
    } else {
        printf("Unknown\n");
    }

    printf("  Data:                              ");
    if (header.e_ident[EI_DATA] == ELFDATA2LSB) {
        printf("2's complement, little endian\n");
    } else if (header.e_ident[EI_DATA] == ELFDATA2MSB) {
        printf("2's complement, big endian\n");
    } else {
        printf("Unknown\n");
    }

    printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (header.e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV: printf("UNIX - System V\n");
			    break;
        case ELFOSABI_HPUX: printf("HP-UX\n");
			    break;
        case ELFOSABI_NETBSD: printf("NetBSD\n");
			      break;
        case ELFOSABI_LINUX: printf("Linux\n"); 
			     break;
        case ELFOSABI_SOLARIS: printf("Solaris\n");
			       break;
        case ELFOSABI_AIX: printf("AIX\n");
			   break;
	case ELFOSABI_IRIX: printf("IRIX\n");
			    break;
	case ELFOSABI_FREEBSD: printf("FreeBSD\n");
			       break;
	case ELFOSABI_OPENBSD: printf("OpenBSD\n");
			       break;
	default: printf("Unknown\n");
		 break;
    }

    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
	switch (header.e_type)
		case ET_NONE: printf("NONE (Unknown type)\n"); break;
		case ET_REL: printf("REL (Relocatable file)\n"); break;
		case ET_EXEC: printf("EXEC (Executable file)\n"); break;
}
