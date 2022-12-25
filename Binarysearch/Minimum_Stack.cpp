#include <vector>
#include <stack>

using namespace std;

/* My solution - Faster than 3% lol (didn't knpw std::stack<T> is allowed) */
class MinimumStack 
{
    public:
    int m_min = std::numeric_limits<int>::min();
    vector<int> m_vals;
    int m_size;

    MinimumStack() 
    {    
        m_size = 0;
    }

    void append(int val) 
    {
        if (m_size == 0) m_min = val;
        else if (val < m_min) m_min = val;

        m_vals.push_back(val);
        ++m_size;
    }

    int peek() 
    {
        return m_vals.back();
    }

    int min() 
    {
        return m_min;
    }

    int pop() 
    {
        int val = m_vals.back();
        m_vals.pop_back();
        --m_size;

        int newMin = m_vals[m_size - 1];
        for (int i = 0; i < m_size; ++i)
        {
            int val = m_vals[i];
            if (val < newMin) newMin = val;
        }
        m_min = newMin;

        return val;
    }
};

/* Better solution - Faster than 95% */
class MinimumStack {
    public:
    stack<int> s;
    int mini;
    MinimumStack() {
        mini = -1;
    }

    void append(int val) {
        if (s.empty() || mini == -1) {
            s.push(val);
            mini = val;
        } else if (val < mini) {
            s.push(2 * val - mini);
            mini = val;
        } else {
            s.push(val);
        }
    }

    int peek() {
        if (s.top() < mini) {
            return mini;
        }
        return s.top();
    }

    int min() {
        return mini;
    }

    int pop() {
        if (s.top() < mini) {
            int k = 2 * mini - s.top();
            s.pop();
            int ret = mini;
            mini = k;
            return ret;
        }
        int a = s.top();
        s.pop();
        return a;
    }
};