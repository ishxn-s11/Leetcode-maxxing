class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans(words.size(),'a');
        for(int i=0;i<words.size();i++){
            int sum=0;
            for(int j=0;j<words[i].length();j++) sum+=weights[words[i][j]-'a'];
            sum%=26;
            ans[i]=('a'+25-sum);
        }
        return ans;
    }
};
