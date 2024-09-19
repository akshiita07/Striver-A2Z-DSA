#include <bits/stdc++.h>
using namespace std;

// TIME: O(3^n)-->??
// SPACE: O()
vector<int> diffWaysToCompute(string expression)
{
    vector<int> ans;
    // return all possible different results:
    // at each opeator..split into 2 halves, left & right & recursively solve expression on both sides n store answers in ans vector

    // get operator & split into left & right side
    for(int i=0;i<expression.length();i++){
        char current=expression[i];
        // expression consists of digits and the operator '+', '-', and '*' GIVEN
        if(current=='+' || current=='-' || current=='*'){
            // found operator so split
            string leftExp=expression.substr(0,i);
            string rightExp=expression.substr(i+1);
            // compute their results
            vector<int>leftAns= diffWaysToCompute(leftExp);
            vector<int>rightAns= diffWaysToCompute(rightExp);
            // combine result based on operator:
            for(auto lit:leftAns){
                for(auto rit:rightAns){
                    if(current=='+'){
                        ans.push_back(lit+rit);
                    }else if(current=='-'){
                        ans.push_back(lit-rit);
                    }else if(current=='*'){
                        ans.push_back(lit*rit);
                    }
                }
            }
        }
    }
    // ADD THIS BASE CASE AT END IF NO OPERATOR FOUND:
    // base case: if no operators in whole expression then add it to ans
    if(ans.empty()){
        // convert string to int to store in ans
        ans.push_back(stoi(expression));
    }

    return ans;
}

int main()
{
    string expression = "2*3-4*5";
    // Output: [-34,-14,-10,-10,10]
    vector<int> ans=diffWaysToCompute(expression);
    cout << "\nThe different possible answers are: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}