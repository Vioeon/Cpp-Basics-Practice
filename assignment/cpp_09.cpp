#include <iostream>
#include <string>
using namespace std;;

string removeChar(string str, char c){
    while(1){
        int n = str.find(c);
        str.erase(n, 1);
        
        if(str.find(c) == -1){
            break;
        }
    }
    return str;
}
string findAndReplace(string str, string olds, string news){
    int n = str.find(olds);
    str.replace(n, olds.length(), news);
    
    return str;
}

int main(){
    string str;
    char c;

    cout << "���ڿ� �Է�: ";
    getline(cin, str);
    cout << "�����ϰ��� �ϴ� ���� �Է�: ";
    cin >> c;
    cout << "���� �� ���ڿ� = " << removeChar(str, c) << endl
    << endl;

    string str1 = "an old string";
    string str2("an old");
    string str3("a new");

    cout << str1 << "���� ";
    string strnew = findAndReplace(str1, str2, str3);
    cout << str2 << "���ڿ��� " << str3 << " �� ��ü �� ���ڿ� = " << strnew << endl;
    return 0;
}