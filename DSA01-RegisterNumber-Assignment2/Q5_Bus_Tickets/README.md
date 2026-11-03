# Q5 – Static Members and Arrays of Objects

`issued` and `CAPACITY` are class-wide static members. The definition `int BusTicket::issued = 0;` appears outside the class. The static `count()` function has no `this` pointer and can access static data, but cannot directly access an individual ticket's non-static `seat` or `name`.

The `trip` array constructs four objects. Each constructor runs once; only the first three get seats. Static count persists after a function returns and increments on every later construction until capacity is reached. A separate counter per bus (e.g. TicketOffice object passed to tickets) is preferable if two buses must operate independently. A single static counter is simple for one shared bus but makes multiple independent buses awkward. A global counter has weaker encapsulation.

Complexity: construction/check O(1), one shared counter O(1) storage. A separate office object also uses one counter per office and supports multiple buses.

## Build and run
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```
