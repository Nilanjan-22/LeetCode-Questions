class ZeroEvenOdd {
private:
    int n;
    int i;
    mutex m;
    condition_variable cv;
public:
    ZeroEvenOdd(int n) {
        this->n = 2*n;
        i=1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(i<=n && i%2!=1)cv.wait(lock);
            if(i>n)break;
            printNumber(0);
            i++;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(i<=n && (i%2!=0 || (i/2)%2!=0))cv.wait(lock);
            if(i>n)break;
            printNumber(i/2);
            i++;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(i<=n &&(i%2!=0 || (i/2)%2!=1))cv.wait(lock);
            if(i>n)break;
            printNumber(i/2);
            i++;
            cv.notify_all();
        }
    }
};