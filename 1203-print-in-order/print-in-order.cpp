class Foo {
public:
    atomic<int> turn;
    Foo() {
        turn =0;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn=1;
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        while(turn!=1){

        }
        printSecond();
        turn =2;
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        while(turn!=2){

        }
        printThird();
        turn=0;
    }
};