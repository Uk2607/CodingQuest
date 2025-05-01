#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

vector<string> get_input(string file_name) {
    string file_path = "2024/"+file_name+".in";
    ifstream file(file_path);

    vector<string> arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while (getline(file, line)) arr.push_back(line);
    
    file.close();
    return arr;
}

int hex_to_dec(string hx) {
    int mul = 0, dec = 0;
    for(int i=hx.length()-1;i>=0;i--) {
        int x;
        if(hx[i]>='a' && hx[i]<='f') x = hx[i]-'a'+10;
        else if(hx[i]>='A' && hx[i]<='F') x = hx[i]-'A'+10;
        else x = hx[i]-'0';
        dec += (pow(16, mul)*x);
        mul++;
    }
    return dec;
}

void solve(vector<string>&arr) {
    int network_traffic = 0, wifi_traffic = 0;
    for(string hex_str: arr) {
        string byte_size_str = hex_str.substr(4, 4);
        string src_ip_hex = hex_str.substr(24, 8);
        string dest_ip_hex = hex_str.substr(32, 8);
        vector<int>src_ip;
        vector<int>dest_ip;
        int byte_size = hex_to_dec(byte_size_str);
        for(int i=0;i<8;i+=2) {
            src_ip.push_back(hex_to_dec(src_ip_hex.substr(i, 2)));
            dest_ip.push_back(hex_to_dec(dest_ip_hex.substr(i, 2)));
        }

        if((src_ip[0]==192 && src_ip[1]==168) || (dest_ip[0]==192 && dest_ip[1]==168)) network_traffic += byte_size;
        if(src_ip[0]==10 && src_ip[1]==0 || (dest_ip[0]==10 && dest_ip[1]==0)) wifi_traffic += byte_size;
    }
    cout<<"\nRES:: "<<network_traffic<<"/"<<wifi_traffic<<"\n\n";
    return;
}

int main() {
    vector<string> arr = get_input("02");
    solve(arr);
    return 0;
}
