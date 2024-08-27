class Solution {
public:

    void findcombination(int index,vector<int>&main, int target, vector<vector<int>>&ans, vector<int>&ds)
    {
        if(index==main.size())
        {
            if(target==0)
                ans.push_back(ds);
            return;
        }

        if(main[index]<= target)
        {
            ds.push_back(main[index]);
            findcombination(index,main,target-main[index],ans,ds);
            ds.pop_back();
        }
        findcombination(index+1,main,target,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findcombination(0,candidates,target, ans,ds);
        return ans;
        
    }
};