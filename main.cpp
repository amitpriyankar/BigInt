#include "BigInt.cpp"
#include <iostream>
#include <assert.h>

void testMultiplication()
{
    cout << "Testing Multiplication...\n";
    srand(time(0));
    for(int i = 0; i < 10; i++)
    {
        cout << "Test " << i+1 << "....";
        long long a = rand() % 1000000000 - 500000000;
        long long b = rand() % 1000000000 - 500000000;
        BigInt aa = a;
        BigInt bb = b;
        BigInt resBuiltin = (a * b);
        BigInt resBigInt = (aa * bb);
        assert(resBigInt == resBuiltin);
        cout << "Success..!!\n";
    }
}
int main()
{

    testMultiplication();

    return 0;
}