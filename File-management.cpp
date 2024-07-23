#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
#include<stdio.h>
#include<sstream>
#include<string>
#include<string.h>
#include<fstream>
#include<filesystem>
#include<windows.h>
#include<stdlib.h>
#include<cstring>
using namespace cv;
using namespace std;

void create_file();
void delete_file();
void append_file();
void open_file();
void cpp_programs();
void access_images();
void find_data();
void screen();


int main()
{
	system("Color E0");
	screen();
	return 0;
}

void screen()
{
	do {
		int choice = 0;
		cout << endl;
		cout << "\033[31m";
		cout << "\t\t\t==============================================================" << endl;
		cout << "\t\t\t\t :Press <1> to create a new file or folder:" << endl;
		cout << "\t\t\t\t   :Press <2> to delete a file or folder:" << endl;
		cout << "\t\t\t\t    :Press <3> to open a file or folder:" << endl;
		cout << "\t\t\t\t    :Press <4> to edit a file or folder:" << endl;
		cout << "\t\t\t\t:Press <5> to open code of some c++ programs:" << endl;
		cout << "\t\t\t\t        :Press <6> to open images:" << endl;
		cout << "\t\t\t\t      :Press <0> to end the program:" << endl;
		cout << "\t\t\t==============================================================" << endl;
		cout << "\033[30m" << "\033[103m";
		cin >> choice;
		system("CLS");

		switch (choice)
		{
		case 1:
		{
			create_file();
			break;
		}
		case 2:
		{
			delete_file();
			break;
		}
		case 3:
		{
			open_file();
			break;
		}
		case 4:
		{
			append_file();
			break;
		}
		case 5:
		{
			cpp_programs();
			break;
		}
		case 6:
		{
			access_images();
			break;
		}
		case 0:
		{
			cout << "\033[95m";
			cout << "\t\t:PROGRAM IS EXITING SUCESSFULY:" << endl;
			cout << "\t\t===============================" << endl;
			cout << "\033[30m" << "\033[103m";
			exit(-1);
			break;
		}
		default:
			cout << "\t    :Enter number from given options:" << endl << endl;
		}
	} while (1);
}

void create_file()
{
	int n = 0;
	cout << "\033[34m";
	cout << "Press <1> to create and type data in text file" << endl;
	cout << "Press <2> to create and type data in excel sheet" << endl;
	cin >> n;
	cout << "\033[30m" << "\033[103m";


	if (n == 1)
	{
		string st2;
		cin.ignore();
		cout << "File Name: ";
		getline(cin, st2);
		st2 = st2 + ".txt";
		string str;
		fstream newfile1;
		newfile1.open(st2, ios::out | ios::app);
		cout << "\033[34m";
		cout << "Add data:" << endl;
		cout << "Press N to exit" << endl;
		cout << "\033[30m" << "\033[103m";
		for (int i = 0;; i++)
		{
			getline(cin, str);
			if (str == "N")
			{
				screen();
				exit(-1);
			}
			newfile1 << str << endl;
		}
		newfile1.close();
	}


	if (n == 2)
	{
		string st2;
		cin.ignore();
		cout << "File Name: ";
		getline(cin, st2);
		st2 = st2 + ".csv";
		string str;
		fstream newfile1;
		newfile1.open(st2, ios::out | ios::app);
		cout << "\033[34m";
		cout << "Add data press < , > (comma) to go to next cell:" << endl;
		cout << "Press N to exit adding data" << endl;
		cout << "\033[30m" << "\033[103m";
		for (int i = 0;; i++)
		{
			getline(cin, str);
			if (str == "N")
			{
				screen();
				exit(-1);
			}
			newfile1 << str << "," << endl;
		}
		newfile1.close();
	}
}

void delete_file()
{
	int a = 0;
	cout << "\033[34m";
	cout << " Press <1> to delete an Excel file" << endl;
	cout << "Press <2> to delete a Text file" << endl;
	cout << "=================================" << endl;
	cin >> a;
	cout << "\033[30m" << "\033[103m";

	if (a == 1)
	{
		bool status;
		string fileName;
		cin.ignore();
		char file[50];
		int count = 0;
		cout << "Enter the Name of Excel File: ";
		getline(cin, fileName);
		fileName += ".csv";
		const char* str = fileName.c_str();
		cout << count << "\n" << str << endl;
		remove(str);
		cout << endl;
	}

	if (a == 2)
	{
		bool status;
		string fileName;
		cin.ignore();
		char file[50];
		int count = 0;
		cout << "Enter the Name of Text File: ";
		getline(cin, fileName);
		fileName += ".txt";
		const char* str = fileName.c_str();
		cout << count << "\n" << str << endl;
		remove(str);
		cout << endl;
	}
}

