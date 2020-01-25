#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include<string>

/*
百钱买百鸡
a:  鸡翁 5
b： 鸡母 3
c:  鸡雏 1

*/
int g[1000000],m[1000000],s[1000000];
void chicken_question(int n,int &k,int g[],int m[],int s[]);
void chicken_question2(int n,int &k,int g[],int m[],int s[]);
void chicken_question3(int n,int &k,int g[],int m[],int s[]);

int main()
{
int k=0;
int n=15000000,c=0;
double  duration1,duration2,duration3;
clock_t start, finish;
printf("请输入n的值\n");


//while(c<=10){
/*
start = clock();
chicken_question(n,k,g,m,s);
finish = clock();
duration1 = (double)(finish - start)/ CLOCKS_PER_SEC;  //转化为秒
printf( "\n算法1运行%d次的时间为%f seconds\n",n,duration1 );

start = clock();
chicken_question2(n,k,g,m,s);
finish = clock();
duration2 = (double)(finish - start)/ CLOCKS_PER_SEC;  //转化为秒*/
start = clock();
chicken_question3(n,k,g,m,s);
finish = clock();
duration3 = (double)(finish - start)/ CLOCKS_PER_SEC;  //转化为秒

//printf( "\n算法2运行%d次的时间为%f seconds\n",n,duration2 );
printf( "\n算法3运行%d次的时间为%f seconds\n",n,duration3 );

//c++;
//n+=1000;}


/*
while(c<=10){
start = clock();
chicken_question2(n,k,g,m,s);
finish = clock();
duration = (double)(finish - start)/ CLOCKS_PER_SEC;  //转化为秒
printf( "\n%f seconds\n", duration );
c++;
n+=1000;
}
*/


system("pause");//
return 0;
}



// 公鸡 母鸡 小鸡的数目为 g[] m[] s[]  三种鸡购买的总数目为n  问题的解数目为k
void chicken_question(int n,int &k,int g[],int m[],int s[])
{
int a,b,c;
k = 0;
for (a=0;a<=n;a++)
{
	for(b=0;b<=n;b++)
	{
		for(c=0;c<=n;c++)
		{
			  if((a+b+c == n)&&(5*a + 3*b + c/3 == n)&&(c%3==0))
			  {
			  g[k] = a;
			  m[k] = b;
			  s[k] = c;
            //printf("g[%d]=%d,m[%d]=%d,s[%d]=%d\n",k,a,k,b,k,c);
			  k++;

			  }
		}
	}
}
}

void chicken_question2(int n,int &k,int g[],int m[],int s[])
{
int i,j,a,b,c;
k = 0;
i = n/5;
 j = n/3;
for (a=0;a<=i;a++)
{

	for(b=0;b<=j;b++)
	{
	    c = n -a-b;
 if(5*a + 3*b + c/3 == n && c%3==0)
			  {
			  g[k] = a;
			  m[k] = b;
			  s[k] = c;
              printf("g[%d]=%d,m[%d]=%d,s[%d]=%d\n",k,a,k,b,k,c);
			  k++;
			  }

	}
}
}


void chicken_question3(int n,int &k,int g[],int m[],int s[])
{
int x,y,z;
k = 0;
for(int k1=0;k1<=n/28;k1++)
{

    x = 4*k1;
    y = n/4 -7*k1;
    z = (3*n)/4+3*k1;
       if(5*x + 3*y + z/3 == n && z%3==0)
        {
            g[k] = x;
            m[k] = y;
            s[k] = z;
            printf("g[%d]=%d,m[%d]=%d,s[%d]=%d\n",k,x,k,y,k,z);
            k++;
        }

}
}
