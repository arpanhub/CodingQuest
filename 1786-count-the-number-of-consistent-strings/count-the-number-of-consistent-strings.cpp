class Solution {
public:
    bool allowedString(string allowed,string word){
        for(int j = 0;j < word.length();j++){
            bool flag = false;
            for(int k = 0;k < allowed.length();k++){
                if(word[j] == allowed[k]) flag = true;
            }
            if(flag == false) return false;
        }
        return true;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        for(int i  = 0;i < words.size();i++){
            if(allowedString(allowed,words[i])){
                count++;
            }
        }
        return count;
    }
};