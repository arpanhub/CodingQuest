class Solution {
public:
    string frequencySort(string s) {
        // ordered_map<int,char> mp;
        string str ="";
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        for(char i:s){
            mp[i]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            int occurence = pq.top().first;
            char chr =  pq.top().second;
            pq.pop();
            str.append(occurence,chr);
        }
        return str;
    }
};