void open_file()
{
	int num = 0;
	cout << "\033[34m";
	cout << "\t           Press <1> to open File 1= Data of Students" << endl;
	cout << "\tPress <2> to open File 2= Introduction to Artificial intelligence" << endl;
	cout << "\t     Press <3> to open File 3= Worksheet of electricity bill" << endl;
	cout << "\t           Press <4> to open File= Introduction to C++" << endl;
	cout << "\t           Press <5> to open file= Details about Tesla" << endl;
	cout << "\t         Press <6> to open file= Introduction to Google" << endl;
	cout << "\t        Press <7> to open file= Introduction to Microsoft" << endl;
	cout << "\t        Press <8> to open file= Introduction to Facebook." << endl;
	cin >> num;
	cout << "\033[30m" << "\033[103m";

	if (num == 1)
	{
		int n = 0;
		fstream file;
		cin.ignore();
		file.open("D:\\python\\Mentor's assignment\\Mentor's assignment\\data.csv", ios::in);

		cout << "\033[31m";
		cout << "Press <1> to read data of students or press <2> to find data of specific student" << endl;
		cin >> n;
		cout << "\033[30m" << "\033[103m";

		if (n == 1)
		{
			if (file.is_open())
			{
				string read;
				while (getline(file, read, ','))
				{
					cout << read << "\t";
				}

				file.close();
			}
		}
		else
		{
			find_data();
		}
		cout << endl;
	}
	if (num == 2)
	{
		fstream file1;
		file1.open("D:\\content\\AI.txt", ios::in);
		if (file1.is_open())
		{
			string read;
			while (getline(file1, read, ','))
			{
				cout << read;
			}
			file1.close();
		}
		cout << endl;
	}
	if (num == 3)
	{
		fstream file2;
		file2.open("D:\\content\\Worksheet.csv", ios::in);
		if (file2.is_open())
		{
			string view;
			while (getline(file2, view, ','))
			{
				cout << view << "\t";
			}
			file2.close();
		}
		cout << endl << endl;
	}
	if (num == 4)
	{
		fstream file3;
		file3.open("D:\\content\\C++.txt", ios::in);
		if (file3.is_open())
		{
			string view;
			while (getline(file3, view, ','))
			{
				cout << view << "\t";
			}
			file3.close();
		}
		cout << endl;
	}
	if (num == 5)
	{
		fstream file2;
		file2.open("C:\\Users\\Lenovo\\Downloads\\file2.txt", ios::in);
		if (file2.is_open())
		{
			string view;
			while (getline(file2, view, ','))
			{
				cout << view;
			}
			file2.close();
		}
		screen();
		cout << endl;
	}
	if (num == 6)
	{
		fstream file3;
		file3.open("C:\\Users\\Lenovo\\Downloads\\file3.txt", ios::in);
		if (file3.is_open())
		{
			string view;
			while (getline(file3, view, ','))
			{
				cout << view;
			}
			file3.close();
		}
		screen();
		cout << endl;
	}
	if (num == 7)
	{
		fstream file4;
		file4.open("C:\\Users\\Lenovo\\Downloads\\file4.txt", ios::in);
		if (file4.is_open())
		{
			string view;
			while (getline(file4, view, ','))
			{
				cout << view;
			}
			file4.close();
		}
		screen();
		cout << endl;
	}
	if (num == 8)
	{
		fstream file5;
		file5.open("C:\\Users\\Lenovo\\Downloads\\file5.txt", ios::in);
		if (file5.is_open())
		{
			string view;
			while (getline(file5, view, ','))
			{
				cout << view;
			}
			file5.close();
		}
		screen();
		cout << endl;
	}
}

void find_data()
{
	fstream file;
	string rollno;
	int i = 0;
	string str[3];

	file.open("D:\\python\\Mentor's assignment\\Mentor's assignment\\data.csv", ios::in);
	string line;

	if (file.is_open())
	{
		cout << "\033[34m";
		cout << "Enter roll number to get details of student: ";
		cout << "\033[30m" << "\033[103m";
		cin >> rollno;
		cout << "name:   grade:" << endl;
		while (getline(file, line))
		{
			int i = 0;
			stringstream s(line);
			string word;
			while (getline(s, word, ','))
			{
				str[i] = word;
				i++;
			}
			if (str[1] == rollno)
			{
				cout << str[0] << "  " << str[2] << endl;
			}

		}
		file.close();
		cout << endl;
	}
	else
		cout << "error" << endl;
}

