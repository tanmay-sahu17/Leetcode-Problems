class Solution {
public:
    string ans = "";
    int count = 0;

    void solve(string curr, int n, int k){
        
       if(curr.size()==n){
        count++;
        if(count==k)ans=curr;
       
       return;
       }

       for(auto ch:{'a','b','c'}){
        if(curr.empty()||curr.back()!=ch){
            solve(curr+ch,n,k);
        }
        if(ans != "") return;
       }
      
    }

    string getHappyString(int n, int k) {
        
        solve("", n, k);
        return ans;
    }
};