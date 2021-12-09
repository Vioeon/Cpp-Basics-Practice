#include<iostream>

using namespace std;

class Accumulator {
    int value;
public:
    Accumulator(int val) : value{val} { };
    Accumulator &add(int n);
    int get() { return value; }
};

Accumulator & Accumulator::add(int n){
    value += n;

    return *this; // Call by Reference �̱� ������ *�� �Ἥ ������ �����ؾ� �Ѵ�.
}

//add() �Լ��� �ۼ��մϴ�. //

int main() {
    Accumulator acc(10);
    cout << acc.get() << endl; //10 ���
    acc.add(1).add(2).add(3); //acc ��ü�� value�� 16�� ��. co
    cout << acc.get() << endl; //16 ���
}