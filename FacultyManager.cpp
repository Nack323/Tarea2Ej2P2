#include "FacultyManager.hpp"
using namespace std;

void FacultyManager::loadFaculty(){
    ifstream input(this->pathFaculty);
    //formato:
    //bannerid nombre apellido usuario contrasenia carrera
    string _bannerId;
    string _nombre;
    string _apellido;
    string _usuario;
    string _contrasenia;
    string _carrera;
    input >> this->totalProfesores; //cambiar cuando aprendamos array list
    profesores = new Faculty[this->totalProfesores];
    for (int i = 0; i < this->totalProfesores ; i ++){
        input >> _bannerId >> _nombre >> _apellido >> _usuario >> _contrasenia >> _carrera;
        profesores[i] = Faculty{_bannerId, _nombre, _apellido, _usuario, _contrasenia, _carrera};
    }
};

void FacultyManager::updateFaculty(){
};

FacultyManager::FacultyManager(string path) : pathFaculty(path){
    loadFaculty();
};


//void FacultyManager::createNewFaculty(UserManager* um){

//};

Faculty* FacultyManager::getFacultyByID(string BannerID){
    return nullptr;
};

Faculty* FacultyManager::getAllFaculty(){
    return profesores;
};

void FacultyManager::editFaculty(Faculty* faculty){
};

void FacultyManager::showFaculty(string BannerId){

};

void FacultyManager::deleteFaculty(string BannerId){

};
