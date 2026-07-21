class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<long long>> dp(n, vector<long long>(fuel + 1, -1));
        const int MOD = 1e9 + 7;

        function<long long(int, int)> dfs = [&](int curr, int remainingFuel) {
            if (remainingFuel < 0) return 0LL;
            if (dp[curr][remainingFuel] != -1) return dp[curr][remainingFuel];

            long long count = (curr == finish) ? 1 : 0;

            for (int next = 0; next < n; ++next) {
                if (next != curr) {
                    int cost = abs(locations[curr] - locations[next]);
                    count = (count + dfs(next, remainingFuel - cost)) % MOD;
                }
            }

            return dp[curr][remainingFuel] = count;
        };

        return dfs(start, fuel);
    }
};