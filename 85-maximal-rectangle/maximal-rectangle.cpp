class Solution {
public:
    int maxi(vector<int>& heights) {
        int n = heights.size();
        int maxii = 0;
        vector<int> leftsmall(n,-1);
        vector<int> rightsmall(n,n);
        stack<int> st;
        for(int i = 0;i < n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                leftsmall[i] = -1;
            }else{
                leftsmall[i] = st.top();
            }
            st.push(i);
        }
        for(int i:leftsmall) cout<<i<<" ";
        while(!st.empty()){
            st.pop();
        } 
        for(int i = n-1;i >= 0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                rightsmall[i] = n;
            }else{
                rightsmall[i] = st.top();
            }
            st.push(i);
            maxii = max(maxii,(rightsmall[i]-leftsmall[i] -1) * heights[i]);
        }
        cout<<endl;
        for(int i:rightsmall) cout<<i<<" ";
        return maxii;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> hist(matrix[0].size());
        int maxiSuper = 0;
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[0].size();j++){
                if(matrix[i][j] == '1'){
                    hist[j] +=1;
                }else{
                    hist[j] = 0;
                }
            }
            maxiSuper = max(maxiSuper,maxi(hist));
        }
        return maxiSuper;
    }
};