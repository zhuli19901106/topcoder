#include <cstdio>
#include <string>
using namespace std;

class ExerciseMachine {
public:
    int getPercentages(string time) {
        int ans = 0;
        int i;
        int hh, mm, ss;
        sscanf(time.data(), "%2d:%2d:%2d", &hh, &mm, &ss);
        int sec = hh * 3600 + mm * 60 + ss;
        for (i = 1; i < 100; ++i) {
            if (sec % (100 / gcd(100, i)) == 0) {
                ++ans;
            }
        }
        return ans;
    }
private:
    int gcd(int x, int y) {
        return x ? gcd(y % x, x) : y;
    }
};