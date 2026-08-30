class Solution {
public:
    bool isPalindrome(int x) {
        string y = to_string(x);
        for (int i = 0; i < y.size() / 2; i++) {  //chck half str
            if (y[i] != y[y.size()-1-i]) {    //y[i] is left element
                return false;         //y[y.size()-1-i] is rght elmnt
            }
        }
        return true;
    }
};