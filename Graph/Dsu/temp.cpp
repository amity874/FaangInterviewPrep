class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0;
        map<int,int>seen;
        int m = profit.size();
        for(int i = 0 ; i < m ; i++)
        {
            seen[difficulty[i]] = max(seen[difficulty[i]],profit[i]);
        }
        sort(difficulty.begin(),difficulty.end());
        int i = 0;
        for(auto it : difficulty)
        {
            profit[i] = seen[it];
            i++;
        }
        int n = worker.size();
        for(int i = 0 ; i < n ; i++)
        {
            int ind = upper_bound(difficulty.begin(),difficulty.end(),worker[i]) - difficulty.begin();
            ind--;
            if(ind<0)
                continue;
            int max1 = *max_element(profit.begin(),profit.begin()+ind+1);
            ans+=max1;
        }
        return ans;
    }
};