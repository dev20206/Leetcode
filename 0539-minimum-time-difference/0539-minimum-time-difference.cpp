class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
    
        // Split the time points and convert them into minutes
        for (const auto& time : timePoints) {
            size_t pos = time.find(':');
            int hours = stoi(time.substr(0, pos));     // Extract the hour part
            int mins = stoi(time.substr(pos + 1));     // Extract the minute part
            int totalMinutes = hours * 60 + mins;      // Convert to total minutes
            minutes.push_back(totalMinutes);
        }
        
        // Sort the minutes for easier comparison
        sort(minutes.begin(), minutes.end());
        
        // Find the minimum difference between consecutive times
        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }

        // Also consider the difference between the last and the first time (circular difference)
        int circularDiff = (1440 - minutes.back() + minutes[0]);  // 1440 = total minutes in a day
        minDiff = min(minDiff, circularDiff);

        return minDiff;
    }
};
