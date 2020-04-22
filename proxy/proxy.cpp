class ISubject{
public:
    virtual void process()=0;
};

class RealSubjet:public ISubject{
public:
    virtual void process(){
        //...
    }
};

class ClientApp{
    ISubject * subject;
public:
    ClientApp(){
        subject = new RealSubjet();
    }
    void DoTask(){
        //...
        subject->process();
        //...
    }
};