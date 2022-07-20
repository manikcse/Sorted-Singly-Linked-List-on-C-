#include <iostream>
#include "Sorted_List.h"

// Name: Manik Debnath
// Student ID.: 2021124913

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	Sorted_single_list test;
	
	test.push_front(75);
	test.push_front(63);
	test.push_front(50);
	test.push_front(44);
	test.push_front(37);
	test.push_front(33);
	test.push_front(29);
	test.push_front(25);
	test.push_front(17);
	
//test.display();
	
//Our Main List
	test.display();
	cout<<"This is Main list  size is "<<test.size()<<endl;
	cout<<"\n";
	cout<<"The front element in list:  "<<test.front()<<endl;
	cout<<"------------------------------------------------------------";
	
	
//pushing element in first node in the list
	cout<<"\n";
	test.push_front(13);
	test.display();
	cout<<"This test size is "<<test.size()<<endl;
	cout<<"Added 1 element in first node ( Head node ) in the list"<<endl;
	cout<<"The front element in list:  "<<test.front()<<endl;
	cout<<"------------------------------------------------------------";
	
//Remove first item from list
	cout<<"\n";
	test.pop_front();
	test.display();
	cout<<"Removing first element in list"<<endl;
	cout<<"This test size is "<<test.size()<<endl;
	cout<<"\n";
	cout<<"Removed 1 Number from the list"<<endl;
	cout<<"The front element in list:  "<<test.front()<<endl;
	cout<<"------------------------------------------------------------";
	
// delete specific number from list
	cout<<"\n";
	cout<<"Removing element (33) in list"<<endl;
	test.erase(33);
	test.display();
	cout<<"The front element in list:  "<<test.front()<<endl;
	cout<<"This test size is "<<test.size()<<endl;
	cout<<"------------------------------------------------------------";
	
// creating disply list for user to choose
	int select, n, loc;
	while (1) {
		cout<<"\n"<<"1. Select this number To insert new element: "<<endl;
		cout<<"2. Select this number To remove element:"<<endl;
		cout<<"3. Select this to Exit."<<endl;
		cin>>select;
		switch (select) {
			case 1:	cout<<" Please enter the new Element ";
					cin>>n;
					cout<<" Please enter the location for this new element";
					cin>>loc;
					test.insert(n, loc); 
					test.display();
					cout<<"The front element in list:  "<<test.front()<<endl;
					cout<<"This is New list  size is "<<test.size()<<endl;
					cout<<"------------------------------------------------------------";
					break;
			case 2: cout<<" Please enter the element you want to be removed:"<<endl;
					cin>>n; 
					cout<<" The removed Element is: \n"<<test.remove(n)<<endl; 
					test.display();
					cout<<"The front element in list:  "<<test.front()<<endl;
					cout<<"This is New list  size is "<<test.size()<<endl;
					cout<<"------------------------------------------------------------";
					break;
			case 3: test.display(); 
			        cout<<"The front element in list:  "<<test.front()<<endl;
			        cout<<"This is New list  size is:  "<<test.size()<<endl;
			        cout<<"------------------------------------------------------------";
					return 0;
			
		}
	}
return 0;
}