void append_file()
{
	int choice = 0;
	cout << "\033[34m";
	cout << "\t            Press <1> to edit File 1= Data of Students" << endl;
	cout << "\tPress <2> to edit File 2= Introduction to Artificial intelligence" << endl;
	cout << "\t      Press <3> to edit File 3= Worksheet of electricity bill" << endl;
	cout << "\t            Press <4> to edit File= Introduction to C++" << endl;
	cin >> choice;
	cout << "\033[30m" << "\033[103m";

	switch (choice)
	{
	case 1:
	{
		int i = 0;

		string name, rollno, grade;
		cin.ignore();
		fstream file;

		file.open("D:\\python\\Mentor's assignment\\Mentor's assignment\\data.csv", ios::app);
		if (file.is_open())
		{
			do
			{
				cout << "Enter name of student press N to exit: ";

				getline(cin, name);
				if (name == "N")
				{
					screen();
					exit(-1);
				}
				file << name << ",";

				cout << "Enter roll number of student press N to exit: ";
				getline(cin, rollno);
				if (rollno == "N")
				{
					screen();
					exit(-1);
				}
				file << rollno << ",";

				cout << "Enter grade of student press N to exit: ";
				getline(cin, grade);
				if (grade == "N")
				{
					screen();
					exit(-1);
				}
				file << grade << "," << endl;

				i++;
			} while (i < 10);
			file.close();
		}
		screen();
		break;
	}
	case 2:
	{
		fstream file1;
		cin.ignore();

		file1.open("D:\\content\\AI.txt", ios::app);
		if (file1.is_open())
		{
			string str;
			cout << "\033[34m";
			cout << "Write paragraph press N to exit:" << endl;
			cout << "\033[30m" << "\033[103m";
			for (int i = 0; ; i++)
			{
				getline(cin, str);
				if (str == "N")
				{
					screen();
					exit(-1);
				}
				file1 << str << endl;
			}
			file1.close();
		}
		screen();
		break;
	}
	case 3:
	{
		fstream file2;
		string name, previous_units, current_units, units_consumed, electricity_charges;
		string surcharge, bill;
		cin.ignore();

		file2.open("D:\\content\\Worksheet.csv", ios::app);
		if (file2.is_open())
		{
			for (int i = 0; ; i++)
			{
				cout << "Enter name press N to exit." << endl;
				getline(cin, name);
				file2 << name << ",";
				if (name == "N")
				{
					screen();
				}

				cout << "Enter previous units press N to exit." << endl;
				getline(cin, previous_units);
				file2 << previous_units << ",";
				if (previous_units == "N")
				{
					screen();
				}

				cout << "Enter current units press N to exit." << endl;
				getline(cin, current_units);
				file2 << current_units << ",";
				if (current_units == "N")
				{
					screen();
				}

				cout << "Enter units consumed press N to exit." << endl;
				getline(cin, units_consumed);
				file2 << units_consumed << ",";
				if (units_consumed == "N")
				{
					screen();
				}

				cout << "Enter electricity charges press N to exit." << endl;
				getline(cin, electricity_charges);
				file2 << electricity_charges << ",";
				if (electricity_charges == "N")
				{
					screen();
				}

				cout << "Enter surcharge press N to exit." << endl;
				getline(cin, surcharge);
				file2 << surcharge << ",";
				if (surcharge == "N")
				{
					screen();
				}

				cout << "Enter current units press N to exit." << endl;
				getline(cin, bill);
				file2 << bill << "," << endl;
				if (bill == "N")
				{
					screen();
				}
			}
			file2.close();
		}
		screen();
		break;
	}
	case 4:
	{
		fstream file3;
		string para;
		cin.ignore();

		file3.open("D:\\content\\C++.txt", ios::app);
		if (file3.is_open())

		{
			cout << "\033[34m";
			cout << "write content: " << endl;
			cout << "\033[30m" << "\033[103m";
			for (int i = 0;; i++)
			{
				getline(cin, para);
				if (para == "N")
				{
					screen();
					exit(-1);
				}
				file3 << para << endl;
			}
			file3.close();
		}
		screen();
		break;
	}
	}
	cout << endl;
}

