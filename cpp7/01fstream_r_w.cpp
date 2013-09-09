#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(int argc, char* argv [])
{
    //a.out 源文件 目标文件
    if(argc!=3){
        cout << argv[0] << " 源文件 新文件" << endl;
        return 1;
    }

    ifstream fin(argv[1], ios::binary|ios::in);
    ofstream fout(argv[2], ios::binary|ios::out);
    if(!fin){
        cout << "打开" << argv[1] << "失败" << endl;
        return 1;
    }

    if(!fout){
        cout << "打开" << argv[2] << "失败" << endl;
        return 2;
    }


    char buf[1024];

    while(fin){
        fin.read(buf, sizeof(buf));
        int i;
        for(i=0;i<fin.gcount();i++){
            buf[i] = buf[i]+1;
        }
        fout.write(buf, fin.gcount());//.gcount()返回最后一次读取的字节数
    }

    fin.close();
    fout.close();

    return 0;
}
