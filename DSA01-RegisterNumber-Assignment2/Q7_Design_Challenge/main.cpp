#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class ShiftHistory {
    static const int K = 10;
    long long data[K]{};
    int count = 0;
public:
    void add(long long value) {
        if (count < K) data[count++] = value;
        else {
            for (int i = 1; i < K; ++i) data[i - 1] = data[i];
            data[K - 1] = value;
        }
    }
    long long checksum() const {
        long long s = 0;
        for (int i = 0; i < count; ++i) s += data[i];
        return s;
    }
};

class CircularHistory {
    static const int K = 10;
    long long data[K]{};
    int count = 0;
    int next = 0;
public:
    void add(long long value) {
        data[next] = value;
        next = (next + 1) % K;
        if (count < K) ++count;
    }
    long long checksum() const {
        long long s = 0;
        int start = count == K ? next : 0;
        for (int i = 0; i < count; ++i) s += data[(start + i) % K];
        return s;
    }
};

template<class History>
long long runTest(int n) {
    History h;
    for (int i = 1; i <= n; ++i) h.add(i);
    return h.checksum();
}
template<class History>
long long timeTest(int n) {
    auto start = chrono::steady_clock::now();
    volatile long long result = runTest<History>(n);
    (void)result;
    auto stop = chrono::steady_clock::now();
    return chrono::duration_cast<chrono::microseconds>(stop-start).count();
}
int main() {
    const int n = 2000000;
    cout << "Transactions inserted: " << n << '\n';
    cout << "Shift checksum: " << runTest<ShiftHistory>(n) << '\n';
    cout << "Circular checksum: " << runTest<CircularHistory>(n) << '\n';
    cout << "Shift time (us): " << timeTest<ShiftHistory>(n) << '\n';
    cout << "Circular time (us): " << timeTest<CircularHistory>(n) << '\n';
}
