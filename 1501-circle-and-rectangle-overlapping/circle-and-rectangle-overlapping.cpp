class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX = max(x1, min(x2,xCenter));
        int closestY = max(y1, min(y2,yCenter));

        int distX = abs(xCenter-closestX);
        int distY = abs(yCenter-closestY);

        if(distX*distX + distY*distY <= radius*radius)return true;
        return false;
    }
};