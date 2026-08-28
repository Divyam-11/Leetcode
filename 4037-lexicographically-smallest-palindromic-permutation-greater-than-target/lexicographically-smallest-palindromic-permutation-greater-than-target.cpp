class Solution {
public:
    string ss="";
    int done=0;
    char odd;

    void rec(int level,string &s,string &target,vector <int> &freq,string &gen,int taken){
        int n=s.size();

        if (level==n/2 && done==0){
            if (taken==1){
                string temp=gen;
                reverse(temp.begin(),temp.end());
                if (n%2!=0)gen+=odd;
                gen+=temp;
                ss=gen;

                done=1;
                return;
            }
            else{
                string temp1=gen;
                string temp2=gen;
                reverse(temp1.begin(),temp1.end());
                if (n%2!=0)temp2+=odd;
                temp2+=temp1;

                if (temp2>target){
                    done=1;
                    ss=temp2;
                }
                return;
            }
        }


        for (int i=0;i<26;i++){

            if (done==1)return;
            if (freq[i]>0 && (taken==1||('a'+i>=target[level]))){
                freq[i]--;
                gen+=('a'+i);
                if ('a'+i>target[level])rec(level+1,s,target,freq,gen,1);
                else{
                    rec(level+1,s,target,freq,gen,taken);
                }
                gen.pop_back();
                freq[i]++;
            }
        }
    }
    
    string lexPalindromicPermutation(string s, string target) {
        int n=s.size();

        ss.clear();
        done=0;
        vector <int> freq(26,0);
        for  (int i=0;i<n;i++)freq[s[i]-'a']++;

        int cnt=0;
        for (int i=0;i<26;i++)if (freq[i]%2!=0)cnt++;

        if (cnt>1)return "";
        else{
            for (int i=0;i<26;i++){
                if (freq[i]%2!=0)odd='a'+i;
            }

            for (int i=0;i<26;i++){
                if (freq[i]%2==0)freq[i]/=2;
                else freq[i]=freq[i]/2;
            }
            string gen="";

            rec(0,s,target,freq,gen,0);

            return ss;
        }
    }
};