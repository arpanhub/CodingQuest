const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map1;
        unordered_map<char,char> map2;
        if(s.length() != t.length()) return false;
        for(int i =0;i <s.length();i++){
            if(map1.find(s[i]) != map1.end()){
                if(map1[s[i]] != t[i]) return false;
            }
            else if(map2.find(t[i]) != map2.end()){
                if(map2[t[i]] != s[i]) return false;
            }else{
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
        }
        return true;
    }
};