void cpp_programs()
{
	int n = 0;
	cout << "\033[34m";
	cout << "\t          Press <1> to open code of lab task 1" << endl;
	cout << "\t          Press <2> to open code of lab task 2" << endl;
	cout << "\t          Press <3> to open code of lab task 3" << endl;
	cout << "\t      Press <4> to open image of house buit using c++" << endl;
	cout << "\t     =================================================" << endl;
	cin >> n;
	cout << "\033[30m" << "\033[103m";

	if (n == 1)
	{
		ifstream file;
		file.open("D:\\Semester Project\\220976 lab task 8\\220976 lab task 8\\220976 lab task 8.cpp");
		if (file.is_open())
		{
			cout << "\033[31m";
			cout << "\tTHIS IS CODE OF SOME C++ PROGRAMS" << endl;
			cout << "\t=================================" << endl;
			cout << "\033[30m" << "\033[103m";

			string view;
			while (getline(file, view, ','))
			{
				cout << view << "\t";
			}
			file.close();
		}
	}
	if (n == 2)
	{
		ifstream file;
		file.open("D:\\python\\220976 lab task 6\\220976 lab task 6\\Source.cpp");
		if (file.is_open())
		{
			cout << "\033[31m";
			cout << "\tTHIS IS CODE OF SOME C++ PROGRAMS" << endl;
			cout << "\t=================================" << endl;
			cout << "\033[30m" << "\033[103m";
			string view;
			while (getline(file, view, ','))
			{
				cout << view << "\t";
			}
			file.close();
		}
	}
	if (n == 3)
	{
		ifstream file;
		file.open("D:\\python\\220976\\220976\\Source.cpp");
		if (file.is_open())
		{
			cout << "\033[31m";
			cout << "\tTHIS IS CODE OF SOME C++ PROGRAMS" << endl;
			cout << "\t=================================" << endl;
			cout << "\033[30m" << "\033[103m";
			string view;
			while (getline(file, view, ','))
			{
				cout << view << "\t";
			}
			file.close();
		}
	}
	if (n == 4)
	{
		ifstream file;
		file.open("D:\\house\\house\\Source.cpp");
		if (file.is_open())
		{
			cout << "\033[31m";
			cout << "\tTHIS IS CODE Of A HOUSE MADE USING C++" << endl;
			cout << "\t======================================" << endl;
			cout << "\033[30m" << "\033[103m";

			string view;
			while (getline(file, view, ','))
			{
				cout << view << "\t";
			}
			file.close();
		}
	}
}

void access_images()
{
	int n = 0;
	cout << "\033[34m";
	cout << "enter a number between (1-5) to open an image" << endl;
	cin >> n;
	cout << "\033[30m" << "\033[103m";

	if (n == 1)
	{
		cout << "Gojo Saturo from Jujutsu kaisen" << endl;
		Mat img = imread("C:/Users/Lenovo/Downloads/Image.jpeg");
		namedWindow("Gojo Chibi", WINDOW_AUTOSIZE);
		imshow("Gojo Chibi", img);
		moveWindow("Gojo Chibi", 0, 45);
		waitKey(0);
		destroyAllWindows();
		screen();

	}

	if (n == 2)
	{
		cout << "Dazai from stray dogs" << endl;
		Mat img = imread("C:/Users/Lenovo/Downloads/dazai.jpg");
		namedWindow("dazai", WINDOW_AUTOSIZE);
		imshow("dazai", img);
		moveWindow("dazai", 0, 45);
		waitKey(0);
		destroyAllWindows();
		screen();
	}

	if (n == 3)
	{
		cout << "Marin from My dressup darling" << endl;
		Mat img = imread("C:/Users/Lenovo/Downloads/Marin.jpg");
		namedWindow("Marin", WINDOW_AUTOSIZE);
		imshow("Marin", img);
		moveWindow("Marin", 0, 45);
		waitKey(0);
		destroyAllWindows();
		screen();
	}

	if (n == 4)
	{
		cout << "Kiluua from hunter x hunter" << endl;
		Mat img = imread("C:/Users/Lenovo/Downloads/anime.jpg");
		namedWindow("Kiluua", WINDOW_AUTOSIZE);
		imshow("Kiluua", img);
		moveWindow("Kiluua", 0, 45);
		waitKey(0);
		destroyAllWindows();
		screen();
	}

	if (n == 5)
	{
		cout << "Shoto Todoroki from My hero academia" << endl;
		Mat img = imread("C:/Users/Lenovo/Downloads/shoto.jpg");
		namedWindow("Shoto", WINDOW_AUTOSIZE);
		imshow("Shoto", img);
		moveWindow("Shoto", 0, 45);
		waitKey(0);
		destroyAllWindows();
		screen();
	}
}

DEV C++ PROJECT
/*#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>*/
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <string.h>
#include <fstream>
#include <dirent.h>
#include <conio.h>
#include <filesystem>
#include <windows.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

int create();
int move();
int path();
int remove();
int append_file();
int open_file();
int cpp_programs();
//int access_images();
int find_data();
int screen();

int main()
{
	system("Color E0");
	screen();
	return 0;
}

