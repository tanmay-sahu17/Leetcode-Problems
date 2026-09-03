class Solution {
public:
    int lengthOfLastWord(string s) {
        while(s.back()==' '){
            s.pop_back();
        }
        int len=0;
        while(!s.empty()&&s.back()!=' '){
             len++;
             s.pop_back();
        }
        return len;
    }
};