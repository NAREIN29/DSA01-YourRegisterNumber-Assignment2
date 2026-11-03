#include <iostream>
using namespace std;

// Pass by value: only the local copy changes.
void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
}

// Pass by reference: caller's fee changes.
void applyByReference(long long& fee, int percent) {
    fee -= fee * percent / 100;
}

// Pass by pointer: caller's fee changes through the address.
void applyByPointer(long long* fee, int percent) {
    if (fee != nullptr) *fee -= *fee * percent / 100;
}

// Return-by-value alternative.
long long concessionResult(long long fee, int percent) {
    return fee - fee * percent / 100;
}

void change(int a, int& b, int* c) {
    a += 10; b += 10; *c += 10;
}
int& bigger(int& p, int& q) { return p > q ? p : q; }
void show(int x, int y = 5, int z = 10) {
    cout << x + y + z << ' ';
}

int main() {
    cout << "=== Concession methods ===\n";
    long long byValue = 45000, byReference = 45000, byPointer = 45000;
    applyByValue(byValue, 10);
    applyByReference(byReference, 10);
    applyByPointer(&byPointer, 10);
    cout << "By value: " << byValue << '\n';
    cout << "By reference: " << byReference << '\n';
    cout << "By pointer: " << byPointer << '\n';
    cout << "Return by value: " << concessionResult(45000, 10) << '\n';

    cout << "=== Given output-prediction program ===\n";
    int a = 1, b = 2, c = 3;
    change(a, b, &c);
    cout << a << ' ' << b << ' ' << c << '\n';
    bigger(a, c) = 100;
    cout << a << ' ' << c << '\n';
    show(1); show(1, 2); show(1, 2, 3);
    cout << '\n';

    cout << "=== Complete the Code ===\n";
    long long hostelFee = 45000;
    applyByValue(hostelFee, 10);
    cout << "after call by value : " << hostelFee << '\n';
    applyByReference(hostelFee, 10);
    cout << "after call by reference: " << hostelFee << '\n';
}
