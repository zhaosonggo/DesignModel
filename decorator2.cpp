//业务操作
class Stream
{
public:
    virtual char Read(int number)=0;
    virtual void Seek(int position)=0;
    virtual void Write(char data)=0;
    virtual ~Stream(){}
};

//主体类
class FileStream:public Stream
{
public:
    virtual char Read(int number){
        //读文件流
    }
    virtual void Seek(int position){
        //定位 文件流
    }
    virtual void Write(char data){
        //写文件流
    }
};

class NetworkStream:public Stream
{
public:
    virtual char Read(int number){
        //读网络流
    }
    virtual void Seek(int position){
        //定位网络流
    }
    virtual void Write(char data){
        //写网络流
    }
};

class MemoryStream:public Stream
{
public:
    virtual char Read(int number){
        //读内存流
    }
    virtual void Seek(int position){
        //定位内存流
    }
    virtual void Write(char data){
        //写内存流
    }
};

//扩展操作
//此处将组合代替继承，使用基类的指针
//装饰器类
class Decorator:public Stream
{
protected:
    Stream *stream;
    Decorator(Stream *stm):stream(stm){}
};



class CryptoStream:public Decorator
{
public:
    CryptoStream(Stream *stm):Decorator(stm){}
    virtual char Read(int number){
        //加密操作
        stream->Read(number);
    }
    virtual void Seek(int position){
        //加密操作
        stream->Seek(position);
    }
    virtual void Write(char data){
        //加密操作
        stream->Write(data);
    }
};

class BufferStream:public Decorator
{
public:
    BufferStream(Stream*stm):Decorator(stm){}
    virtual char Read(int number){
        //缓冲操作
        stream->Read(number);
    }
    virtual void Seek(int position){
        //缓冲操作
        stream->Seek(position);
    }
    virtual void Write(char data){
        //缓冲操作
        stream->Write(data);
    }
};


void Process(){
    Stream *f1 = new FileStream();
    CryptoStream *f2 = new CryptoStream(f1); //文件流加密 
    BufferStream *f3 = new BufferStream(f1); //文件流缓冲
    BufferStream *f4 = new BufferStream(f2); //文件流缓冲加密
}

