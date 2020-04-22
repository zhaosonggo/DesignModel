class Messager
{
protected:
    MessagerImp * messager;
public:
    Messager(MessagerImp *mes):messager(mes){}
    virtual void Login(string username, string password)=0;
    virtual void SendMessage(string message)=0;
    virtual void SendPicture(Image image)=0;
    virtual ~Messager(){}
};

class MessagerImp
{
public:
    /*这一段和 实现平台有很大关系*/
    virtual void PlaySound()=0;
    virtual void DrawShape()=0;
    virtual void WriteText()=0;
    virtual void Connect()=0;
    /*------------------------*/
    virtual ~MessagerImp(){}
};

//平台实现
class PCMessagerBase:public MessagerImp
{
public:
    virtual void PlaySound(){

    }
    virtual void DrawShape(){

    }
    virtual void WriteText(){

    }
    virtual void Connect(){

    }
};

class MobileMessagerBase:public MessagerImp
{
public:
    virtual void PlaySound(){

    }
    virtual void DrawShape(){

    }
    virtual void WriteText(){

    }
    virtual void Connect(){
        
    }
};

//业务抽象
class MessagerLite:public Messager //基础版本 
{
public:
    MessagerLite(MessagerImp *mes):Messager(mes){}
    virtual void Login(string username, string password)
    {
        messager->Connect();
        //.....
    }
    virtual void SendMessage(string message){
        messager->WriteText();
        //...
    }
    virtual void SendPicture(Image image){
        messager->DrawShape();
    }
};

class MessagerPerfect:public Messager //完美版本 
{
public:
    MessagerPerfect(MessagerImp *mes):Messager(mes){}
    virtual void Login(string username, string password)
    {
        messager->PlaySound();
        //...
        messager->Connect();
        //.....
    }
    virtual void SendMessage(string message){
        messager->PlaySound();
        //...
        messager->WriteText();
        //...
    }
    virtual void SendPicture(Image image){
        messager->PlaySound();
        //...
        messager->DrawShape();
    }
};

