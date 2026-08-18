class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>mp;
        for(char x:s){
            mp[x]++;
        }
        for(char y:t){
            mp[y]--;
        }
        for(auto it:mp){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
};