#include <iostream>
#include "CourseManager.hpp"


void CourseManager::loadCourses(){
    int numberCourses;
    std::ifstream input;
    input.open("courses.txt");
    input>>numberCourses;
    cursos=new Course[numberCourses];
    for(int i=0;i<numberCourses;i++){
        int a;
        
    }
};

void CourseManager::updateCourses(){

};

CourseManager::CourseManager(char path[], StudentManager* sm, FacultyManager* fm){

};

void CourseManager::createNewCourse(){

};

void CourseManager::editCourse(){

};

void CourseManager::showCourses(){

};

void CourseManager::showClassByID(std::string nrc){

};

void CourseManager::deleteCourse(){

};
