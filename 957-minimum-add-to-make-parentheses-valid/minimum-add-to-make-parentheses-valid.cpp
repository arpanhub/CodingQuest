class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ctr=0;
        for(char c:s){
            if(c=='('){
                st.push('(');
            }
            if(c==')'){
                if(!st.empty() && st.top()=='(') st.pop();
                else ctr++;
            }
        }
        return st.size()+ctr;
        
        
    }
};