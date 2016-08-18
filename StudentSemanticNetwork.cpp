#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

#include "SemanticNetworkClasses.hpp"

using namespace std;

void userChoseCreateNode();
void userChoseUseData();

Node semester = Graph::getSemester();

int main(){

	cout<<"What would you like to do today?"<<endl;
	cout<<"1) Create a new Node"<<endl;
	cout<<"2) Use the data in the Network"<<endl;
	int choice;
	cin>>choice;
	cin.ignore();

	switch(choice){
		case 1: userChoseCreateNode();
		break;
		case 2: userChoseUseData();
		default: cout<<"Invalid choice"<<endl;
		exit(1);
	}
}

void userChoseCreateNode(){
	Node myNode;
	Edge myEdge;
	int size;	
	myNode = Graph::createNode();
	if(myNode.getType() == "1"){
		myEdge = Graph::createEdge(myNode,semester);
	}else if(myNode.getType() == "3"){
		myEdge = Graph::createEdge(semester,myNode);
	}else if(myNode.getType() == "4"){

		int linesInFile = 0;
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
					cout<<endl<<endl;					
					myNodes[i].showNodeData();
				}
				myFile.close();				
			}						
		}else{
			cout <<"Could not open file"<<endl;
		}

		string code;

		myNodes[10].showNodeData();


		cout<<endl<<"Please enter the course code of the unit taught: ";
		getline(cin,code);

		for(i=0; i<size; i++){
			if(myNodes[i].courseID == code){
				myEdge = Graph::createEdge(myNodes[i],myNode);
			}
		}
	}




			//read nodes from file, check for nodes that are of type 3(course units)
			//display them to the user and have them choose one;
			//otherwise have them create a new class node;


		// Node newCourseUnit;
		// newCourseUnit = Graph::createCourseUnitNode();
		// Edge newCourse_SemesterEdge;
		// newCourse_SemesterEdge = Graph::createEdge(semester,newCourseUnit);
		// myEdge = Graph::createEdge(newCourseUnit,myNode);

}

void userChoseUseData(){

}


// Node myNode;
// myNode = Graph::createNode();
// if myNode

// 	Node semester;
// semester = Graph::getSemester();
// Node created;
// created = Graph::createNode();
// Node course;
// course = Graph::createNode();
// Edge myEdge;
// myEdge = Graph::createEdge(created,semester);
// Edge myEdge2;
// myEdge2 = Graph::createEdge(created,course);
// Node testO;
// Node test1;
// Node tester0;
// Node tester1;
// tester0 = myEdge2.getOrigin();
// tester1 = myEdge2.getTarget();
// test1 = myEdge.getTarget();
// testO = myEdge.getOrigin();	
// string rlshp;
// string rlshp2;
// rlshp = myEdge.getRelationship();
// rlshp2 = myEdge2.getRelationship();

// cout<<endl<<endl;

// testO.showNodeData();
// cout<<rlshp<<": ";
// test1.showNodeData();
// cout<<rlshp2<<": ";
// tester1.showNodeData();

