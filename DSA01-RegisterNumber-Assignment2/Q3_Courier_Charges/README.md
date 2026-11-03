# Q3 – Default Arguments and Function Overloading

The original declarations `charge(double)`, `charge(double,bool)` and `charge(double,bool=false,bool=false)` make calls such as `charge(2)` ambiguous because more than one candidate can be called with one argument. The redesigned set has distinct parameter types: `int` grams, `double` kilograms with defaults, and `const Parcel&`.

## Six-call prediction
- `charge(2)`: exact match to `int` overload.
- `charge(2.0)`: exact match to `double` overload.
- `charge(2.0f)`: float-to-double promotion, selecting kg overload.
- `charge(2.0,true)`: kg overload.
- `charge(2.0,true,true)`: kg overload.
- `charge(parcel)`: Parcel overload.

Overload ranking prefers exact match, then promotion, then standard conversion. Defaults fill omitted trailing parameters; they do not create a different overload. Defaults must be supplied from the right because an omitted argument can only be filled when all later parameters also have defaults.

A `Parcel` parameter can grow naturally by adding fields/options, while many overloads can become hard to maintain. A template is useful for type-generic operations but is unnecessary here. Overload resolution happens at compile time and adds no run-time dispatch cost. Passing a large Parcel by value copies it; `const Parcel&` avoids that copy.

## Build and run
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```
