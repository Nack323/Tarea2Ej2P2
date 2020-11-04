#include <iostream> 
#include "StudentManager.hpp"

void StudentManager::loadUnderGrads(){
    int numberUnder;
    std::ifstream input;
    input.open("estudiantes_pregrado.txt");
    input>>numberUnder;
    estudiantes=new Student[numberUnder];
    UnderGraduateStudent* UnderGrad=dynamic_cast<UnderGraduateStudent*>(estudiantes);

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

void StudentManager::updateUnderGrads(){
    loadUnderGrads();
     
};

StudentManager::StudentManager(char path[]){

};

void StudentManager::createNewStudent(UserManager* um){

};

Student* StudentManager::getStudentByID(std::string BannerID){

};

Student* StudentManager::getAllStudents(){

};

void StudentManager::editStudent(){

};

void StudentManager::showStudents(){

};

void StudentManager::deleteStudent(){

};
