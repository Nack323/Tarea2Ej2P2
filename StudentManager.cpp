#include <iostream> 
#include "StudentManager.hpp"
using namespace std;

<<<<<<< HEAD
StudentManager::StudentManager(char* path){//cambiar para dos paths
    ifstream input(path);
    
};

=======
>>>>>>> b31bc87c645c754c396c81b323ce96c0a2742dd6
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
//cambiar implementar updateGrads 
//cambiar implemebtar loadGrads
void StudentManager::updateUnderGrads(){
<<<<<<< HEAD
    // Esto actualiza el archivo
=======
    loadUnderGrads();
     
};

StudentManager::StudentManager(char path[]){
>>>>>>> b31bc87c645c754c396c81b323ce96c0a2742dd6

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
