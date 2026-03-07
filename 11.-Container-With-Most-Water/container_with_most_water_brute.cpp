class Solution {
public:
    //Brtue Force Approach
    int maxArea(vector<int>& height){
        int ans=0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                int w=j-i;
                int h=min(height[i],height[j]);
                int container=w*h;
                ans=max(ans,container);
            }
        }
        return ans;
    }
};
