/**
 *这个设计方式在扩展 功能的时候一直在使用继承的方法 
 * 
 * num =  1+n+n*(Cm1+Cm2+...Cmm)
 * 
 */
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
class CryptoFileStream:public FileStream
{
public:
    virtual char Read(int number){
        //读文件流加密操作
        FileStream::Read(number);
    }
    virtual void Seek(int position){
        //定位 文件流加密操作
        FileStream::Seek(position);
    }
    virtual void Write(char data){
        //写文件流加密操作
        FileStream::Write(data);
    }
};

class CryptoNetworkStream:public NetworkStream
{
public:
    virtual char Read(int number){
        //读网络流加密操作
        NetworkStream::Read(number);
    }
    virtual void Seek(int position){
        //定位网络流加密操作
        NetworkStream::Seek(position);
    }
    virtual void Write(char data){
        //写网络流加密操作
        NetworkStream::Write(data);
    }
};


class CryptoMemoryStream:public MemoryStream
{
public:
    virtual char Read(int number){
        //读内存流加密操作
        MemoryStream::Read(number);
    }
    virtual void Seek(int position){
        //定位内存流加密操作
        MemoryStream::Seek(position);
    }
    virtual void Write(char data){
        //写内存流加密操作
        MemoryStream::Write(data);
    }
};

class BufferFileStream:public FileStream
{
public:
    virtual char Read(int number){
        //读文件流加密操作
        FileStream::Read(number);
    }
    virtual void Seek(int position){
        //定位 文件流加密操作
        FileStream::Seek(position);
    }
    virtual void Write(char data){
        //写文件流加密操作
        FileStream::Write(data);
    }
};

class BufferNetworkStream:public NetworkStream
{
public:
    virtual char Read(int number){
        //读网络流加密操作
        NetworkStream::Read(number);
    }
    virtual void Seek(int position){
        //定位网络流加密操作
        NetworkStream::Seek(position);
    }
    virtual void Write(char data){
        //写网络流加密操作
        NetworkStream::Write(data);
    }
};


class BufferMemoryStream:public MemoryStream
{
public:
    virtual char Read(int number){
        //读内存流加密操作
        MemoryStream::Read(number);
    }
    virtual void Seek(int position){
        //定位内存流加密操作
        MemoryStream::Seek(position);
    }
    virtual void Write(char data){
        //写内存流加密操作
        MemoryStream::Write(data);
    }
};

//...更多的操作以及操作的组合
class CryBufFileStream:public FileStream
{
public:
    virtual char Read(int number){
        //文件流加密缓冲操作
        FileStream::Read(number);
    }
    virtual void Seek(int position){
       //文件流加密缓冲操作
        FileStream::Seek(position);
    }
    virtual void Write(char data){
       //文件流加密缓冲操作
        FileStream::Write(data);
    }
};
//...