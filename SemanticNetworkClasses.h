#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Node{
private:
	//shared data
	string objName;
	int objType;

	 //data for students
	string regNumber;

	//data for semester
	int semesterNumber;

	//data for teachers
	string staffNumber;
	
	//data for courses
	string courseID;

	void populateStudent(){
		std::cout<< "Enter new Registration Number" << endl;
		getline(std::cin,regNumber);
		// std::getline(std::cin,regNumber);
		semesterNumber = -1;
		staffNumber = "-1";
		courseID ="-1"; 
	}

	void populateSemester(){
		std::cout<< "Enter Semester Number" << endl;
		std::cin>>semesterNumber;
		regNumber = "-1";
		staffNumber = "-1";
		courseID ="-1";
	}

	void populateCourse(){
		std::cout<< "Enter Course ID" << endl;
		getline(std::cin,courseID);
		regNumber = "-1";
		staffNumber = "-1";
		semesterNumber = -1;
	}

	void populateTeacher(){
		std::cout<< "Enter Staff Number" << endl;
		getline(std::cin,staffNumber);
		regNumber = "-1";
		courseID = "-1";
		semesterNumber = -1;
	}

	void write_to_file(){
		ofstream myFile;
		myFile.open("nodes.txt",ofstream::out | ofstream::app);
		myFile << objName << ",";
		myFile << objType << ",";
		myFile << regNumber << ",";
		myFile << semesterNumber << ",";
		myFile << staffNumber << ",";
		myFile << courseID << endl;
		myFile.close();
	}

public:

	void setData(string name, int type){
		objName = name;
		objType = type;
		switch (objType){
			case 1: populateStudent();write_to_file();	
			break;
			case 2: populateSemester();write_to_file();	
			break;
			case 3: populateCourse();write_to_file();	
			break;		
			case 4: populateTeacher();write_to_file();				
			break;
			default: std::cout <<"Invalid type"<<endl;	
		}
	}

	int getType(){
		return objType;
	}

	void showNodeData(){
		std::cout << objName << ", ";	
		if (regNumber != "-1"){
			std::cout << regNumber << endl;			
		}else if(semesterNumber != -1){
			std::cout << semesterNumber << endl;
		}else if(staffNumber != "-1"){
			std::cout << staffNumber << endl;
		}else{
			std::cout << courseID << endl;
		}		
	}
};


class Edge{
private:
	Node origin;
	Node target;
	string relationship;
public:
	void setOrigin(Node o_node){
		origin = o_node;
	}

	void setTarget(Node t_node){
		target = t_node;
	}


	void setRelationship(string rlshp){
		relationship = rlshp;
	}

	Node getOrigin(){return origin;}
	Node getTarget(){return target;}
	string getRelationship(){return relationship;}

	// void write_to_file(){
	// 	ofstream myFile;
	// 	myFile.open("edges.txt",ofstream::out | ofstream::app);
	// 	myFile << origin.objName << ",";
	// 	myFile << origin.objType << ",";
	// 	myFile << target.objName << ",";
	// 	myFile << target.objType << ",";
	// 	myFile << relationship << endl;
	// 	myFile.close();
	// }
};


class Graph{

public:
	static Node createNode(){
		char nodeSelect;
		cout <<"\nWhat type Node would you like to create?"<<endl;
		cout <<"1) Student"<<endl;
		cout <<"2) Course"<<endl;
		cout <<"3) Teacher"<<endl;

		cout << "Choice: ";
		cin >>nodeSelect;
		cin.ignore();

		Node newNode; 

		switch (nodeSelect){
			case '1': newNode = createStudentNode();
			return newNode;
			break;
			case '2': newNode = createCourseUnitNode();
			return newNode;
			break;
			case '3': newNode = createTeacherNode();
			return newNode;
			default: cout <<"Invalid Entry"<<endl;
		}			
	}

	static Node createStudentNode(){
		Node newStudent;
		string name;
		int type = 1;

		cout<<"Please enter the name of the student"<< endl;
		getline(std::cin,name);

		newStudent.setData(name,type);

		return newStudent;
	}

	static Node createCourseUnitNode(){
		Node newCourse;
		string name;
		int type = 3;

		cout<<"Please enter the name of the course"<< endl;
		getline(std::cin,name);	

		newCourse.setData(name, type);

		return newCourse;
	}

	static Node createTeacherNode(){
		Node newTeacher;
		string name;
		int type = 4;

		cout<<"Please enter the name of the Teacher"<< endl;
		getline(std::cin,name);

		newTeacher.setData(name, type);

		return newTeacher;
	}

	static Edge createEdge(Node o_node, Node t_node){
		Edge newEdge;
		if(o_node.getType() == 1 && t_node.getType() == 2){
			newEdge.setRelationship("Registered in");
		}else if(o_node.getType() == 2 && t_node.getType() == 3){
			newEdge.setRelationship("Has");
		}else if(o_node.getType() == 3 && t_node.getType() == 4){
			newEdge.setRelationship("Taught By");
		}

		newEdge.setOrigin(o_node);
		newEdge.setTarget(t_node);	

		return newEdge;
	}

};