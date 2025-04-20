#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<int> get_input(string file_name) {
    string file_path = "2023/"+file_name+".in";
    ifstream file(file_path);

    vector<int> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line)) {
        arr.push_back(stoi(line));
    }
    
    file.close();
    return arr;
}

string to_bin(int x) {
    string b = "";
    while(x>0) {
        b = (x%2==1?'1':'0') + b;
        x>>=1;
    }
    while (b.length()<16) b = '0'+b;
    return b;
}

void solve(vector<int>&arr) {
    int sum = 0, cnt = 0;
    for(int x: arr) {
        string bin_str = to_bin(x);
        cout<<x<<"\t:: "<<bin_str;
        if(bin_str[0]=='1') {
            int y = x-32768; // 32768 = 2^15 remove parity bit
            cout<<" : "<<y;
            sum += y;
            cnt++;
        }
        cout<<"\n";
    }
    cout<<"\nRES:: "<<sum/cnt<<"\n\n";
    return;
}

int main() {
    vector<int> arr = get_input("02");
    solve(arr);
    return 0;
}
