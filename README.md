# 0x15. C - Simple Shell

## Description

In this project we are tasked with creating our own simple UNIX command interpreter. The program must have the exact same output as sh (/bin/sh) as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your argv[0].

---

## Project Requirements
- All your files will be compiled on Ubuntu 14.04 LTS
- Your C programs and functions will be compiled with gcc 4.8.4 using the flags `-Wall -Werror -Wextra and -pedantic`
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to

---

### TASKS

- [x] uses the PATH
- [x] implements builtins
- [x] handles command line arguments
- [ ] custom strtok function
- [x] uses exit status
- [x] shell continues upon Crtl+C (**^C**)
- [ ] handles comments (#)
- [ ] handles **;**
- [ ] custom getline type function
- [ ] handles **&&** and **||**
- [ ] aliases
- [ ] variable replacement


### Builtins

- [x] exit
- [x] env
- [ ] setenv
- [ ] unsetenv
- [x] cd
- [x] help
- [ ] history


## Instructions

* Compiling the program:
`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

* Interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

* Non-interactie mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
---

## Example
Run the executable in your terminal after compiling:
```
$ ./hsh
$ ls -al
total 100
drwxrwxr-x  3 vagrant vagrant  4096 Jul 19 22:49 .
drwxr-xr-x 14 vagrant vagrant  4096 Jul 17 22:37 ..
-rw-rw-r--  1 vagrant vagrant   144 Jul 19 17:16 AUTHORS
-rw-rw-r--  1 vagrant vagrant  2367 Jul 19 22:33 builtins2.c
-rw-rw-r--  1 vagrant vagrant  2764 Jul 19 22:14 builtins.c
-rw-rw-r--  1 vagrant vagrant   710 Jul 16 01:03 environment.c
-rw-rw-r--  1 vagrant vagrant  1217 Jul 16 03:24 errors.c
drwxrwxr-x  8 vagrant vagrant  4096 Jul 19 22:34 .git
-rwxrwxr-x  1 vagrant vagrant 32287 Jul 19 22:34 hsh
-rw-rw-r--  1 vagrant vagrant  1792 Jul 19 22:12 man_1_simple_shell
-rw-rw-r--  1 vagrant vagrant   484 Jul 15 20:09 memory_allocation.c
-rw-rw-r--  1 vagrant vagrant  1273 Jul 18 21:00 new_strtok.c
-rw-rw-r--  1 vagrant vagrant  3427 Jul 19 22:06 path.c
-rw-rw-r--  1 vagrant vagrant  2347 Jul 19 22:49 README.md
-rw-rw-r--  1 vagrant vagrant  1769 Jul 19 22:04 shell.h
-rw-rw-r--  1 vagrant vagrant  1480 Jul 18 21:15 simple_shell.c
-rw-rw-r--  1 vagrant vagrant  2111 Jul 16 01:10 strfunc.c
-rw-rw-r--  1 vagrant vagrant   719 Jul 19 21:46 tokenize.c
```
## Files

File|Description
---|---
[main.c](./main.c)|entry point for shell
[simple_shell.c](./simple_shell.c)|executes the shell
[simple_shell.h](./simple_shell.h)|header
[built_in.c](./built_in.c)|built-in functions
[ext_functions.c](./ext_functions.c)|helper functions
[support.c](./support.c)|more helper functions
[environment.c](./environment.c)|gets inputted env
[cwd.c](./cwd.c)|gets current working dir
[path.c](./path.c)|finds PATH
[builtin_caller.c](./builtin_caller.c)|checks if builtin or not
[execute_program.c](./execute_program.c)|executes builtin or binary
[man_1_simple_shell](./man_1_simple_shell)|man page

## Bugs
At that time we do not know bugs.

## Authors
Carlos Araque  |[GitHub](https://github.com/carlosaraque22)
Esteban Aguiar |[GitHub](https://github.com/AmericoVespucio)