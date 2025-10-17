class ExamTracker
{
public:
    vector<int> records;
    vector<long long> prefix_scores;
    ExamTracker()
    {
    }

    void record(int time, int score)
    {
        if (records.empty())
        {
            records.push_back(time);
            prefix_scores.push_back(score);
        }
        else
        {
            records.push_back(time);
            prefix_scores.push_back(prefix_scores.back() + score);
        }
    }

    long long totalScore(int startTime, int endTime)
    {
        // finding first element < start_time;
        int low = 0;
        int high = records.size() - 1;
        int i = lower_bound(records.begin(), records.end(), startTime) - records.begin();

        int j = upper_bound(records.begin(), records.end(), endTime) - records.begin();
        if (j == 0)
        {
            return 0;
        }
        else
        {
            j--;
        }
        if (i == 0)
            return prefix_scores[j];
        else
            i--;
        return prefix_scores[j] - prefix_scores[i];
    }
};