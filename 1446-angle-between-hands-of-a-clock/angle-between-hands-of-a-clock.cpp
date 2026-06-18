class Solution {
public:
    double angleClock(int hour, int minutes) {
        double totalAngle=360;
        double inc=30;
        map<int,double> angles;
        angles[12]=(double)0;
        angles[1]=inc;
        for(int i=2;i<12;i++){
            angles[i]=angles[i-1]+inc;
        }

        double start=angles[hour] + (inc*(double)minutes)/(double)60;
        double end = (totalAngle*(double)minutes)/(double)60;

        double angle = abs(end-start);
        angle= min(angle, totalAngle-angle);

        return angle;

    }
};