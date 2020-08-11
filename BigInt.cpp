#include "BigInt.h"

BigInt::BigInt() : sign(0) {}

BigInt::BigInt(long long x) {
    *this = x;
}

BigInt::BigInt(const string &s) {
    readString(s);
}

void BigInt::trim() {
    while(!digit.empty() && digit.back() == 0)
        digit.pop_back();
   
    if(digit.empty())
        sign = 0;
}
void BigInt::readString(const string &s) {
    digit.clear();
    sign = 1;
    if(s[0] == '-')
        sign = -1;

    for(int i = (int)s.size()-1; i >= 0; i--) {
        if(isdigit(s[i])) {
            digit.push_back(s[i] - '0');
        }
    }


    trim();
}

void BigInt::operator=(long long v) {
    digit.clear();

    if(v > 0)
        sign = 1;
    else if(v < 0)
        sign = -1;
    else 
        sign = 0;

    while(v > 0) {
        digit.push_back(v%10);
        v /= 10;
    }
}

BigInt BigInt::operator-() const {
    BigInt res;
    res.digit = digit;
    res.sign *= -1;
    return res;
}

BigInt BigInt::operator+(const BigInt &b) const {

   if(sign == b.sign)
   {
       // We can perform add operation
        BigInt res;
        res = b;
        for(int i = 0, carry = 0; i < max(b.digit.size(), digit.size()) || carry; i++)
        {
            if(i == (int)res.digit.size())
                res.digit.push_back(0);
            
            res.digit[i] += carry + (i < digit.size())?digit[i] : 0;
            carry = res.digit[i] >= 10;
            if(carry)
                res.digit[i] -= 10;
        }
        return res;
   }

   return *this - (-b);
}

BigInt BigInt::operator-(const BigInt &b) const {
    if(sign == b.sign)
    {
        if(abs() > b.abs()) {
            BigInt res = *this;
            for(int i = 0, carry = 0; i < b.digit.size() || carry; i++)
            {
                res.digit[i] -= carry + (i < b.digit.size())?b.digit[i]:0;

                carry = (res.digit[i] < 0);
                if(carry)
                    res.digit[i] += 10;
            }
            res.trim();
            return res;
        }

        return -(b - *this);
    }

    return *this + (-b);
}

bool BigInt::operator>(const BigInt &b) const {
    if(sign != b.sign)
        return (sign > b.sign);
    if(sign == 0)
        return false;
    if(digit.size() != b.digit.size())
        return (digit.size() * sign > b.digit.size() * b.sign);
    
    for(int i = digit.size() - 1; i >= 0; i--)
    {
        if(digit[i] == b.digit[i])
            continue;
        return (digit[i] * sign > b.digit[i] * b.sign);
    }

    return false; // since the numbers are equal
}

bool BigInt::operator<(const BigInt &b) const {
    return *this > b;
}

BigInt BigInt::abs() const{
    BigInt res = (*this);
    res.sign *= res.sign;
    return res;
}

ostream& operator<<(ostream &output, const BigInt &b) {
    if(b.sign == 0)
        output << 0;
    if(b.sign == -1)
        output << '-';
    for(int i = b.digit.size() - 1; i >= 0; i--)
        output << b.digit[i];
    return output;
}

istream& operator>>(istream &input, BigInt &b) {
    string s;
    input >> s;
    b.readString(s);
    return input;
}



