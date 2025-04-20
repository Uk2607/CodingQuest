#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

#define ll long long
#define ull unsigned long long

vector<vector<int>>  get_input(string file_name) {
    string file_path = "2022/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<int>> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line)) {
        vector<int>t;
        stringstream ss(line);
        int x;
        while(ss>>x) t.push_back(x);
        arr.push_back(t);
    }
    
    file.close();
    return arr;
}

void solve(vector<vector<int>>&arr) {
    int R = 20000, C = 100000;
    vector<vector<int>>pre(R+1, vector<int>(C+1, 0)), GRID(R, vector<int>(C, 0));
    int cnt = 0;
    for(vector<int>row: arr) {
        int x = row[0], y = row[1];
        int r = row[2], c = row[3];
        pre[x][y]+=1;
        if(x+r<=R) pre[x+r][y]-=1;
        if(y+c<=C) pre[x][y+c]-=1;
        if(x+r<=R && y+c<=C) pre[x+r][y+c]+=1;
    }
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(i>0) pre[i][j] += pre[i-1][j];
            if(j>0) pre[i][j] += pre[i][j-1];
            if(i>0 && j>0) pre[i][j] -= pre[i-1][j-1];
            if(pre[i][j]==0) cnt++;
        }
    }
    // for(int i=0;i<R;i++)
    //     for(int j=0;j<C;j++)
    //         GRID[i][j] = pre[i][j];

    cout<<"\nRES:: "<<cnt<<"\n\n";
    return;
}

int main() {
    vector<vector<int>> arr = get_input("07");
    solve(arr);
    return 0;
}
