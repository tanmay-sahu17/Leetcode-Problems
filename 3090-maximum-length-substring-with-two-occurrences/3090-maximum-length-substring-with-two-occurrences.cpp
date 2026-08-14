class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0;
        
         int n=s.size();
         int maxlen=INT_MIN;
         map<int,int>mp;
         for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(mp[s[r]]>2){
                mp[s[l]]--;
                l++;
            }
            if(r-l+1>maxlen){
                maxlen=r-l+1;
            }
         }
        return maxlen;
    }
};