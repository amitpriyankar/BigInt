#include "BigInt.cpp"

int main()
{

    // testing constructor of BigInt class
    BigInt a; // default constructor will be used 
    BigInt b(12345); // initialising using an integer
    BigInt c("-12345"); // initialising using a string
    return 0;
}