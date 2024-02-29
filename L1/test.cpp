#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int info;
    struct Node *next;

public:
    Node()
    {
    }
    Node(int info)
    {
        Node node;
        node.info = info;
        node.next = nullptr;
    }
};

class List
{
private:
    Node *head;

public:
    List()
    {
        this->head = nullptr;
    }

    void print()
    {
        Node *ptr = this->head;
        while (ptr != nullptr)
        {
            cout << ptr->info << endl;
            ptr = ptr->next;
        }
    }
    void append(int info)
    {
        Node *nodeToAdd = new Node(info);
        if (this->head == nullptr)
        {
            this->head = nodeToAdd;
            return;
        }
        Node *crt = this->head;
        while (crt->next != nullptr)
        {
            crt = crt->next;
        }
        crt->next = nodeToAdd;
    }

    ~List()
    {
        cout << "Destructor apelat";
        Node *crt = this->head;
        while (crt != nullptr)
        {
            Node *toDelete = crt;
            crt = crt->next;
            delete toDelete;
        }
    }
};

int main()
{
    List list;
    list.append(10);
    list.append(20);
    list.print();
    return 0;
}