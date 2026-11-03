#include <iostream>
#include <chrono>
using namespace std;

class Time {
    int h, m;
public:
    Time(int hh, int mm) : h(hh), m(mm) {}
    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
    // Equivalent member-function interface for comparison:
    int totalMinutes() const { return h * 60 + m; }
    int minutesTo(const Time& other) const;
    bool isEarlier(const Time& other) const;
};

inline int minutesBetween(const Time& a, const Time& b) {
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;
    return (first > second) ? first - second : second - first;
}
inline bool earlier(const Time& a, const Time& b) {
    return a.h * 60 + a.m < b.h * 60 + b.m;
}
int Time::minutesTo(const Time& other) const {
    int a = totalMinutes(), b = other.totalMinutes();
    return a > b ? a - b : b - a;
}
bool Time::isEarlier(const Time& other) const {
    return totalMinutes() < other.totalMinutes();
}

// Benchmark a tiny operation; volatile sink prevents dead-code elimination.
template <typename F>
long long benchmark(F fn, const Time& a, const Time& b) {
    volatile long long sink = 0;
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < 10000000; ++i) sink += fn(a, b);
    auto stop = chrono::steady_clock::now();
    return chrono::duration_cast<chrono::microseconds>(stop - start).count();
}
int main() {
    Time departure(9, 45), arrival(13, 10);
    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';
    Time sameA(12, 0), sameB(12, 0);
    Time beforeNoon(11, 59), afterNoon(12, 1);
    cout << "same: " << minutesBetween(sameA, sameB) << ' '
         << earlier(sameA, sameB) << '\n';
    cout << "across noon: " << minutesBetween(beforeNoon, afterNoon) << ' '
         << earlier(beforeNoon, afterNoon) << '\n';

    cout << "10M calls benchmark (microseconds): "
         << benchmark([](const Time& x, const Time& y) { return minutesBetween(x,y); },
                      departure, arrival) << '\n';
}
