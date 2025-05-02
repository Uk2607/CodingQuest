#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

#define ull unsigned long long

ull dfs(int target, vector<int>&opt, vector<ull>&dp) {
    if(target==0) return 1;
    if(dp[target]!=-1) return dp[target];
    ull ways = 0;
    for(int x: opt) {
        if(target-x>=0) {
            ways += dfs(target-x, opt, dp);
        }
    }
    return dp[target] = ways;
}

ull countWays(int target, vector<int>& opt) {
    vector<ull> dp(target + 1, 0);
    dp[0] = 1; // Base case

    for (int i = 1; i <= target; ++i)
        for (int x : opt)
            if (i - x >= 0) dp[i] += dp[i - x];

    return dp[target];
}

void solve(int target, vector<int>&opt) {
    // vector<ull>dp(target+1, -1);
    // ull ways = dfs(target, opt, dp);
    ull ways = countWays(target, opt);
    cout<<"\nRES:: "<<ways<<"\n\n";
    return;
}

int main() {
    int total_dist = 856;
    vector<int>opts = {40, 12, 2, 1};
    // int total_dist = 5;
    // vector<int>opts = {3, 2, 1};
    solve(total_dist, opts);
    return 0;
}
