class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> cnt(26, 0);

        // Count frequency
        for(char ch : s){
            cnt[ch - 'a']++;
        }

        string left = "";
        char mid = '\0';

        // Build left half
        for(int i = 0; i < 26; i++){

            // Add half occurrences
            for(int j = 0; j < cnt[i] / 2; j++){
                left += char(i + 'a');
            }

            // Store middle character (if frequency is odd)
            if(cnt[i] % 2 == 1){
                mid = char(i + 'a');
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if(mid != '\0')
            return left + mid + right;

        return left + right;
    }
};