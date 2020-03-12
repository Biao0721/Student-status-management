#include<iostream>
#include"course.h"
using namespace std;

course::course(){}

int course::getCourseNum() {
	return this->c_num;
}

string course::getCourseName() {
	return this->c_name;
}

int course::getCourseCode() {
	return this->c_code;
}

void course::setCourseNum(int c_num) {
	this->c_num = c_num;
}

void course::setCourseName(string c_name) {
	this->c_name = c_name;
}

void course::setCourseCode(int c_code) {
	this->c_code = c_code;
}