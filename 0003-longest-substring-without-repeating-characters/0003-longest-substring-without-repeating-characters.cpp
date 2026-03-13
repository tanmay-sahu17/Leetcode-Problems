class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int maxcnt=0;
       map<char,int>mp;
        for(int right=0;right<s.size();right++){
            mp[s[right]]++;
             if(mp.find(s[right])!=mp.end()){
              while(mp[s[right]]>1){
                mp[s[left]]--;
                left++;
              }
             }
             
            maxcnt=max(right-left+1,maxcnt);
        }
        return maxcnt;
    }
};