#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton* GetInstance()
    {
        return m_instance;
    }
    //删除拷贝构造函数和赋值操作符, 以防止通过拷贝创建新的实例
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
private:
    static Singleton* m_instance;
    // 将默认构造函数设为私有,以防止直接调用构造函数创建新的实例
    Singleton() 
    {       
    }
};
Singleton* Singleton::m_instance = new Singleton;

int main()
{
    Singleton* s1 = Singleton::GetInstance();
    Singleton* s2 = Singleton::GetInstance();
    if (s1 == s2) 
    {
        cout << "s1 and s2 are the same instance." << endl;
    }
    else 
    {
        cout << "s1 and s2 are different instances." << endl;
    }
}
