#include<iostream>
using namespace std;

int getLongestBalancedSubstring(const string &s) {
    int n = s.length(),  longestBalancedSubstring = 0;

    for (int start = 0; start < n; start++) {
        char c1 = 0, c2 = 0;
        int countC1 = 0, countC2 = 0;

        for (int end = start; end < n; end++) {
            char currentChar = s[end];

            if      (currentChar == c1)  countC1++;
            else if (currentChar == c2)  countC2++;
            else if (c1 == 0)  { c1 = currentChar; countC1++; }
            else if (c2 == 0)  { c2 = currentChar; countC2++; }
            else               break;   

            if (c1 && c2 && countC1 == countC2)
                longestBalancedSubstring = max(longestBalancedSubstring, end - start + 1);
        }
    }
    return longestBalancedSubstring;
}

int main() {
    string s;
    cin >> s;
    cout << getLongestBalancedSubstring(s) << endl;
    return 0;
}


