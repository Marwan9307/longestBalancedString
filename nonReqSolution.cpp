#include<iostream>
using namespace std;

int getLongestBalancedSubstring(const string& text) {
    int n = text.length(), best = 0;

    for (int start = 0; start < n; start++) {
        char c1 = 0, c2 = 0;
        int cnt1 = 0, cnt2 = 0;

        for (int end = start; end < n; end++) {
            char ch = text[end];

            if      (ch == c1)  cnt1++;
            else if (ch == c2)  cnt2++;
            else if (c1 == 0)  { c1 = ch; cnt1++; }
            else if (c2 == 0)  { c2 = ch; cnt2++; }
            else               break;   

            if (c1 && c2 && cnt1 == cnt2)
                best = max(best, end - start + 1);
        }
    }
    return best;
}

int main() {
    string text;
    cin >> text;
    cout << getLongestBalancedSubstring(text) << endl;
    return 0;
}

