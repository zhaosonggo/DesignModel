#include<string>
#include<iostream>
#include<list>
using namespace std;

class Component{
public:
    virtual void process()=0;
    virtual ~Component(){}
};

class Composite:public Component{
    string name;
    list<Component *> elements;
public:
    Composite(const string &s):name(s){}
    void add(Component * element){
        elements.push_back(element);
    }
    void remove(Component *element){
        elements.remove(element);
    }
    void process(){
        cout<<name<<"\n";
        for(auto &p:elements){
            p->process();
        }
    }
};


class Leaf:public Component{
    string name;
public:
    Leaf(const string &s):name(s){}
    void process(){
        cout<<name<<"\n";
    }
};


int main()
{
    Composite *root = new Composite("root");
    Composite *child1 = new Composite("child1");
    Leaf *leaf1 = new Leaf("leaf1");
    Leaf *leaf2 = new Leaf("leaf2");
    child1->add(leaf1);
    child1->add(leaf2);
    root->add(child1);
    root->process();
    return 0;
}