class Solution {
public:
    string reorganizeString(string s) {
       std::priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        map<char,int> mp;
        for(auto &it:s){
            mp[it]++;
        }
        for(auto &it:mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        auto block=pq.top();
        pq.pop();
        ans+=block.second;
        block.first-=1;
        while(not pq.empty()){
            auto temp=pq.top();
            pq.pop();
            ans+=temp.second;
            temp.first-=1;
            if(block.first>0){
                pq.push(block);
            }
            block=temp;
        }
        if(block.first>0){
            return "";
        }
        return ans;
    }
};