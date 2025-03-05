class Solution {
public:
    int maxi = 0;
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
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
            maxi = max(maxi,(rightsmall[i]-leftsmall[i] -1) * heights[i]);
        }
        cout<<endl;
        for(int i:rightsmall) cout<<i<<" ";
        return maxi;
    }
};