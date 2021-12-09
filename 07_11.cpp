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
    int c = add(a, sizeof(a)/sizeof(int)); //배열 a의 정수를 size 인덱스까지 모두 더한 값 리턴
    int d = add(a, sizeof(a)/sizeof(int), b); //배열 a, b의 정수를 size 인덱스까지 모두 더한 값

    cout << c << endl; // 10 출력
    cout << d << endl; // 55 출력
}