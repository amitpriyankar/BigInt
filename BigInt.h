#include <vector>
#include <string>
using namespace std;
class BigInt {
    private:
        vector<int> digit;

        /*
            sign denotes of sign of the integer,
            -1 for negative, 1 for positive and 0 for zero.
        */
        int sign;

        //  size denotes the no. of digits in decimal representation of the number.
        int size;


    public:
        
        //  Default constructor, incase no arguement is provided.
        BigInt();

        //  Constructor, when an integer(in-built type) is provided as an arguement.
        BigInt(long long x);

        //  Constructor, when an integer(in-built type) is provided as an arguement.
        BigInt(const string &s);

        // Defining operator overloading for '='
        void operator=(long long v);

        // A fuction to read a string and convert it to vector<int>
        void readString(const string &s);

};