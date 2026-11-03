# Q4 – Savings Account Mini-Statement

The class keeps account number, balance, transaction array, count and circular insertion index private. Private data protects invariants: callers cannot directly corrupt balance or transaction count. Public methods provide controlled operations.

The circular buffer retains the newest 10 transactions. On the 11th transaction it overwrites the oldest entry and advances `next`. It adds each transaction in O(1), with O(10) fixed storage. Shifting a full array costs O(k) per new transaction (here k=10), though it is simple. A `std::deque` can `push_back` and `pop_front` in O(1) amortized at the ends, but has dynamic allocation/overhead. For 50 entries only the array capacity and modulo change; circular-buffer logic remains the same. Choose circular buffer for predictable fixed memory and O(1) insertion.

## Build and run
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```
