#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<vector<int>> get_input(string file_name) {
    string file_path = "2023/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<int>>arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        int x;
        vector<int>t;
        while(ss>>x) t.push_back(x);
        arr.push_back(t);
    }
    
    file.close();
    return arr;
}

int tsp(vector<vector<int>>&arr, vector<vector<int>>&dp, int mask, int curr, int N) {
    if(mask == (1<<N)-1) return arr[curr][0];
    if(dp[curr][mask]!=-1) return dp[curr][mask];

    int res = INT_MAX;

    for(int i=0;i<N;i++) {
        if((mask&(1<<i))==0) {
            res = min(res, arr[curr][i] + tsp(arr, dp, (mask|(1<<i)), i, N));
        }
    }
    return dp[curr][mask] = res;
}

void solve(vector<vector<int>>&arr) {
    int N = arr.size();
    vector<vector<int>>dp(N, vector<int>(1<<N, -1));
    int min_cost = tsp(arr, dp, 1, 0, N);
    cout<<"RES:: "<<min_cost<<"\n";
}

int main() {
    vector<vector<int>>arr = get_input("08");
    solve(arr);
    return 0;
}
