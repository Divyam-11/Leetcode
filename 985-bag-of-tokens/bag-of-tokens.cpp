class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(),tokens.end());
    int max_score = 0;
    int score = 0;
    int low = 0;
    int high = tokens.size() - 1;
    while(low<=high){
        if(tokens[low]<=power){
            power-=tokens[low];
            score++;
            low++;
            max_score = max(max_score,score);
        }
        else if(score>0){
            power+=tokens[high];
            score--;
            high-- ;
        }
        else return max_score;

    }
    return max_score;
    }
};