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
    RandInt(const RandInt & rnadom) = delete; // ���� �����ڸ� �������� ����
    void print() const; // ����, ���� ��� / �� ������ϰ� ��¸� �ϴϱ� const
};

#endif