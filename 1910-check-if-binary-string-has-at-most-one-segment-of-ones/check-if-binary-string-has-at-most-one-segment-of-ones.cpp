class Solution {
public:
    bool checkOnesSegment(string s) {
        int oneCount = 0;
        int segmentCount = 0;
        for(int i = 0 ;i < s.size();i++){
            if(s[i] == '0'){
                if(oneCount) segmentCount++;
                oneCount = 0;
            }
            if(s[i] == '1'){
                oneCount++;
                if(segmentCount == 1) return false;
            }
        }
        return true;
    
    }
};