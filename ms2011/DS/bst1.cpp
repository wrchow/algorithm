#include <cstdlib>
#include <iostream>
using namespace std;
template<class Key>
class BST
{
  public:
   struct Node
      {
          Key keydata;
          Node *left;
          Node *right;
          Node(){}
          Node(Key i):keydata(i),left(NULL),right(NULL){}
      };
   Node *root;
   BST():root(NULL){}
   
   void travel(const Node *tree){                      /*中序遍历*/
       if(tree!=NULL){
         travel(tree->left);
         cout<<tree->keydata<<'\t';
         travel(tree->right); 
         }
     }
   void clear(Node *&tree){                             /*清空*/
       if(tree==NULL)return;
       else{
         clear(tree->left);             
         clear(tree->right);
         delete tree;
        }
        tree=NULL;
     }
    void insert(Node *&tree,Node *p){                             /*插入节点，记得&引用*/
       if(tree==NULL)tree=p;
       else if(p->keydata<tree->keydata)
              insert(tree->left,p);
             else
               insert(tree->right,p); 
        }
    void insertdata(const Key ni){                        /*插入数据，代替上面的函数以提供更好的接口*/ 
            insert(root,new Node(ni));           
      } 
    bool find(Node *tree,const Key i,Node *&p){           /*查找节点*/
       if(tree==NULL)
       {p=tree;return false;}
       else
          if(tree->keydata==i)
            {p=tree;return true;}
          else if(tree->keydata>i)
            find(tree->left,i,p);
          else 
            find(tree->right,i,p);
     }
    void erase(Node *&tree,Key i){                                  /*删除节点，必须用引用 */
        if(tree==NULL) return;
        else{
           if(tree->keydata>i)
             erase(tree->left,i);
           else if(i>tree->keydata)
             erase(tree->right,i);
           else{
             insert(tree->right,tree->left);         
             Node *tem=tree;
             tree=tree->right;
             delete tem;               
             }
           }
      }
    void update(const Key oi,const Key ni){
           erase(root,oi);
           insert(root,new Node(ni));
      }
    int Depth(Node* tree){                                           /*返回树深*/
        int l=1,r=1;
        if (tree==NULL) return 0;
        l+=Depth(tree->left);
        r+=Depth(tree->right);
        return l>r?l:r;
      }
    void print(Node *tree, int level) const{            //打印树形  
         if (tree == NULL) return;                
            print(tree->left, level+3);       
         for (int i=0; i<level; i++)                   
         cout << "  ";
            cout << tree->keydata << "\n";             
         print(tree->right, level+3);       
     }
};
 
/*测试代码*/
int main(int argc, char *argv[])
{
    BST<int>tree;
    int datas[]={7,3,8,0,9,5,6,4,2,1};
    cout<<"插入数据中......\n";
    for(int i=0;i<10;i++)
       tree.insertdata(datas[i]);
    cout<<"插入成功。\n";
    cout<<"按任意键继续：";
    cin.get();
    cout<<"中序遍历：\n"; 
    tree.travel(tree.root);
    //cout<<"左序遍历：\n";
    //tree.travel_left(tree.root);  
    system("PAUSE");
    return EXIT_SUCCESS;
}