class ISplitter
{
public:
    virtual void split()=0;
    virtual ~ISplitter(){}
};

class BinarySplitter:public ISplitter
{
public:
    void split(){
    }
};

class TxtSplitter:public ISplitter
{
public:
    void split(){
    }
};

class PictureSplitter:public ISplitter
{
public:
    void split(){
    }
};

class VideoSplitter:public ISplitter
{
public:
    void split(){
    }
};


class MainForm:public Form
{
private:
    SplitterFactory *factory;
public:
    MainForm(SplitterFactory * fac):factory(fac){}
    void Button1_Click(){
        
        ISplitter *splitter = 
                factory->CreateSplitter(); //多态new
        splitter->split();
    }
};


class SplitterFactory //工厂
{
public:
    virtual ISplitter *CreateSplitter()=0;
    virtual ~SplitterFactory(){}
};

class BinaryFactory:public SplitterFactory
{
public:
    virtual BinarySplitter *CreateSplitter()
    {
        return new BinarySplitter();
    }
};

class TxtFactory:public SplitterFactory
{
public:
    virtual TxtSplitter *CreateSplitter()
    {
        return new TxtSplitter();
    }
};

class PictureFactory:public SplitterFactory
{
public:
    virtual PictureSplitter *CreateSplitter()
    {
        return new PictureSplitter();
    }
};

class VideoFactory:public SplitterFactory
{
public:
    virtual VideoSplitter *CreateSplitter()
    {
        return new VideoSplitter();
    }
};
