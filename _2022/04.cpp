#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

vector<vector<string>> get_input(string file_name) {
    string file_path = "_2022/"+file_name+".in";
    ifstream file(file_path);

    vector<vector<string>>arr;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return arr;
    }

    string line;

    while(getline(file, line)) {
        stringstream ss(line);
        string x;
        vector<string>t;
        while(ss>>x) t.push_back(x);
        arr.push_back(t);
    }
    file.close();
    return arr;
}

int to_bin(string str) {
    int mul = 0, n=str.length(), res = 0;
    for(int i=n-1;i>=0;i--) {
        res += pow(16, mul)*((str[i]>='a' && str[i]<='f')?str[i]-'a'+10:str[i]-'0');
        mul++;
    }
    return res;
}

void solve(vector<vector<string>>&arr) {
    int r = arr.size(), c = arr[0].size();
    vector<vector<int>>arri(r, vector<int>(c, INT_MAX));
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(i==r-1 && j==c-1) continue;
            int x = to_bin(arr[i][j]);
            arri[i][j] = x;
        }
    }
    vector<int>rowSum(r-1, 0), colSum(c-1, 0);
    for(int i=0;i<r-1;i++) {
        for(int j=0;j<c-1;j++) {
            rowSum[i] = (rowSum[i] + arri[i][j])%256;
            colSum[j] = (colSum[j] + arri[i][j])%256;
        }
    }
    int x=-1, y=-1, rSum = 0, cSum = 0;
    for(int i=0;i<r-1;i++) if(rowSum[i]!=arri[i][c-1]) {x=i; break;}
    for(int i=0;i<c-1;i++) if(colSum[i]!=arri[r-1][i]) {y=i; break;}
    rSum = rowSum[x];
    cSum = colSum[y];

    int diffR = (rSum-arri[x][c-1])<0?(rSum-arri[x][c-1]+256):(rSum-arri[x][c-1]);
    int diffC = (cSum-arri[r-1][y])<0?(cSum-arri[r-1][y]+256):(cSum-arri[r-1][y]);
    int correctR = arri[x][y] - diffR;
    int correctC = arri[x][y] - diffC;

    cout<<"\nRES:: "<<arri[x][y]*correctR<<"\n\n";
}

int main() {
    vector<vector<string>>arr = get_input("04");
    solve(arr);
    return 0;
}
