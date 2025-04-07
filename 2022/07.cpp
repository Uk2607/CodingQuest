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
    cout<<"\nRES:: "<<""<<"\n\n";
}

int main() {
    vector<vector<int>> arr = get_input("07");
    solve(arr);
    return 0;
}
