#include <iostream>
#include <string>
#include <random>

#include "1021.h"

using namespace std;

RandInt::RandInt(int l, int h, string name):low(l), high(h), objname(name){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(low, high);
    randn = dis(gen);
}

RandInt::~RandInt(){
    cout << objname << "°´Ã¼ ¼Ò¸ê" << endl;
}

void RandInt::print() const{
    cout << "Random number between " << low << " and " << high << " : " << randn << endl;
}