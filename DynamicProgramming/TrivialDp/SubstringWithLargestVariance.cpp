class Solution {
public:
    int largestVariance(string s) {
       int f1=0;
       int f2=0;
       int n=s.size();
        int ans=0;
        vector<int> freq(27);
        for(auto &it:s){
            freq[it-'a']++;
        }
        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                if(ch1==ch2 or !freq[ch1-'a'] or !freq[ch2-'a']){
                    continue;
                }
                for(int i=1;i<=2;i++){
                    f1=0;
                    f2=0;
                    for(auto &it:s){
                        f1+=(ch1==it)?1:0;
                        f2+=(ch2==it)?1:0;
                        if(f1<f2){
                            f1=0;
                            f2=0;
                        }
                       if(f1>0 && f2>0){
                        ans=max(ans,(f1-f2));
                       }
                    }
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};