#include <cstring>
#include <string>
#include <vector>
using namespace std;

class ImageDithering {
public:
    int count(string dithered, vector<string> screen) {
        string &d = dithered;
        vector<string> &a = screen;
        int n = a.size();
        int m = n ? a[0].length() : 0;
        if (n == 0 && m == 0) {
            return 0;
        }
        
        int c[26];
        int dl = d.length();
        memset(c, 0, sizeof(c));
        int i;
        for (i = 0; i < dl; ++i) {
            c[d[i] - 'A'] = 1;
        }
        
        int ans = 0;
        int j;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                if (c[a[i][j] - 'A']) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};