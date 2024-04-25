class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> dp(n, 1);
        unordered_map<char, int> mp;
        mp[s[0]] = 0;
        for (int i = 1; i < n; i++) {
            for (char ch = (char)max((int)s[i] - k, (int)'a');
                 ch <= (char)min((int)s[i] + k, (int)'z'); ch++) {

                if (mp.find(ch) != mp.end()) {
                    dp[i] = max(dp[i], dp[mp[ch]] + 1);
                }

            }
            mp[s[i]] = i;
        }
        int maxm = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxm = max(maxm, dp[i]);
        }
        
        return maxm;
    }
};