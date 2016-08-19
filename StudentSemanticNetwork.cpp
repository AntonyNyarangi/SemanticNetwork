#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

#include "SemanticNetworkClasses.hpp"

using namespace std;

void programIntro();
void userChoseCreateNode();
void userChoseUseData();

Node semester = Graph::getSemester();

int main(){
	programIntro();	
}

void programIntro(){
	int choice;
	cout<<"What would you like to do today?"<<endl;
	cout<<"1) Create a new Node"<<endl;
	cout<<"2) Use the data in the Network"<<endl;
	cout<<"Choice:";
	
	cin>>choice;
	cin.ignore();

	switch(choice){
		case 1: userChoseCreateNode();
		break;
		case 2: userChoseUseData();
		break;
		default: cout<<"Invalid choice"<<endl;
		exit(1);
	}
}

void userChoseCreateNode(){
	Node myNode;
	Edge myEdge;		
	myNode = Graph::createNode();
	if(myNode.getType() == "1"){
		myEdge = Graph::createEdge(myNode,semester);
	}else if(myNode.getType() == "3"){
		myEdge = Graph::createEdge(semester,myNode);
	}else if(myNode.getType() == "4"){

		int linesInFile = 0;
		int size;
		int i;
		string line;
		ifstream myFile;


		myFile.open("nodes.txt");
		while (getline(myFile, line)){
			++linesInFile;
		}
		myFile.close();

		myFile.open("nodes.txt");

		size = linesInFile;

		Node myNodes[linesInFile];
		if (myFile.is_open() ){
			for(i=0;i<linesInFile;i++){
				if(myFile.good()){					
					getline(myFile,myNodes[i].objName, ',');
					getline(myFile,myNodes[i].objType, ',');
					getline(myFile,myNodes[i].regNumber, ',');
					getline(myFile,myNodes[i].semesterNumber, ',');
					getline(myFile,myNodes[i].staffNumber, ',');
					getline(myFile,myNodes[i].courseID, '\n');
					//myNodes[i].showNodeData();
				}							
			}
			myFile.close();	

		}else{
			cout <<"Could not open file"<<endl;
		}

		string code;		

		cout<<endl<<"Please enter the course code of the unit taught: ";
		getline(cin,code);

		for(i=0; i<size; i++){
			if(myNodes[i].courseID == code){
				myEdge = Graph::createEdge(myNodes[i],myNode);
			}
		}

		cout<<"That unit is not in the system. Adding new Course Unit."<<endl;
		Node newCourseUnit;
		newCourseUnit = Graph::createCourseUnitNode();
		Edge newCourse_SemesterEdge;
		newCourse_SemesterEdge = Graph::createEdge(semester,newCourseUnit);
		myEdge = Graph::createEdge(newCourseUnit,myNode);
	}

}

void userChoseUseData(){
	int choice;
	cout<<endl<<endl;
	cout<<"How would you like to use the Knowledge in the network?"<<endl;
	cout<<"1) Get the number of students taking a course unit"<<endl;
	cout<<"2) Get the course units that have no students"<<endl;
	cout<<"3) Get general information about available course units"<<endl;
	cout<<"Choice:";

	cin>>choice;

	switch(choice){
		case 1: getStudentsTakingCourseUnit();
		break;
		case 2: getCourseUnitsWithNOStudents();
		break;
		case 3: getGeneralInfoOnCourseUnits();
		break;
		default: cout<<"Invalid choice"<<endl;
		exit(1);
	}
}


