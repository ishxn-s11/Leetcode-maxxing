/*
Greedy Approach--
Sort costs
Traverse From left To right
Buy If There's Enough coins
Stop When Next Bar Is Expensive

Time Complexity:O(n*log(n))
Space Complexity:O(1)
*/
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int count=0;
        for(int i:costs){
            if(coins<i) break;
            coins-=i;
            count++;
        }
        return count;
    }
};
