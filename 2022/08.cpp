#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

#define ll long long
#define ull unsigned long long

string get_input(string file_name) {
    string file_path = "2022/"+file_name+".in";
    ifstream file(file_path);

    string msg;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return msg;
    }

    getline(file, msg);
    
    file.close();
    return msg;
}

void solve(string char_set, string key, string msg) {
    map<char, int>mp;
    int st_len = char_set.length();
    for(int i=0;i<st_len;i++) mp[char_set[i]] = i;
    for(int i=0;i<msg.length();i++) {
        if(mp.count(msg[i])) {
            char k = key[i%key.length()];
            if(mp.count(k)) {
                int mv = mp[k]+1;
                int idx = mp[msg[i]];
                msg[i] = char_set[((idx-mv)%st_len+st_len)%st_len];
            }
        }
    }
    cout<<"\nRES:: "<<msg<<"\n\n";
    return;
}

int main() {
    string msg = get_input("08");
    string char_set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,;:?! '()";
    string key = "Roads? Where We're Going, We Don't Need Roads.";
    solve(char_set, key, msg);
    return 0;
}
