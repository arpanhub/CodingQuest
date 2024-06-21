class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int satisfied_customers = 0;
        for(int i = 0;i < n;i++){
            if(grumpy[i] == 0){
                satisfied_customers += customers[i];
            }
        }
        int totoal_satisfied_customers = 0;
        for(int j = 0;j < n - minutes + 1;j++){
        int current_customers = 0;
            for(int k = j;k < j + minutes;k++){
                if(grumpy[k] == 1){
                    current_customers += customers[k];
                }
            }
            totoal_satisfied_customers = max(current_customers,totoal_satisfied_customers);
        }
        return totoal_satisfied_customers + satisfied_customers;
    }
};