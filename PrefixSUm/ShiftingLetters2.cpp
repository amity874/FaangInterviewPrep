https://leetcode.com/problems/shifting-letters-ii/
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> pre(n+1);
        for(auto &it:shifts){
            int i=it[0];
            int j=it[1];
            int k=it[2];
            if(k==1){
                pre[i]+=1;
                pre[j+1]-=1;
            }
            else if(k==0){
                pre[i]-=1;
                pre[j+1]+=1;
            }
        }
        for(int i=1;i<=n;i++){
            pre[i]+=pre[i-1];
        }
        for(int i=0;i<n;i++){
            int val=((s[i]-'a')+pre[i])%26;
            if(val<0){
                val+=26;
            }
            s[i]=('a')+val;
        }
        cout<<'c'-'a';
        return s;
    }
};