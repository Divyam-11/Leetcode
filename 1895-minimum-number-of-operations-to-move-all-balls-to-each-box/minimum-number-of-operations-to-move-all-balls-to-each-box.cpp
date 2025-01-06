class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> answer(boxes.size(), 0);

        int balls = 0;
        int moves = 0;

        for (int i = 0; i < boxes.size(); i++)
        {

            answer[i] = moves + balls;
            moves += balls;
            if (boxes[i] == '1')
                balls++;
        }
        balls = 0;
        moves = 0;
        for (int i = boxes.size() - 1; i >= 0; i--)
        {
            answer[i] += moves + balls;
            moves += balls;
            if (boxes[i] == '1')
                balls++;
        }
        return answer;
    }
};