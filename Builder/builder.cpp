class House
{
public:
    virtual ~House(){}
};

class HouseBuilder
{
friend class HouseDirector;
public:
    HouseBuilder(House *phouse):phouse(phouse){}
   
    House * GetResult()
    {
        return phouse;
    }
    virtual ~HouseBuilder(){}

protected:
    House *phouse;
    virtual bool BuildPart1()=0;
    virtual bool BuildPart2()=0;
    virtual bool BuildPart3()=0;
    virtual bool BuildPart4()=0;
    virtual bool BuildPart5()=0;
};
class StoneHouse: public House
{
    //...
};
class StoneHouseBuilder:public HouseBuilder
{
public:
    StoneHouseBuilder(House * phouse):HouseBuilder(phouse){}
protected:
    virtual bool BuildPart1(){
        //phouse->......
    }
    virtual bool BuildPart2(){
        
    }
    virtual bool BuildPart3(){
        
    }
    virtual bool BuildPart4(){
        
    }
    virtual bool BuildPart5(){
        
    }
};

class HouseDirector
{
public:
    HouseBuilder *phousebuilder;
    HouseDirector(HouseBuilder * phb):phousebuilder(phb){}
     House * Construct(){
        phousebuilder->BuildPart1();
        for(int i = 0; i<4; i++){
            phousebuilder->BuildPart2();
        }
        bool flag = phousebuilder->BuildPart3();
        if(flag){
            phousebuilder->BuildPart4();
        }
        phousebuilder->BuildPart5();
        return phousebuilder->GetResult();
    }
};
int main()
{
    House *phouse = new StoneHouse();
    HouseBuilder * phb = new StoneHouseBuilder(phouse);
    HouseDirector *pd = new HouseDirector(phb);
    pd->Construct();
    return 0;
}