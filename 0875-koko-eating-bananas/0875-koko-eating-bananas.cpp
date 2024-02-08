class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(auto i:piles){
            maxi=max(maxi,i);
        }
        long long int low=1;
        long long int high=maxi;
        long long int res=high;
        while(low<=high){
            long long int mid=(high+low)/2;
            long long int count=0;
            for(auto i:piles){
                count+=(i/mid);
                if(i%mid!=0){
                    count++;
                }
            }
            if(count<=h){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};