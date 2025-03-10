typedef long long ll;
class Solution {
public:
    bool isVowel(char c){
        if(c == 'a'||c=='i'||c=='e'||c=='o'||c=='u'){
            return true;
        }else {
            return false;
        }
    }
    long long countOfSubstrings(string word, int k) {
        unordered_map<char,int> mp;
        int n = word.size();
        int const_count = 0;
        ll result = 0;
        int i = 0;
        int j = 0;
        //pre computing the next constant for each constant
        int last_const_idx = n;
        vector<int> last_idx(n);
        for(int i = n-1;i >= 0;--i){
            char c = word[i];
            if(!isVowel(c)){//that mean this constant
                last_idx[i] = last_const_idx;
                last_const_idx = i;
            }else{
                last_idx[i] = last_const_idx;
            }
        }
        while(j < n){
            char ch = word[j];
            if(isVowel(ch)){
                mp[ch]++;
            }else{
                const_count++;
            }
            while( i < n && const_count > k){
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0)
                        mp.erase(ch);
                }
                else{
                    const_count--;
                }
                i++;
            }
            while( i < n && mp.size()==5 && const_count==k){//valid window
                int next = last_idx[j];
                result += next - j;
                // i++;
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }else{
                    const_count--;
                }
                i++;
            }
            j++;
        }

        return result;
    }
};