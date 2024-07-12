/* const int ZERO = []()
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
}; */
const int ZERO = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        int map[512] = {0}; // Single array to store mappings for both strings

        for (int i = 0; i < s.length(); ++i) {
            if (map[s[i]] != map[t[i] + 256]) return false;
            map[s[i]] = i + 1;
            map[t[i] + 256] = i + 1;
        }
        return true;
    }
};
