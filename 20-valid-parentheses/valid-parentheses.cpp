class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for(int i = 0;i<s.size();i++){
            char c = s[i];
            if(c == '[' || c == '{' || c == '('){
                st.push(c);
            }else{
                if(st.size() == 0) return false;
                if(c == ']' && st.top() != '[')return false;
                else if(c == '}' && st.top() != '{')return false;
                else if(c == ')' && st.top() != '(')return false;
                st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};