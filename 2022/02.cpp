#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<set>

using namespace std;

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
        stringstream ss(line);
        int x;
        vector<int>t;
        while(ss>>x) t.push_back(x);
        arr.push_back(t);
    }
    
    file.close();
    return arr;
}

void solve(vector<vector<int>>&arr) {
    set<int>winning_lottery = {12, 48, 30, 95, 15, 55, 97};
    int amnt = 0;
    for(vector<int>&lot: arr) {
        int cnt = 0;
        for(int x: lot) if(winning_lottery.find(x)!=winning_lottery.end()) cnt++;
        if(cnt<3) {cout<<"SKIP\n"; continue;}
        int won = pow(10,cnt-3);
        cout<<"WON: "<<won<<"\n";
        amnt+=won;
    }
    cout<<"\nRES:: "<<amnt<<"\n\n";
}

int main() {
    vector<vector<int>> arr = get_input("02");
    solve(arr);
    return 0;
}