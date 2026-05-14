#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestBalanced(string s) {

    int maxLen = 0;

    for (char c1 = 'a'; c1 <= 'z'; c1++) {

        for (char c2 = c1 + 1; c2 <= 'z'; c2++) {

            unordered_map<int, int> firstIndex;

            int prefix = 0;

            firstIndex[0] = -1;

            int lastBreak = -1;

            for (int i = 0; i < s.size(); i++) {

                if (s[i] == c1)
                    prefix++;

                else if (s[i] == c2)
                    prefix--;

                else {

                    prefix = 0;

                    firstIndex.clear();

                    firstIndex[0] = i;

                    continue;
                }

                if (firstIndex.count(prefix)) {

                    maxLen = max(maxLen,
                        i - firstIndex[prefix]);
                }

                else {

                    firstIndex[prefix] = i;
                }
            }
        }
    }

    return maxLen;
}

int main() {

    string s;

    cin >> s;

    cout << longestBalanced(s);

    return 0;
}