int screen()
{
	do {
		int choice = 0;
		cout << endl;
		cout << "\033[31m";
		cout << "\t\t\t==============================================================" << endl;
		cout << "\t\t\t\t    :Press <1> to read total files in drive:" << endl;
		cout << "\t\t\t\t           :Press <2> to move files:" << endl;
		cout << "\t\t\t\t :Press <3> to create a new file or folder:" << endl;
		cout << "\t\t\t\t   :Press <4> to delete a file or folder:" << endl;
		cout << "\t\t\t\t    :Press <5> to open a file or folder:" << endl;
		cout << "\t\t\t\t    :Press <6> to edit a file or folder:" << endl;
		cout << "\t\t\t\t:Press <7> to open code of some c++ programs:" << endl;
		cout << "\t\t\t\t          :Press <8> to open images:" << endl;
		cout << "\t\t\t\t        :Press <0> to end the program:" << endl;
		cout << "\t\t\t==============================================================" << endl;
		cout << "\033[30m" << "\033[103m";
		cin >> choice;
		system("CLS");

		switch (choice)
		{
		case 1:
		{
			path();
		}
		case 2:
		{
			move();
			break;
		}
		case 3:
		{
			create();
			break;
		}
		case 4:
		{
			remove();
			break;
		}
		case 5:
		{
			open_file();
			break;
		}
		case 6:
		{
			append_file();
			break;
		}
		case 7:
		{
			cpp_programs();
			break;
		}
		case 8:
		{
			//access_images();
			break;
		}
		case 0:
		{
			cout << "\033[95m";
			cout << "\t\t:PROGRAM IS EXITING SUCESSFULY:" << endl;
			cout << "\t\t===============================" << endl;
			cout << "\033[30m" << "\033[103m";
			exit(-1);
			break;
		}
		default:
			cout << "\t    :Enter number from given options:" << endl << endl;
		}
	} while (1);
	return 0;
}

int path()
{
	//read the names of all folders in the directory

	char path[100];
	char choice;

	DIR* dir;
	dirent* pdir;
	cout << "Enter path to list all the files in a directory:\n1)C:...\n2)D:..." << endl;
	cin >> choice;
	if (choice == 'C' || choice == 'c')
	{
		strcpy(path, "C:\\");
	}
	else if (choice == 'D' || choice == 'd')
	{
		strcpy(path, "D:\\");
	}
	else
	{
		cout << "Drive do not exist" << endl;
	}

	dir = opendir(path);
	while (readdir(dir))
	{
		pdir = readdir(dir);
		cout << pdir->d_name << endl;
	}
	closedir(dir);
	getch();
	screen();
	return 0;
}

int move()
{
	//moves files from games folder to anime folder
	system("Chdir");

	string cmd1 = "move ";
	string cmd2 = "D:\\Dev\\game\\*.txt";
	string cmd3 = "D:\\Dev\\anime";
	char str[] = "move D:\\Dev\\game\\*.txt D:\\Dev\\anime";


	system(str);

	screen();
	return 0;
}

int create()
{
	int num = 0;
	cout << "Enter <1> to create a Folder" << endl;
	cout << "Entere <2> to create a File" << endl;
	cin >> num;

	if (num == 1)
	{
		//creating Folder
		if (mkdir("D:\\New folder") == -1)
			cerr << " Error : " << strerror(errno) << endl;  //identifies the error

		else
			cout << "Folder Created";
	}

	if (num == 2)
	{
		//creating file
		int n = 0;
		cout << "\033[34m";
		cout << "Press <1> to create and type data in text file" << endl;
		cout << "Press <2> to create and type data in excel sheet" << endl;
		cin >> n;
		cout << "\033[30m" << "\033[103m";


		if (n == 1)
		{
			//text file

			string st2;
			cin.ignore();
			cout << "File Name: ";
			getline(cin, st2);
			st2 = st2 + ".txt";
			string str;
			fstream newfile1;
			newfile1.open(st2, ios::out | ios::app);
			cout << "\033[34m";
			cout << "Add data:" << endl;
			cout << "Press N to exit" << endl;
			cout << "\033[30m" << "\033[103m";
			for (int i = 0;; i++)
			{
				getline(cin, str);
				if (str == "N")
				{
					screen();
					exit(-1);
				}
				newfile1 << str << endl;
			}
			newfile1.close();
		}

		if (n == 2)
		{
			//csv file

			string st2;
			cin.ignore();
			cout << "File Name: ";
			getline(cin, st2);
			st2 = st2 + ".csv";
			string str;
			fstream newfile1;
			newfile1.open(st2, ios::out | ios::app);
			cout << "\033[34m";
			cout << "Add data press < , > (comma) to go to next cell:" << endl;
			cout << "Press N to exit adding data" << endl;
			cout << "\033[30m" << "\033[103m";
			for (int i = 0;; i++)
			{
				getline(cin, str);
				if (str == "N")
				{
					screen();
					exit(-1);
				}
				newfile1 << str << "," << endl;
			}
			newfile1.close();
		}
	}

	screen();
	return 0;
}

