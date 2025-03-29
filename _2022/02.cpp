#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<set>
#include<map>

using namespace std;

vector<string> get_input(string file_name) {
    string file_path = "_2022/"+file_name+".in";
    ifstream file(file_path);

    vector<string>words;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return words;
    }

    string line;

    while(getline(file, line)) {
        words.push_back(line);
    }
    file.close();
    return words;
}

void solve(vector<string>&words, vector<pair<string,string>>&guesses) {
    vector<string>valid_words = words;
    // set<string>probable;
    for(auto [guess, colors]: guesses) {
        vector<string>next_valid;
        for(string word: valid_words) {
            bool is_valid = true;
            unordered_map<char, int>letter_count;
            for(char c: word) letter_count[c]++;
            for(int i=0;i<7;i++) {
                if(colors[i]=='G') {
                    if(word[i]!=guess[i]) {
                        is_valid = false;
                        break;
                    }
                    letter_count[guess[i]]--;
                } else if(colors[i]=='Y') {
                    if(word[i]==guess[i] || letter_count[guess[i]]<=0) {
                        is_valid = false;
                        break;
                    }
                    letter_count[guess[i]]--;
                }
            }
            if(is_valid) {
                for(int i=0;i<7;i++) {
                    if(colors[i]=='G') {
                        bool used_elsewhere = false;
                        for(int j=0;j<7;j++) {
                            if(j!=i && (colors[j]=='G' || colors[j]=='Y') && guess[j]==guess[i]) {
                                used_elsewhere = true;
                                break;
                            }
                        }
                        if(!used_elsewhere && letter_count[guess[i]]>0) {
                            is_valid = false;
                            break;
                        }
                    }
                }
            }
            if(is_valid) {
                next_valid.push_back(word);
            }
        }
        valid_words = move(next_valid);
        for(string word: valid_words) cout<<word<<" ";
        cout<<"\n\n";
    }
    words = move(valid_words);
    cout<<"\nRES:: "<<""<<"\n";
}

int main() {
    vector<string>words = get_input("02");

    // vector<pair<string,string>>ex = {{"hapless", "GBYYYBB"}, {"jackpot", "BBBBYBB"}, {"fullest", "YYGYYBB"}};
    // solve(words, ex);

    // Not working for this case
    vector<pair<string,string>>guesses = {{"keyless", "YYBBYYG"}, {"society", "YGYYYBB"}, {"phobias", "BBGBGBG"}};  // _oo_i_s    k,e,c -> cookies
    solve(words, guesses);
    return 0;
}
