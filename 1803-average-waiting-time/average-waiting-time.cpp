const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int cust_arrival_time = customers[0][0];//2
        int cooking_finished_time = customers[0][0] + customers[0][1];//5
        double cust_waiting_time = cooking_finished_time - cust_arrival_time;//3
        for(int i =1;i < customers.size();i++){
            if(customers[i][0] > cooking_finished_time){
                cust_waiting_time +=customers[i][1];//6
                cooking_finished_time = customers[i][0] + customers[i][1];
            }else{
                cooking_finished_time = cooking_finished_time + customers[i][1];//
                cust_waiting_time += cooking_finished_time - customers[i][0];//
            }
        }
        return cust_waiting_time/n;

    }
};