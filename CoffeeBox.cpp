class CoffeBox{
private:
    double balance;
    int cup;

public:
    CoffeBox(int balance, int cup) : balance(balance), cup(cup) {
        this->balance = balance;
        this->cup = cup;
    }

public:
    int getBalance(){
        return balance;
    }
    int depositCoin(int coin){
        balance += coin;
        return balance;
    }
};