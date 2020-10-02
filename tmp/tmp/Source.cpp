#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    // Complete this function
    vector<int> result;
    int tmp, cnt=0;
    stringstream ss(str);
    char ch;

    while (ss >> tmp) {
        result.push_back(tmp);
        ss >> ch;
        cnt++;
    }
    if (cnt == 0) {
        cout << "invalid input!" << endl;
    }
    return result;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}