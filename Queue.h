#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include<bitset>
#include<iostream>
using namespace std;
template<typename T>
class Queue{
private:
    struct Node{     // ���� ������
        T Data;      // �������� ����
        Node *next,*prev;   //������ �� ��������� � ���������� ����
    };
    typedef Node* PNode;
    size_t Size;        // ������
    int errcode;
    PNode Head,Tail;     // ������ � ����� (������ �� ����_)
public:
    Queue():Head(NULL),Tail(NULL),Size(0){};      // ����������� �� ���������( ��� �� �����)
    Queue(Queue<T> &current){     // ����������� �����������
        Head=NULL;
        Tail=NULL;
        Size=0;
        Queue<T> buff;
        T buff_data;
        while(!current.isEmpty()){
            current.Pop(buff_data);
            Push(buff_data);
            buff.Push(buff_data);
        }
        while(!buff.isEmpty()){
            buff.Pop(buff_data);
            current.Push(buff_data);
        }
    }
    bool isEmpty(){return ((!Head)||(!Tail))?true:false;} //���� ? ��:���
    size_t get_size(){return Size;}    // ������� ������
    void err_clear(){errcode=0;}      // ��������� ������
    unsigned err_get(){return errcode;} //������� ������
    unsigned Push(T _Data){          //�������� � �����
        PNode p=new Node;           // ������� ����� ����
        unsigned out=0;
        if(p==NULL)out=1;          // �������� ���������� �� ������ ?
        else{
            Size++;
            p->Data=_Data;
            p->prev=Tail;
            p->next=NULL;
            if(Tail)Tail->next=p;
            Tail=p;
            if(!Head)Head=Tail;
        }
        return out;
    }
    unsigned Pop(T &_Data){  //����� �� ������
        unsigned out=0;
        if(isEmpty())out=1;
        else{
            Size--;
            PNode p=Head;
            _Data=p->Data;
            Head=p->next;
            if(Head)Head->prev=NULL;
            else Tail=NULL;
            delete p;
        }
        return out;
    }
    void get(T &_Data){   // ����������� �������
        if(!isEmpty()){
            PNode p =Head;
            _Data=p->Data;
        }
    }
    void make_empty(){  //������� ������
        if(!isEmpty()){
            PNode p=Head;
            while(p->next){ // ���� ��������� ���������� ��������� ������
                p=Head;
                Head=p->next;
            }
            Tail=NULL;
            Size=0;
        }
    }
    ~Queue(){make_empty();}
};
#endif // QUEUE_H_INCLUDED
