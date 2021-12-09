#ifndef RANDINT_H
#define RANDINT_H

#include <iostream>
#include <string>

using namespace std;

class RandInt{
    string objname;
    int low, high, randn;
public:
    RandInt(int l, int h, string name);
    ~RandInt();
    RandInt(const RandInt & rnadom) = delete; // 복사 생성자를 생성하지 않음
    void print() const; // 범위, 난수 출력 / 값 변경안하고 출력만 하니까 const
};

#endif