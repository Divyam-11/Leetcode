class Solution {
public:
    int maximumSwap(int num) {
        bool is_swapped = false;
        
        int max_idx = -1;
        string str = to_string(num);
        for(int i = 0 ; i < str.size();i++){
            max_idx = i;
            for(int j = i + 1 ; j < str.size();j++){
                if(str[j] >= str[max_idx]){
                    max_idx = j;
                }
            }
            if(str[max_idx] > str[i]){
                swap(str[max_idx],str[i]);
                is_swapped = true;
                break;
            }
        }
        return stoi(str);
    }
};