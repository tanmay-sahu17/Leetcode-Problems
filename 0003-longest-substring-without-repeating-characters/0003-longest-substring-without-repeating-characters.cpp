class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=INT_MIN;
        map<char,int>mp;
        int n=s.size();
        int left=0;
        for(int right=0;right<n;right++){
            mp[s[right]]++;
            while(mp[s[right]]>1){
                mp[s[left]]--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
        }
       if(maxlen!=INT_MIN)return maxlen;
       return 0;
        
    }
};