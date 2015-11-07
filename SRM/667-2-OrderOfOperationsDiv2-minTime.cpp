// O(n^2 * log(n))
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int convert(const string &s) {
    int m = s.length();
    int val = 0;
    int i;
    for (i = 0; i < m; ++i) {
        if (s[i] == '0') {
            continue;
        }
        val |= (1 << i);
    }
    return val;
}

int countOne(int x) {
    int c = 0;
    while (x) {
        x = x & (x - 1);
        ++c;
    }
    return c;
}

bool comp(const int &x, const int &y)
{
    int cx = countOne(x);
    int cy = countOne(y);
    if (cx != cy) {
        return cx > cy;
    } else {
        return x > y;
    }
}

class OrderOfOperationsDiv2 {
public:
    int minTime(vector<string> s) {
        vector<int> a;
        int n = s.size();
        int i;
        for (i = 0; i < n; ++i) {
            a.push_back(convert(s[i]));
        }
        
        int mask = 0;
        int ans = 0;
        int cc;
        int val;
        int j;
        for (i = 0; i < n; ++i) {
            sort(a.begin(), a.end(), comp);
            val = a.back();
            a.pop_back();
            cc = countOne(val ^ (val & mask));
            ans += cc * cc;
            mask |= val;
            for (j = 0; j < n - 1 - i; ++j) {
                a[i] ^= (a[i] & mask);
            }
        }
        
        return ans;
    }
};