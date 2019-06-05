#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include "Queue.h"
template<typename T>
/**
*@in очереди остортированные от дна к верхушке по неубыванию
*@sort функция совмещает две очереди в одну упорядоченную по невозрастанию
*@out очередь упорядоченная по невозрастанию из двух входных
*/
int Sort(Queue<T> &temp1,Queue<T> &temp2,Queue<T> &out){
    int ret=0;
    Queue<T> t1(temp1);
    Queue<T> t2(temp2);
    if(t1.isEmpty()||t2.isEmpty())ret=1;
    else{
        T buff1;
        T buff2;
        while(!t1.isEmpty()&&!t2.isEmpty()){
            t1.get(buff1);
            t2.get(buff2);
            if(buff1>=buff2){
                t2.Pop(buff2);
                out.Push(buff2);
            }
            else{
                t1.Pop(buff1);
                out.Push(buff1);
            }
        }
        while(!t1.isEmpty()){
            t1.Pop(buff1);
            out.Push(buff1);
        }
        while(!t2.isEmpty()){
            t2.Pop(buff2);
            out.Push(buff2);
        }
    }
    return ret;
}


#endif // SORT_H_INCLUDED
