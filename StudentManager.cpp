#include <iostream> 
#include "StudentManager.hpp"
using namespace std;

StudentManager::StudentManager(char* path){//cambiar para dos paths
    ifstream input(path);
    
};

void StudentManager::loadUnderGrads(){

};
//cambiar implementar updateGrads 
//cambiar implemebtar loadGrads
void StudentManager::updateUnderGrads(){
    // Esto actualiza el archivo

};
void StudentManager::createNewStudent(UserManager* um){
    //preguntar como se hace esto :<

};

Student* StudentManager::getStudentByID(string BannerID){
    for(int i = 0; i < totalEstudiantes; i ++){
        if (estudiantes[i].getBannerID() == BannerID){
            return &estudiantes[i];
        }
    }//cambiar por array list
    return nullptr;
};

Student* StudentManager::getAllStudents(int &total){
    total = totalEstudiantes;
    return estudiantes;
}

void StudentManager::editStudent(){
    //cambiar con input student
};

void StudentManager::showStudents(){
    //preguntar aqui se imprime todos?
};

void StudentManager::deleteStudent(){
    //preguntar aqui se tendria que pasar un banner id?
};
