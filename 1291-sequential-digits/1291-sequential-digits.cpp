class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int>ans;

        int l = to_string(low).size();
        int h = to_string(high).size();

        for (int len=l;len<=h;len++) {
            for (int i=0;i+len<=9;i++) {
                int num=stoi(s.substr(i,len));

                if(num>=low&&num<=high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};