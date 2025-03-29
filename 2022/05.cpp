#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<set>

using namespace std;

#define ll long long
#define ull unsigned long long

vector<vector<string>>  get_input(string file_name) {
    string file_path = "2022/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<string>> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        vector<string>t;
        string word;
        while(getline(ss, word, '|')) t.push_back(word);
        arr.push_back(t);
    }
    
    file.close();
    return arr;
}

void solve(vector<vector<string>>&arr) {
    for(vector<string>row: arr) {
        for(string str: row) cout<<str<<"|";
        cout<<"\n";
    }
    cout<<"\nRES:: "<<""<<"\n\n";
}

int main() {
    vector<vector<string>> arr = get_input("05");
    solve(arr);
    return 0;
}
