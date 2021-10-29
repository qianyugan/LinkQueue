#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

class linkqueue{
public:
    linkqueue();
    ~linkqueue();
    void enQueue(int x);
    int deQueue();
    int getHead();
    int isEmpty();
private:
    node *front, *rear;
};

linkqueue::linkqueue(){
    node *s = NULL;
    s = new node;
    s -> next = NULL;
    front = rear = s;
}

linkqueue::~linkqueue(){
    node *s = NULL;
    while(front->next != NULL){
        s = rear;
        rear = s-> next;
        delete(s);
    }
}

void linkqueue::enQueue(int x){
    node *s = NULL;
    s = new node;
    s->data = x;
    s->next = NULL;
    rear->next = s;
    rear = s;
}

int linkqueue::deQueue(){
    int x = 0;
    node *s = NULL;
    if(rear == front) throw"Dequeue Error.";
    s = front->next;
    front->next = s->next;
    x = s->data;
    if(s->next == NULL) rear = front;
    delete s;
    return x;
}

int linkqueue::getHead(){
    return front->next->data;
}

int linkqueue::isEmpty(){
    if(front == rear) return -1;
    else return 0;
}

int main(){
    linkqueue ls;
    int x;
    for(int i = 0; i < 100; i++) ls.enQueue(i);
    cout << "Top element is: " << ls.getHead() << endl;

    try{
        x = ls.deQueue();
        cout << "Linkqueue pop. Delete " << x << endl;
    }catch(char*str){ cout << str << endl; }

    try{
        cout << "Input x:" << endl;
        cin >> x;
        ls.enQueue(x);
    }catch(char*str){ cout << str << endl; }

    if(ls.isEmpty() == -1) cout << "Linkqueue is empty." << endl;
    else cout << "Linkqueue is not empty" << endl;
    for(int i = 0; i < 100, ls.isEmpty() != -1; i++){
        cout << ls.deQueue() << " ";
    }
    return 0;
}
