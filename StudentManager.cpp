#include <iostream> 
#include "StudentManager.hpp"
using namespace std;

void StudentManager::loadUnderGrads(){
    int numberUnder;
    std::ifstream input;
    input.open(this->pathUndergraduate);
    input>>numberUnder;
    UnderGraduateStudent* UnderGrad= new UnderGraduateStudent[numberUnder];
    for(int i=0;i<numberUnder;i++){
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

        UnderGrad[i]=UnderGraduateStudent(bannerIDAux,nombreAux,apellidoAux,usuarioAux,contraseniaAux,carreraAux,proxyAux);
    }
    for(int i = 0; i < numberUnder; i ++){
        estudiantes[i] = UnderGrad[i];
    }
};

void StudentManager::loadGrads(){
    int numberGrad;
    std::ifstream input;
    input.open(this->pathGraduate);
    input>>numberGrad;

    GraduateStudent* Grad= new GraduateStudent[numberGrad];
    for(int i=0;i<numberGrad;i++){
        std::string bannerIDAux;
        std::string nombreAux;
        std::string apellidoAux;
        std::string usuarioAux;
        std::string contraseniaAux;
        std::string carreraAux;
        std::string nivelAux;
        input>>bannerIDAux>>nombreAux>>apellidoAux>>usuarioAux>>contraseniaAux>>carreraAux>>nivelAux;

        Grad[i + totalUnderGraduate]=GraduateStudent(bannerIDAux,nombreAux,apellidoAux,contraseniaAux,usuarioAux,carreraAux,nivelAux);
    }
    for(int i = 0; i < numberGrad; i ++){
        estudiantes[i] = Grad[i];
    }
};
void StudentManager::updateUnderGrads(){
    // Esto actualiza el archivo
};

//para poder hacer esta parte pongamos primero los undergrads y luego los grads en el
//arreglo de estudiantes. así cuando queramos iterar por la lista de undergrads podemos 
//ir desde 0 hasta numUndergrads y si queremos iterar por los grads vamos desde numundergrads+1 hasta 
//num undergrads+numgrads
StudentManager::StudentManager(char* pathUndergrad, char* pathGrad) : pathUndergraduate(pathUndergrad), pathGraduate(pathGrad){
    ifstream Under(this->pathUndergraduate);//leo la primera linea para saber el total de cada tipo
    ifstream Grad(this->pathGraduate);
    Under >> totalUnderGraduate;//creé una variable de total para poder iterar despues
    Grad >> totalGraduate;
    totalEstudiantes = totalUnderGraduate + totalGraduate;
    estudiantes=new Student[totalEstudiantes]; //cambiar, hay que hacer que sume los graduados tambien
    loadUnderGrads();
    loadGrads();
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

void StudentManager::editStudent(Student* estudiante){//cambiar polimosfismo
    for (int i = 0; i < totalEstudiantes; i ++){
        if(estudiantes[i].getBannerID() == estudiante->getBannerID()){
            estudiantes[i] = *estudiante;
        }
    }
};

void StudentManager::showStudents(){
    for (int i = 0; i < totalEstudiantes; i ++) {
        cout << estudiantes[i].to_string() << endl;
    }
};

void StudentManager::deleteStudent(std::string bannerID_){
    //preguntar aqui se tendria que pasar un banner id?
};
