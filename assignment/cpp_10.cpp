#include <iostream>
#include <string>

using namespace std;

void find2replace(string &fstr, string &fhas, string &fre, bool &fresult) {
    // find 함수로 찾아야 한다.
    // fing가 -1이 될떄까지 반복해서 찾아야 한다.
    // replace() 함수가 필요하다.
    // replace함수를 쓸려면 길이가 필요하다.
    // 길이를 찾는 length()함수가 필요함
    // 반복이 필요함
    while(1){
        int n = fstr.find(fhas);
        fstr.replace(n, fhas.length(), fre);

        if(fstr.find(fhas) == -1){
            fresult = true;
            break;
        }
    }
}

int main(){
    std::string str = "C++ programming";
    std::string has = "+";
    string replace = "p";
    bool result = false;

    cout << "변경 전 문자열 = " << str << endl;

    find2replace(str, has, replace, result);
    
    if (result == true)
        cout << "변경 후 문자열 = " << str << endl;
    else
        cout << str << "에서 " << has << "를 발견하지 못함." << endl;
    return 0;
}