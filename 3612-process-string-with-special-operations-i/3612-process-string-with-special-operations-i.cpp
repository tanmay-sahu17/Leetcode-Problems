class Solution {
public:
    string processStr(string s) {
        string result;

        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z'){
                result+=s[i];
            }
            if(!result.empty()&&s[i]=='*')result.pop_back();
            if(!result.empty()&&s[i]=='#')result+=result;
            if(!result.empty()&&s[i]=='%')reverse(result.begin(),result.end());
        }
        
        return result;
    }
};