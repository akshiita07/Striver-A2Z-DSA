class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> st;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i]=="C"){
                st.pop();
            }else if (operations[i]=="D"){
                int elem=stoi(st.top());
                elem=elem*2;
                st.push(to_string(elem));
            }else if (operations[i]=="+"){
                //sum of the previous two scores & then push in stack
                int elem1=stoi(st.top());
                st.pop();
                int elem2=stoi(st.top());
                st.pop();
                int sum=elem1+elem2;
                st.push(to_string(elem2));
                st.push(to_string(elem1));
                st.push(to_string(sum));
            }else{
                // store integer
                st.push(operations[i]);
            }
        }
        // return sum of all elem of stack
        int sum=0;
        while(!st.empty()){
            sum+=stoi(st.top());
            st.pop();
        }
        return sum;
    }
};