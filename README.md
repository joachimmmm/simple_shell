# Simple Shell

A custom shell project from Alx SE wrriten in C programming language.

## Table of Contents

- [Project Description](#project-description)
- [Usage](#usage)
- [License](#license)
- [Installation](#installation)
## Project Description

The Simple Shell Project allows users to enter commands and execute them within a terminal environment. It provides a shell prompt where users can type commands, and the shell will interpret and execute them accordingly. The project involves parsing user input, executing commands, handling various built-in shell commands, and managing the execution environment.

## Usage

To use the Simple Shell, users can launch the shell executable from the command line. They will be presented with a prompt where they can enter commands. The shell will interpret the commands and execute them accordingly. Users can take advantage of the shell's features, such as input/output redirection, pipelines, and background execution, by using the appropriate syntax.

```bash
$ ./simple_shell
Welcome to Simple Shell!
$ ls
file1.txt  file2.txt  directory
$ cd directory
$ pwd
/home/user/directory
$ cat file1.txt | grep "keyword"
This line contains the keyword.
$ ls > files.txt
$ exit
Goodbye!
$
```
## License
This project is licensed under the MIT License. You can find the full text of the license in the LICENSE file.


## Installation
To install and run the Simple Shell Project on your system, follow these steps:

Clone the project repository from GitHub: 
```git clone https://github.com/joachimmmm/simple_shell.git```
Navigate to the project directory: cd simple-shell
Compile the source code: 
```gcc -o simple_shell main.c shell.c ...```
(replace ... with additional source files if any)
Run the executable: ``./simple_shell``
Ensure that you have a C compiler installed on your system (such as GCC) to compile the source code.
