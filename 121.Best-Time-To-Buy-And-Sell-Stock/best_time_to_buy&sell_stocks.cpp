class Solution {
public:
    int maxProfit(vector<int>& prices){
        int mini=prices[0];
        int maxgain=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            int cost=prices[i]-mini;
            maxgain=max(maxgain,cost);
            mini=min(mini,prices[i]);
        }
        return maxgain;
    }
};