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
    for(int i = 0; i < totalProfesores; i ++){
        if(profesores[i].getBannerID() == BannerID){
            return &profesores[i];
        }
    }
    cerr << "No match found for banner Id " << BannerID << "\nReturning nullptr";
    return nullptr;
};

Faculty* FacultyManager::getAllFaculty(int &total){ //cambiar referencia cuando aprendamos array list
    total = this->totalProfesores;
    return profesores;
};

void FacultyManager::editFaculty(Faculty* profesor){
    //buscar la que tiene el mismo banner id y reemplazarle en la memoria
    for(int i = 0; i < this->totalProfesores; i ++){
        if (profesor->getBannerID() == profesores[i].getBannerID()){
            profesores[i] = *profesor;
        }
    }
};

void FacultyManager::showFaculty(string BannerId){
};

void FacultyManager::deleteFaculty(string BannerId){//cambiar cuando aprendamos array lists
    Faculty* profesoresAux = new Faculty[this->totalProfesores - 1];
    int offset = 0;
    bool facultyExists = false;
    for (int i = 0; i < this->totalProfesores ; i ++){
        if (profesores[i].getBannerID() != BannerId){
            profesoresAux[i - offset] = profesores[i];
        } else {
            facultyExists = true;
            offset += 1;
        }
    }// si sale core dumped esto puede ser
    if (facultyExists){
        delete profesores;
        this->totalProfesores = this->totalProfesores -1;
        profesores = new Faculty[this->totalProfesores];
        for (int i = 0; i < this->totalProfesores ; i ++){
            profesores[i] = profesoresAux[i];
        }
    }
};

