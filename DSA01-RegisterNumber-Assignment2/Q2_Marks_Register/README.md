# Q2 – Return by Reference and Its Dangers

`highestMark` finds the largest array element in O(n) and returns an `int&`; therefore `highestMark(marks,n) += 2` assigns through the returned reference. Returning `const int&` permits reading but not modification. Returning `int` returns an independent copy.

`danglingReference()` intentionally returns a reference to a local variable to demonstrate the compiler diagnostic. It is deliberately not called: using the returned reference is undefined behaviour because the local object ceases to exist when the function returns. Compile with warnings to capture the diagnostic.

Alternatives: return an index (`marks[index]`) or pointer (`*p`). All search in O(n) time and O(1) auxiliary space. For a vector, an index can be used again after reallocation (provided the logical element remains); pointers and references may be invalidated by growth/reallocation. Reacquire them after modifying the vector.

## Build and run
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```
