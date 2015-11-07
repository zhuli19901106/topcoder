#include <vector>
using namespace std;

class PointDistance {
public:
    vector <int> findPoint(int x1, int y1, int x2, int y2) {
        int x3, y3;
        vector<int> ans;
        
        x3 = x2 + sign(x2 - x1);
        y3 = y2 + sign(y2 - y1);
        
        ans.push_back(x3);
        ans.push_back(y3);
        return ans;
    }
private:
    int sign(int x) {
        return x > 0 ? 1 : x < 0 ? -1 : 0;
    }
};