int remove()
{
	int num = 0;
	cout << "Enter <1> to delete the created Folder" << endl;
	cout << "Entere <2> to delete a File" << endl;
	cin >> num;

	if (num == 1)
	{
		//removing Folder

		if (rmdir("D:\\New folder") == -1)
			cerr << " Error : " << strerror(errno) << endl;

		else
			cout << "Folder Deleted";
	}
	if (num == 2)
	{
		//removing file

		int a = 0;
		cout << "\033[34m";
		cout << "Press <1> to delete an Excel file" << endl;
		cout << "Press <2> to delete a Text file" << endl;
		cout << "=================================" << endl;
		cin >> a;
		cout << "\033[30m" << "\033[103m";

		if (a == 1)
		{
			//csv file

			bool status;
			string fileName;
			cin.ignore();
			char file[50];
			int count = 0;
			cout << "Enter the Name of Excel File: ";
			getline(cin, fileName);
			fileName += ".csv";
			const char* str = fileName.c_str();
			cout << count << "\n" << str << endl;
			remove(str);
			cout << endl;
		}

		if (a == 2)
		{
			//text file

			bool status;
			string fileName;
			cin.ignore();
			char file[50];
			int count = 0;
			cout << "Enter the Name of Text File: ";
			getline(cin, fileName);
			fileName += ".txt";
			const char* str = fileName.c_str();
			cout << count << "\n" << str << endl;
			remove(str);
			cout << endl;
		}
	}
	screen();
	return 0;
}

int open_file()
{
	int num = 0;
	cout << "\033[34m";
	cout << "\t           Press <1> to open File 1= Data of Students" << endl;
	cout << "\tPress <2> to open File 2= Introduction to Artificial intelligence" << endl;
	cout << "\t     Press <3> to open File 3= Worksheet of electricity bill" << endl;
	cout << "\t           Press <4> to open File= Introduction to C++" << endl;
	cout << "\t           Press <5> to open file= Details about Tesla" << endl;
	cout << "\t         Press <6> to open file= Introduction to Google" << endl;
	cout << "\t        Press <7> to open file= Introduction to Microsoft" << endl;
	cout << "\t        Press <8> to open file= Introduction to Facebook." << endl;
	cin >> num;
	cout << "\033[30m" << "\033[103m";

	if (num == 1)
	{
		//student data file

		int n = 0;
		fstream file;
		cin.ignore();
		file.open("D:\\Work\\python\\Mentor's assignment\\Mentor's assignment\\data.csv", ios::in);
		cout << "\033[31m";
		cout << "Press <1> to read data of students or press <2> to find data of specific student" << endl;
		cin >> n;
		cout << "\033[30m" << "\033[103m";

		if (n == 1)
		{
			if (file.is_open())
			{
				string read;
				while (getline(file, read, ','))
				{
					cout << read << "\t";
				}

				file.close();
			}
		}
		else
		{
			find_data();
		}
		cout << endl;
	}
	if (num == 2)
	{
		//AI intro

		fstream file1;
		file1.open("D:\\Work\\content\\AI.txt", ios::in);
		if (file1.is_open())
		{
			string read;
			while (getline(file1, read, ','))
			{
				cout << read;
			}
			file1.close();
		}
		cout << endl;
	}
	if (num == 3)
	{
		//Bill worksheet

		fstream file2;
		file2.open("D:\\Work\\content\\Worksheet.csv", ios::in);
		if (file2.is_open())
		{
			string view;
			while (getline(file2, view, ','))
			{
				cout << view << "\t";
			}
			file2.close();
		}
		cout << endl << endl;
	}
	if (num == 4)
	{
		//C++ intro

		fstream file3;
		file3.open("D:\\Work\\content\\C++.txt", ios::in);
		if (file3.is_open())
		{
			string view;
			while (getline(file3, view, ','))
			{
				cout << view << "\t";
			}
			file3.close();
		}
		cout << endl;
	}
	if (num == 5)
	{
		//tesla file

		fstream file2;
		file2.open("C:\\Users\\Lenovo\\Downloads\\file2.txt", ios::in);
		if (file2.is_open())
		{
			string view;
			while (getline(file2, view, ','))
			{
				cout << view;
			}
			file2.close();
		}
		screen();
		cout << endl;
	}
	if (num == 6)
	{
		//google intro

		fstream file3;
		file3.open("C:\\Users\\Lenovo\\Downloads\\file3.txt", ios::in);
		if (file3.is_open())
		{
			string view;
			while (getline(file3, view, ','))
			{
				cout << view;
			}
			file3.close();
		}
		screen();
		cout << endl;
	}
	if (num == 7)
	{
		//microsoft file

		fstream file4;
		file4.open("C:\\Users\\Lenovo\\Downloads\\file4.txt", ios::in);
		if (file4.is_open())
		{
			string view;
			while (getline(file4, view, ','))
			{
				cout << view;
			}
			file4.close();
		}
		screen();
		cout << endl;
	}
	if (num == 8)
	{
		//facebook file

		fstream file5;
		file5.open("C:\\Users\\Lenovo\\Downloads\\file5.txt", ios::in);
		if (file5.is_open())
		{
			string view;
			while (getline(file5, view, ','))
			{
				cout << view;
			}
			file5.close();
		}
		screen();
		cout << endl;
	}

	screen();
	return 0;
}

