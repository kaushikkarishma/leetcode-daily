class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int count=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            int x=sum-k;
            if(mp.find(x) != mp.end()) {
                count=count+mp[x];
           }
           mp[sum]++;
        }
        
    return count;
    }
};