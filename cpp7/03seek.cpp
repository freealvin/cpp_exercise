#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void encode(char *buf, int count){
    int i;
    for(i=0;i<count;i++)
        buf[i] = buf[i]+1;
}

void decode(char *buf, int count)
{
    int i;
    for(i=0;i<count;i++)
        buf[i] = buf[i] - 1;
}

int main(int argc, char * argv[])
{
    //使用方式 a.out -d|-e 文件名
    if(argc!=3||strcmp(argv[1],"-e")&&strcmp(argv[1], "-d"))
    {
        cout << argv[0] << "-e|-d"<< endl;
        return 1;

    }

    fstream fs(argv[2], ios::binary|ios::in|ios::out);
    if(!fs){
        cout << "can not open file " << argv[2] << endl;
        return 1;
    }

    void(*p)(char *, int) = argv[1][1]=='e'?encode:decode;//使用函数指针

    char buf[100];
    bool ok = true;
    int pos1=0, pos2;
    int count = 0;
    while(ok){
        fs.seekg(pos1);
        fs.read((char*)buf, sizeof(buf));
        if(!fs){
            ok = false;
            fs.clear();
        }

         pos2 = fs.tellg();
         count = fs.gcount();
         p((char*)buf,count);
         fs.seekp(pos1);//.seekp(bytes, ios::cur)
         fs.write((char*)buf, count);
         pos1 = pos2;
    }

    return 0;
}
