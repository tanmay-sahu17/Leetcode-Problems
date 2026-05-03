class Solution {
public:
    bool rotateString(string s, string goal) {
       if(s==goal)return true;
        for(int i=0;i<s.size();i++){
             if(s.compare(goal)!=0){
                s.push_back(s[0]);
                s.erase(0,1);
             }
             else{
                return true;
             }

        }
        return false;
        
    }
};