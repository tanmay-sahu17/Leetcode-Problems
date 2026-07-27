class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int x : nums) {
            maxHeap.push(x);
            minHeap.push(x);
        }

        int max1 = maxHeap.top(); maxHeap.pop();
        int max2 = maxHeap.top(); maxHeap.pop();
        int max3 = maxHeap.top(); maxHeap.pop();

        int min1 = minHeap.top(); minHeap.pop();
        int min2 = minHeap.top(); minHeap.pop();

        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};