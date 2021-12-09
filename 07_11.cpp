#include<iostream>

using namespace std;

int add(int arr[], int count, int barr[]=nullptr){
    int sum=0;
    for(int i=0; i < count; i++){
        sum += arr[i];
        if(barr != nullptr){
            sum+= barr[i];
        }
    }
    return sum;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};
    int c = add(a, sizeof(a)/sizeof(int)); //�迭 a�� ������ size �ε������� ��� ���� �� ����
    int d = add(a, sizeof(a)/sizeof(int), b); //�迭 a, b�� ������ size �ε������� ��� ���� ��

    cout << c << endl; // 10 ���
    cout << d << endl; // 55 ���
}