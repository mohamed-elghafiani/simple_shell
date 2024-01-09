# ALX Simple Shell Project

As an ALX student, I had the opportunity to work on the challenging Simple Shell project, which stands out as one of the most anticipated and demanding assignments in the curriculum. This project served as a comprehensive test of my knowledge in several crucial areas:

- Basics of programming
- Basics of C
- Basics of thinking like an engineer
- Group work
- Learning how to learn

## Learning Objectives

Upon completion of this project, I gained a deep understanding of various key concepts, including:

- The original Unix operating system and its designers
- The first version of the UNIX shell and its author
- The inventor of the B programming language (predecessor to C)
- Ken Thompson and his contributions
- The inner workings of a shell
- Process identifiers (pid and ppid)
- Manipulating the environment of the current process
- Differentiating between functions and system calls
- Process creation and termination
- Prototypes of the main function
- Using the PATH to locate programs
- Executing programs with the execve system call
- Suspending process execution until a child terminates
- Understanding EOF (end-of-file)

## Requirements

To successfully complete the project, the following requirements were in place:

- Use specific editors: vi, vim, emacs
- Compile on Ubuntu 20.04 LTS using gcc with prescribed options
- Adhere to the Betty style for code formatting
- Eliminate memory leaks in the shell
- Limit each file to no more than 5 functions
- Include header files with proper include guards
- Utilize system calls only when necessary
- Develop a README.md file at the project root
- Create an AUTHORS file listing all contributors
- Ensure the shell produces identical output and error output as `/bin/sh`

# Output and Testing

To ensure consistency with the standard shell (/bin/sh), the program must produce the exact same output and error output unless explicitly stated otherwise. The only divergence is when an error is printed; in such cases, the name of the program should be equivalent to your `argv[0]`.

## Example Error Output Comparison:

### Error with /bin/sh:

```bash
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

### Similar Error with Your Program (hsh):

```bash
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

## List of Allowed Functions and System Calls:

- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

## Compilation

Compile your the using the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Testing

The shell should exhibit the following behaviors:

### Interactive Mode:

```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

### Non-Interactive Mode:

```bash
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

Testing the shell involved both interactive and non-interactive modes. The compilation command was standardized as follows:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

This ensured the shell operated effectively, producing the expected output and error output comparable to `/bin/sh`.

Working on this project provided an invaluable learning experience, pushing me to apply and integrate my knowledge across various domains. The strict guidelines and testing conditions fostered a deep understanding of the material, contributing significantly to my growth as a developer during my time at ALX.