int find_data()
{
	fstream file;
	string rollno;
	int i = 0;
	string str[3];

	file.open("D:\\Work\\python\\Mentor's assignment\\Mentor's assignment\\data.csv", ios::in);
	string line;

	if (file.is_open())
	{
		cout << "\033[34m";
		cout << "Enter roll number to get details of student: ";
		cin >> rollno;
		cout << "\033[30m" << "\033[103m";
		cout << "name:   grade:" << endl;
		while (getline(file, line))
		{
			int i = 0;
			stringstream s(line);
			string word;
			while (getline(s, word, ','))
			{
				str[i] = word;
				i++;
			}
			if (str[1] == rollno)
			{
				cout << str[0] << "  " << str[2] << endl;
			}

		}
		file.close();
		cout << endl;
	}
	else
		cout << "error" << endl;
	screen();
	return 0;
}

int append_file()
{
	int choice = 0;
	cout << "\033[34m";
	cout << "\t            Press <1> to edit File 1= Data of Students" << endl;
	cout << "\tPress <2> to edit File 2= Introduction to Artificial intelligence" << endl;
	cout << "\t      Press <3> to edit File 3= Worksheet of electricity bill" << endl;
	cout << "\t            Press <4> to edit File= Introduction to C++" << endl;
	cin >> choice;
	cout << "\033[30m" << "\033[103m";

	switch (choice)
	{
	case 1:
	{
		int i = 0;

		string name, rollno, grade;
		cin.ignore();
		fstream file;

		file.open("D:\\Work\\python\\Mentor's assignment\\Mentor's assignment\\data.csv", ios::app);
		if (file.is_open())
		{
			do
			{
				cout << "Enter name of student press N to exit: ";

				getline(cin, name);
				if (name == "N")
				{
					screen();
					exit(-1);
				}
				file << name << ",";

				cout << "Enter roll number of student press N to exit: ";
				getline(cin, rollno);
				if (rollno == "N")
				{
					screen();
					exit(-1);
				}
				file << rollno << ",";

				cout << "Enter grade of student press N to exit: ";
				getline(cin, grade);
				if (grade == "N")
				{
					screen();
					exit(-1);
				}
				file << grade << "," << endl;

				i++;
			} while (i < 10);
			file.close();
		}
		screen();
		break;
	}
	case 2:
	{
		fstream file1;
		cin.ignore();

		file1.open("D:\\Work\\content\\AI.txt", ios::app);
		if (file1.is_open())
		{
			string str;
			cout << "Write paragraph press N to exit:" << endl;
			for (int i = 0; ; i++)
			{
				getline(cin, str);
				if (str == "N")
				{
					screen();
					exit(-1);
				}
				file1 << str << endl;
			}
			file1.close();
		}
		screen();
		break;
	}
	case 3:
	{
		fstream file2;
		string name, previous_units, current_units, units_consumed, electricity_charges;
		string surcharge, bill;
		cin.ignore();

		file2.open("D:\\Work\\content\\Worksheet.csv", ios::app);
		if (file2.is_open())
		{
			for (int i = 0; ; i++)
			{
				cout << "Enter name press N to exit." << endl;
				getline(cin, name);
				file2 << name << ",";
				if (name == "N")
				{
					screen();
				}

				cout << "Enter previous units press N to exit." << endl;
				getline(cin, previous_units);
				file2 << previous_units << ",";
				if (previous_units == "N")
				{
					screen();
				}

				cout << "Enter current units press N to exit." << endl;
				getline(cin, current_units);
				file2 << current_units << ",";
				if (current_units == "N")
				{
					screen();
				}

				cout << "Enter units consumed press N to exit." << endl;
				getline(cin, units_consumed);
				file2 << units_consumed << ",";
				if (units_consumed == "N")
				{
					screen();
				}

				cout << "Enter electricity charges press N to exit." << endl;
				getline(cin, electricity_charges);
				file2 << electricity_charges << ",";
				if (electricity_charges == "N")
				{
					screen();
				}

				cout << "Enter surcharge press N to exit." << endl;
				getline(cin, surcharge);
				file2 << surcharge << ",";
				if (surcharge == "N")
				{
					screen();
				}

				cout << "Enter current units press N to exit." << endl;
				getline(cin, bill);
				file2 << bill << "," << endl;
				if (bill == "N")
				{
					screen();
				}
			}
			file2.close();
		}
		screen();
		break;
	}
	case 4:
	{
		fstream file3;
		string para;
		cin.ignore();

		file3.open("D:\\Work\\content\\C++.txt", ios::app);
		if (file3.is_open())

		{
			cout << "write content: " << endl;
			for (int i = 0;; i++)
			{
				getline(cin, para);
				if (para == "N")
				{
					screen();
					exit(-1);
				}
				file3 << para << endl;
			}
			file3.close();
		}
		screen();
		break;
	}
	}
	cout << endl;
	return 0;
}

