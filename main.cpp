#include "menu.h"
#include "Queue.h"
#include "Sort.h"
int main()
{
	Queue<int> curr1;
	Queue<int> curr2;
	Queue<int> result;
	int buff_data,chm=0,errcode=0,time_buff;
	size_t lenght1,lenght2;
	while (chm!=7){
		press_menu(chm);
		if(chm==1){
			system("cls");
			cout<<"press lenght >>"<<endl;
			cin>>lenght1;
			while((lenght1<1)||(!cin)){
				system("cls");
				cin.clear();
				cin.ignore(32767,'\n');
				cout<<"press lenght >>"<<endl;
				cin>>lenght1;
			}
			curr1.make_empty();
			time_buff=INT_MIN;
			for(size_t i=0;i<lenght1;i++){
                system("cls");
                cout<<"["<<i+1<<"] :";
                cin>>buff_data;
                while((!cin)||(buff_data<time_buff)){
                   system("cls");
                   cin.clear();
                   cin.ignore(32767,'\n');
                   cout<<"invalid data"<<endl;
                    cout<<"["<<i+1<<"] :";
                   cin>>buff_data;
                }
                curr1.Push(buff_data);
                time_buff=buff_data;
			}
            chm=0;
		}
		if(chm==2){
            system("cls");
			cout<<"press lenght >>"<<endl;
			cin>>lenght2;
			while((lenght2<1)||(!cin)){
				system("cls");
				cin.clear();
				cin.ignore(32767,'\n');
				cout<<"press lenght >>"<<endl;
				cin>>lenght2;
			}
			curr2.make_empty();
            time_buff=INT_MIN;
			for(size_t i=0;i<lenght2;i++){
                system("cls");
                cout<<"["<<i+1<<"] :";
                cin>>buff_data;
                while((!cin)||(buff_data<time_buff)){
                   system("cls");
                   cin.clear();
                   cin.ignore(32767,'\n');
                   cout<<"invalid data"<<endl;
                    cout<<"["<<i+1<<"] :";
                   cin>>buff_data;
                }
                curr2.Push(buff_data);
                time_buff=buff_data;
			}
            chm=0;
		}
        if(chm==3){
            system("cls");
            if(curr1.isEmpty())cout<<"Queue 1 Empty"<<endl;
            else{
                Queue<int> buff(curr1);
                while(!buff.isEmpty()){
                    buff.Pop(buff_data);
                    cout<<buff_data<<" ";
                }
                cout<<endl;
            }
            chm=0;
        }
        if(chm==4){
            system("cls");
            if(curr2.isEmpty())cout<<"Queue 2 Empty"<<endl;
            else{
                Queue<int> buff(curr2);
                while(!buff.isEmpty()){
                    buff.Pop(buff_data);
                    cout<<buff_data<<" ";
                }
                cout<<endl;
            }
            chm=0;
        }
        if(chm==5){
            system("cls");
            if(result.isEmpty())cout<<"result Queue empty"<<endl;
            else{
                Queue<int> buff(result);
                while(!buff.isEmpty()){
                    buff.Pop(buff_data);
                    cout<<buff_data<<" ";
                }
                cout<<endl;
            }
            chm=0;
        }
        if(chm==6){
            system("cls");
            result.make_empty();
            int check=Sort(curr1,curr2,result);
            if(check==1){
                cout<<": ERROR EMPTY QUEUE "<<endl;
            }
            else{
                cout<<"RESULE QUEUE EXCELLENT FILL "<<endl;
                cout<<"Press 5 for see result"<<endl;
            }
            chm=0;
        }

	}
    return 0;
}
