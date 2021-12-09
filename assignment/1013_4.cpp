#include <iostream>
using namespace std;
void fun (int* x){
cout << *(x + 2);
}
int main (){
int sample [5] = {5, 10, 15, 20, 25};
cout << *sample + 2 << endl;
cout << *(sample + 2); 
return 0;
}
