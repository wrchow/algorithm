// 单链表 C++ 类实现
// by wrchow@20110911
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyList;
//提前声明 
class LNode
{//结点类  friend MyList;
public:
    int data;
    LNode *next;
};
class MyList{
//链表类 
public: 
    void InitList(int n);//头插法初始化带头结点的表,长度为n,不算头结点 
    void DestroyList();//摧毁表 
    void ClearList();//清空表 
    bool ListEmpty();//判空 
    int ListLength();//取表长 
    int GetElem(int i);//取第i个结点的值 
    int LocateElem(int e);//找出值为e的元素是第几个元素 
    bool ListInsert(int i, int e);//第i个位置插入元素e 
    bool ListDelete(int i);//删除第i个元素 
    void PrintList();//输出链表 
public:
    void initList(); // wrchow
    void initList(string); // wrchow
private: 
    LNode *head;//头指针 
};
void MyList::InitList(int n)
{ 
    int x;
    head = new LNode;
    head->next = NULL;
    for(int i=n;i>0;--i){
        cin>>x;
        LNode *p = new LNode;
        p->data = x;
        p->next = head->next;
        head->next = p;
    }
}

void MyList::DestroyList()
{ 
    delete head;
    cout<<"表摧毁了!"<<endl;
}
void MyList::ClearList()
{ 
    head->next = NULL;
    cout<<"清空完毕!"<<endl;
}
bool MyList::ListEmpty()
{
    if(head->next == NULL) return true; else return false;
}
int MyList::ListLength()
{
    LNode *p=head;
    int j=0;
    while(p->next){ 
        p=p->next; 
        j++; 
    } 
    return j;
}
int MyList::GetElem(int i)
{ 
    int j=1;
    LNode *p=head->next;//第一个结点 if(i<1) return NULL;
    while(p&&j<i){
        p=p->next; 
        j++; 
        } 
    return p->data;
}
int MyList::LocateElem(int e)
{
    int i=0; LNode *p=head->next;
    while(p!=NULL&&p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p==NULL) return 0;
    else return i+1;
}
bool MyList::ListInsert(int i, int e)
{ 
    LNode *p, *s;
    int j=1;
    p=head;
    while(p&&j<i)
    {p=p->next;j++;}
    if(p==NULL) return false;
    if((s = new LNode)==NULL) return false;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
bool MyList::ListDelete(int i)
{ 
    LNode *p,*q;
    int j=1;
    p=head;
    while(p&&j<i)
    { p=p->next;j++;}
    if(p==NULL) return false;
    q=p->next;
    p->next=q->next;
    delete q;
    return true;
}
void MyList::PrintList()
{ 
    if(ListEmpty()){ 
        cout<<"表是空的！"<<endl;
    } else { 
        cout<<"表中元素为:";
        LNode *p = head->next;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}

/////////wrchow/////////
void MyList::initList()
{
    head = new LNode;
    head->next = NULL;
}


int main(int argc,char *argv[])
{
    string str = argv[1]; 
    MyList mlist;    
    cout << "isEmpty : " << mlist.ListEmpty() << endl;
    cout << "init List(int) :" << mlist.InitList(str) << endl;
    return 0;
}
