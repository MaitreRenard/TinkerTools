# TinkerTools

Little C programs useful for dev, ctf or only discovery.

## Development

Using [qlibc](https://github.com/wolkykim/qlibc) and [glib](https://gitlab.gnome.org/GNOME/glib).

### C code templates

* [Basic](templates/basis.c)
* [Handling arguments basis](templates/basis_with_args.c)
* [Simple display with ncurses](templates/basic_ncurses.c)
* [File reading](templates/file_read.c)

### PWN

Disassembler using [Capstone](https://www.capstone-engine.org/).

Payload generator using [Keystone](https://www.keystone-engine.org/).

* [Get the address of an environment variable](pwn/env_var.c)
* [\[WIP\] ELF disassembler](pwn/elf_parser/parser.c)
* [\[WIP\] De bruijn implementation](pwn/de_bruijn.c)

### Steganography

* [LSB Extraction](steg/lsb.c)
