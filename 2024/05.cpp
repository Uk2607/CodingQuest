#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

pair<vector<vector<int>>, vector<vector<int>>> get_input(string file_name) {
    string file_path = "2024/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<int>>arr;
    vector<vector<int>>routes;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return {arr, routes};
    }

    string line;
    bool flag = true;
    int idx = 0;
    map<string,int>mp;

    while (getline(file, line)) {
        if(line.length()==0) {
            flag=!flag;
            continue;
        }
        if(flag) {
            if(line[0]==' ') continue;
            stringstream ss(line);
            vector<string>t;
            string str;
            while(ss>>str) t.push_back(str);
            mp[t[0]] = idx++;
            vector<int>tt;
            for(int i=1;i<t.size();i++) tt.push_back(stoi(t[i]));
            arr.push_back(tt);
        } else {
            stringstream ss(line);
            vector<string>t;
            string str;
            while(ss>>str) t.push_back(str);
            vector<int>tt;
            for(int i=3;i<t.size();i+=2) tt.push_back(mp[t[i]]);
            routes.push_back(tt);
        }
    }
    
    file.close();
    return {arr, routes};
}

void solve(vector<vector<int>>arr, vector<vector<int>>routes) {
    for(vector<int>v: arr) {
        for(int x: v) cout<<x<<"\t"; 
        cout<<"\n";
    }
    for(vector<int>v: routes) {
        for(int x: v) cout<<x<<"->"; 
        cout<<"\n";
    }
    cout<<"\nRES:: "<<""<<"\n\n";
    return;
}

int main() {
    pair<vector<vector<int>>, vector<vector<int>>> ip = get_input("05");
    solve(ip.first, ip.second);
    return 0;
}
