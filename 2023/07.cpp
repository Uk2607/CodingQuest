#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

pair<vector<pair<int,int>>, string> get_input(string file_name) {
    string file_path = "2023/"+file_name+".in";
    ifstream file(file_path);

    vector<pair<int,int>> arr;
    string moves;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return {arr, moves};
    }

    string line;
    int idx = 0;

    while (getline(file, line)) {
        idx++;
        if(idx%2==1) continue;
        if(idx==2) {
            stringstream ss(line);
            string coords;
            while(ss>>coords) {
                stringstream pairs(coords);
                int x, y;
                string t;
                bool flag = false;
                while(getline(pairs, t, ',')) {
                    if(!flag) x = stoi(t);
                    if(flag) y = stoi(t);
                    flag = !flag;
                }
                arr.push_back({x, y});
            }
        } else {
            moves = line;
        }
    }
    
    file.close();
    return {arr, moves};
}

void solve(vector<pair<int,int>>&fruits, string &moves) {
    for(pair<int,int>p: fruits) cout<<p.first<<", "<<p.second<<"\n";
    cout<<moves<<"\n";
    cout<<"\nRES::\n"<<""<<"\n";
}

int main() {
    auto[fruits, moves]= get_input("07");
    solve(fruits, moves);
    return 0;
}
