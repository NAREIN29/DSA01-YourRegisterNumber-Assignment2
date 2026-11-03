#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Parcel {
    double weightKg;
    bool express;
    bool insured;
};

// Integer grams overload; no defaults.
double charge(int weightGrams) {
    cout << "[grams overload] ";
    return 30.0 + (weightGrams / 1000.0) * 12.0;
}

// Kilograms overload; optional service flags default from the right.
double charge(double weightKg, bool express = false, bool insured = false) {
    cout << "[kg overload] ";
    double total = 30.0 + weightKg * 12.0;
    if (express) total += 20.0;
    if (insured) total += 10.0;
    return total;
}

// Parcel overload.
double charge(const Parcel& p) {
    cout << "[Parcel overload] ";
    return charge(p.weightKg, p.express, p.insured);
}

int main() {
    cout << fixed << setprecision(2);
    cout << "charge(2) = " << charge(2) << '\n';
    cout << "charge(2.0) = " << charge(2.0) << '\n';
    cout << "charge(2.0f) = " << charge(2.0f) << '\n';
    cout << "charge(2.0, true) = " << charge(2.0, true) << '\n';
    cout << "charge(2.0, true, true) = " << charge(2.0, true, true) << '\n';
    Parcel p{2.0, false, true};
    cout << "charge(parcel) = " << charge(p) << '\n';
}
