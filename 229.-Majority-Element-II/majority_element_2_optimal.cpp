class Solution {
public:
//Optimal Approach
//Moore's Voting Algorithm
    vector<int> majorityElement(vector<int>& nums){
        int c1=0,c2=0;
        int e1=INT_MIN;
        int e2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(c1==0 && e2!=nums[i]){
                c1=1;
                e1=nums[i];
            }
            else if(c2==0 && e1!=nums[i]){
                c2=1;
                e2=nums[i];
            }
            else if(nums[i]==e1) c1++;
            else if(nums[i]==e2) c2++;
            else{
                c1--;
                c2--;
            }
        }
        vector<int>l;
        c1=0,c2=0;
        for(int i=0;i<nums.size();i++){
            if(e1==nums[i]) c1++;
            if(e2==nums[i]) c2++;
            }
        int min=(int)((nums.size()/3)+1);
        if(c1>=min) l.push_back(e1);
        if(c2>=min) l.push_back(e2);
        return l;
    }
};