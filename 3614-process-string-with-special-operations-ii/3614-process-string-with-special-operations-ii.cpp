class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n);
        
        long long cur = 0;
        
        
        for (int i = 0; i < n; i++) {
            if (islower(s[i])) {
                cur++;
            } else if (s[i] == '*') {
                if (cur > 0) cur--;
            } else if (s[i] == '#') {
                cur = min(cur * 2, (long long)1e15);
            } else if (s[i] == '%') {
                
            }
            len[i] = cur;
        }
        
        if (k >= cur) return '.';
        
        
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            
            if (islower(c)) {
                
                if (k == len[i] - 1) return c;
                
            } 
            else if (c == '*') {
                
            } 
            else if (c == '#') {
                long long half = len[i] / 2;
                if (k >= half) k %= half;
            } 
            else if (c == '%') {
                k = len[i] - 1 - k;
            }
        }
        
        return '.'; // fallback
    }
};