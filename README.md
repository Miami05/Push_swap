# Push_swap
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

# Push Swap

## Description

**Push Swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using a limited set of operations, while keeping the number of operations as low as possible. The project consists of two parts:
- **Mandatory part**: Create a program that sorts integers using a limited set of operations.
- **Bonus part**: Implement additional features such as a checker program and visualizer.

The project helps to improve skills in algorithm development, optimization, and manipulation of linked lists.

## Table of Contents
1. [Features](#features)
2. [Operations](#operations)
3. [Usage](#usage)
   - [Compiling](#compiling)
   - [Running the program](#running-the-program)
   - [Bonus](#bonus)
4. [Visualizer](#visualizer)
5. [Project Structure](#project-structure)
6. [Examples](#examples)
7. [Resources](#resources)

## Features

- Sorts a list of integers using two stacks: **stack_a** and **stack_b**.
- Limited set of operations (see below).
- Optimized solution with as few operations as possible.
- **Bonus**: Includes a checker program to verify the correctness of the solution and a visualizer to display the sorting steps in real time.

## Operations

You can perform the following operations on the stacks:

| Operation | Description |
| --------- | ----------- |
| `sa`      | Swap the first two elements of **stack_a** |
| `sb`      | Swap the first two elements of **stack_b** |
| `ss`      | Swap the first two elements of both **stack_a** and **stack_b** |
| `pa`      | Push the first element from **stack_b** to **stack_a** |
| `pb`      | Push the first element from **stack_a** to **stack_b** |
| `ra`      | Rotate **stack_a** (shift all elements up by one) |
| `rb`      | Rotate **stack_b** (shift all elements up by one) |
| `rr`      | Rotate both **stack_a** and **stack_b** |
| `rra`     | Reverse rotate **stack_a** (shift all elements down by one) |
| `rrb`     | Reverse rotate **stack_b** (shift all elements down by one) |
| `rrr`     | Reverse rotate both **stack_a** and **stack_b** |

## Usage

### Compiling

To compile the mandatory part of the project, run:

```bash
make
```
This will create the `push_swap` executable.

For the **bonus part**, which includes the checker program and other bonus features, compile with:
```bash
make bonus
```
This will generate the `checker` executable in addition to `push_swap`.

### Running the Program

To sort a list of numbers using **push_swap**, run:

```bash
./push_swap [numbers]
```
Example:

```bash
./push_swap 2 5 3 1 4
```
This will output the sequence of operations to sort the given numbers.

### Bonus

To check if a sequence of operations correctly sorts the list, use the **checker** program. This can be used with the `push_swap` output:

```bash
./push_swap [numbers] | ./checker [numbers]
```
If the numbers are sorted, `checker` will print `OK`. Otherwise, it will print `KO`.

You can also manually input operations

```bash
./checker [numbers]
```
Then type operations such as `sa`, `pb`, etc., followed by `Ctrl+D`.

## Visualizer

The **visualizer** is a bonus feature that provides a visual representation of the sorting process. To activate the visualizer, run **checker** with the `-v` option:

```bash
./checker -v [numbers]
```
The visualizer will print the current state of **stack_a** and **stack_b** after each operation, allowing you to follow the sorting step by step.

## Project Structure

```bash
/push_swap
    ├── bonus/               # Bonus source files
    ├── includes/            # Header files
    ├── libft/               # Library files for additional functions
    ├── src/                 # Source files for the push_swap program
    └── Makefile             # Makefile for compilation

```

## Examples

Sorting a small list:

```bash
./push_swap 3 2 1
```
Output (operations):

```bash
sa
ra
```
Checking the result:

```bash
./push_swap 3 2 1 | ./checker 3 2 1
OK
```
Using the visualizer:
```bash
./checker -v 4 1 3 2
Stack A         Stack B
4
1
3
2
-------------
sa
Stack A         Stack B
1
4
3
2
-------------
...
```

## Examples

To see how the program works with visual `-v`, you can run:
```bash
./push_swap 5 3 2 4 1 | ./checker -v 5 3 2 4 1
```

## Resources
-	[Medium:Push Swap](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
-   [Wikipedia: Sorting Algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm)
-   [Big O Notation](https://en.wikipedia.org/wiki/Big_O_notation)