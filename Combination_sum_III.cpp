class Solution {
private:
void helper(int n, int k, vector<vector<int>>& res, vector<int>& ans, int ind, int sum ){
    if (n==sum && k==0){
        res.push_back(ans);
        return;
    }

    if(sum>n){
        return;
    }

    for(int i = ind; i <=9; i++){
        ans.push_back(i);
        helper(n,k-1,res,ans,i+1, sum+i);
        ans.pop_back();
    }
}

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ans;
        helper(n,k,res,ans,1,0);

        return res;
    }
};
