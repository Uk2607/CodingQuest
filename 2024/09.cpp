#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<vector<string>> get_input(string file_name) {
    string file_path = "2024/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<string>>arr(2);

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    bool flag = true;
    string line;

    while (getline(file, line)) {
        if(line.length()==0) {
            flag=!flag;
            continue;
        }
        if(flag) arr[0].push_back(line);
        else arr[1].push_back(line);
    }
    
    file.close();
    return arr;
}

void solve(vector<vector<string>>grid) {
    for(vector<string>floor: grid) {
        for(string row: floor) cout<<row<<"\n";
        cout<<"\n";
    }
    cout<<"\nRES:: "<<""<<"\n\n";
    return;
}

int main() {
    vector<vector<string>> arr = get_input("09");
    solve(arr);
    return 0;
}
