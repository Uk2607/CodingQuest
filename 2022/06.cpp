#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

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
        vector<string>t;
        stringstream ss(line);
        string word;
        while(ss>>word) t.push_back(word);
        arr.push_back(t);
    }
    
    file.close();
    return arr;
}

void solve(vector<vector<string>>&arr) {
    int idx = 0;
    bool b = false;
    string res = "";
    vector<ll>val(12, 0LL);
    while(true) {
        string op = arr[idx][0];
        if(arr[idx].size()>2) {
            string target = arr[idx][1];
            string source = arr[idx][2];
            if(op=="CEQ") {
                int x, y;
                if(target.length()>1) x = stoll(target);
                else {
                    char c = target[0];
                    if(c>='A' && c<='L') x = val[c-'A'];
                    else x = c-'0';
                }
                if(source.length()>1) y = stoll(source);
                else {
                    char c = source[0];
                    if(c>='A' && c<='L') y = val[c-'A'];
                    else y = c-'0';
                }
                b = (x==y);
            } else if(op=="CGE") {
                int x, y;
                if(target.length()>1) x = stoll(target);
                else {
                    char c = target[0];
                    if(c>='A' && c<='L') x = val[c-'A'];
                    else x = c-'0';
                }
                if(source.length()>1) y = stoll(source);
                else {
                    char c = source[0];
                    if(c>='A' && c<='L') y = val[c-'A'];
                    else y = c-'0';
                }
                b = (x>=y);
            } else if(op=="ADD") {
                int tidx = target[0]-'A';
                if(source.length()>1) val[tidx] += stoll(source);
                else {
                    char c = source[0];
                    if(c>='A' && c<='L') val[tidx] += val[c-'A'];
                    else val[tidx] += c-'0';
                }
            } else if(op=="MOD") {
                int tidx = target[0]-'A';
                if(source.length()>1) val[tidx] %= stoll(source);
                else {
                    char c = source[0];
                    if(c>='A' && c<='L') val[tidx] %= val[c-'A'];
                    else val[tidx] %= c-'0';
                }
            } else if(op=="DIV") {
                int tidx = target[0]-'A';
                if(source.length()>1) val[tidx] /= stoll(source);
                else {
                    char c = source[0];
                    if(c>='A' && c<='L') val[tidx] /= val[c-'A'];
                    else val[tidx] /= c-'0';
                }
            } else if(op=="MOV") {
                int tidx = target[0]-'A';
                if(source.length()>1) val[tidx] = stoll(source);
                else {
                    char c = source[0];
                    if(c>='A' && c<='L') val[tidx] = val[c-'A'];
                    else val[tidx] = c-'0';
                }
            } else {
                cout<<op<<"\n";
                break;
            }
        } else if(arr[idx].size()>1) {
            string source = arr[idx][1];
            if(op=="JMP") {
                int x = stoll(source);
                idx += x;
                continue;
            } else if(op=="JIF") {
                int x = stoll(source);
                if(b) {
                    idx += x;
                    continue;
                }
            } else if(op=="OUT") {
                if(source.length()>1) res+=source;
                else {
                    char c = source[0];
                    if(c>='A' && c<='L') res+=to_string(val[c-'A']);
                    else res+=c;
                }
                res+=",";
            } else {
                cout<<op<<"\n";
                break;
            }
        } else {
            break;
        }
        ++idx;
    }
    cout<<"\nRES:: "<<res<<"\n\n";
}

int main() {
    vector<vector<string>> arr = get_input("06");
    solve(arr);
    return 0;
}
