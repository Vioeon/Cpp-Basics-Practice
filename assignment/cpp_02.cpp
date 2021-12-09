#include <iostream>
#include <string>

using namespace std;

int main(){
    string arr[6] = {"8", "oct", "16", "hex", "10", "digit"};
    int i;
    string j;

    cout << "10진수를 입력 : ";
    cin >> i;

    cout << "\n여러 진법으로 출력 하기" << endl;
    cout << "oct(8), hex(16), digit(10)" << endl;
    cout << "해당 진법 입력 : ";
    cin >> j;

    for(int k = 0; k < 6; k++){
        if(j == arr[k]){
            if(k == 0 || k == 1){
             cout << "=> 8진법 : " << oct << i << endl;
            }
            else if(k == 2 || k == 3){
             cout << "=> 16진법 : " << hex << i << endl;
            }
            else if(k == 4 || k == 5){
             cout << "=> 10진법 : " << i << endl;
            }
        }
    }
    return 0;
}
