class Solution {
public:

    void findcombinations(int index, int target, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            ds.push_back(arr[i]);
            findcombinations(i + 1, target - arr[i], arr, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sorting to handle duplicates
        vector<int> ds;
        vector<vector<int>> ans;
        findcombinations(0, target, candidates, ds, ans);
        return ans;
    }
};
