#include <iostream> 
#include "StudentManager.hpp"
using namespace std;

StudentManager::StudentManager(char* path){//preguntar hay que pasarle dos paths de undergrads y grads?
    ifstream input(path);
    
};

void StudentManager::loadUnderGrads(){

};

void StudentManager::updateUnderGrads(){
    // preguntar para que sirve esta funcion

};
void StudentManager::createNewStudent(UserManager* um){
    //preguntar como se hace esto :<

};

Student* StudentManager::getStudentByID(string BannerID){
    for(int i = 0; i < totalEstudiantes; i ++){
        if (estudiantes[i].getBannerID() == BannerID){
            return &estudiantes[i];
        }
    }//preguntar esta bien dejar con un int que guarde la longitud?
    return nullptr;
};

Student* StudentManager::getAllStudents(int &total){
    total = totalEstudiantes;
    return estudiantes;
}

void StudentManager::editStudent(){
    //preguntar debería tener de input in student
};

void StudentManager::showStudents(){
    //preguntar aqui se imprime todos?
};

void StudentManager::deleteStudent(){
    //preguntar aqui se tendria que pasar un banner id?
};
