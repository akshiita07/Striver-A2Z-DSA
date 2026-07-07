class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0){
            return 0;
        }
        string numX="";
        string numOrig=to_string(n);
        for(int i=0;i<numOrig.length();i++){
            if(numOrig[i]!='0'){
                numX+=numOrig[i];
            }
        }
        long long sum=0;
        for(int i=0;i<numX.length();i++){
            sum+=(numX[i]-'0');
        }
        long long x=stoi(numX);
        return (long long)sum*x;
    }
};
