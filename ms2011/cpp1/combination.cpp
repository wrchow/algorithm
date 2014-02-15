// by wr-chow at 2011-3-10
// refer to http://zhidao.baidu.com/question/48996976.html

//递归法
//分析所列的10个组合，可以采用这样的递归思想来考虑求组合函数的算法。
//设函数为void    comb(int m,int k)为找出从自然数1、2、... 、m中任取k个数的所有组
//合。当组合的第一个数字选定时，其后的数字是从余下的m-1个数中取k-1数的组合。这
//就将求m个数中取k个数的组合问题转化成求m-1个数中取k-1个数的组合问题。设函数引
//入工作数组a[ ]存放求出的组合的数字，约定函数将确定的k个数字组合的第一个数字放
//在a[k]中，当一个组合求出后，才将a[ ]中的一个组合输出。第一个数可以是m、m-1、
//...、k，函数将确定组合的第一个数字放入数组后，有两种可能的选择，因还未去顶组
//合的其余元素，继续递归去确定；或因已确定了组合的全部元素，输出这个组合。细节
//见以下程序中的函数comb。
 

#include <time.h>
#include <iostream>

using namespace std;

# define      MAXN      100
int a[MAXN];
int counts=0;

 

void comb(int m, int k)
{     
	int i,j;
    for (i = m; i >= k; i--)
      {    
		  a[k] = i;
          if (k > 1)
              comb(i-1, k-1);
          else
          {   
              counts++;
              /*for (j = a[0]; j  > 0; j--)
                  printf("%4d",a[j]);
              printf("\n");*/
          }
      }
}

int main()
{   
	 time_t start = 0;
     time_t end   = 0;
     int m, r;
     cout << "m = ";     cin >> m;
     cout << "r = ";     cin >> r;
     counts = 0;
     a[0] = r;
	 start = time(0);
     comb(m, r);
	 end = time(0);
     cout << counts << endl;
	 printf("Total time is %d s.\n", end - start);
     return 0;
}

