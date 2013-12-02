#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//图书类，图书结点
class Book
{
public:
    Book();                  //构造函数

    //以下部分为各种获取图书信息的函数
    void getData();             //获得图书信息
    char * getBookID();          //获得书号
    char * getBookName();           //获得书名
    char * getPubDate();         //获得出版日期
    int getPrice();             //获得图书价格

    //以下部分为各种设置图书信息的函数
    void setData();             //初次录入图书信息
    void udData();              //更改图书信息
    void setBookID();            //设置书号
    void setBookName();             //设置书名
    void setPubDate();           //设置出版日期
    void setPrice();            //设置价格

    //以下是关于图书结点指针的函数
    Book * getNext();        //获得下一个图书节点的指针
    void setNext(Book * ptr);    //设置指向下一个图书节点的指针

private:
    //以下部分为图书结点的各种数据成员
    char bookID[30];                //书号
    char bookName[30];              //书名
    char pubDate[15];               //出版日期

    double price;                   //价格

    Book * next;                     //指向下一个图书节点的指针

};

//链表类，图书信息数据库
class BookList
{
public:

    BookList();                 //构造函数

    //文件操作函数
    void readFromFile();        //读取文件函数
    void saveToFile();          //保存文件函数

    //各种对图书操作的函数
    void addBook();              //添加图书
    void updateBook();           //更新图书信息
    void searchBook();           //查找图书
    void deleteBook();           //删除图书
    void checkInfo(Book * paraBook);    //检查输入的图书信息是否合理，不合理的需要重新输入
    void checkID(Book* paraBook);      //检查书号长度是否合理并且书号是否唯一
    bool checkIDuni(Book * paraBook);   //检查书号是否唯一
    void allbooks();             //显示所有图书信息

    //各种查找图书信息函数
    void searchID();            //按书号查找
    void searchName();          //按书名查找

    //主菜单
    void menuList();

private:
    //链表的头指针和用于对结点操作的指针
    Book * HeadPtr;          //链表头指针
    Book * CurPtr;           //当前指针。操作图书及图书信息时用到
    Book * PrePtr;          //下一个指针。操作图书及图书信息时用到
};

/*    以下是对图书类的成员函数的定义    */
Book::Book()          //构造函数，将指针初始化为空指针
{
    next = NULL;
}

//以下部分为各种获取图书信息的函数的定义
void Book::getData()     //获得图书信息
{
    cout<<bookID<<"\t"<<bookName<<"\t"<<pubDate<<"\t"<<price<<"\t"<<endl;
}

char * Book::getBookID()  //获得书号
{
    return bookID;
}

char * Book::getBookName()   //获得书名
{
    return bookName;
}

char * Book::getPubDate() //获得出版日期
{
    return pubDate;
}

int Book::getPrice() //获得价格
{
    return price;
}

//以下部分为各种设置图书信息的函数的定义
void Book::setData()     //初次录入图书信息
{
    setBookID();
    setBookName();
    setPubDate();
    setPrice();
}

void Book::udData()     //更改录入图书信息
{
    setBookName();
    setPubDate();
    setPrice();
}

void Book::setBookID()    //设置书号
{
    cout<<"请输入书号: ";
    cin>>bookID>>setiosflags(ios_base::unitbuf);
}

void Book::setBookName()     //设置书名
{
    string str;
    cout<<"请输入书名: ";
    cin>>bookName>>setiosflags(ios_base::unitbuf);
    str.assign(bookName);
    while(str.length() > 30)
    {
        cout<<"书名过长，请重新输入书名: ";
        cin>>bookName>>setiosflags(ios_base::unitbuf);
        str.assign(bookName);
    }
}

void Book::setPubDate()   //设置出版日期
{
    string str;
    cout<<"请输入出版日期: ";
    cin>>pubDate>>setiosflags(ios_base::unitbuf);
    str.assign(pubDate);
    while(str.length() > 15)
    {
        cout<<"日期输入过长，请重新输入日期: ";
        cin>>pubDate>>setiosflags(ios_base::unitbuf);
        str.assign(pubDate);
    }
}

void Book::setPrice()    //设置价格
{
    cout<<"请输入价格: ";
    cin>>price>>setiosflags(ios_base::unitbuf);
    while(price < 0 || price > 30000000000000)
    {
        cout<<"价格超出正常范围，请重新输入价格: ";
        cin>>price>>setiosflags(ios_base::unitbuf);
    }

}

//以下是关于图书结点指针的函数
Book * Book::getNext()    //获得下一个图书节点的指针
{
    return next;
}
void Book::setNext(Book * ptr)    //设置指向下一个图书节点的指针
{
    next = ptr;
}



/*    以下是对图书链表类的成员函数的定义    */
BookList::BookList()      //构造函数，将指针初始化为空指针
{
    HeadPtr = NULL;
    CurPtr = NULL;
    PrePtr = NULL;
}

