#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<map>

using namespace std;

string  get_input(string file_name) {
    string file_path = "_2022/"+file_name+".in";
    ifstream file(file_path);

    string str;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return str;
    }

    file>>str;
    file.close();
    return str;
}

map<string, string>lookup = {
    {"0010", "A"}, {"0000", "E"}, {"0001", "T"}, {"0011", "I"}, {"0100", "N"},
    {"0101", "O"}, {"0110", "S"}, {"0111", "H"}, {"10000", "R"}, {"10001", "D"},
    {"10010", "L"}, {"10011", "U"}, {"10100", "C"}, {"10101", "M"}, {"10110", "F"},
    {"10111", "B"}, {"1100000", "F"}, {"1100001", "Y"}, {"1100010", "W"},
    {"1100011", "G"}, {"1100100", "P"}, {"1100101", "B"}, {"1100110", "V"},
    {"1100111", "K"}, {"1101000", "Q"}, {"1101001", "J"}, {"1101010", "X"},
    {"1101011", "Z"}, {"1110000", "0"}, {"1110001", "1"}, {"1110010", "2"},
    {"1110011", "3"}, {"1110100", "4"}, {"1110101", "5"}, {"1110110", "6"},
    {"1110111", "7"}, {"1111000", "8"}, {"1111001", "9"}, {"1111010", "_"},
    {"1111011", "."}, {"1111100", "'"}, {"1111111", "*"}
    };

string hexToBinary(const string& hex) {
    string binary;
    
    for (char hexChar : hex) {
        int value = (hexChar >= '0' && hexChar <= '9') ? (hexChar - '0') : (hexChar - 'a' + 10);
        binary += bitset<4>(value).to_string();
    }

    return binary;
}

void solve(string &hex_str) {
    string bin_str = hexToBinary(hex_str);
    for(int i=0;i<bin_str.length();i++) {
        ;
    }
    cout<<"\nRES:: "<<""<<"\n\n";
}

int main() {
    string arr = get_input("05");
    solve(arr);
    return 0;
}