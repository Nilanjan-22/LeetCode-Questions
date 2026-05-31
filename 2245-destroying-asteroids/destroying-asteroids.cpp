class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<asteroids.size();i++){
            if(mass<asteroids[i])return false;
            if(mass<=INT_MAX-asteroids[i])mass+=asteroids[i];
        }
        return true;
    }
};