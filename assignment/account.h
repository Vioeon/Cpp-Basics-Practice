#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using std::string;

namespace Bank{
    enum class MENU{ DEPOSIT = 1, WITHDRAW, CHECK };

    class Account{
        private:
            string name;
            int balance;

        public:
            Account(string n, int bal);
            ~Account();
            void deposit(const int money);
            int withdraw(int money);
            int check() const;
            string getOwner() const;
    };
}

#endif