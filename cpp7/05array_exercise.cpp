#include<iostream>
#include<exception>
#include<cstdlib>
#include<cstdio>

using namespace std;

class Outofrange : public exception
{
    int index;
    int maxsize;
    char buf[100];
    public:
        Outofrange(int index, int maxsize):index(index), maxsize(maxsize){
            sprintf(buf, "%d is out of rang, please enter a number between 0 and %d", index, maxsize);
        }

        const char * what()const throw(){
            return buf;
        }
};

class Array{
    int max_size;
    int *p;
    public:
        Array(int max_size);
        friend istream &operator>>(istream &in, Array &arr){
            int i = 0;
            for(i=0;i<arr.max_size;i++){
                in >> arr.p[i];
            }

            return in;

        }

        friend ostream & operator << (ostream & out, const Array &arr){
            int i;
            out << '[';
            for(i=0;i<arr.max_size-1;i++){
                out << arr.p[i] << ' ';
            }
            cout << arr.p[arr.max_size-1] << ']';

            return out;
        }

        int size(){
            return max_size;
        }


        ~Array(){
            free(p);
            cout<<"释放数组空间"<< endl;
        }


        int operator[](int index)throw(Outofrange){
            cout << "max_size:" << max_size << ',' << " index:" << index << endl;
            if(index >= max_size|| index<0){
                cout << "出错了" << endl;
                throw Outofrange(index, max_size);
            }
            else{
                return p[index];
            }

        }
};

Array::Array(int max_size):max_size(max_size){
    p = (int *) malloc(sizeof(int)*max_size);
}

int main()
{

    Array arr(3);
    cin >> arr;
    cout << arr << endl;
    int index;
    cin >> index;
    try{
        cout << arr[index] << endl;
    }
    catch(exception& ex){
       cout<< ex.what() << endl;
    }

    cout << "end of main" << endl;
    return 0;

}
