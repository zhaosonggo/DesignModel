class Messager
{
public:
    virtual void Login(string username, string password)=0;
    virtual void SendMessage(string message)=0;
    virtual void SendPicture(Image image)=0;

    /*这一段和 实现平台有很大关系*/
    virtual void PlaySound()=0;
    virtual void DrawShape()=0;
    virtual void WriteText()=0;
    virtual void Connect()=0;
    /*------------------------*/

    virtual ~Messager(){}
};

//平台实现
class PCMessagerBase:public Messager
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

class MobileMessagerBase:public Messager
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
class PCMessagerLite:public PCMessagerBase //基础版本 
{
public:
    virtual void Login(string username, string password)
    {
        PCMessagerBase::Connect();
        //.....
    }
    virtual void SendMessage(string message){
        PCMessagerBase::WriteText();
        //...
    }
    virtual void SendPicture(Image image){
        PCMessagerBase::DrawShape();
    }
};

class PCMessagerPerfect:public PCMessagerBase //完美版本 
{
public:
    virtual void Login(string username, string password)
    {
        PCMessagerBase::PlaySound();
        //...
        PCMessagerBase::Connect();
        //.....
    }
    virtual void SendMessage(string message){
        PCMessagerBase::PlaySound();
        //...
        PCMessagerBase::WriteText();
        //...
    }
    virtual void SendPicture(Image image){
        PCMessagerBase::PlaySound();
        //...
        PCMessagerBase::DrawShape();
    }
};
class MobileMessagerLite:public MobileMessagerBase //完美版本 
{
public:
    virtual void Login(string username, string password)
    {
        MobileMessagerBase::Connect();
        //.....
    }
    virtual void SendMessage(string message){
        MobileMessagerBase::WriteText();
        //...
    }
    virtual void SendPicture(Image image){
        MobileMessagerBase::DrawShape();
    }
};

class MobileMessagerPerfect:public MobileMessagerBase //完美版本 
{
public:
    virtual void Login(string username, string password)
    {
        MobileMessagerBase::PlaySound();
        //...
        MobileMessagerBase::Connect();
        //.....
    }
    virtual void SendMessage(string message){
        MobileMessagerBase::PlaySound();
        //...
        MobileMessagerBase::WriteText();
        //...
    }
    virtual void SendPicture(Image image){
        MobileMessagerBase::PlaySound();
        //...
        MobileMessagerBase::DrawShape();
    }
};