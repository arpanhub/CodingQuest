class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        /*if(s == goal) return true;
        if(s[0] == goal[0]) return false;
        int idx;
        for(idx = 0;idx < s.length();idx++){
            if(goal[0] == s[idx]) break;
        }
        string str="";
        str = goal.substr(idx+1,goal.length());
        str = str + goal.substr(0,idx+1);
        if(str == s) return true;
        else return false; */
        // return (((s+s).find(goal))==1);
        return (((s+s).find(goal)) != -1);
    
    }
};