#include<iostream>
using namespace std;

typedef int T;

    struct Node{
        T data;
        Node * next;
        Node(const T& d):data(d), next(NULL){
        }

        operator T(){
            return data;
        }

    };
class List{
    Node * head;
    int n;
    public:
        List():head(NULL), n(0){}
        void push_front(const T & a){
            Node *p = new Node(a);
            p->next = head;
            head = p;
        }

        void init_list(int n){
            this->n = n;
            for(int i=0;i<n;i++){
                int temp;
                cin >> temp;
                push_front(temp);
            }
        }
        void print(){
            Node *p = head;
            while(p!=NULL){
                cout << *p << ' ';
                p = p->next;
            }
            cout << endl;
        }

        Node * getHead()const{
            return head;
        }

        ~List(){
            while(head!=NULL){
                Node *p = head;
                head = head->next;
                //cout << "delte " << *p << endl;
                delete p;
            }
        }
};

bool interset(const List &list1, const List &list2)
{
    if(list1.getHead()!=NULL&&list2.getHead()!=NULL){
        Node * p = list1.getHead();
        Node * q = list2.getHead();
        while(p!=NULL){
            while(q!=NULL){
                if(p->data==q->data)
                    return true;
                q = q->next;
            }
        p = p->next;
        }
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t>0){
        int m, n;
        cin >> m >> n;
        List list1;
        List list2;

        list1.init_list(m);
        list2.init_list(n);
        list1.print();
        list2.print();
        cout << boolalpha << interset(list1, list2) << endl;
        t--;
    }
}
