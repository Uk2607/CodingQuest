#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

map<string, vector<pair<int, string>>> get_input(string file_name) {
    string file_path = "2023/"+file_name+".in";
    ifstream file(file_path);

    map<string, vector<pair<int, string>>>mp;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return mp;
    }

    string line;

    while (getline(file, line)){
        string src = line.substr(0, 3);
        string dest_list = line.substr(7);
        stringstream ss(dest_list);

        vector<pair<int, string>>dest;
        string pr;
        while(ss>>pr) {
            string st = pr.substr(0, 3);
            int cost = stoi(pr.substr(4));
            dest.push_back({cost, st});
        }
        mp[src] = dest;
    }
    
    file.close();
    return mp;
}

void solve(map<string, vector<pair<int, string>>>&mp) {
    string src = "TYC", dest = "EAR";
    int stop_time = 600;
    for(auto it: mp) {
        cout<<it.first<<" => ";
        for(auto [cost, st]: it.second) cout<<st<<":"<<cost<<" ";
        cout<<"\n";
    }
    cout<<"RES:: "<<""<<"\n";
}

int main() {
    map<string, vector<pair<int, string>>>mp = get_input("10");
    solve(mp);
    return 0;
}
