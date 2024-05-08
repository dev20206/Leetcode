class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
    vector<pair<int, int>> rankedScores;
    vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    vector<string> result(score.size());

    for (int i = 0; i < score.size(); ++i) {
        rankedScores.push_back({score[i], i});
    }

    sort(rankedScores.rbegin(), rankedScores.rend());

    for (int i = 0; i < rankedScores.size(); ++i) {
        if (i < 3) {
            result[rankedScores[i].second] = medals[i];
        } else {
            result[rankedScores[i].second] = to_string(i + 1);
        }
    }

    return result;
}
};