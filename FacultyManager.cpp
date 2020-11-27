#include "FacultyManager.hpp"
using namespace std;

template <typename T>
T consoleInput(const char * askfor){
    cout << askfor << endl;
    T retValue;
    cin >> retValue;
    return retValue;
}

void FacultyManager::loadFaculty(){
    ifstream input(this->pathFaculty);
    //formato:
    //bannerid nombre apellido usuario contrasenia carrera
    int total;
    input >> total;
    string _bannerId;
    string _nombre;
    string _apellido;
    string _usuario;
    string _contrasenia;
    string _carrera;
    for (int i = 0; i < total ; i ++){
        input >> _bannerId >> _nombre >> _apellido >> _usuario >>
            _contrasenia >> _carrera;
        this->profesores.push_back(Faculty{_bannerId, _nombre, _apellido, _usuario, _contrasenia, _carrera});
    }
    input.close();
};

void FacultyManager::updateFaculty(){
    //volver a escribir todos los datos dentro de los archivos
    ofstream output(this->pathFaculty);
    if (output.is_open()) {
        output << profesores.size() << endl;
        for (int i = 0; i < profesores.size() ; i++) {
            output << profesores[i].getBannerID() << " " << profesores[i].getNombre() << " " << profesores[i].getApellido() << " " << profesores[i].getUsuario() << profesores[i].getContrasenia() << profesores[i].getCarrera() << endl;
        }
    } else {
        cerr << "No se pudo encontrar el archivo para guardar. No se pudo actualizar." << this->pathFaculty<< endl;
    }
    output.close();
};

FacultyManager::FacultyManager(string path) : pathFaculty(path){
    loadFaculty();
};


void FacultyManager::createNewFaculty(UserManager* um){//terminar
    string _bannerId = um->getNewBannerID();
    string _nombre = consoleInput<string>("Nombre del profesor: ");
    string _apellido = consoleInput<string>("Apellido del profesor: ");
    string _carrera = consoleInput<string>("Carrera: ");
    string _usuario = consoleInput<string>("Nombre de usuario: ");
    string _contrasenia = consoleInput<string>("Contrasenia: ");
    profesores.push_back(Faculty(_bannerId, _nombre, _apellido, _contrasenia, _usuario, _carrera));
};

Faculty* FacultyManager::getFacultyByID(string BannerID){
    for(int i = 0; i < profesores.size(); i ++){
        if(profesores[i].getBannerID() == BannerID){
            return &profesores[i];
        }
    }
    cerr << "No match found for banner Id " << BannerID << "\nReturning nullptr";
    return nullptr;
};

deque<Faculty> FacultyManager::getAllFaculty(){ 
    return profesores;
};

void FacultyManager::editFaculty(Faculty* profesor){
    //buscar la que tiene el mismo banner id y reemplazarle en la memoria
    for(int i = 0; i < this->profesores.size(); i ++){
        if (profesor->getBannerID() == profesores[i].getBannerID()){
            profesores[i] = *profesor;
        }
    }
};

void FacultyManager::showFaculty(string BannerId){
    for (int i = 0; i < profesores.size(); i ++)  {
        if (profesores[i].getBannerID() == BannerId) {
            cout << profesores[i].to_string() << endl;
        }
    }
};

void FacultyManager::deleteFaculty(string _BannerId){
    //encontrar el profesor:
    int pos = 0;
    for (auto prof : profesores) {
        if (prof.getBannerID() == _BannerId) {
            profesores.erase(profesores.begin() + pos);
            break;
        }
        pos ++;
    }
};

FacultyManager::~FacultyManager(){
    updateFaculty();
}
