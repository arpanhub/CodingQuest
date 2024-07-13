class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> actual_index(n);

        iota(begin(actual_index),end(actual_index),0);
        
        auto lambda = [&](int &i,int &j){
            return positions[i] < positions[j];
        };

        sort(actual_index.begin(),actual_index.end(),lambda);

        vector<int> result;
        stack<int> st;
        for(int &currrent_index:actual_index){
            if(directions[currrent_index] == 'R'){
                st.push(currrent_index);
            }else{
                while(!st.empty() && healths[currrent_index] > 0){
                    int top_index = st.top();
                    st.pop();

                    if(healths[top_index] > healths[currrent_index]){
                        healths[top_index] -= 1;
                        healths[currrent_index] = 0;
                        st.push(top_index);
                    }
                    else if(healths[top_index] < healths[currrent_index]){
                        healths[top_index] = 0;
                        healths[currrent_index] -=1;
                    }else{
                        healths[top_index] = 0;
                        healths[currrent_index] =0;
                    }
                }
            }
        }
        for(int i = 0;i < n;i++){
            if(healths[i] > 0) result.push_back(healths[i]);
        }
        return result;
    }
};