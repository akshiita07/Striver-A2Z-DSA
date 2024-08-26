#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t reverseBin=0;
    // reverse bits
    for(int i=0;i<32;i++){
        reverseBin=(reverseBin<<1) | (n&1);
        n=n>>1;
    }
    return reverseBin;
}

int main()
{
    // write prefix 0b for binary:
    uint32_t n = 0b00000010100101000001111010011100;
    // Output:    964176192 (00111001011110000010100101000000 reversed form)
    // range of values goes from 0 to 2^32 - 1
    cout<<"\nThe no after reversal is: "<<reverseBits(n);

    return 0;
}