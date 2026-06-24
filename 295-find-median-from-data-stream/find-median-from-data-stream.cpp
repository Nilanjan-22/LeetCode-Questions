class MedianFinder {
public:
    priority_queue<int,vector<int>, greater<int>> right;
    priority_queue<int> left;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(left.size()==0)left.push(num);
        else if(right.size()==0)right.push(num);
        else{
            if(left.size()>right.size())right.push(num);
            else{
                left.push(num);
            }

            while(left.top()>right.top()){
                int t1=left.top(),t2=right.top();
                left.pop();
                right.pop();
                left.push(t2);
                right.push(t1);
            }
        }
    }
    
    double findMedian() {
        if(left.size()==0 && right.size()==0)return 0.0;

        if(left.size()>right.size())return left.top();

        return ((double)left.top()+(double)right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */