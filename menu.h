#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <stdlib.h>
using namespace std;
void menu(){
	cout<<"============="<<endl;
	cout<<"1.Fill Qeque 1"<<endl;
	cout<<"2.Fill Queue 2"<<endl;
	cout<<"3.See Qeque 1"<<endl;
	cout<<"4.See Queue 2"<<endl;
	cout<<"5.See result"<<endl;
	cout<<"6.Sort"<<endl;
	cout<<"7.Exit"<<endl;
	cout<<"============="<<endl;
}
void press_menu(int &ch){
	menu();
	cin>>ch;
	while((!cin)||(ch<1)||(ch>7)){
		system("cls");
		cin.clear();
		cin.ignore(32767,'\n');
		menu();
		cin>>ch;
	}
}

#endif // MENU_H_INCLUDED
