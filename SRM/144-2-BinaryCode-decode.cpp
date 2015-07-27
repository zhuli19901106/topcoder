#include <string>
#include <vector>
using namespace std;

class BinaryCode {
public:
    vector<string> decode(string message) {
        string &s = message;
        vector<string> ans;
        ans.push_back(dec(s, 0));
        ans.push_back(dec(s, 1));
        return ans;
    }
private:
    string dec(string &s, int b0) {
        string res = "";
        int n = s.length();
        if (n == 1) {
            return s[0] == b0 + '0' ? s : "NONE";
        }
        int n1, n2, n3;
        n1 = 0;
        n2 = b0;
        res.push_back(n2 + '0');
        int i;
        for (i = 1; i < n; ++i) {
            n3 = s[i - 1] - '0' - n1 - n2;
            if (n3 < 0 || n3 > 1) {
                return "NONE";
            }
            res.push_back(n3 + '0');
            n1 = n2;
            n2 = n3;
        }
        if (s[n - 1] - '0' != n1 + n2) {
            return "NONE";
        }
        
        return res;
    }
};