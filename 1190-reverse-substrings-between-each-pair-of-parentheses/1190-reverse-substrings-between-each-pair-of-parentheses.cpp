class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int i = 0;

        while(i < s.length()) {

            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {
                int j = st.top();
                st.pop();

                reverse(s.begin() + j + 1, s.begin() + i);
            }

            i++;
        }

        string ans = "";

        for(char ch : s) {
            if(ch != '(' && ch != ')') {
                ans += ch;
            }
        }

        return ans;
    }
};