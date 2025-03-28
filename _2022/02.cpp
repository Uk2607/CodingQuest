#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<set>

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
    string correct_word = "";
    set<string>probable, wrong;
    for(auto [guess, result]: guesses) {
        ;
    }
    cout<<"\nRES:: "<<correct_word<<"\n";
}

int main() {
    vector<string>words = get_input("02");
    vector<pair<string,string>>guesses = {{"keyless", "YYBBYYG"}, {"society", "YGYYYBB"}, {"phobias", "BBGBGBG"}};
    solve(words, guesses);
    return 0;
}