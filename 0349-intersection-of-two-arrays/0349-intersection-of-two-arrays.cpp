#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> ans;
        auto iter1 = set1.begin();
        auto iter2 = set2.begin();
        
        while (iter1 != set1.end() && iter2 != set2.end()) {
            if (*iter1 == *iter2) {
                ans.push_back(*iter1);
                ++iter1;
                ++iter2;
            } else if (*iter1 < *iter2) {
                ++iter1;
            } else {
                ++iter2;
            }
        }
        
        return ans;
    }
};
