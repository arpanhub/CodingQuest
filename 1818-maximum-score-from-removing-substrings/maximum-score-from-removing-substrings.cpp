const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    int maxAmount(string& s,string find_str,int gains){
        int n = s.length();
        stack<int> st;
        int points = 0;
        for(int i = 0;i < n;i++){
            if(st.empty()){
                st.push(s[i]);
            } 
            else if(st.top() == find_str[0] && s[i] == find_str[1]){
                points += gains;
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        s="";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return points;
    }
    int maximumGain(string s, int x, int y) {
        string s1 = "ab";
        string s2 = "ba";
        if(y>x){
            swap(s1,s2);
            swap(x,y);
        }
        int amount1 =  maxAmount(s,s1,x);
        int amount2 =  maxAmount(s,s2,y);
        return amount1 + amount2;
    }
};