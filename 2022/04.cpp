#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<set>

using namespace std;

#define ll long long
#define ull unsigned long long

vector<string>  get_input(string file_name) {
    string file_path = "2022/"+file_name+".in";
    ifstream file(file_path);

    vector<string> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line)) {
        arr.push_back(line);
    }
    
    file.close();
    return arr;
}

void solve(vector<string>&arr) {
    cout<<"\nRES:: "<<""<<"\n\n";
}

int main() {
    vector<string> arr = get_input("04");
    solve(arr);
    return 0;
}
