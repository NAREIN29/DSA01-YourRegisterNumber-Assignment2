# Q1 – Hostel Fee Concession
**Concepts:** call by value, reference, pointer, return by value, default arguments, return by reference.

## Prediction
For the supplied `change` program: `1 12 13`; then `13 100`; then `16 13 6`.  
`show(1)` uses defaults 5 and 10; `show(1,2)` uses default 10; `show(1,2,3)` uses no defaults.

## Key explanation
- Value parameter is a separate local copy; caller's variable is unchanged.
- Reference parameter is an alias to the caller's variable.
- Pointer parameter contains the caller's address; dereferencing changes the original.
- `const Student&` is suitable when a large object must be read without copying or modification.
- Return-by-value is often the clearest interface for calculating a result; use in-place reference/pointer mutation when the function's purpose is explicitly to update an existing fee. For multiple concessions, apply sequentially or calculate a combined rate carefully because integer rounding can differ.

## Complexity
Each arithmetic update is O(1) time. A `long long` value copy is constant-sized; a large `Student` passed by value copies all its members (and owned data as applicable), while reference/const-reference pass an alias (typically pointer-sized). Space for a local `long long` copy is O(1); copying a student is proportional to its stored data.

## Build and run
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```
