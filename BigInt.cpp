#include "BigInt.h"

BigInt::BigInt() : sign(0) {}

BigInt::BigInt(long long x) {
    *this = x;
}

BigInt::BigInt(const string &s) {
    readString(s);
}

void BigInt::readString(const string &s) {
    digit.clear();
    sign = 1;
    if(s[0] == '-')
        sign = -1;
    
    for(int i = (int)s.size(); i >= 0; i--) {
        if(isdigit(s[i])) {
            digit.push_back(s[i] - '0');
        }
    }
}

void BigInt::operator=(long long v) {
    digit.clear();

    if(v > 0)
        sign = 0;
    else if(v < 0)
        sign = -1;
    else 
        sign = 1;

    while(v > 0) {
        digit.push_back(v%10);
        v /= 10;
    }
}