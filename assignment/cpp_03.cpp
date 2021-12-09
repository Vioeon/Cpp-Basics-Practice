#include <iostream>
#include <cstdlib> // abs사용 절대값
#include <initializer_list>

using namespace std;

void lista(initializer_list<char> value, char k){
    int i;
    int j = 10;
    char c;
    for(auto data : value){
        i = (int)data - (int)k;
        if(abs(i) < j){
            j = abs(i);
            c = data;
        }
    }
    cout << c << endl;
}

int main() {

    cout << "{ 'd', 'p', 'r', 'w', 'g', 'f' }문자 중 h와 가까운 문자는 : " ;
    lista({ 'd', 'p', 'r', 'w', 'g', 'f' }, 'h');


    cout << "{ 'k', 'q', 'b', 'r', 'a', 'e', 'v', 'z'}문자 중 w와 가까운 문자는 : ";
    lista({ 'k', 'q', 'b', 'r', 'a', 'e', 'v', 'z'}, 'w');

}
