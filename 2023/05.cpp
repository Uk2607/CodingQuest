#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<vector<int>> get_input(string file_name) {
    string file_path = "2023/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<int>> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        vector<int>t;
        int x;
        while(ss>>x) t.push_back(x);
        arr.push_back(t);
    }
    
    file.close();
    return arr;
}

void solve(vector<vector<int>>&arr) {
    vector<vector<char>>grid(10, vector<char>(50, '.'));
    for(vector<int>v: arr) {
        int x = v[0], y = v[1], dy = v[2]-1, dx = v[3]-1;
        ;
    }

    cout<<"\nRES::\n";
    for(vector<char>v:grid) {
        for(char c:v) cout<<c;
        cout<<"\n";
    }
    return;
}

int main() {
    vector<vector<int>> arr = get_input("05");
    solve(arr);
    return 0;
}
