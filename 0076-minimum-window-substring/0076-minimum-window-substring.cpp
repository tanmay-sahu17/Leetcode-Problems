class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> freq(128, 0);

        for (char ch : t) {
            freq[ch]++;
        }

        int left = 0;
        int start = 0;
        int minLen = INT_MAX;

        // Kitne characters abhi bhi required hain
        int count = t.size();

        for (int right = 0; right < s.size(); right++) {

            // Current character ko window me add kiya
            if (freq[s[right]] > 0) {
                count--;
            }

            freq[s[right]]--;

            // Agar saare required characters mil gaye
            while (count == 0) {

                // Minimum window update karo
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Left character ko remove karne ki try karo
                freq[s[left]]++;

                if (freq[s[left]] > 0) {
                    count++;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) return "";

        return s.substr(start, minLen);
    }
};