# Q7 – Diagnose, Redesign and Validate

## A. Diagnosis
Q4's simple shifting strategy moves up to k-1 existing entries for every new transaction once the fixed history is full. For k=10 this is small, but if the required history grows to 50 or 5000, the per-insertion work grows linearly with capacity.

## B. Objective
Keep exactly the newest 10 entries while making insertion O(1), with fixed O(k) memory and identical retained values.

## C. Redesign
Original: on full history, shift elements left and write the new item at the end.  
Redesign: circular buffer with `next` index; overwrite `data[next]`, then advance modulo capacity. No dynamic memory is needed. The trade-off is that logical order wraps around and must be calculated when displaying entries.

## D. Prediction
Both versions produce the same checksum for the newest 10 values. Circular insertion should perform fewer writes and scale better as k increases.

## E. Validation
Both implementations receive the same 2,000,000 sequential values and print checksums and elapsed microseconds. Run repeatedly and compare results on the same machine. The two checksums must match. Record actual times from your run; do not treat one timing as universal.

## F. Evaluation
The objective is met if checksums match and circular insertion is faster or shows reduced scaling in repeated tests. The circular version adds index logic and may be less intuitive; shifting is perfectly reasonable for very small capacities or when ordered contiguous data is more important than insertion speed.

## Build and run
```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic main.cpp -o main
./main
```
