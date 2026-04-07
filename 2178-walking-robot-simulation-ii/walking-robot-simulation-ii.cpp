class Robot {
public:
    int w,h;
    long long dist=0;
    int cf=0;
    bool rot=false;
    Robot(int width, int height) {
        w=width;
        h=height;
        cf=2*(w-1+h-1);
    }
    
    void step(int num) {
        dist+=num;
        if(dist>=cf)rot=true;
        dist%=cf;
    }
    
    vector<int> getPos() {
        int t=dist;
        if(t<w)return {t,0};
        else if(t<w+h-1)return {w-1,t-w+1};
        else if(t<2*w+h-2)return {w-1-(t-w-h+2),h-1};
        return {0,h-1-(t-2*w-h+3)};
    }
    
    string getDir() {
        if(dist==0 && rot)return "South";
        else if(dist<w)return "East";
        else if(dist<w+h-1)return "North";
        else if(dist<2*w+h-2)return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */