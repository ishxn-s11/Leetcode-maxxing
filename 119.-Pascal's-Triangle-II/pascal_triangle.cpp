class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>tri;
        long  int ans=1;
        tri.push_back(ans);
        for(int i=1;i<=rowIndex;i++){
            ans*=(rowIndex-i+1);
            ans/=i;
            tri.push_back(ans);
        }
        return tri;
    }
};