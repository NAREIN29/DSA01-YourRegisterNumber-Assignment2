# Q6 – Friend and Inline Functions

Friend functions `minutesBetween(a,b)` and `earlier(a,b)` are non-members but are granted access to private `h` and `m`. A symmetric operation on two Time objects can read naturally as a non-member. A member alternative would be `a.minutesTo(b)` and `a.isEarlier(b)`; public getters would preserve private storage but expose read access.

`inline` is a request/permission for inline substitution and also allows suitable definitions in headers; it does not guarantee substitution. Modern compilers decide based on optimisation. Keep private data private: making it public weakens invariants. Friend is justified when a symmetric operation needs direct access; otherwise member functions/getters may be clearer.

Correctness: 09:45 to 13:10 = 205 minutes; 13:10 is not earlier than 09:45. Same time gives 0 and false. 11:59 is 2 minutes before 12:01.

Run benchmark with:
```bash
g++ -std=c++17 -O0 main.cpp -o train_O0 && ./train_O0
g++ -std=c++17 -O2 main.cpp -o train_O2 && ./train_O2
```
Record the actual microsecond results on your machine in the report. Timing varies by CPU, compiler, background load and optimisation. Do not invent a benchmark result. The function is O(1) per call; the 10-million-call loop is O(n). The small Time references avoid object copies.
