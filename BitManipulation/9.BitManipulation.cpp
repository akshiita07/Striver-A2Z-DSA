#include <bits/stdc++.h>
using namespace std;

void bitManipulation(int num, int i)
{
    i--;        //as 1 based indexing!!
    // 1. Get ith bit
    int getBit=0;
    if((num & (1<<i))>0){
        getBit=1;
    }else{
        getBit=0;
    }
    cout<<"\nGet Bit= "<<getBit;

    // 2. Set ith bit to 1
    int setBit=0;
    setBit=(num | (1<<i));
    cout<<"\nSet Bit= "<<setBit;

    // 3. Clear ith bit
    int clearBit=0;
    clearBit=(num & ~(1<<i));
    cout<<"\nClear Bit= "<<clearBit;
}

int main()
{
    int num=9;
    int i=3;
    // op: 0 13 9
    bitManipulation(num,i);

    return 0;
}