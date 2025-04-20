#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<vector<string>> get_input(string file_name) {
    string file_path = "2023/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<string>> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line)) {
        vector<string>t;
        stringstream ss(line);
        string x;
        while(ss>>x) t.push_back(x);
        arr.push_back(t);
    }
    
    file.close();
    return arr;
}

void solve(vector<vector<string>>&arr) {
    map<string, long long>mp;
    for(vector<string>row: arr) mp[row[2]] += stoll(row[1]);

    long long total_p = 1;
    for(auto it: mp) total_p *= (it.second%100LL);
    cout<<"\nRES:: "<<total_p<<"\n\n";
    return;
}

int main() {
    vector<vector<string>> arr = get_input("01");
    solve(arr);
    return 0;
}
