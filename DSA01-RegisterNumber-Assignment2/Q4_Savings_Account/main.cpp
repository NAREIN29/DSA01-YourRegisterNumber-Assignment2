#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    long long balance;
    long long transactions[10];
    int count;
    int next; // next insertion position; oldest item when full

    void record(long long amount) { // defined inside class
        transactions[next] = amount;
        next = (next + 1) % 10;
        if (count < 10) ++count;
    }

public:
    SavingsAccount(const string& number, long long opening)
        : accountNumber(number), balance(opening), transactions{}, count(0), next(0) {}

    void deposit(long long amount); // defined outside
    bool withdraw(long long amount);
    void miniStatement() const;
    long long getBalance() const { return balance; }
};

void SavingsAccount::deposit(long long amount) {
    if (amount <= 0) return;
    balance += amount;
    record(amount);
}

bool SavingsAccount::withdraw(long long amount) {
    if (amount <= 0 || amount > balance) return false;
    balance -= amount;
    record(-amount);
    return true;
}

void SavingsAccount::miniStatement() const {
    cout << "Account: " << accountNumber << "\nBalance: " << balance
         << "\nRecent transactions (oldest to newest):\n";
    int start = (count == 10) ? next : 0;
    for (int i = 0; i < count; ++i)
        cout << transactions[(start + i) % 10] << '\n';
}

int main() {
    SavingsAccount account("SA1001", 10000);
    account.deposit(500);
    account.withdraw(200);
    account.deposit(1000);
    account.withdraw(300);
    account.deposit(250);
    account.withdraw(100);
    account.deposit(700);
    account.withdraw(50);
    account.deposit(125);
    account.withdraw(25);
    account.deposit(600); // 11th transaction: oldest is overwritten
    account.miniStatement();
}
