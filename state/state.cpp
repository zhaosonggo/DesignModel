class NetworkState{
public:
    NetworkState *pNext;
    virtual void Operation1()=0;
    virtual void Operation2()=0;
    virtual void Operation3()=0;
    virtual ~NetworkState(){}
};

class OpenState: public NetworkState{
    static NetworkState *m_instance;
public:
    static NetworkState *getInstance(){
        if(m_instance == nullptr){
            m_instance = new OpenState();
        }
        return m_instance;
    }
    void Operation1(){
        //...
        pNext = CloseState::getInstance();
    }
     void Operation2(){
        //...
        pNext = ConnectState::getInstance();
    }
     void Operation3(){
        //...
        pNext = OpenState::getInstance();
    }
};

class ConnectState: public NetworkState{
    static NetworkState *m_instance;
public:
    static NetworkState *getInstance(){
        if(m_instance == nullptr){
            m_instance = new ConnectState();
        }
        return m_instance;
    }
    void Operation1(){
        //...
        pNext = CloseState::getInstance();
    }
     void Operation2(){
        //...
        pNext = ConnectState::getInstance();
    }
     void Operation3(){
        //...
        pNext = OpenState::getInstance();
    }
};

class CloseState: public NetworkState{
    static NetworkState *m_instance;
public:
    static NetworkState *getInstance(){
        if(m_instance == nullptr){
            m_instance = new CloseState();
        }
        return m_instance;
    }
    void Operation1(){
        //...
        pNext = CloseState::getInstance();
    }
     void Operation2(){
        //...
        pNext = ConnectState::getInstance();
    }
     void Operation3(){
        //...
        pNext = OpenState::getInstance();
    }
};  


class NetworkProcess{
    NetworkState *pState;
public:
    NetworkProcess(NetworkState *pState){
        this->pState = pState;
    }

    void Operator1(){
        //...
        pState->Operation1();
        pState = pState->pNext;
    }

    void Operator2(){
        //...
        pState->Operation2();
        pState = pState->pNext;
    }
    
    void Operator3(){
        //...
        pState->Operation3();
        pState = pState->pNext;
    }

};