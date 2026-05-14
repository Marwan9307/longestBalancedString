#include <iostream>
#include <string>
using namespace std;

bool isBalancedSubstring(const string& s, int left, int right) {
    char c1 = 0, c2 = 0;
    int countC1 = 0, countC2 = 0;

    for (int i = left; i <= right; i++) {
        char currentChar = s[i];

        if (currentChar == c1) countC1++;
        else if (currentChar == c2) countC2++;
        else if (c1 == 0) { c1 = currentChar; countC1++; }
        else if (c2 == 0) { c2 = currentChar; countC2++; }
        else return false;
    }

    return (c1 != 0 && c2 != 0 && countC1 == countC2);
}

int  getLongestBalancedSubstring(const string &s, int start) {
    int n = s.size();
    if (start == n) return 0;

    int longestBalancedLength = 0;

    for (int end = start; end < n; end++) {
        if (isBalancedSubstring(s, start, end))
            longestBalancedLength = max(longestBalancedLength, end - start + 1); // end - start + 1 current substring length
    }

    return max(longestBalancedLength, getLongestBalancedSubstring(s, start + 1));
}

int longestBalancedSubstring(const string &s) {
    return getLongestBalancedSubstring(s, 0);
}

int main() {
    string s;
    cin >> s;

    cout << longestBalancedSubstring(s) << endl;
}