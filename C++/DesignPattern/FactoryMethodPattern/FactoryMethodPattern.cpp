#include <iostream>

using namespace std;

//抽象产品类
class Shape
{
public: 
    virtual void Draw() = 0;
};

//具体产品类
class Line :public Shape
{
public:
    void Draw() override
    {
        printf("画了一条直线");
    }
};

class Circle :public Shape
{
public:
    void Draw() override
    {
        printf("画了一个圆");
    }
};

class Rectangle :public Shape
{
public:
    void Draw() override
    {
        printf("画了一个矩形");
    }
};

//抽象工厂类
class Factory
{
public:
    virtual Shape* GetShape() = 0;
};

//具体工厂类
class LineFactory :public Factory
{
public:
    Shape* GetShape() override
    {
        return new Line;
    }
};

class CircleFactory :public Factory
{
public:
    Shape* GetShape() override
    {
        return new Circle;
    }
};

class RectFactory :public Factory
{
public:
    Shape* GetShape() override
    {
        return new Rectangle;
    }
};


int main()
{
    string input;
    Factory* MyFactory = nullptr;
    while (1)
    {
        cin >> input;
        if (input == "Line")
        {
            MyFactory = new LineFactory;
            MyFactory->GetShape()->Draw();
            cout<<endl;
            delete MyFactory;
        }
        else if (input == "Rect")
        {
            MyFactory = new RectFactory;
            MyFactory->GetShape()->Draw();
            cout << endl;
            delete MyFactory;
        }
        else if (input == "Circle")
        {
            MyFactory = new CircleFactory;
            MyFactory->GetShape()->Draw();
            cout << endl;
            delete MyFactory;
        }
    }  
}

