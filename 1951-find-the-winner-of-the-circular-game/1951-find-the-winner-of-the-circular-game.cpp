class Solution {
public:

    void recursion(vector<int>&array , int k , int index)
    {
        int n = array.size();
        if(n==1)
        {
            return;
        }

        index = ((index+k) % n);
        array.erase(array.begin()+index);
        recursion(array, k , index);
    }
    int findTheWinner(int n, int k) {
        vector<int>array;
        for(int i = 1 ; i<=n ; i ++)
        {
            array.push_back(i);
        }

        recursion(array,k-1,0);

        return array[0];
        
    }
};