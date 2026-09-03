class Solution {
public:
    string reverseWords(string s) {
         int i=0;
        while(!s.empty() &&s.front()==' '){
           s.erase(0, 1);
        }
        while(!s.empty() &&s.back()==' '){
            s.pop_back();
        }
        reverse(s.begin(),s.end());
        string ans="";
        string currstr="";

        for(int i=0;i<s.size();i++){
            currstr = "";
             while(i<s.size()&&s[i]!=' '){
                currstr+=s[i];
                i++;
             }
             reverse(currstr.begin(),currstr.end());
             ans+=currstr;
             ans+=' ';
             while(i<s.size()&&s[i]==' '){
                i++;
             }
              i--;
        }
        ans.pop_back();
        return ans;
        
    }
};