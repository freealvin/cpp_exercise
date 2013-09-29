#include<iostream>
#include<fstream>
#include<string>
#include<mutex>
#include<thread>
using namespace std;

class Logfile{
    ofstream _f;
    std::mutex _mu;
    public:
        Logfile(){
            _f.open("log.txt");
        }

        void shared_print(string id, int value){
            std::lock_guard<mutex> locker(_mu);
            _f << "From " << id << ":" << value << endl;
        }

};

void function_1(Logfile &log)
{
    for(int i=0;i>-1000;i--){
        log.shared_print("t1", i);
        //sleep(1);
    }
}


int main()
{
    Logfile log;
    std::thread t1(function_1, std::ref(log));
    for(int i=0; i<1000; i++)
        log.shared_print(string("main"), i);
    t1.join();
    return 0;
}
