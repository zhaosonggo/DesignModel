#include<iostream>
using namespace std;
class Visitor;
class Element
{
public:
    virtual void accept(Visitor &visitor) = 0;
    virtual ~Element(){}
};

class ElementA:public Element
{
public:
    void accept(Visitor &visitor) override{
        visitor.visitElementA(*this);
    }
};

class ElementB:public Element
{
public:
    void accept(Visitor &visitor) override{
        visitor.visitElementB(*this);
    }
};


class Visitor
{
public:
    virtual void visitElementA(ElementA &element) = 0;
    virtual void visitElementB(ElementB &element) = 0;
    virtual ~Visitor(){}
};