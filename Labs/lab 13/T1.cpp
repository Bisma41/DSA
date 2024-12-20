#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string freqSort(string s) {
    vector<pair<char, int>> freq(26, { 0, 0 });

    for (char c : s) {
        freq[c - 'A'].first = c; 
        freq[c - 'A'].second++;
    }

    sort(freq.begin(), freq.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return (a.second == b.second) ? a.first < b.first : a.second < b.second;
        });

    string result;
    for (auto& p : freq) {
        for (int i = 0; i < p.second; ++i) {
            result += p.first;
        }
    }

    return result;
}

int main() {
    string s1 = "DACDACCDCBC";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << freqSort(s1) << endl;

    string s2 = "ZXZXYYZZYYXYYZZZWWQQQQQVVVVVVVVVWXX";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << freqSort(s2) << endl;

    return 0;
}
