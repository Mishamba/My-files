#include <iostream>
#include <fstream>
#include <ifstream>
#include <ofstream>
#include <string>

struct message
{
	string username;
	string text; 
};

struct cur_user 
{
	string username;
	int status;
} 
CUR_USER; 

void menu_u()
{
	int choise;
	std::cout << "1: create new user" << std::endl
		<< "2: log in" << std:: endl;
	switch(choise)
	{
		case 1:
			{
				std::cout << "enter user name:" << std::endl;
				cin >> CUR_USER.username;
				string psw;
				std::cout << "enter your password:" << std::endl;
				cin >> psw; 
				CUR_USER.status = 1;
				ofstream users;
				users.open("users.txt", ios_base::app | ois_base::binary);
				if(!users.is_open())
				{
					std::cout << "file can not to be opened";
				}
				else
				{
					users << CUR_USER.username; //need to write in binary file
					users << psw; 
				}
				break;
			}
		case 2:
			{
				string username;
				string psw;
				std::cout << "enter user name:" << std::endl;
				cin >> username;
				std::cout << "enter password:" << std::endl;
				cin >> psw;
				h //need to write from binary file
			}
	}
}

int main
{
	menu_u();
}	
