# TinkerTools

Liste d'exécutables (principalement C) utiles en CTF ou pour du dev.

```bash
gcc -Wall -Wextra -pedantic -std=c99 -o <binary_file_name> <source_file_name>
```

## Développement

* [Liste](libs/list)

## CTF

### PWN

Le désassembleur utilise la bibliothèque [Capstone](https://www.capstone-engine.org/).

Le générateur de payload utilise [Keystone](https://www.keystone-engine.org/).

* [Récupération addresse variable environnement](pwn/env_var.c)
* [\[WIP\] Désassembleur ELF](pwn/parser.c)

### Steganographie

* [Extraction LSB](steg/lsb.c)
