#include <iostream>
using namespace std;

/*产品类*/
class House
{
public:
    void SetWalls(const string& walls)
    {
        m_walls = walls;
    }
    void SetDoors(const string& doors)
    {
        m_doors = doors;
    }
    void SetRoof(const string& roof)
    {
        m_roof = roof;
    }
    void SetWindows(const string& windows)
    {
        m_windows = windows;
    }
    void ShowHouse()
    {
        cout << "这间房子的墙是" << m_walls << ",门是" << m_doors
            << ",屋顶是" << m_roof << ",窗户是" << m_windows << endl;
    }
private:
    string m_walls;
    string m_doors;
    string m_roof;
    string m_windows;
};
/*抽象建造者*/
class HouseBuilder
{
public:
    virtual ~HouseBuilder() {}
    void CreateHouse()
    {
        m_house = new House;
    }
    House* GetHouse()
    {
        return m_house;
    }
    virtual void BuildWalls() = 0;
    virtual void BuildDoors() = 0;
    virtual void BuildRoof() = 0;
    virtual void BuildWindows() = 0;
protected:
    House* m_house;
};
/*具体建造者*/
class WoodenHouseBuilder :public HouseBuilder
{
public:
    virtual ~WoodenHouseBuilder(){}
    void BuildWalls() override
    {
        m_house->SetWalls("木头");
    }
    void BuildDoors() override
    {
        m_house->SetDoors("木门");
    }
    void BuildRoof() override
    {
        m_house->SetRoof("木头");
    }
    void BuildWindows() override
    {
        m_house->SetWindows("玻璃");
    }
};
class StoneHouseBuilder :public HouseBuilder
{
public:
    virtual ~StoneHouseBuilder() {}
    void BuildWalls() override
    {
        m_house->SetWalls("石头墙");
    }
    void BuildDoors() override
    {
        m_house->SetDoors("石门");
    }
    void BuildRoof() override
    {
        m_house->SetRoof("石头");
    }
    void BuildWindows() override
    {
        m_house->SetWindows("玻璃");
    }
};
/*指挥者*/
class Architect
{
public:
    void SetHouseBuilder(HouseBuilder* hb)
    {
        m_houseBuilder = hb;
    }
    House* GetHouseBuilder()
    {
        return m_houseBuilder->GetHouse();
    }
    void ConstructHouse()
    {
        m_houseBuilder->CreateHouse();
        m_houseBuilder->BuildWalls();
        m_houseBuilder->BuildRoof();
        m_houseBuilder->BuildDoors();
        m_houseBuilder->BuildWindows();
    }
private:
    HouseBuilder* m_houseBuilder;
};
int main()
{
    Architect artist;
    WoodenHouseBuilder woodhouse;
    StoneHouseBuilder stonehouse;

    //构建木屋
    artist.SetHouseBuilder(&woodhouse);
    artist.ConstructHouse();
    House* mywoodhouse = artist.GetHouseBuilder();
    mywoodhouse->ShowHouse();

    //构建石屋
    artist.SetHouseBuilder(&stonehouse);
    artist.ConstructHouse();
    House* mystonehouse = artist.GetHouseBuilder();
    mystonehouse->ShowHouse();
    delete mywoodhouse;
    delete mystonehouse;
}

