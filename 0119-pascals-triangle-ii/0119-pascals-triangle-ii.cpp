class Solution {
public:
    vector<int> getRow(int rowIndex) {

        long long ans = 1;
        vector<int>answer(rowIndex+1,1);

        for(int i = 1 ; i <rowIndex ; i++)
        {
            ans = ans*(rowIndex-i+1);
            ans=ans/i;
            answer[i]=ans;
        }
        return answer;
        
    }
};