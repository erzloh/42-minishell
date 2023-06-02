# Minishell

This project is a simple shell implementation that provides a basic command-line interface for executing commands on a Unix-like system. It was developed as part of the curriculum at School 42. This project was made in collaboration with my good friend Alessandro Palumbi, another student at 42.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)

## Introduction

Minishell is a command-line interpreter that allows you to execute commands and interact with your system. It provides a user-friendly interface similar to the default shell (`bash`, `zsh`, etc.), allowing you to run programs, navigate the file system, and perform various operations.

The project focuses on understanding and implementing core concepts such as process management, signal handling, input/output redirection, and basic command parsing. It provides a solid foundation for learning more about system programming and operating systems.

## Features

- Command execution: Run commands and programs on your system.
- Basic shell functionality: Navigate the file system, change directories, etc.
- Input/output redirection: Redirect input/output to/from files.
- Environment variables: Set and use environment variables.
- Signal handling: Handle signals such as `Ctrl+C` and `Ctrl+\`.

## Installation

To install and run Minishell, follow these steps:

1. Clone the repository to your local machine:

   ```shell
   git clone https://github.com/erzloh/42-minishell
	```
2. In the cloned folder, compile the source code:

	```shell
	make
	```

3. Run Minishell:

	```shell
	./minishell
	```

## Usage

Once you have Minishell up and running, you can start entering commands just like you would in any other shell. Here are a few examples:

```shell
echo "Hello, World!"
```
```shell
pwd
```
```shell
cd /path/to/directory
```
```shell
ls -l | wc -l > output.txt
```
```shell
cat file.txt
```

## Screenshots

<img width="550" alt="Screen Shot 2023-06-02 at 3 49 57 PM" src="https://github.com/erzloh/42-minishell/assets/48589114/a2fcaa9d-587f-4851-98cb-107cdec05d74">

<img width="550" alt="Screen Shot 2023-06-02 at 3 50 09 PM" src="https://github.com/erzloh/42-minishell/assets/48589114/d26ef1dd-17bb-4475-a41d-1578a57b1ad6">

<img width="550" alt="Screen Shot 2023-06-02 at 3 51 11 PM" src="https://github.com/erzloh/42-minishell/assets/48589114/7ac8bf0c-f3c2-4882-a8f2-091cc8af2cf9">
