#include<iostream>
#include<string>
using namespace std;
char a[100][20];
int rows = 0;
int ful_col = 0;
void fill(int col){
    string str;
    cin >> str;
    int len = str.size();
    for(int i=0;i<len;i++){
        int r = i/col;
        int c = r%2!=0?col-i%col-1:i%col;
        a[r][c] = str[i];
    }
    if(len%col==0){
        rows = len/col;
        ful_col= col;
    }
    else{
        rows = len/col+1;
        ful_col = len%col;
    }
    //rows = len%col==0?len/col:len/col+1;
    //ful_col = len%col==0?col:len%col;
}

void print(int col){
    bool end = false;
    for(int j=0;j<col;j++){
            if(j>=ful_col&&!end){
                rows--;
                end = true;
            }
            for(int i=0;i<rows;i++){
                cout << a[i][j];
            }
    }
    cout << endl;
}


int main()
{
    int col;
    while(cin>>col){
        if(col==0)
            break;
        fill(col);
        print(col);

    }


    return 0;
}
