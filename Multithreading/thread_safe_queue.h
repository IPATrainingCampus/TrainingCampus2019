template<typename Data>
class ConcurrentQueue
{
    // Please add your own private members
//private:

public:
    // Constructor
    // kiMaxSize is the capacity of the queue
    ConcurrentQueue(const int kiMaxSize);
    
    // Destructor
    virtual ~ConcurrentQueue();
    
    // push one element into the queue from the back
    // if the queue is full, wait till one element is popped out
    // please print the number of elements on the console
    void Push(const Data& data);

    // judge whether the queue is empty
    bool Empty() const;

    // pop one element
    // the output argument popped_value should be assigned the element popped
    // if the queue is empty, wait till one element is pushed into the queue;
    // if the queue is not empty, pop the front element to the output parameter
    // please print the number of elements on the console
    void Pop(Data& popped_value);
};
