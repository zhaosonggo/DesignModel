#include<string>
using namespace std;
class Memento{
    string state;
public:
    Memento(const string &s):state(s){}
    string getState() const {return state;}
    void setState(const string &s){state = s;}
};

class Oroginator{
    string state;
public:
    Oroginator(){}
    Memento createMomento(){
        Memento m(state);
        return m;
    }

    void setMomento(const Memento &m){
        state = m.getState();
    }
};