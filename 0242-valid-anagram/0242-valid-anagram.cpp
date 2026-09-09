class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(auto x:s){
            mp[x]++;
        }
        for(auto y:t){
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