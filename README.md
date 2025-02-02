
# Push Swap

## 📌 Introduction

Push Swap is a project that challenges you to sort a stack of integers using a limited set of operations. The objective is to develop an efficient sorting algorithm while minimizing the number of moves.

## 🚀 Features

-   Developed in **C**

-   Stack-based sorting mechanism

-   **Optimized sorting algorithm** for different input sizes

-   **Bonus:** Interactive mode with a checker to validate results


## ⚙️ Compilation

Compile the project using the provided **Makefile**:

```
make
```

This will generate the `push_swap` executable for sorting numbers.

For the checker (bonus feature):

```
make bonus
```

This will generate the `checker` executable to verify sorting correctness.

## 📌 Usage

### ✅ Mandatory Part

Execute the program as follows:

```
./push_swap <list_of_numbers>
```
You can validate the sorting sequence using:

```
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

You can validate the sorting sequence using checker from the 42 School
```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
```
Example:

```
./push_swap 3 2 5 1 4
```

This outputs the sequence of operations required to sort the numbers.

### 🎯 Bonus Part (Checker)

You can validate the sorting sequence using:

```
./push_swap <list_of_numbers> | ./checker <list_of_numbers>
```

Example:

```
./push_swap 3 2 1 | ./checker 3 2 1
```

The checker will return:

-   **OK** → The sequence correctly sorts the numbers.

-   **KO** → The sequence does not sort the numbers correctly.


## 🔄 Operations

The following stack operations are implemented:

-   **Swap**:

    -   `sa` (swap top two elements of stack A)

    -   `sb` (swap top two elements of stack B)

    -   `ss` (swap top two elements of both stacks)

-   **Push**:

    -   `pa` (push top element from stack B to A)

    -   `pb` (push top element from stack A to B)

-   **Rotate**:

    -   `ra` (rotate stack A upwards)

    -   `rb` (rotate stack B upwards)

    -   `rr` (rotate both stacks upwards)

-   **Reverse Rotate**:

    -   `rra` (rotate stack A downwards)

    -   `rrb` (rotate stack B downwards)

    -   `rrr` (rotate both stacks downwards)


## 📊 Algorithm

The program selects an appropriate sorting strategy based on input size:

-   **Small inputs (≤ 3 numbers):** Hardcoded optimal moves.

-   **Medium inputs (≤ 5 numbers):** Sorting with minimal `push` operations.

-   **Larger inputs:** QuickSort-like partitioning combined with stack operations for efficiency.


## ⚠️ Error Handling

-   Detects **duplicates**, **non-numeric inputs**, and **out-of-range values**.

-   Displays clear error messages on `stderr`.


## 🧪 Testing

To test the program, use:

```
ARG="4 67 3 87"; ./push_swap $ARG | ./checker $ARG
```

Additionally, automated test scripts can help evaluate performance.
