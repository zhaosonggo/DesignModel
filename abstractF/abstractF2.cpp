class IDBConnection
{//连接操作抽象基类
public:
    virtual void ConnectionString(char *str)=0;
};

class IDBCommand
{//数据库命令操作抽象基类
public:
    virtual void CommandText(char *str)=0;
    virtual  SqlDataReader * ExecuteReader()=0;
};

class IDBDataReader
{//数据读取抽象基类
public:
    virtual bool Read()=0;
};

//支持 sqlserver的数据库访问类
class SqlConnection:public IDBConnection
{
public:
    virtual void ConnectionString(char *str)
    {
        //....
    }
};

class SqlCommand:public IDBCommand
{
public:
    virtual void CommandText(char *str)
    {
        //...
    }
    virtual  SqlDataReader * ExecuteReader()
    {
        //...
        return new SqlDataReader();
    }
};

class SqlDataReader:public IDBDataReader
{
public:
    virtual bool Read()
    {
        //...
        return false;
    }
};

class IDBFactory //抽象工厂
{
public:
    virtual IDBConnection * CreateConnection()=0;
    virtual IDBCommand * CreateCommand()=0;
    virtual IDBDataReader * CreateDataReader()=0;
};

class SqlFactory:public IDBFactory //抽象工厂的具体实现
{
public:
    virtual IDBConnection * CreateConnection(){//...
    }
    virtual IDBCommand * CreateCommand(){//...
    }
    virtual IDBDataReader * CreateDataReader(){//...
    }

};


class EmployeeDAO
{
private:
    IDBFactory *dbfactory;
public:
    EmployeeDAO(IDBFactory * dbf):dbfactory(dbf){}
    vector<EmployeeDAO> GetEmployees(){
        IDBConnection * connection =
            dbfactory->CreateConnection();
        connection->ConnectionString("...");
        IDBCommand *command =
            dbfactory->CreateCommand();
        command->CommandText("...");
        IDBDataReader *reader = dbfactory->CreateDataReader();
        while(reader->Read()){
            
        }
    }
};