class Solution {
public:

    int distinctSubseqII(string s) {

        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> dp(n + 1, 0);

        // Empty subsequence
        dp[0] = 1;

        vector<long long> last(26, 0);

        for(int i = 1; i <= n; i++) {

            int ch = s[i - 1] - 'a';

            // Every previous subsequence can either
            // take or not take current character
            dp[i] = (2 * dp[i - 1]) % MOD;

            // Remove duplicate subsequences
            dp[i] = (dp[i] - last[ch] + MOD) % MOD;

            // Store previous dp value for this character
            last[ch] = dp[i - 1];
        }

        // Remove empty subsequence
        return (dp[n] - 1 + MOD) % MOD;
    }
};