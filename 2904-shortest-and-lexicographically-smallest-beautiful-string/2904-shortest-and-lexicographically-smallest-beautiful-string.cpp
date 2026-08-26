class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int left = 0;
        int ones = 0;

        string ans = "";

        for (int right = 0; right < n; right++) {

            // Add current character to window
            if (s[right] == '1') {
                ones++;
            }

            // If window has more than k ones,
            // move left until we have at most k ones
            while (ones > k) {
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }

            // If window has exactly k ones
            if (ones == k) {

                // Remove unnecessary leading zeroes
                while (s[left] == '0') {
                    left++;
                }

                string current = s.substr(left, right - left + 1);

                // First valid answer
                if (ans == "") {
                    ans = current;
                }
                // Prefer shorter string
                else if (current.size() < ans.size()) {
                    ans = current;
                }
                // Same length -> lexicographically smaller
                else if (current.size() == ans.size() && current < ans) {
                    ans = current;
                }
            }
        }

        return ans;
    }
};