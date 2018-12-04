#include <queue>
#include "boost/thread.hpp"

namespace TrainingCampus2019
{

template<typename Data>
class ConcurrentQueue
{
    // Please add your own private members
//private:

public:
    // Constructor
    ConcurrentQueue(const int iMaxsize)
        : m_kiMaxSize(iMaxsize)
    {

    }

    // Destructor
    ~ConcurrentQueue()
    {

    }

    // push one element into the queue from the back
    // please print the number of elements on the console
    void Push(const Data& data)
    {
        boost::mutex::scoped_lock lock(m_mutex);

        do 
        {
            if (m_queueData.size() >= m_kiMaxSize)
            {
                m_condition.wait(lock);
            }
        } while (m_queueData.size() >= m_kiMaxSize);

        m_queueData.push(data);
        std::cout << "Thread ID: " << boost::this_thread::get_id() <<
            ". Push integer " << data << ".\n";
        m_condition.notify_one();

        return;
    }

    // judge whether the queue is empty
    bool Empty() const
    {
        boost::mutex::scoped_lock lock(m_mutex);

        return m_queueData.empty();
    }

    // try to pop one element
    // if the queue is empty, return false; 
    // otherwise return true and pop the front element to the output paramenter
    // please print the number of elements on the console
    bool TryPop(Data& popped_value)
    {
        boost::mutex::scoped_lock lock(m_mutex);

        if (m_queueData.empty())
        {
            return false;
        }

        popped_value = std::move(m_queueData.front());
        m_queueData.pop();
        std::cout << "Thread ID: " << boost::this_thread::get_id() <<
            ". Pop integer " << popped_value << ".\n";

        m_condition.notify_one()

        return true;
    }

    // wait for the queue to pop one element
    // if the queue is empty, wait till one element is pushed into the queue; 
    // if the queue is not empty, pop the front element to the output parameter
    // please print the number of elements on the console
    void WaitAndPop(Data& popped_value)
    {
        boost::mutex::scoped_lock lock(m_mutex);

        while (m_queueData.empty())
        {
            if (m_queueData.empty())
            {
                m_condition.wait(lock);
            }
        }

        popped_value = std::move(m_queueData.front());
        //std::swap(popped_value, m_queueData.front());
        m_queueData.pop();
        std::cout << "Thread ID: " << boost::this_thread::get_id() <<
            ". Pop integer " << popped_value << ".\n";

        m_condition.notify_one();

        return;
    }

private:
    std::queue<Data>            m_queueData;
    boost::mutex                m_mutex;
    boost::condition_variable   m_condition;
    const unsigned int          m_kiMaxSize;
};

}
