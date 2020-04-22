/**
 *namespace first实现了一个文件分割的功能 
 */

namespace first{
class FileSplitter
{
    string m_filePath;
    int m_fileNumber;
public:
    FileSplitter(const string&filePath, int fileNumber):
        m_filePath(filePath),
        m_fileNumber(fileNumber){
    }
    void split(){
        //1.读取文件
        //2.分批次向小文件中写入
        for(int i=0;i<m_fileNumber;i++){
            //...
        }
    }
};


class MainForm:public Form
{
    TextBox *txtFilePath;
    TextBox *txtFileNumber;
public:
    void Button1_Click(){
        string filepath = txtFilePath->getText();
        int number = atoi(txtFileNumber->getText().c_str());
        FileSplitter splitter(filePath, number);
        splitter.split();
    }
};
}

/**
 *second 在first的基础上添加了进度框的功能 ,但是m_progressbar的设置使得
 *两个类之间过分依赖（依赖倒置问题），如果MainForm中进度提示的样式改变，
 *那么FileSplitter中的split也需要进行改变
 */
namespace second{
class FileSplitter
{
    string m_filePath;
    int m_fileNumber;
    ProgressBar* m_progressBar;
public:
    FileSplitter(const string&filePath, int fileNumber, ProgressBar *progressBar):
        m_filePath(filePath),
        m_fileNumber(fileNumber),
        m_progressBar(progressBar){
    }
    void split(){
        //1.读取文件
        //2.分批次向小文件中写入
        for(int i=0;i<m_fileNumber;i++){
            //...
            if(m_progressBar!=nullptr){
                m_progressBar->setValue((i+1)/m_fileNumber);
            }            
        }
    }
};


class MainForm:public Form
{
    TextBox *txtFilePath;
    TextBox *txtFileNumber;
    ProgressBar *progressBar;
public:
    void Button1_Click(){
        string filepath = txtFilePath->getText();
        int number = atoi(txtFileNumber->getText().c_str());
        FileSplitter splitter(filePath, number, progressBar);
        splitter.split();
    }
};
}
/**
 *观察者模式下的新构建方式 
 * 
 */
namespace third{

class IProgress
{
public:
    virtual void DoProgress(float value)=0;
    virtual ~IProgress(){}
};

class FileSplitter
{
    string m_filePath;
    int m_fileNumber;
    IProgress *m_iprogress; //抽象通知机制
public:
    FileSplitter(const string&filePath, int fileNumber, IProgress *iprogress):
        m_filePath(filePath),
        m_fileNumber(fileNumber),
        m_iprogress(iprogress){
    }
    void split(){
        //1.读取文件
        //2.分批次向小文件中写入
        for(int i=0;i<m_fileNumber;i++){
            //...           
                float progressValue = m_fileNumber;
                progressValue = (i+1)/progressValue;
                onProgress(progressValue);           
        }
    }
protected:
    void onProgress(float value){ //添加的优化，可不加
        if(m_iprogress!=nullptr)
        m_iprogress->DoProgress(value);
    }
};


class MainForm:public Form, public IProgress
{
    TextBox *txtFilePath;
    TextBox *txtFileNumber;
    ProgressBar *progressBar;
public:
    void Button1_Click(){
        string filepath = txtFilePath->getText();
        int number = atoi(txtFileNumber->getText().c_str());
        FileSplitter splitter(filePath, number, this);
        splitter.split();
    }
    void DoProgress(float value){
        if(progressBar!=nullptr)
            progressBar->setValue(value);
    }
};
}


/**
 *多观察者模式 
 */
namespace third{

class IProgress
{
public:
    virtual void DoProgress(float value)=0;
    virtual ~IProgress(){}
};

class FileSplitter
{
    string m_filePath;
    int m_fileNumber;
    list<IProgress *> m_iprogressList; //多观察者抽象通知机制
public:
    FileSplitter(const string&filePath, int fileNumber:
        m_filePath(filePath),
        m_fileNumber(fileNumber){
    }

    void add_IProgress(IProgress* iprogress){
        m_iprogressList.push_back(iprogress);
    }

    void remove_IProgress(IProgress *iprogress){
        m_iprogressList.remove(iprogress);
    }

    void split(){
        //1.读取文件
        //2.分批次向小文件中写入
        for(int i=0;i<m_fileNumber;i++){
            //...           
                float progressValue = m_fileNumber;
                progressValue = (i+1)/progressValue;
                onProgress(progressValue);           
        }
    }
protected:
    void onProgress(float value){ //添加的优化，可不加
        for(auto p = m_iprogressList.begin(); p!=m_iprogressList.end();p++)
            (*p)->DoProgress(value);
    }
};


class MainForm:public Form, public IProgress
{
    TextBox *txtFilePath;
    TextBox *txtFileNumber;
    ProgressBar *progressBar;
public:
    void Button1_Click(){
        string filepath = txtFilePath->getText();
        int number = atoi(txtFileNumber->getText().c_str());
        ConsoleNoyifer cn;
        FileSplitter splitter(filePath, number);
        splitter.add_IProgress(this);
        splitter.add_IProgress(&cn);
        splitter.split();
    }
    void DoProgress(float value){
        if(progressBar!=nullptr)
            progressBar->setValue(value);
    }
};

class ConsoleNoyifer:public IProgress{
    void DoProgress(float value)
    {
        cout<<".";
    }
};
}