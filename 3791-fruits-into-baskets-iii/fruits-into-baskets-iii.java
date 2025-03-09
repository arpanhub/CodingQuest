class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int unp = 0;
        int max = 0;
        List<Integer> list = new ArrayList<>();
        for(int j = 0 ; j < baskets.length ;j++){
            list.add(baskets[j]);
            max = Math.max(max, baskets[j]);
        }
        for(int i = 0 ; i < fruits.length ; i++){
            if(fruits[i] > max){
                unp++;
                continue;
            }
            boolean placed = false;
            for(int j = 0 ; j < list.size() ; j++){
                if(list.get(j) >= fruits[i]){
                    list.remove(j);
                    placed = true;
                    break;
                }
            }
            if(!placed) unp++;
        }
        return unp;
    }
}