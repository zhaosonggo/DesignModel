class ISplitter
{
public:
    virtual void split()=0;   
    virtual ISplitter *clone()=0;
    virtual ~ISplitter(){}
};

class BinarySplitter:public ISplitter
{
public:
    void split(){
    }
    ISplitter *clone()
    {
        return new BinarySplitter(*this);
    }
};

class TxtSplitter:public ISplitter
{
public:
    void split(){
    }
     ISplitter *clone()
    {
        return new TxtSplitter(*this);
    }
};

class PictureSplitter:public ISplitter
{
public:
    void split(){
    }
     ISplitter *clone()
    {
        return new PictureSplitter(*this);
    }
};

class VideoSplitter:public ISplitter
{
public:
    void split(){
    }
     ISplitter *clone()
    {
        return new VideoSplitter(*this);
    }
};


class MainForm:public Form
{
private:
    ISplitter *prototype;  //原型，只可以用来生成新的对象，不可以直接用来使用
public:
    MainForm(ISplitter * pry):prototype(pry){}
    void Button1_Click(){
        
        ISplitter *splitter = 
                prototype->clone(); 
        splitter->split();
    }
};




