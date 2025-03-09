class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<int> basket_copy;
        int count = 0;
        int maxi = 0;
        for(int i:baskets){
            basket_copy.push_back(i);
            maxi = max(maxi,i);
        }
        for(int i =0;i < fruits.size();i++){
            int fruit = fruits[i];
            if(fruit > maxi){
                count++;
                continue;
            }
            bool is_placed = false;
            for(int j = 0;j < basket_copy.size();j++){
                int basket_size = basket_copy[j];
                if(basket_size >= fruit){
                    is_placed = true;
                    basket_copy.erase(basket_copy.begin() + j);
                    break;
                }
            }
            if(!is_placed) count++;
        }
        return count;
    }
};