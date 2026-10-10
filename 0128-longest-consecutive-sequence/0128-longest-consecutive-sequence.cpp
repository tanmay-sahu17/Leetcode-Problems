class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;

        priority_queue<int>q;

        int n=nums.size();
        int cnt=1;
        int maxcnt=INT_MIN;
        int i=0;

        for(auto x:nums){
            q.push(x);
        }

        while(!q.empty()){
            int top=q.top();
            q.pop();

            if(!q.empty()&&top==q.top())continue;
            if(!q.empty()&&top==q.top()+1){
                cnt++;
                maxcnt=max(cnt,maxcnt);
            }
            else{
                cnt=1;
            }
            i++;
        }  
        return  maxcnt;      
    }
};