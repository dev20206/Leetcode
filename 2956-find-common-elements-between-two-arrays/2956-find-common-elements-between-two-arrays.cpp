class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(2);
        unordered_map<int, int> arr1;
        unordered_map<int, int> arr2;
        

        for (int num : nums1) {
            arr1[num]++;
        }
        
        for (int num : nums2) {
            arr2[num]++;
        }

        int count1 = 0;
        for (auto it1 = arr1.begin(); it1 != arr1.end(); it1++) {
            for (auto it2 = arr2.begin(); it2 != arr2.end(); it2++) {
                if (it1->first == it2->first) {
                    count1 += it2->second;
                }
            }
        }
   
        int count2 = 0;
        for (auto it2 = arr2.begin(); it2 != arr2.end(); it2++) {
            for (auto it1 = arr1.begin(); it1 != arr1.end(); it1++) {
                if (it2->first == it1->first) {
                    count2 += it1->second;
                }
            }
        }
        
        ans[1] = count1;
        ans[0] = count2;
        
        return ans;
    }
};
