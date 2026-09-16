class Solution {
public:
    bool check(vector<int>& nums) {  //true false btane wala function
        int n=nums.size(); //array size
        int count=0; //will store breaks
        for(int i=0;i<n;i++){  //iteration
            if(nums[i] > nums[(i+1)%n]){
                count++;
            }
        }
    return count<=1;  //A sorted and rotated array can have at most ONE place where the order decreases. If there are 2 or more such breaks, it cannot be obtained by rotating a sorted array.
    }
};