//文件操作函数的定义
void BookList::readFromFile()    //读取文件
{
    ifstream readDB("BookDB.dat", ios_base::in | ios_base::binary);  //以二进制方式打开待读取的文件
    if(readDB)
    {
        cout<<"打开数据文件成功!"<<endl;
        readDB.seekg(0, ios::end);
        if(readDB.tellg() != 0)             //判断文件是否为空
        {
            readDB.clear();
            readDB.seekg(0);        //将文件指针设回文件开头
            cout<<"正在读取"<<endl;
            HeadPtr = new Book;
            readDB.read(reinterpret_cast<char *>(HeadPtr), sizeof(Book));
            cout<<"1 ";
            CurPtr = HeadPtr;
            for (int i = 2; CurPtr->getNext() != NULL; i++)     //从文件中读取图书信息，直到图书节点指向下一个图书的指针为空
            {
                CurPtr->setNext(new Book);
                CurPtr = CurPtr->getNext();
                readDB.read(reinterpret_cast<char *>(CurPtr), sizeof(Book));
                cout<<i<<" ";
            }
            cout<<endl<<"读取完成"<<endl;
        }
        else
            cout<<"数据文件为空"<<endl;
        readDB.close();
    }
    else
        cout<<"打开文件失败或没有数据文件"<<endl;
}

void BookList::saveToFile()  //保存文件
{
    ofstream saveDB ("BookDB.dat", ios_base::out | ios_base::binary);    //以二进制方式打开待保存的文件
    cout<<endl<<"正在保存数据"<<endl;
    if (HeadPtr != NULL)
    {
        CurPtr = HeadPtr;
        for(int i =1; CurPtr!= NULL; CurPtr = CurPtr->getNext())        //保存数据直到最后一个节点
        {
            cout<<i<<" ";
            saveDB.write(reinterpret_cast<char *>(CurPtr), sizeof(Book));
            i++;
        }
    }
    else
        saveDB.write(NULL, 0);
    cout<<endl<<"保存完成"<<endl;
    saveDB.close();
}

//各种对图书操作的函数的定义
void BookList::addBook()      //添加图书
{
    Book * newBookPtr = new Book;      //为新增的图书动态分配内存
    newBookPtr->setData();
    if (HeadPtr == NULL)
    {
        HeadPtr = newBookPtr;
        cout<<"添加成功"<<endl;
    }
    else
    {
        CurPtr = HeadPtr;
        for ( ; (CurPtr->getNext() != NULL); CurPtr = CurPtr->getNext()) ;  //将新增图书加到链表最后
        CurPtr->setNext(newBookPtr);
        cout<<"添加成功"<<endl;
    }
}

void BookList::updateBook()   //更新图书信息
{
    string uID, ID;
    cout<<"请输入要更新信息的书号: ";
    cin>>uID>>setiosflags(ios_base::unitbuf);
    if (HeadPtr == NULL)
        cout<<"还没有录入任何图书信息!"<<endl;
    else
    {
        CurPtr = HeadPtr;
        ID.assign(CurPtr->getBookID());
        for (CurPtr = HeadPtr; (CurPtr->getNext() != NULL) && (ID.assign(CurPtr->getBookID()) != uID); CurPtr = CurPtr->getNext()) ; //查找并定位欲更新信息的图书

        if(ID == uID)
        {
            CurPtr->udData();
            cout<<"更新信息成功"<<endl;
        }
        else
            cout<<"没有这个书号的信息!"<<endl;
    }
}

void BookList::searchBook()   //查找图书信息
{
    char choice, i=1;

    cout<< endl<<"请选择按照哪种方式查找:"<<endl;
    cout<<"(i)书号，(n)书名，(k)返回主菜单"<<endl<<">>";
    while (i != 0)      //按不同方式查找信息
    {
        cin>>choice>>setiosflags(ios_base::unitbuf);

        switch (choice)
        {
        case 'i':
            searchID();
            i = 0;
            break;
        case 'n':
            searchName();
            i = 0;
            break;
        case 'k':
            i = 0;
            break;
        default:
            cout<<"请选择正确的选项>>";
        }
    }
}

void BookList::deleteBook()   //删除图书
{
    string dID, ID;
    cout<<"请输入要删除图书的书号: ";
    cin>>dID>>setiosflags(ios_base::unitbuf);
    if (HeadPtr == NULL)
        cout<<"还没有录入任何图书信息!"<<endl;
    else
    {
        PrePtr = NULL;
        CurPtr = HeadPtr;
        ID.assign(CurPtr->getBookID());
        for (; (CurPtr->getNext() != NULL) && (ID.assign(CurPtr->getBookID()) != dID);)  //查找并定位欲删除的图书
        {
            PrePtr = CurPtr;
            CurPtr = CurPtr->getNext();
        }

        if (CurPtr->getBookID() == dID)
        {

            if((PrePtr == NULL) && (CurPtr->getNext() == NULL))
                HeadPtr = NULL;
            else if(PrePtr == NULL)
            {
                HeadPtr = CurPtr->getNext();
            }
            else
            {
                PrePtr->setNext(CurPtr->getNext());

            }
            delete CurPtr;         //释放已删除图书节点的内存
            cout<<"删除成功"<<endl;
        }
        else
            cout<<"没有这个书号的信息!"<<endl;
    }
}

