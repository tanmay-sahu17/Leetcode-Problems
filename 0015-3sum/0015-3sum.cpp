class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            // duplicate num skip
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int num = nums[i];

            int l = i + 1;
            int r = n - 1;

            while(l < r) {

                int sum = num + nums[l] + nums[r];

                if(sum == 0) {

                    ans.push_back({num, nums[l], nums[r]});

                    // duplicate left values skip
                    while(l < r && nums[l] == nums[l+1])
                        l++;

                    // duplicate right values skip
                    while(l < r && nums[r] == nums[r-1])
                        r--;

                    l++;
                    r--;
                }

                else if(sum < 0) {
                    l++;
                }

                else {
                    r--;
                }
            }
        }

        return ans;
    }
};