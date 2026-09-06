class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;

        int wordLen = words[0].size();
        int totalWords = words.size();

        unordered_map<string,int> wordMap;
        for (auto &w : words) wordMap[w]++;

        for (int i = 0; i < wordLen; i++) {
            unordered_map<string,int> curr;
            int left = i, right = i, count = 0;

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordMap.count(word)) {
                    curr[word]++;
                    count++;

                    while (curr[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        curr[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == totalWords)
                        ans.push_back(left);
                } else {
                    curr.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return ans;
    }
};
