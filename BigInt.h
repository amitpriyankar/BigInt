#include <vector>
#include <string>
#include <iostream>

using namespace std;
class BigInt {
    private:
        // digit at 0th index is LSB i.e. least significant digit
        vector<int> digit;

        /*
            sign denotes of sign of the integer,
            -1 for negative, 1 for positive and 0 for zero.
        */
        int sign;

        //  size denotes the no. of digits in decimal representation of the number.
        int size;


        // karatsuba multiplication algorithm
        void karatsubaMultiply(int* a, int n, int* b, int m, int* res);
       

    public:
        
        //  Default constructor, incase no arguement is provided.
        BigInt();

        //  Constructor, when an integer(in-built type) is provided as an arguement.
        BigInt(long long x);

        //  Constructor, when an integer(in-built type) is provided as an arguement.
        BigInt(const string &s);

        // Declaring operator overloading for '='
        void operator=(long long v);

        // A fuction to read a string and convert it to vector<int>
        void readString(const string &s);

        // Declaring comparison operator
        bool operator>(const BigInt &b) const;

        // Declaring comparison operator
        bool operator<(const BigInt &b) const;

       
        // Function to calculate abs()
        BigInt abs() const;

        // overloading unary minus operator
        BigInt operator-() const;

        // Declaring operator overloading for '+'
        BigInt operator+(const BigInt &b) const;

        // Declaring operator overloading for '-'
        BigInt operator-(const BigInt &b) const;

        // To remove leading zeroes from the intger
        void trim();

        // Overload '<<' operator
        friend ostream& operator<<(ostream &output, BigInt const &b);

        // Overload '>>' operator
        friend istream& operator>>(istream &input, BigInt &b);

        // print
        vector<int> print();

        // Overload  '*' operator
        BigInt operator *(BigInt&b);

        // Overload '==' operator
        bool operator ==(const BigInt& b) const;

};