//目标接口
class ITarget{
public:
    virtual void process()=0;
};

//遗留接口
class IAdaptee{
public:
    virtual void foo(int data)=0;
    virtual int bar()=0;
};

//对象适配器
class Adapter: public ITarget{
protected:
    IAdaptee * pAdaptee;
public:
    virtual void process(){
        //....
       int i =  pAdaptee->bar();
        //...
        pAdaptee->foo(i);
        //....
    }
};

