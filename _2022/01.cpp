#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

pair<vector<vector<int>>, vector<pair<int,int>>> get_input(string file_name) {
    string file_path = "_2022/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<int>>arr;
    vector<pair<int,int>>moves;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return {arr, moves};
    }

    string line;

    while(getline(file, line)) {
        stringstream ss(line);
        int x;
        vector<int>t;
        while(ss>>x) t.push_back(x);
        if(t.size()!=2) arr.push_back(t);
        else moves.push_back({t[0], t[1]});
    }
    file.close();
    return {arr, moves};
}

void solve(vector<vector<int>>grid, vector<pair<int,int>>moves) {
    ;
    cout<<"\nRES:: "<<""<<"\n";
}

int main() {
    pair<vector<vector<int>>, vector<pair<int,int>>> ip = get_input("01");
    solve(ip.first, ip.second);
    return 0;
}