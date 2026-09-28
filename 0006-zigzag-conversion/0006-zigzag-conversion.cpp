class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string> ans(numRows, "");
        string res = "";
        int j = 0;

        while(j < s.length()) {

            for(int i = 0; i < numRows && j < s.length(); i++) {
                ans[i] += s[j];
                j++;
            }

            for(int k = numRows - 2; k > 0 && j < s.length(); k--) {
                ans[k] += s[j];
                j++;
            }
        }

        for(string &str : ans) {
            res += str;
        }

        return res;
    }
};
