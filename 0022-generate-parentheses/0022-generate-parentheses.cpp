class Solution {
    void GP(int openp,int closep,int n,string s,vector<string>&ans){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(openp<n){
            GP(openp+1,closep,n,s+'(',ans);
           
        }
        if(closep<openp){
            GP(openp,closep+1,n,s+')',ans);
           
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
       int openp=0;
       int closep=0;
        GP(openp,closep,n,"",ans);
        return ans;
        
    }
};