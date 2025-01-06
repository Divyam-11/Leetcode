class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> answer(boxes.size(), 0);
        for (int i = 0; i < boxes.size(); i++)
        {
            int ans = 0;
            for (int j = 0; j < boxes.size(); j++)
            {   
                if(boxes[j] == '1')
                ans += abs(j - i);
            }
            answer[i] = ans;
        }
        return answer;
    }
};