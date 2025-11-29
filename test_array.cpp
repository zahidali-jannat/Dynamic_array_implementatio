#include "dynamic_array.cpp"
#include <iostream>

using namespace std;
int main () {
    Array<int> arr;
    for (int i=0; i<20; i++)
    {
         arr.push(i);
    }
       

    arr.print();
    arr.push(123);
    arr.print();
    int a= arr.pop();
    cout << a << endl;
    return 0;
}