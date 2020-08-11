#include "BigInt.cpp"
#include <iostream>
int main()
{

    // testing constructor of BigInt class
    BigInt a; // default constructor will be used 
    BigInt b = 12345; // initialising using an integer
    BigInt c("-12345"); // initialising using a string
    BigInt d("0000");

    cout << a << " " << b << " " << c << " " << d << endl;

    return 0;
}