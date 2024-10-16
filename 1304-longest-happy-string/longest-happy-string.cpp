class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a > 0) pq.push({a,'a'});
        if(b > 0) pq.push({b,'b'});
        if(c > 0) pq.push({c,'c'});
        string res = "";
        while(!pq.empty()){
            int currentCount = pq.top().first;
            char currentChar = pq.top().second;
            pq.pop();
            if(res.length()>=2 && res[res.length()-1] == currentChar && res[res.length()-2] == currentChar){
                if(pq.empty()) break;
                int nextCount = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();
                res.push_back(nextChar);
                nextCount--;
                if(nextCount>0){
                    pq.push({nextCount,nextChar});
                }
                // pq.push({currentCount,currentChar});
            }else{
                res.push_back(currentChar);
                currentCount--;
            }
            if(currentCount > 0) pq.push({currentCount,currentChar});
            }
        return res;
        }
    };