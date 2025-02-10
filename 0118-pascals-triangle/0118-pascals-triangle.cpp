class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>answer(numRows);

        for(int i = 0 ; i<numRows ; i++)
        {
            int ans = 1;
            vector<int>temp(i+1,1);

            for(int col = 1; col<i ; col++)
            {
                ans = ans*(i-col+1)/col;
                temp[col] = ans;
            }
            answer[i]=temp;
        }
        return answer;
    }
};