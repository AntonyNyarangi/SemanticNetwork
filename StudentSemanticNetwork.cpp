#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

#include "SemanticNetworkClasses.hpp"

using namespace std;

// Node createStudentNode();
// Node createCourseUnitNode();
// Node createTeacherNode();
// Edge createEdge(Node o_node, Node t_node);
int main(){
	Node semester;
	semester = Graph::getSemester();
	Node created;
	created = Graph::createNode();
}
// Node createStudentNode(){
// 	Node newStudent;
// 	string name;
// 	int type = 1;

// 	cout<<"Please enter the name of the student"<< endl;
// 	getline(std::cin,name);

// 	newStudent.setData(name,type);

// 	return newStudent;
// }

// Node createCourseUnitNode(){
// 	Node newCourse;
// 	string name;
// 	int type = 3;

// 	cout<<"Please enter the name of the course"<< endl;
// 	getline(std::cin,name);	

// 	newCourse.setData(name, type);

// 	return newCourse;
// }

// Node createTeacherNode(){
// 	Node newTeacher;
// 	string name;
// 	int type = 4;

// 	cout<<"Please enter the name of the Teacher"<< endl;
// 	getline(std::cin,name);
	
// 	newTeacher.setData(name, type);

// 	return newTeacher;
// }

// Edge createEdge(Node o_node, Node t_node){
// 	Edge newEdge;
// 	if(o_node.getType() == 1 && t_node.getType() == 2){
// 		newEdge.setRelationship("Registered in");
// 	}else if(o_node.getType() == 2 && t_node.getType() == 3){
// 		newEdge.setRelationship("Has");
// 	}else if(o_node.getType() == 3 && t_node.getType() == 4){
// 		newEdge.setRelationship("Taught By");
// 	}

// 	newEdge.setOrigin(o_node);
// 	newEdge.setTarget(t_node);	

// 	return newEdge;
// }
