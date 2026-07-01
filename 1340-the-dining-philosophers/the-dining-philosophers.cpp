
class DiningPhilosophers {
public:
    // 1. Added std:: and corrected the array syntax
    mutex m;

    binary_semaphore spoons[5] = {
        binary_semaphore{1}, 
        binary_semaphore{1}, 
        binary_semaphore{1}, 
        binary_semaphore{1}, 
        binary_semaphore{1}
    };

    DiningPhilosophers() {}

    // 2. Added std:: to the function types
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
	
            {
                lock_guard<mutex> lock(m);
                spoons[philosopher % 5].acquire();
                spoons[(philosopher + 1) % 5].acquire();
            }

            pickLeftFork();
            pickRightFork();
            
            eat();
            
            putLeftFork();
            spoons[(philosopher + 1) % 5].release();
            putRightFork();
            spoons[philosopher % 5].release();
       
    }   
};
