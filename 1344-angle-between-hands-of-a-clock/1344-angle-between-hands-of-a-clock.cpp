class Solution {
public:
    double angleClock(int hour, int minutes) {
        float move_byminute=minutes*6;
        float move_byhour=minutes*0.5+hour%12*30;

        float ans=min(abs(move_byhour-move_byminute),360-abs(move_byhour-move_byminute));
        return ans;
    }
};