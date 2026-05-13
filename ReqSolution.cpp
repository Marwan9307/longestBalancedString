#include <iostream>
#include <string>
using namespace std;

bool isBalanced(const string& s, int l, int r) {
    char c1 = 0, c2 = 0;
    int cnt1 = 0, cnt2 = 0;

    for (int i = l; i <= r; i++) {
        char ch = s[i];

        if (ch == c1) cnt1++;
        else if (ch == c2) cnt2++;
        else if (c1 == 0) { c1 = ch; cnt1++; }
        else if (c2 == 0) { c2 = ch; cnt2++; }
        else return false;
    }

    return (c1 != 0 && c2 != 0 && cnt1 == cnt2);
}

int solve(string s, int start) {
    int n = s.size();
    if (start == n) return 0;

    int best = 0;

    for (int end = start; end < n; end++) {
        if (isBalanced(s, start, end))
            best = max(best, end - start + 1);
    }

    return max(best, solve(s, start + 1));
}

int longestBalanced(string s) {
    return solve(s, 0);
}

int main() {
    string s;
    cin >> s;

    cout << longestBalanced(s) << endl;
}