void BookList::checkID(Book * paraBook)        //检查书号长度是否合理并检查书号是否唯一
{
    string str;
    str.assign(paraBook->getBookID());
    while((str.length() > 30) || (checkIDuni(paraBook) == false))
    {
        while (str.length() > 30)
        {
            cout<<"书号过长，请重新输入书号: ";
            paraBook->setBookID();
            str.assign(paraBook->getBookID());
        }
        if (checkIDuni(paraBook) == false)
        {
            cout<<"此书号已存在，请重新输入书号: ";
            paraBook->setBookID();
            str.assign(paraBook->getBookID());
        }
    }
}

bool BookList::checkIDuni(Book * paraBook)   //检查书号是否唯一
{
    string ID, str;
    str.assign(paraBook->getBookID());
    if (HeadPtr != NULL)
    {
        CurPtr = HeadPtr;
        ID.assign(CurPtr->getBookID());
        for (; (CurPtr->getNext() != NULL) && (ID.assign(CurPtr->getBookID()) != str); CurPtr = CurPtr->getNext()) ;     //查找图书以确定要录入的书号是否唯一
        if (ID != str)
            return true;
        else
            return false;
    }
    else
    {
        return true;
    }
}

void BookList::allbooks()     //显示所有图书信息
{
    if (HeadPtr == NULL)
        cout<<"还没有录入任何图书信息!"<<endl;
    else
    {
        cout<<"书号\t\t"<<"书名\t\t"<<"出版日期\t"<<"价格\t"<<endl;
        for (CurPtr = HeadPtr; CurPtr != NULL; CurPtr = CurPtr->getNext())
            CurPtr->getData();
    }
}

//各种查找图书信息函数的定义
void BookList::searchID()    //按书号查询
{
    string sID, ID;
    cout<<"请输入要查找的书号: ";
    cin>>sID>>setiosflags(ios_base::unitbuf);
    if (HeadPtr == NULL)
        cout<<"还没有录入任何图书信息!"<<endl;
    else
    {
        cout<<"书号\t\t"<<"书名\t\t"<<"出版日期\t"<<"价格\t"<<endl;
        for (CurPtr = HeadPtr; (CurPtr->getNext() != NULL) && (ID.assign(CurPtr->getBookID()) != sID); CurPtr = CurPtr->getNext()) ;     //查找书号

        if(CurPtr != NULL)
            CurPtr->getData();
        else
            cout<<"没有这个书号的信息!"<<endl;
    }
}

void BookList::searchName()  //按书名查询
{
    int i=0;
    string sName, Name;
    cout<<"请输入要查找图书的书名: ";
    cin>>sName>>setiosflags(ios_base::unitbuf);
    if (HeadPtr == NULL)
        cout<<"还没有录入任何图书信息!"<<endl;
    else
    {
        cout<<"书号\t\t"<<"书名\t\t"<<"出版日期\t"<<"价格\t"<<endl;
        CurPtr = HeadPtr;
        Name.assign(CurPtr->getBookName());

        //将所有该书名的图书信息都输出出来
        if(Name.assign(CurPtr->getBookName()) == sName)
        {
            CurPtr->getData();
            i++;
        }
        for (; (CurPtr->getNext() != NULL);)
        {
            CurPtr = CurPtr->getNext();
            if(Name.assign(CurPtr->getBookName()) == sName)
            {
                CurPtr->getData();
                i++;
            }
        }
        if (i == 0)
            cout<<"没有这个书名的信息!"<<endl;
    }
}

//操作菜单函数的定义
void BookList::menuList()        //主菜单
{
    char choice, i = 1, j;
    while(i != 0)
    {
        j = 1;
        cout<<endl<<"请选择一项操作: "<<endl;
        cout<<"(a)添加图书，(u)更新图书信息，(s)查找信息，(p)显示所有图书，(d)删除图书，(q)退出"<<endl<<">>";
        while (j != 0)
        {
            cin>>choice>>setiosflags(ios_base::unitbuf);

            switch (choice)
            {
            case 'a':
                addBook();
                j = 0;
                break;
            case 'u':
                updateBook();
                j = 0;
                break;
            case 's':
                searchBook();
                j = 0;
                break;
            case 'p':
                allbooks();
                j = 0;
                break;
            case 'd':
                deleteBook();
                j = 0;
                break;
            case 'q':
                j = 0;
                i = 0;
                break;
            default:
                cout<<"请选择正确的选项>>";
            }
        }
    }
}

//欢迎、退出界面函数的定义
void welcome()
{
    cout<<"\t\t       "<<"欢迎进入图书信息管理系统"<<endl;
}
void quit()
{
    cout<<"\t\t       "<<"图书信息管理系统已关闭"<<endl;
}

int main()
{
    welcome();
    BookList BookDB;      //建立图书数据库链表
    BookDB.readFromFile();   //从文件中读取数据库数据
    BookDB.menuList();       //展示操作菜单
    BookDB.saveToFile();     //存入数据库数据
    quit();

    return 0;
}
