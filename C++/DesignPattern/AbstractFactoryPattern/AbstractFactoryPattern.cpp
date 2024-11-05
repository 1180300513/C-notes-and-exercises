#include <iostream>
using namespace std;

/*抽象产品*/
//冰箱
class Fridge
{
public:
	virtual ~Fridge() {}
	virtual void FridgeFun() = 0;
};
//洗衣机
class Washer
{
public:
	virtual ~Washer() {}
	virtual void WasherFun() = 0;
};
/*抽象工厂*/
class Factory
{
public:
	virtual Fridge* CreateFridge() = 0;
	virtual Washer* CreateWasher() = 0;
};

/*具体产品类*/
//美的冰箱
class MideaFridge :public Fridge
{
public:
	void FridgeFun()
	{
		cout << "这是美的冰箱\n";
	}
};
//海尔冰箱
class HaierFridge :public Fridge
{
public:
	void FridgeFun()
	{
		cout << "这是海尔冰箱\n";
	}
};
//美的洗衣机
class MideaWasher :public Washer
{
public:
	void WasherFun()
	{
		cout << "这是美的洗衣机\n";
	}
};
//海尔洗衣机
class HaierWasher:public Washer
{
public:
	void WasherFun()
	{
		cout << "这是海尔洗衣机\n";
	}
};
/*具体工厂类*/
//美的工厂
class MideaFactory :public Factory
{
public:
	Fridge* CreateFridge() override
	{
		return new MideaFridge;
	}
	Washer* CreateWasher()	override
	{
		return new MideaWasher;
	}
};
//海尔工厂
class HaierFactory :public Factory
{
public:
	Fridge* CreateFridge() override
	{
		return new HaierFridge;
	}
	Washer* CreateWasher()	override
	{
		return new HaierWasher;
	}
};

int main()
{
	int Choice;
	cout << "选择你想要的工厂:1.美的 2.海尔:";
	cin >> Choice;
	Factory* MyFactory = nullptr;
	switch (Choice)
	{
	case 1:	
		MyFactory = new MideaFactory;
		break;
	case 2:
		MyFactory = new HaierFactory;
		break;		
	default:
		cout << "输入错误\n";
		exit;
	}
	MyFactory->CreateFridge()->FridgeFun();
	MyFactory->CreateWasher()->WasherFun();
	delete MyFactory;
	return 0;
}

