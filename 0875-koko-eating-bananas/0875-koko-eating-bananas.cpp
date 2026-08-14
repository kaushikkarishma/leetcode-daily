class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int left=1; 
        int right = *max_element(piles.begin(), piles.end());
        int mid=(left+right)/2;   //mid=koko current speed
        while(left<=right){
            mid=(left+right)/2;
            long long hours=0;
            for(int i=0;i<n;i++){
                hours+=((long long)piles[i]+mid-1)/mid;
            }
            if(hours<=h){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};