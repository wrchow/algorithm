// refer to http://wenku.baidu.com/view/4a226426a5e9856a5612601b.html

#include <stdio.h>
#include <unistd.h>
int factorial (int n);
int main(int argc, char **argv)
{
    int n;
    if(argc < 2)
    {
        printf("Usage:%s n\n",argv[0]);
        return -1;
    }
    else
    {
        n = atoi(argv[1]);
        printf("Factorial of %d is %d.\n", n, factorial(n));
    }
    return 0;
}




