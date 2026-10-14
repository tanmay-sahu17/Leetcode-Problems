class Solution {
public:
    bool isPalindrome(string s){
        int i=0;
        int j=s.size()-1;

        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    void solve(string s,int index,vector<string>&curr,vector<vector<string>>&ans){
        if(index==s.size()){
            ans.push_back(curr);
            return;
        }

        for(int j=index;j<s.size();j++){
            string sub=s.substr(index,j-index+1);

            if(isPalindrome(sub)){
                curr.push_back(sub);
                solve(s,j+1,curr,ans);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;

        solve(s,0,curr,ans);

        return ans;
    }
};