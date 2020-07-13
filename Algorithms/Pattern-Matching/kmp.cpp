#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Prefix(vector<int> &pi, const string &pattern) {
    int n = pattern.size();

    pi[0] = 0; // always zero
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        // find the character with match with character at
        // pattern[i]
        // else set j = 0
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }

        //incase pattern mathes, increment j++
        if (pattern[j] == pattern[i])
            j++;

        pi[i] = j;
    }
}


vector<int> KMP(const string &text, const string &pattern) {
    int text_len = text.size();
    int pat_len = pattern.size();
    vector<int> pi(pat_len);

    Prefix(pi, pattern);
    vector<int> result;

    for (int i = 0, j = 0; i < text_len; i++) {

        while (j > 0 && pattern[j] != text[i]) {
            j = pi[j - 1];
        }

        if (pattern[j] == text[i])
            j++;

        if (j == pat_len) {
            result.push_back(i - pat_len  + 1);
        }
    }

    return result;
}

int main()
{
    string text;
    cout << "Text : ";
    cin >> text;
    string pattern;
    cout << "Pattern : ";
    cin >> pattern;
    auto result = KMP(text, pattern);
    for(auto r : result) {
        cout << "Found at : " << r << "\n";
    }
}
