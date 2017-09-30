#include <iostream>

using namespace std;

template<typename T, int size>
class Stack
{
    T m_Buffer[size];
    T m_Top {-1};
public:
    
    Stack() = default;
    
    //copy contructor
    Stack( const Stack &obj)
    {
        m_Top = obj.m_Top;
        for( int i = 0; i <= m_Top; ++i)
        {
            m_Buffer[i] = obj.m_Buffer[i];
        }
    }
    
    void Push(T elem)
    {
        m_Buffer[++m_Top] = elem;
    }
    
    void Pop();
    
    const T& Top() const
    {
        return m_Buffer[m_Top];
    }
    
    bool isEmpty()
    {
        return m_Top == -1;
    }
    
    
    //factory method
    static Stack Create();
};


//NOTAION
//Stack( const Stack &obj)           - short hand notation
//Stack( const Stack<T, size> &obj)  - long hand notation

template <typename T, int size> // in templates arguments paramaters are part of the type
void Stack<T, size>::Pop()
{
    --m_Top;
}

template <typename T, int size>
Stack<T, size> Stack<T, size>::Create()
{
   return Stack<T, size>();
}

int main() {

    Stack<int, 10> s = Stack<int, 10>::Create(); //types and numbers have to match
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    
    /*
    while(!s.isEmpty())
    {
        cout<< s.Top() << endl;
        s.Pop();
    }
    cout << endl;
     */
    
    auto s2 (s);
    while(!s2.isEmpty())
    {
        cout<< s2.Top() << endl;
        s2.Pop();
    }
       
	return 0;
}
