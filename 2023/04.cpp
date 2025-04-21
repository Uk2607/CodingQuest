#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<string> get_input(string file_name) {
    string file_path = "2023/"+file_name+".in";
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

int hex_to_dec(string hx) {
    int mul = 0, dec = 0;
    for(int i=hx.length()-1;i>=0;i--) {
        int x;
        if(hx[i]>='0' && hx[i]<='9') x = hx[i]-'0';
        else x = hx[i]-'a'+10;
        dec += (pow(16, mul)*x);
        mul++;
    }
    return dec;
}

string dec_to_hex(int dec) {
    if (dec == 0) return "0"; // Handle the case for 0 explicitly
    string hx = "";
    while (dec > 0) {
        int r = dec % 16;
        hx = (r<10?to_string(r):string(1, char(r-10+'a'))) + hx;
        dec /= 16;
    }
    while(hx.length()<2) hx = "0"+hx;
    return hx;
}

void solve(vector<string>&arr) {
    map<int, string>mp;
    for(string str: arr) {
        if(str.substr(0, 4)!="5555") continue;
        string hex_str = str.substr(4, 8); // ship number
        string seq_no = str.substr(12, 2);
        string checksum = str.substr(14, 2);
        string payload = str.substr(16);
        int sum = 0;
        for(int i=0;i<payload.length();i+=2) {
            string hx = payload.substr(i, 2);
            int x = hex_to_dec(hx);
            sum+=x;
        }
        sum %= 256;
        if(checksum!=dec_to_hex(sum)) continue;
        mp[stoi(seq_no)] = payload;
    }
    string res = "", msg = "";
    for(auto it: mp) msg+=it.second;
    for(int i=0;i<msg.length();i+=2) {
        int x = hex_to_dec(msg.substr(i, 2));
        res.push_back(x);
    }
    cout<<"\nRES:: "<<res<<"\n\n";
    return;
}

int main() {
    vector<string> arr = get_input("04");
    solve(arr);
    return 0;
}
