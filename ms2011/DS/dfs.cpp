// dfs() 图的深度优先遍历 / 邻接矩阵
// by wr-chow at 20111015
// refer to http://blog.csdn.net/lalor/article/details/6845788
// 1. dfs   图的深度优先遍历;
// 2. dfs2  通过深度遍历判断图是否有环/从所有顶点开始深度遍历，
//          并判断其后继顶点是否已被访问;如果需要打印环的话，用
//          2来标记visit[]中的当前访问节点；

#include<iostream>  
using namespace std;  
#define  MAX_NODE 4  
bool visited[MAX_NODE] ;  
int stack[ MAX_NODE] ; 
int Matric[4][4] = { // A-B-C-D(-A) // 无向图
    {0,1,0,0}, 
    {0,0,1,0},
    {0,0,0,1},
    {0,0,0,0},
};
int Matric1[12][12] =  {  
     {-1,1,1,0,0,0,0,0,0,0,0,0},  
     {1,-1,1,0,1,1,0,0,0,0,0,0},  
     {1,1,-1,1,0,0,0,0,0,0,0,0},  
     {0,0,1,-1,1,0,0,0,0,0,1,1},  
     {0,1,0,1,-1,0,0,0,0,0,0,0},  
     {0,1,0,0,0,-1,0,0,0,0,1,0},  
     {0,0,0,0,0,0,-1,1,1,1,0,0},  
     {0,0,0,0,0,0,1,-1,0,0,0,0},  
     {0,0,0,0,0,0,1,0,-1,1,1,0},  
     {0,0,0,0,0,0,1,0,1,-1,0,1},  
     {0,0,0,1,0,1,0,0,1,0,-1,0},  
     {0,0,0,1,0,0,0,0,0,1,0,-1},   
}; 

void dfs(int);
bool icdfs(int);
bool isCircle();

int main(int argc,char *argv[])  
{  
    dfs(1);  
    cout << isCircle() << endl;
    return 0 ;  
}  

void dfs(int v) {  
    cout << " v"<< v ;  
    int top = -1 ;  
    visited[v] = true;  
    stack[++top] = v ;  
    while (top != -1) {  
        v = stack[top] ;  
        int i;
        for ( i = 0 ; i < MAX_NODE ; i++)  {  
            if (Matric[v][i] == 1 &&!visited[i]) {  
                cout << " v" << i ;  
                visited[i] = true ;  
                stack[ ++top ] = i ;  
                break ;  
            }  
        }  
        if( i == MAX_NODE)  {  
           top -- ;  
        }  
    }  
    cout << endl;
}

bool icdfs(int v) {
    cout << " v"<< v;  
    int top = -1;  
    visited[v] = true;  
    stack[++top] = v;  
    while (top != -1) {  
        v = stack[top];  
        int i;
        for (i = 0; i < MAX_NODE; i++) {  
            if (Matric[v][i] == 1 && !visited[i]) {  
                cout << " v" << i ;  
                visited[i] = true ;  
                stack[++top] = i ;  
                break;  
            }  
        }  
        // 判断i的后继节点是否访问过（无向图）
        for (int j=0; j<MAX_NODE; j++)
            if (Matric[i][j] == 1 && visited[j] && j != v) {
                cout << endl;
                return false;
            }
        if(i == MAX_NODE) {  
           top -- ;  
        }  
    }  
    cout << endl;
    return true;
}

bool isCircle(){
    for (int i=0; i<MAX_NODE; i++) {
        if (icdfs(i) == false) return true;
    }
    return false;
}