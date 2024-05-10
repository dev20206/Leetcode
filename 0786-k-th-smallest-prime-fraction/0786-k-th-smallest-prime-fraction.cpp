class Solution {
public:
   vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        set<pair<double, pair<int, int>>> s1;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                s1.insert({(double)arr[i] / arr[j], {arr[i], arr[j]}});
            }
        }
        auto it = s1.begin();
        advance(it, k-1);
        pair<int, int> kthFraction = it->second;
        return {kthFraction.first, kthFraction.second};
    }
};