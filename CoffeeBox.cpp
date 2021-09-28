class CoffeeBox {
private:
    double balance;
    int cup;

public:
    CoffeeBox(int balance, int cup) : balance(balance), cup(cup) {
        this->balance = balance;
        this->cup = cup;
    }

public:
    int getBalance() {
        return balance;
    }

    int depositCoin(int coin) {
        balance += coin;
        return balance;
    }
};