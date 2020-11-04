#include <iostream>
#include "CourseManager.hpp"


void CourseManager::loadCourses(){

    std::ifstream input;
    input.open("courses.txt");
    input>>numCursos;
    cursos=new Course[numCursos];
    for(int i=0;i<numCursos;i++){
        std::string nombreAux;
        std::string creditos;
        std::string nrcAux;
        std::string path;
        input>>nombreAux>>creditos>>nrcAux>>path;
    }
};

void CourseManager::updateCourses(){
    loadCourses();
};

CourseManager::CourseManager(char path[], StudentManager* sm, FacultyManager* fm){

};

void CourseManager::createNewCourse(){
    
};

void CourseManager::editCourse(){

};

void CourseManager::showCourses(){
    std::cout<<"Cursos disponibles"<<std::endl;
    for(int i=0;i<numCursos;i++){
        std::cout<<"NRC"<<std::setw(10)<<"Creditos"<<std::setw(10)<<"Profesor"<<std::endl;
        std::cout<<cursos[i].getNRC()<<std::setw(10)<<cursos[i].getName()<<std::setw(10)<<cursos[i].getCreditos()<<" "<<cursos[i].getProfesor()->getNombre()<<cursos[i].getProfesor()->getApellido()<<std::endl;
    }

};

void CourseManager::showClassByID(std::string nrc){
    for(int i=0;i<numCursos;i++){
        if(cursos[i].getNRC()==nrc){
            std::cout<<"NombreCurso:"<<" "<<cursos[i].getName()<<std::endl;
            std::cout<<"NRC:"<<cursos[i].getNRC()<<std::endl;
            std::cout<<"Profesor:"<<cursos[i].getProfesor()->getNombre()<<" "<<cursos[i].getProfesor()->getApellido()<<std::endl;
            std::cout<<"Estudiantes"<<std::endl;
            for(int j=0;j<cursos[i].getTotalEstudiantes();j++){
                std::cout<<cursos[i].getStudents()[j].getBannerID()<<"\t"<<cursos[i].getStudents()[j].getNombre()<<"\t"<<cursos[i].getStudents()[j].getApellido()<<std::endl;
            }
        }else{
            std::cout<<"No existe clase con ese NRC"<<std::endl;
        }
        
    }
};

void CourseManager::deleteCourse(std::string nrc){
    for(int i=0;i<numCursos;i++){
        if(cursos[i].getNRC()==nrc){
            std::ofstream file;
            file.open("courses.txt", std::ofstream::out | std::ofstream::trunc);
            file.close();
            std::ofstream output;
            output.open("/data/courses.txt");
            output<<numCursos-1<<"\n";
            for(int j=0;j<i-1;j++){
                output<<cursos[i].getName()<<" "<<cursos[i].getCreditos()<<" "<<cursos[i].getNRC()<<" "<<cursos[i].getPath();
            }
            for(int j=i+1;j<numCursos;j++){
                output<<cursos[i].getName()<<" "<<cursos[i].getCreditos()<<" "<<cursos[i].getNRC()<<" "<<cursos[i].getPath();
            }
        }
    }
    updateCourses();
};
