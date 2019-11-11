# TinkerTools

Liste d'exécutables (principalement C) utiles en CTF ou pour du dev.

```bash
gcc -O3 -std=c18 -Wall -Wextra -Wpedantic -Wformat=2 -Wno-unused-parameter -Wshadow -Wwrite-strings -Wstrict-prototypes -Wold-style-definition -Wredundant-decls -Wnested-externs -Wmissing-include-dirs -Wjump-misses-init -Wlogical-op -o <binary_file>.out <source_file>
```

## Développement

### Templates de code C

* Basique
* Affichage simple avec ncurses

### Structures de données

* [Liste](list/list.h)

## CTF

### PWN

Le désassembleur utilise la bibliothèque [Capstone](https://www.capstone-engine.org/).
Le générateur de payload utilise [Keystone](https://www.keystone-engine.org/).

* [Récupération addresse variable environnement](pwn/env_var.c)
* [\[WIP\] Désassembleur ELF](pwn/elf_parser/parser.c)
* [\[WIP\] Implémentation de l'algorithme de De Bruijn](pwn/de_bruijn.c)

### Steganographie

* [Extraction LSB](steg/lsb.c)
