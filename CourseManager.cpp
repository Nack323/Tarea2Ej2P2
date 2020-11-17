#include <iostream>
#include "CourseManager.hpp"

void CourseManager::loadCourses(){

    std::ifstream input;
    input.open(pathCursos);
    input>>numCursos;
    cursos=new Course[numCursos];
    for(int i=0;i<numCursos;i++){
        std::string nrcAux,creditosAux,profeAux,pathAux;
        input>>nrcAux>>creditosAux>>profeAux>>pathAux;
        int x=3;
        Faculty* profesores=fm->getAllFaculty(x);
        Student* estudiantes=sm->getAllStudents(x);
        int numberEst; 
        Faculty* profesor;
        for(int j=0;j<(sizeof(profesores)/sizeof(profesores[0]));i++){
            if(profeAux==profesores[j].getBannerID()){
                profesor=&(profesores[j]);
            }
        }
        std::string* BannerID;
        std::ifstream fileEst;
        fileEst.open(pathAux);
        fileEst>>numberEst;
        Student* clase;
        Grade* notas;
        clase=new Student[numberEst];
        notas=new Grade[numberEst];
        std::string line;
        for(int j=0;j<numberEst;j++){
            getline(fileEst,line);
            std::string ban,nota;
            int k=0;
            while(line[k]!=' '){
                ban+=line[k];
                k++;
            }
            k++;
            while(line[k]){
                nota+=line[k];
            }
            notas[i].setNota(stoi(nota));
            //Problema con la funcion getStudentByID
            //clase[i]=sm.getStudentByID(ban);
        fileEst.close();
        }
        cursos[i]=Course(nrcAux,profesor,clase,notas,numberEst,stoi(creditosAux),pathAux);
    }
    input.close();
};

void CourseManager::updateCourses(){
    std::ofstream file;
    file.open(pathCursos,std::ofstream::out | std::ofstream::trunc);
    file<<numCursos;
    for(int i=0;i<numCursos;i++){
        file<<cursos[i].getNRC()<<" "<<cursos[i].getCreditos()<<" "<<cursos[i].getProfesor()->getBannerID()<<" "<<cursos[i].getPath()<<std::endl;
    }   
    file.close();
    loadCourses();
};



CourseManager::CourseManager(std::string pathCursos_, StudentManager* sm, FacultyManager* fm):pathCursos(pathCursos_),sm(sm),fm(fm){
    loadCourses();
};  

void CourseManager::createNewCourse(){
    std::string NRXAux,creditosAux,ProfesorAux;
    std::cout<<"NRC de la nueva Clase"<<std::endl;
    std::cin>>NRCAux;
    std::cout<<"Creditos de la Nueva Clase"<<std::endl; 
    std::cin>>creditosAux;
    std::cout<<"BannerID del profesor de la Clase"<<std::endl;
    std::cin>>ProfesorAux,
    std::ofstream file;
    std::string newpath=nrcAux+"_"+BannerID+"txt";
    std::ofstram newfile;
    newfile.open(newpath);
    newfile<<"0";
    newfile.close()
    file.open(pathCursos,std::ios::app);
    file<<NRXAux<<" "<<creditosAux<<" "<<ProfesorAux<<" "<<newpath<<std::endl;
    delete[] cursos;
    loadCourses();
};

void CourseManager::editCourse(){

};

void CourseManager::showCourses(){
    std::cout<<"Cursos disponibles"<<std::endl;
    for(int i=0;i<numCursos;i++){
        std::cout<<"NRC"<<std::setw(10)<<"Creditos"<<std::setw(10)<<"Profesor"<<std::endl;
        std::cout<<cursos[i].getNRC()<<std::setw(10)<<cursos[i].getCreditos()<<" "<<cursos[i].getProfesor()->getNombre()<<cursos[i].getProfesor()->getApellido()<<std::endl;
    }

};


void CourseManager::showClassByID(std::string nrc){
    for(int i=0;i<numCursos;i++){
        if(cursos[i].getNRC()==nrc){
            std::cout<<"NRC:"<<cursos[i].getNRC()<<std::endl;
            std::cout<<"Creditos"<<cursos[i].getCreditos()<<std::endl;
            std::cout<<"Profesor:"<<cursos[i].getProfesor()->getNombre()<<" "<<cursos[i].getProfesor()->getApellido()<<std::endl;
            std::cout<<"Estudiantes"<<std::endl;
            for(int j=0;j<cursos[i].getTotalEstudiantes();j++){
                std::cout<<cursos[i].getStudents()[j].getBannerID()<<"\t"<<cursos[i].getStudents()[j].getNombre()<<"\t"<<cursos[i].getStudents()[j].getApellido()<<std::endl;
            }
        }else{
            std::cout<<"No existe clase con ese NRC"<<std::endl;
        }
        
    }
}

void CourseManager::deleteCourse(std::string nrc){
    for(int i=0;i<numCursos;i++){
        if(cursos[i].getNRC()==nrc){
            std::ofstream file;
            file.open("courses.txt", std::ofstream::out | std::ofstream::trunc);
            file.close();
            std::ofstream output;
            output.open("courses.txt");
            output<<numCursos-1<<"\n";
            for(int j=0;j<i-1;j++){
                output<<cursos[i].getNRC()<<" "<<cursos[i].getCreditos()<<" "<<cursos[i].getProfesor()->getBannerID()<<" "<<cursos[i].getPath();
            }
            for(int j=i+1;j<numCursos;j++){
                output<<cursos[i].getNRC()<<" "<<cursos[i].getCreditos()<<" "<<cursos[i].getProfesor()->getBannerID()<<" "<<cursos[i].getPath();
            }
        }
    }
    loadCourses();
};
