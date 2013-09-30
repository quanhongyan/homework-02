#include<stdio.h>
#include<stdlib.h>
int getsum(int s[100],int n,int t[100],int *p1,int *p2)//处理一维数组子程序
{
	int i,j1=0,j2=0;
	int sum=0;
	int x=0;
	for(i=0;i<n;i++)
	{
		if(x>0)
		{
			x+=s[i];
			t[j1++]=s[i];
		}
		else
		{
		    x=s[i];
			t[j1++]=s[i];
			*p1=i;
		}
		if(x>sum)
		{
			sum=x;
			*p2=i;
		}
	}
	return sum;
   
}
int getsum(int s[100][100],int x1,int y1,int x2,int y2)//子矩阵求和函数
{
	int i,j;
	int sum=0;
	for(i=x1;i<=x2;i++)
		for(j=y1;j<=y2;j++)
		{
			sum+=s[i][j];

		}
		return sum;
}
int main(){
	FILE*in;
	int m,n;
    int sum;
	int i=0,j,k;

	int s1[100];
	int t[100];
	int *p1,*p2;
	int t1,t2;
	p1=&t1;
	p2=&t2;

	char ch;
	int s2[100][100];
	int max=0;
    int x1,y1,x2,y2;
	int w1,w2,w3,w4;
	
    

	if((in=fopen("input2.txt","r"))==NULL)//本程序的测试文件有input.txt(测试一维数组)，input2.txt(测试矩阵)
	{
		printf("can't open file");
		exit(0);
	}
	    ch=fgetc(in);
		m=ch-'0';
        //printf("%d\n",m);

		fgetc(in);

		ch=fgetc(in);
		n=ch-'0';
        //printf("%d\n",n);

		if(m==1){//当只有一行，即处理一维数组
			for(i=0;i<n;i++){
			ch=fgetc(in);
			fscanf(in,"%d",&s1[i]);
			}
			sum=getsum(s1,n,t,p1,p2);
			printf("一维数组最长子数组和为：");
			printf("sum=%d\n",sum);
			printf("一维数组最长子数组为：");
	        for(i=t1;i<=t2;i++)printf("%d  ",t[i]);
	        printf("\n");
            printf("子数组在原数组中的位置为：%d-%d",t1+1,t2+1);
	        printf("\n");
		}
		else
		{
			for(i=0;i<m;i++)
				for(j=0;j<n;j++)
				{
					ch=fgetc(in);
					fscanf(in,"%d",&s2[i][j]);

				}
				for(x1=0;x1<m;x1++)
		           for(y1=0;y1<n;y1++)
			         for(x2=x1;x2<m;x2++)
				        for(y2=y1;y2<n;y2++)//穷举法进行查找和求最大和
						{
					      sum=getsum(s2,x1,y1,x2,y2);
					      if(sum>max)
						  {
						   max=sum;
						   w1=x1;w2=y1;w3=x2;w4=y2;
						  }
						}
		    printf("二维数组和最大子矩阵的和为：%d\n",max);
		    printf("子矩阵对应的两个顶点为：x1=%d y1=%d x2=%d y2=%d ",w1,w2,w3,w4);
		    printf("\n");
		}


    fclose(in);
    return 0;



}