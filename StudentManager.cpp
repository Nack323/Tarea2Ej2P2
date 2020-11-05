#include <iostream> 
#include "StudentManager.hpp"
using namespace std;

void StudentManager::loadUnderGrads(){
    int numberUnder;
    std::ifstream input;
    input.open(this->pathUndergraduate);
    input>>numberUnder;
    UnderGraduateStudent* UnderGrad=dynamic_cast<UnderGraduateStudent*>(estudiantes);//preguntar dynamic cast va a devolver 0 en toda esta parte?
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
};
void StudentManager::loadGrads(){

}
//cambiar implementar updateGrads 
//cambiar implemebtar loadGrads
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

void StudentManager::editStudent(){
    //cambiar con input student
};

void StudentManager::showStudents(){
    //preguntar aqui se imprime todos?
};

void StudentManager::deleteStudent(){
    //preguntar aqui se tendria que pasar un banner id?
};
