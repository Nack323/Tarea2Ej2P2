#include <iostream> 
#include "StudentManager.hpp"
using namespace std;

StudentManager::StudentManager(char* path){
    ifstream input(path);
    
};

void StudentManager::loadUnderGrads(){

};

void StudentManager::updateUnderGrads(){

};
void StudentManager::createNewStudent(UserManager* um){

};

Student* StudentManager::getStudentByID(string BannerID){
    for(int i = 0; i < totalEstudiantes; i ++){
        if (estudiantes[i].getBannerID() == BannerID){
            return &estudiantes[i];
        }
    }
    return nullptr;
};

Student* StudentManager::getAllStudents(int &total){
    total = totalEstudiantes;
    return estudiantes;
}

void StudentManager::editStudent(){

};

void StudentManager::showStudents(){

};

void StudentManager::deleteStudent(){

};
