class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans;
        int n = words.size();

        int i = 0;

        while (i < n) {

            // Current line ke words
            vector<string> line;

            int lineLength = 0;

            // Maximum words current line me bharna
            while (i < n &&
                   lineLength + words[i].size() + line.size() <= maxWidth) {

                line.push_back(words[i]);
                lineLength += words[i].size();
                i++;
            }

            // Last line OR single word
            if (i == n || line.size() == 1) {

                string curr = "";

                for (int j = 0; j < line.size(); j++) {

                    curr += line[j];

                    if (j != line.size() - 1)
                        curr += " ";
                }

                // Remaining spaces end me
                curr += string(maxWidth - curr.size(), ' ');

                ans.push_back(curr);
            }

            // Normal line
            else {

                int totalSpaces = maxWidth - lineLength;

                int gaps = line.size() - 1;

                int spacesEach = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                string curr = "";

                for (int j = 0; j < line.size(); j++) {

                    curr += line[j];

                    if (j != line.size() - 1) {

                        // Extra spaces left wale gaps ko
                        int spaces = spacesEach;

                        if (j < extraSpaces)
                            spaces++;

                        curr += string(spaces, ' ');
                    }
                }

                ans.push_back(curr);
            }
        }

        return ans;
    }
};