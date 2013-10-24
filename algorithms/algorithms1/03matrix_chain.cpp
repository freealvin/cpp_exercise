#include<iostream>

using namespace std;

/*
求连乘矩阵最优计算次序
*/
void matrix_chain(int *p, int len,int min[][20],int s[][20])
{
    int n = len;
    //初始化min
    for(int i=1;i<=n;i+=1)    min[i][i] = 0;
    
    for(int chain_len=2;chain_len<=n;chain_len+=1)//子矩阵链的长度
    {
        for(int i=1;i<=n-chain_len+1;i+=1)//i<-[1:长度为chain_len的子矩阵链的结尾]
	{
	    int j = i+chain_len-1;//子矩阵链的结尾位置
	    min[i][j] = min[i][i] + min[i+1][j] + p[i-1]*p[i]*p[j];//k=i
	    s[i][j] = i;

	    for(int k=i+1; k<j; k+=1)
	    {
	        int tmp = min[i][k] + min[k+1][j] + p[i-1]*p[k]*p[j];
		if(tmp < min[i][j])
		{
		    min[i][j] = tmp;
		    s[i][j] = k;
		}
	    }
	}
    }
}

void traceback(int i, int j, int s[][20])
{
    if(i==j) return;
    traceback(i, s[i][j], s);
    traceback(s[i][j]+1, j, s);
    cout << "multiply A" << i<< ',' << s[i][j] << "and A" << s[i][j]+1 << ',' << j << endl;
}

int main()
{
    int p[20] = {30, 35, 15, 5, 10, 20, 25};
    int min[20][20];
    int s[20][20];
    int len = 6;
    matrix_chain(p, len, min, s);
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++)
        cout << "A[" << i << ',' << j << "]=" << min[i][j] << endl;
    }

    traceback(1, 6, s);

    return 0;
}
