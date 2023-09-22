const int N = 1e5+1;

int dp[N];
vector<vector<vector<int>>> offers_starting_at(N);

class Solution {
    
    int MaxProfit (int ind) {
        if (ind == N) return 0;
        
        int &ans = dp[ind];
        if (ans != -1) return ans;
        
        ans = MaxProfit (ind+1);
        for (auto offer : offers_starting_at[ind]) {
            ans = max (ans, offer[2] + MaxProfit (offer[1]+1));
        }
        return ans;
    }
    
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        for (auto &i : offers_starting_at) i.clear();
        memset(dp, -1, sizeof(dp));
        
        for (auto i : offers) {
            offers_starting_at[i[0]].push_back(i);
        }
        
        return MaxProfit (0);
    }
};