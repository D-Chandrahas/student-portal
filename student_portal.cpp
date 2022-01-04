#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <c_functions.h>
using namespace std;



class student {
	public:
		char name[30];
		int roll_no;
		int adv_rank;
		char inst[30];
		char course[30];
		
		friend ofstream& operator << (ofstream &ofile, student &stu){
			ofile.write(reinterpret_cast < const char* > (&stu), sizeof(stu));
			return ofile;
		}
		
		friend ifstream& operator >> (ifstream &ifile, student &stu){
			ifile.read(reinterpret_cast < char* > (&stu), sizeof(stu));
			return ifile;
		}
		
		friend ostream& operator << (ostream &o, student &stu) {
			o << "Name: " << stu.name << endl;
			o << "Roll no.: " << stu.roll_no << endl;
			o << "JEE Advanced rank: " << stu.adv_rank << endl;
			o << "Institution: " << stu.inst << endl;
			o << "Course: " << stu.course << endl;
			return o;
		}
};

int main(){
	system("mkdir data");
	system("cls");
	cout << "\nWelcome to STUDENT PORTAL\n";
	int mminput=0;
	do {
		cout << "\n1.Add new student\n" << "2.Edit student details\n" << "3.View student details\n" << "4.View All Students\n" << "5.Remove student\n" << "6.Exit\n\n" << "Enter an option number: ";
		cin >> mminput;
		system("cls");
		
		switch (mminput) {
			case 1:
			 {student s;
				cout << "\nEnter student name: ";  my_getline(s.name);
				cout << "Enter roll no.: "; cin >> s.roll_no;
				cout << "Enter JEE Advanced rank: "; cin >> s.adv_rank;
				cout << "Enter institution name: ";  my_getline(s.inst);
				cout << "Enter course name: "; my_getline(s.course);
				
				ofstream ofile("data/" + string(s.name) + ".dat", ios::binary | ios::trunc);
				ofile << s;
				ofile.close();
				
				ofile.open("data/all.txt", ios::app);
				ofile << s.name << endl;
				ofile.close();
				
				cout << "\nYou have successfully added " << s.name << endl;
				system("pause");
				system("cls");
				break;
			 }
			 
			case 2:
			 {student s;
				int einput;
				string emore="yes";
				cout << "\nEnter student name: ";  my_getline(s.name);
				ifstream ifile;
				ifile.open("data/" + string(s.name) + ".dat",ios::binary);
				if(!ifile){
					cout << "\nNo such student exists"<<endl;
					ifile.close();
					system("pause");
					system("cls");
					break;
				}
				ifile.close();
				ofstream ofile;
			
				while(emore == "yes"){
					ifile.open("data/" + string(s.name) + ".dat",ios::binary);
					ifile >> s;
					ifile.close();
					
					cout << "\nWhat do you want to edit: \n\n" << "1.Name: " << s.name  << "\n2.Roll no.: "<< s.roll_no  << "\n3.JEE Advanced rank: "<< s.adv_rank << "\n4.Institution: "<< s.inst << "\n5.Course: "<< s.course << "\n\nEnter option number: ";
					cin >> einput;
					
					ofile.open("data/" + string(s.name) + ".dat",ios::binary | ios::trunc);
					
					switch (einput) {
						case 1:
						{
							string oldname = s.name,student, filecontents = "";
							cout << "\nEnter new name: "; my_getline(s.name);
							ofile << s;
							ofile.close();
							
							ifstream ifile("data/all.txt");
							
							while(getline(ifile,student)){
								if(student != oldname) {
									filecontents = filecontents + student + "\n";
								}
								else{filecontents = filecontents + s.name + "\n";}
							}
							
							ifile.close();
							
							ofile.open("data/all.txt" , ios::trunc);
							ofile << filecontents;
							
							system("cls");
							cout << endl << s.name << "'s name has been changed to " << s.name << endl;
							break;
						}
						
						case 2:
							cout << "\nEnter new roll no.: "; cin >> s.roll_no;
							ofile << s;
							system("cls");
							cout << endl << s.name << "'s roll no has been changed to " << s.roll_no << endl;
							break;
						
						case 3:
							cout << "\nEnter new rank: "; cin >> s.adv_rank;
							ofile << s;
							system("cls");
							cout << endl << s.name << "'s rank has been changed to " << s.adv_rank << endl;
							break;
						
						case 4:
							cout << "\nEnter new institution name: ";  my_getline(s.inst);
							ofile << s;
							system("cls");
							cout << endl << s.name << "'s institution name has been changed to " << s.inst << endl;
							break;
						
						case 5:
							cout << "\nEnter new course name: ";  my_getline(s.course);
							ofile << s;
							system("cls");
							cout << endl << s.name << "'s course has been changed to " << s.course << endl;
							break;
						
					}
					
					ofile.close();
					cout << "\nDo you want to change any other details of " << s.name << " (yes/no): ";
					cin >> emore;
					system("cls");
				}
				
				break;	
			 }
			
			case 3:
			 {student s;
				cout << "\nEnter student name: ";  my_getline(s.name); cout << endl;				
				ifstream ifile("data/" + string(s.name) + ".dat",ios::binary);
				if(!ifile){
					cout << "No such student exists"<<endl;
					ifile.close();
					system("pause");
					system("cls");
					break;
				}
				ifile >> s;
				ifile.close();
				
				cout << s;
				
				cout << endl;
				system("pause");
				system("cls");
				break;
			 }
			
			case 4:
			 {ifstream ifile("data/all.txt");
			  cout << endl;
				string student;
			  while(getline(ifile,student)){
				  cout << student << endl;
			  }
				ifile.close();
				
				cout << endl;
				system("pause");
				system("cls");
				break;
			 }
			
			case 5:
			{
				string confirmdel,student,filecontents = "";
				char delstu[30];
				cout << "Enter name of student you want to delete: ";  my_getline(delstu);
				ifstream ifile("data/" + string(delstu) + ".dat",ios::binary);
				if(!ifile){
					cout << "\nNo such student exists"<<endl;
					ifile.close();
					system("pause");
					system("cls");
					break;
				}
				ifile.close();
				cout << endl << "All details of " << delstu << " will be deleted. Confirm(yes/no): "; cin >> confirmdel;
				
				if(confirmdel == "yes"){
					remove(("data/" + string(delstu) + ".dat").c_str());
					
					ifstream ifile("data/all.txt");
					
					while(getline(ifile,student)){
						if(student != delstu) {
							filecontents = filecontents + student + "\n";
						}
					}
					
					ifile.close();
					
					ofstream ofile("data/all.txt" , ios::trunc);
					
					ofile << filecontents;
					
					ofile.close();
					
					cout << endl << delstu << " has been removed" << endl;
					system("pause");
				}
				system("cls");
				break;
			}
		}
	} while ( mminput < 6 );
	return 0;
}	
	
	