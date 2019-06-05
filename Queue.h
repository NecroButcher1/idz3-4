#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include<bitset>
#include<iostream>
using namespace std;
template<typename T>
class Queue{
private:
    struct Node{     // узед списка
        T Data;      // значение узла
        Node *next,*prev;   //ссылки на следующий и предыдущий узлы
    };
    typedef Node* PNode;
    size_t Size;        // размер
    int errcode;
    PNode Head,Tail;     // голова и хвост (ссылка на узел_)
public:
    Queue():Head(NULL),Tail(NULL),Size(0){};      // конструктор по умолчанию( все по нулям)
    Queue(Queue<T> &current){     // конструктор копирования
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
    bool isEmpty(){return ((!Head)||(!Tail))?true:false;} //пуст ? да:нет
    size_t get_size(){return Size;}    // вернуть размер
    void err_clear(){errcode=0;}      // отчистить оштбку
    unsigned err_get(){return errcode;} //вернуть ошибку
    unsigned Push(T _Data){          //добавить в конец
        PNode p=new Node;           // создаем новый узел
        unsigned out=0;
        if(p==NULL)out=1;          // проверка выделилась ли память ?
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
    unsigned Pop(T &_Data){  //взять из начала
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
    void get(T &_Data){   // просмотреть элемент
        if(!isEmpty()){
            PNode p =Head;
            _Data=p->Data;
        }
    }
    void make_empty(){  //сделать пустым
        if(!isEmpty()){
            PNode p=Head;
            while(p->next){ // пока следующий существует двигаемся вперед
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
