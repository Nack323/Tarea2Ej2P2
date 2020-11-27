#include <iostream> 
#include "StudentManager.hpp"
using namespace std;

template <typename T>
T consoleInput(const char * askfor){
    cout << askfor << endl;
    T retValue;
    cin >> retValue;
    return retValue;
}


void StudentManager::loadUnderGrads(){
    int total;
    ifstream input;
    input.open(this->pathUndergraduate);
    input>>total;
    for(int i=0;i<total;i++){
        std::string bannerIDAux;
        std::string nombreAux;
        std::string apellidoAux;
        std::string usuarioAux;
        std::string contraseniaAux;
        std::string carreraAux;
        std::string pnombreAux;
        std::string papellidoAux;
        std::string pemailAux;
        std::string ptelefAux;
        input>>bannerIDAux>>nombreAux>>apellidoAux>>usuarioAux>>contraseniaAux>>carreraAux>>pnombreAux>>papellidoAux>>pemailAux>>ptelefAux;
        Proxy proxyAux(pnombreAux,papellidoAux,pemailAux,ptelefAux);


        UnderGraduateStudent* newUnder = new UnderGraduateStudent(bannerIDAux,nombreAux,apellidoAux,usuarioAux,contraseniaAux,carreraAux,proxyAux);
        Student *Stptr(&*newUnder);
        estudiantes.push_back(Stptr);
    }
};

void StudentManager::loadGrads(){
    int total;
    std::ifstream input;
    input.open(this->pathGraduate);
    input>>total;
    for(int i=0;i<total;i++){
        std::string bannerIDAux;
        std::string nombreAux;
        std::string apellidoAux;
        std::string usuarioAux;
        std::string contraseniaAux;
        std::string carreraAux;
        std::string nivelAux;
        input>>bannerIDAux>>nombreAux>>apellidoAux>>usuarioAux>>contraseniaAux>>carreraAux>>nivelAux;

        GraduateStudent* newGrad = new GraduateStudent(bannerIDAux,nombreAux,apellidoAux,contraseniaAux,usuarioAux,carreraAux,nivelAux);
        Student *stpt{&*newGrad};
        estudiantes.push_back(stpt);
    }
};
void StudentManager::updateUnderGrads(){
    // Esto actualiza el archivo
};


StudentManager::StudentManager(char* pathUndergrad, char* pathGrad) : pathUndergraduate(pathUndergrad), pathGraduate(pathGrad){
    loadUnderGrads();
    loadGrads();
};

void StudentManager::createNewStudent(UserManager* um){
    cout << "Pregrado o posgrado? \n1. Pregrado\n2. Posgrado" << endl;
    int opt;
    cin >> opt;
    cout << endl;

    if (opt == 2){
        string _bannerId = um->getNewBannerID();
        std::string nombreAux = consoleInput<string>("Nombre: ");
        std::string apellidoAux = consoleInput<string>("Apellido: ");
        std::string usuarioAux = consoleInput<string>("Usuario: ");
        std::string contraseniaAux = consoleInput<string>("Contrasenia: ");
        std::string carreraAux = consoleInput<string>("Carrera: ");
        std::string nivelAux = consoleInput<string>("Nivel: ");
        GraduateStudent* newGrad = new GraduateStudent(_bannerId,nombreAux,apellidoAux,contraseniaAux,usuarioAux,carreraAux,nivelAux);
        Student *stpt{&*newGrad};
        estudiantes.push_back(stpt);
    }
    else if (opt == 1) {
        std::string bannerIDAux = um->getNewBannerID();
        std::string nombreAux = consoleInput<string>("Nombre: ");
        std::string apellidoAux = consoleInput<string>("Apellido: ");
        std::string usuarioAux = consoleInput<string>("Usuario: ");
        std::string contraseniaAux = consoleInput<string>("Contrasenia: ");
        std::string carreraAux = consoleInput<string>("Carrera: ");
        std::string pnombreAux = consoleInput<string>("Nombre del representante: ");
        std::string papellidoAux = consoleInput<string>("Apellido del representante: ");
        std::string pemailAux = consoleInput<string>("Email del representante: ");
        std::string ptelefAux = consoleInput<string>("Telefono del representante: ");
        Proxy proxyAux(pnombreAux,papellidoAux,pemailAux,ptelefAux);

        UnderGraduateStudent* newUnder = new UnderGraduateStudent(bannerIDAux,nombreAux,apellidoAux,usuarioAux,contraseniaAux,carreraAux,proxyAux);
        Student *Stptr(&*newUnder);
        estudiantes.push_back(Stptr);

    }
    else {
        cout << "No es una opcion valida" << endl;
    }
};

Student* StudentManager::getStudentByID(string BannerID){
    for(int i = 0; i < estudiantes.size(); i ++){
        if (estudiantes[i]->getBannerID() == BannerID){
            return estudiantes[i];
        }
    }//cambiar por array list
    return nullptr;
};

deque<Student*> StudentManager::getAllStudents(){
    return this->estudiantes;
}

void StudentManager::editStudent(Student* estudiante){//preguntar
    for (int i = 0; i < estudiantes.size(); i ++){
        if(estudiantes[i]->getBannerID() == estudiante->getBannerID()){
            estudiantes[i] = estudiante;
        }
    }
};

void StudentManager::showStudents(){
    for (auto stud : estudiantes) {
        cout << stud->to_string() << endl;
    }
};

void StudentManager::deleteStudent(std::string bannerID_){
    int pos = 0;
    for(auto stud : estudiantes) {
        if (stud->getBannerID() == bannerID_) {
            estudiantes.erase(estudiantes.begin() + pos);
            break;
        }
        pos ++;
    }
};

void StudentManager::showStudent(string bannerId) {
    for(auto stud : estudiantes) {
        if (stud->getBannerID() == bannerId) {
            cout << stud->to_string() << endl;
        }
    }
}
