#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Command
{
public:
    virtual void execude() = 0;
};

class ConcreteCommand1: public Command
{
    string arg;
public:
    ConcreteCommand1(const string &a):arg(a){}
    void execude() override{
        cout<<"#1 process...."<<arg<<endl;
    }
};

class ConcreteCommand2: public Command
{
    string arg;
public:
    ConcreteCommand2(const string &a):arg(a){}
    void execude() override{
        cout<<"#2 process...."<<arg<<endl;
    }
};

class MacroCommand: public Command
{
    vector<Command *> commands;
public:
    void addCommand(Command *c){commands.push_back(c);}
    void execude() override{
        for(auto &c:commands){
            c->execude();
        }
    }
};









