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
total 88
drwxrwxr-x 3 vagrant vagrant  4096 Nov 25 23:31 .
drwxr-xr-x 9 vagrant vagrant  4096 Nov 25 23:31 ..
drwxrwxr-x 8 vagrant vagrant  4096 Nov 25 23:31 .git
-rw-rw-r-- 1 vagrant vagrant   125 Nov 25 23:31 AUTHORS
-rw-rw-r-- 1 vagrant vagrant  3818 Nov 25 23:31 README.md
-rw-rw-r-- 1 vagrant vagrant  1297 Nov 25 23:31 built_in.c
-rw-rw-r-- 1 vagrant vagrant   482 Nov 25 23:31 builtin_caller.c
-rw-rw-r-- 1 vagrant vagrant  1152 Nov 25 23:31 cwd.c
-rw-rw-r-- 1 vagrant vagrant   557 Nov 25 23:31 environment.c
-rw-rw-r-- 1 vagrant vagrant   473 Nov 25 23:31 execute_program.c
-rw-rw-r-- 1 vagrant vagrant  2463 Nov 25 23:31 ext_functions.c
-rwxrwxr-x 1 vagrant vagrant 18805 Nov 25 23:31 hsh
-rw-rw-r-- 1 vagrant vagrant   379 Nov 25 23:31 main.c
-rw-rw-r-- 1 vagrant vagrant  1610 Nov 25 23:31 man_1_simple_shell
-rw-rw-r-- 1 vagrant vagrant  2241 Nov 25 23:31 path.c
-rw-rw-r-- 1 vagrant vagrant   921 Nov 25 23:31 simple_shell.c
-rw-rw-r-- 1 vagrant vagrant  1497 Nov 25 23:31 simple_shell.h
-rw-rw-r-- 1 vagrant vagrant  1136 Nov 25 23:31 support.c
```
## Flowchart
https://www.zenflowchart.com/docs/view/58DKgl9av2zPraG1vzAp

## Bugs
At that time we do not know bugs.

## Authors
Carlos Araque  | [GitHub](https://github.com/carlosaraque22)
Esteban Aguiar | [GitHub](https://github.com/AmericoVespucio)
