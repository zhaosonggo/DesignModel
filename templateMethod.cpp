#include<iostream>

using namespace std;

class Library
{
    public:
        void run()
        {
            step1();
            step2();
        }
        virtual ~Library(){
            cout<<"Library destory\n";
        };
    protected:
        virtual void step1()=0;
        virtual void step2()=0;
};

class Application:public Library
{
    void step1()
    {
        cout<<"Application step1"<<endl;
    }
    void step2()
    {
        cout<<"Application step2"<<endl;
    }
    public:
        ~Application(){
            cout<<"Application destory\n";
        }
};

class windapp:public Library
{
    void step1()
    {
        cout<<"winapp step1"<<endl;
    }
    void step2()
    {
        cout<<"winapp step2"<<endl;
    }
    public:
        ~windapp(){
            cout<<"winapp destory\n";
        }
};


int main()
{
    Library *la = new Application();
    la->run();
    delete la;
    Library *lb = new windapp();
    lb->run();
    delete lb;
    return 0;
}