int cpp_programs()
{
	int n = 0;
	cout << "\033[34m";
	cout << "\t          Press <1> to open code of lab task 1" << endl;
	cout << "\t          Press <2> to open code of lab task 2" << endl;
	cout << "\t          Press <3> to open code of lab task 3" << endl;
	cout << "\t      Press <4> to open image of house buit using c++" << endl;
	cout << "\t     =================================================" << endl;
	cin >> n;
	cout << "\033[30m" << "\033[103m";

	if (n == 1)
	{
		ifstream file;
		file.open("D:\\Work\\Semester Project\\lab task 9\\lab task 9\\source.cpp");
		if (file.is_open())
		{
			cout << "\033[31m";
			cout << "\tTHIS IS CODE OF SOME C++ PROGRAMS" << endl;
			cout << "\t=================================" << endl;
			cout << "\033[30m" << "\033[103m";

			string view;
			while (getline(file, view, ','))
			{
				cout << view << "\t";
			}
			file.close();
		}
	}
	if (n == 2)
	{
		ifstream file;
		file.open("D:\\Work\\python\\220976 lab task 6\\220976 lab task 6\\Source.cpp");
		if (file.is_open())
		{
			cout << "\033[31m";
			cout << "\tTHIS IS CODE OF SOME C++ PROGRAMS" << endl;
			cout << "\t=================================" << endl;
			cout << "\033[30m" << "\033[103m";
			string view;
			while (getline(file, view, ','))
			{
				cout << view << "\t";
			}
			file.close();
		}
	}
	if (n == 3)
	{
		ifstream file;
		file.open("D:\\Work\\python\\220976\\220976\\Source.cpp");
		if (file.is_open())
		{
			cout << "\033[31m";
			cout << "\tTHIS IS CODE OF SOME C++ PROGRAMS" << endl;
			cout << "\t=================================" << endl;
			cout << "\033[30m" << "\033[103m";
			string view;
			while (getline(file, view, ','))
			{
				cout << view << "\t";
			}
			file.close();
		}
	}
	if (n == 4)
	{
		ifstream file;
		file.open("D:\\Work\\house\\house\\Source.cpp");
		if (file.is_open())
		{
			cout << "\033[31m";
			cout << "\tTHIS IS CODE Of A HOUSE MADE USING C++" << endl;
			cout << "\t======================================" << endl;
			cout << "\033[30m" << "\033[103m";

			string view;
			while (getline(file, view, ','))
			{
				cout << view << "\t";
			}
			file.close();
		}
	}
	screen();
	return 0;
}
/*int access_images()
{
	int n = 0;
	cout << "\033[34m";
	cout << "enter a number between (1-5) to open an image" << endl;
	cin >> n;
	cout << "\033[30m" << "\033[103m";

	if (n == 1)
	{
		cout << "Gojo Saturo from Jujutsu kaisen" << endl;
		Mat img = imread("C:/Users/Lenovo/Downloads/gojo.jpg");
		namedWindow("Gojo Chibi", WINDOW_AUTOSIZE);
		imshow("Gojo Chibi", img);
		waitKey(0);
		screen();

	}

	if (n == 2)
	{
		cout << "Dazai from stray dogs" << endl;
		Mat img = imread("C:/Users/Lenovo/Downloads/dazai.jpg");
		namedWindow("dazai", WINDOW_AUTOSIZE);
		imshow("dazai", img);
		waitKey(0);
		screen();
	}

	if (n == 3)
	{
		cout << "Marin from My dressup darling" << endl;
		Mat img = imread("C:/Users/Lenovo/Downloads/Marin.jpg");
		namedWindow("Marin", WINDOW_AUTOSIZE);
		imshow("Marin", img);
		waitKey(0);
		screen();
	}

	if (n == 4)
	{
		cout << "Kiluua from hunter x hunter" << endl;
		Mat img = imread("C:/Users/Lenovo/Downloads/anime.jpg");
		namedWindow("Kiluua", WINDOW_AUTOSIZE);
		imshow("Kiluua", img);
		waitKey(0);
		screen();
	}

	if (n == 5)
	{
		cout << "Shoto Todoroki from My hero academia" << endl;
		Mat img = imread("C:/Users/Lenovo/Downloads/shoto.jpg");
		namedWindow("Shoto", WINDOW_AUTOSIZE);
		imshow("Shoto", img);
		waitKey(0);
		screen();
	}
	return 0;
}*/