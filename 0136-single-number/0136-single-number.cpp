//T.C=O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i]; //ON OFF concept
        }
        return ans;
    }
};