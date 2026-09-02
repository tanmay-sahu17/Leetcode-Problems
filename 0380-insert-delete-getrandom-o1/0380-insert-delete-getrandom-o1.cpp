class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> mp;

    RandomizedSet() {
    }

    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }

        nums.push_back(val);
        mp[val] = nums.size() - 1;

        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }

        int index = mp[val];
        int last = nums.back();

        // Last element ko val ki jagah le aao
        nums[index] = last;

        // Last element ka index update karo
        mp[last] = index;

        // Ab last element remove karo
        nums.pop_back();

        // val ko map se remove karo
        mp.erase(val);

        return true;
    }

    int getRandom() {
        int index = rand() % nums.size();
        return nums[index];
    }
};