class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x = (hour%12)* 30 + 0.5 * minutes;
        double y = minutes *6;
        double ans = abs(y-x);
        return min(ans,360-ans);
}};