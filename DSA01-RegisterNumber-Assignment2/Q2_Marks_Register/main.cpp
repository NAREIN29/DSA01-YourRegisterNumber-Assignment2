#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int& highestMark(int marks[], int n) {
    if (n <= 0) throw invalid_argument("marks array must not be empty");
    int index = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[index]) index = i;
    return marks[index];
}

int highestMarkIndex(const int marks[], int n) {
    if (n <= 0) throw invalid_argument("marks array must not be empty");
    int index = 0;
    for (int i = 1; i < n; ++i)
        if (marks[i] > marks[index]) index = i;
    return index;
}

int* highestMarkPointer(int marks[], int n) {
    return &highestMark(marks, n);
}

// Deliberately unsafe demonstration. Do NOT call/use the returned reference.
int& danglingReference() {
    int local = 99;
    return local; // compiler warning; returned reference dangles
}

int main() {
    int marks[] = {78, 91, 84, 88, 91};
    const int n = sizeof(marks) / sizeof(marks[0]);
    cout << "Highest before moderation: " << highestMark(marks, n) << '\n';
    highestMark(marks, n) += 2;
    cout << "Highest after moderation: " << highestMark(marks, n) << '\n';

    int index = highestMarkIndex(marks, n);
    cout << "Index approach: marks[" << index << "] = " << marks[index] << '\n';
    int* p = highestMarkPointer(marks, n);
    cout << "Pointer approach: " << *p << '\n';

    vector<int> growing = {70, 82, 95};
    int& beforeGrowth = growing[2];
    cout << "Vector reference before growth: " << beforeGrowth << '\n';
    // push_back may reallocate and invalidate beforeGrowth; do not use it afterward.
    growing.push_back(99);
    cout << "Vector after growth, safe indexed access: " << growing[2] << '\n';
    cout << "Do not dereference the old reference after possible reallocation.\n";
}
