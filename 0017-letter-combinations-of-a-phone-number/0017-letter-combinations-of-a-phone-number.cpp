class Solution {
public:
    void backtracking(string &digits,int i,vector<string>&ans,string curr,map<int,string>&mp){
       if(i==digits.size()){
        ans.push_back(curr);
        return;
       }

      string letters=mp[digits[i]-'0'];

      for(auto l:letters){
        curr.push_back(l);
        backtracking(digits,i+1,ans,curr,mp);
        curr.pop_back();
      }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        vector<string>ans;
        string curr="";

        map<int,string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";

    backtracking(digits,0,ans,curr,mp);
    return ans;
        
    }
};