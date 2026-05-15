class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> ans;

       for(auto i:nums){
        string num=to_string(i);
        for(int i=0;i<num.size();i++){
            ans.push_back(num[i]-'0');
        }
       }

        return ans;
    }
};