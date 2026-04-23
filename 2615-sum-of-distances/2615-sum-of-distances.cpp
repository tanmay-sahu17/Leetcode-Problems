class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n, 0);
        
        unordered_map<int, long long> count, sum;
        
        for(int i = 0; i < n; i++){
            if(count[nums[i]] > 0){
                res[i] += count[nums[i]] * i - sum[nums[i]];
            }
            count[nums[i]]++;
            sum[nums[i]] += i;
        }
        count.clear();
        sum.clear();
        for(int i = n-1; i >= 0; i--){
            if(count[nums[i]] > 0){
                res[i] += sum[nums[i]] - count[nums[i]] * i;
            }
            count[nums[i]]++;
            sum[nums[i]] += i;
        }
        
        return res;
    }
};