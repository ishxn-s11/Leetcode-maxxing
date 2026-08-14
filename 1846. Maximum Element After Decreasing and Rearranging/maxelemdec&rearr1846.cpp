/*
Sort The Array
Set arr[0]=1
Traverse 
Update As arr[i]=min(arr[i],arr[i-1]+1)
Return arr.back()

Time Complexity: O(n*log(n))
Space Complexity: O(1)
*/

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        arr[0]=1;
        for(int i=1;i<arr.size();i++) arr[i]=min(arr[i],arr[i-1]+1);
        return arr.back();
    }
};
