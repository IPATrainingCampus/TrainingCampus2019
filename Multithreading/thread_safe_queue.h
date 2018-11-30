template<typename Data>
class ConcurrentQueue
{
    // Please add your own private members
//private:

public:
    // Constructor
    ConcurrentQueue(const int kiMaxSize);
    
    // Destructor
    virtual ~ConcurrentQueue();
    
    // push one element into the queue from the back
    // please print the number of elements on the console
    void Push(const Data& data);

    // judge whether the queue is empty
    bool Empty() const;

    // try to pop one element
    // if the queue is empty, return false; 
    // otherwise return true and pop the front element to the output paramenter
    // please print the number of elements on the console
    bool TryPop(Data& popped_value);

    // wait for the queue to pop one element
    // if the queue is empty, wait till one element is pushed into the queue; 
    // if the queue is not empty, pop the front element to the output parameter
    // please print the number of elements on the console
    void WaitAndPop(Data& popped_value);
};
