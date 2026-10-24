class Solution {
public:
    int extractDate(string& s, vector<int>& monthlyDays){
        string month="", days="";
        month.push_back(s[0]);
        month.push_back(s[1]);
        days.push_back(s[3]);
        days.push_back(s[4]);

        int monthOffset = monthlyDays[stoi(month)-1];
        int dayOffset = stoi(days);
        return monthOffset+dayOffset;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> monthlyDays;
        int days=0;
        for(int i=1;i<=12;i++){
            monthlyDays.push_back(days);
            if(i==2)days+=28;
            else if(i==4 || i==6 || i==9 || i==11)days+=30;
            else days+=31;
        }

        int arriveDate = max(extractDate(arriveAlice,monthlyDays), extractDate(arriveBob,monthlyDays));
        int leaveDate = min(extractDate(leaveAlice,monthlyDays), extractDate(leaveBob,monthlyDays));

        return max(0,leaveDate-arriveDate+1);


    }
};