class Solution {
public:
    long long funncr(int n, int r)
    {
        long long res = 1;
        for(int i = 0 ; i<r ; i++)
        {
            res = res * (n-i);
            res = res/(i+1);
        }
        return res;
    }
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        int n = rowIndex;
        for(int i = 0 ; i<=n ; i++)
        {
            long long temp = funncr(rowIndex,i);
            ans.push_back(static_cast<int>(temp));
        }
        return ans;
    }
};