/*
Hour Hand-> 360 In 12 hrs
Minute Hand-> 360 In 60 mins => 6 deg/min
So,
Minute Angle= 6*Minutes
Hour Angle= 30*Hours + (360/(12*60))*Minutes

Clock Angle Can Be Measured In Two Ways:
Angle= min(d,360-d)

Time Complexity: O(1)
*/
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr=30.0*(hour%12)+0.5*minutes;
        double mnt=6.0*minutes;
        double d=abs(hr-mnt);
        return min(d,360.0-d);
    }
};
