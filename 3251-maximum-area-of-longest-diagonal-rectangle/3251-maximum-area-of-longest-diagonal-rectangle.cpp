class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxi = 0;
        int l = 0;
        int b = 0;

        for(int i = 0 ; i < dimensions.size() ; i++)
        {
            int length = dimensions[i][0];
            int breadth = dimensions[i][1];

            if (sqrt((length * length) + (breadth * breadth)) > maxi ||
               (sqrt((length * length) + (breadth * breadth)) == maxi && length * breadth > l * b))
            {
                l = length;
                b = breadth;
                maxi = sqrt((length * length) + (breadth * breadth));
            }
        }
        return l * b;
    }
};
