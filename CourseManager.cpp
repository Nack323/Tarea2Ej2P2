#include <iostream>
#include "CourseManager.hpp"


void CourseManager::loadCourses(){

    std::ifstream input;
    input.open(this->pathCursos);
    input>>numCursos;
    ArrayList<Course> cursosAux:
    cursos=cursosAux;
    

    for(int i=0;i<this->numCursos;i++){

        std::string nrcAux,creditosAux,profeAux,pathAux;
        Faculty* profesor;

        input>>nrcAux>>creditosAux>>profeAux>>pathAux;

        Curso cursoAux;
        cursoAux=Curso(nrcAux,creditosAux);

        cursos.add(cursoAux);

        profesor=fm->getFacultyByID(profeAux);
        cursos[i].setProfesor(profesor);

        std::ifstream fileEst;    
        
        fileEst.open(pathAux);
        fileEst>>numberEst;

        for(int j=0;j<numberEst;j++){

            std::string BannerIDAux;
            std::string notaAux;
            Student* studentAux;
            Grade* nota;

            fileEst>>BannerIDAux>>notaAux;

            studentAux=sm.getStudentByID(BannerIDAux);
            notaAux=Grade(stof(notaAux));

            cursos[i].addStudentGrade(studentAux,notaAux);

        }

        fileEst.close();

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
    delete[] cursos;
    loadCourses();
};


CourseManager::CourseManager(std::string pathCursos_, StudentManager* sm, FacultyManager* fm):pathCursos(pathCursos_),sm(sm),fm(fm){
    loadCourses();
};  

void CourseManager::createNewCourse(){
    
    std::string NRCAux,creditosAux,ProfesorAux;
    
    std::cout<<"NRC de la nueva Clase"<<std::endl;
    std::cin>>NRCAux;
    std::cout<<"Creditos de la Nueva Clase"<<std::endl; 
    std::cin>>creditosAux;
    std::cout<<"BannerID del profesor de la Clase"<<std::endl;
    std::cin>>ProfesorAux;

    std::ofstream file;
    std::string newpath=NRCAux+"_"+ProfesorAux+".txt";
    std::ofstream newfile;
    newfile.open(newpath);
    newfile<<"0";
    newfile.close();
    
    file.open(pathCursos,std::ios::app);
    file<<NRCAux<<" "<<creditosAux<<" "<<ProfesorAux<<" "<<newpath<<std::endl;
    
    Course* cursoAux{NRCAux,stof(creditosAux)};
    cursoAux.setProfesor(fm.getFacultyByID(ProfesorAux));
    cursos.add(cursoAux);
    updateCourses();
} 

void CourseManager::editCourse(){

    std::string option,NRCAux;
    std::cout<<"NRC del curso a editar"<<std::endl;
    std::cin>>NRCAux;

    for(int i=0;i<numCursos;i++){

        if(cursos[i].getNRC()==NRCAux){

            std::cout<<"Que desea cambiar de su Curso\n1.NRC\n2.Profesor\n3.Numero de Creditos"<<std::endl;
            std::cin>>option;

            if(option=="1"){

                std::string nrcAux;
                std::cout<< "Nuevo NRC:    ";
                std::cin>>nrcAux;

                std::string newPath=nrcAux+"_"+cursos[i].getProfesor()->getBannerID()+".txt";
                rename(cursos[i].getPath(),newPath);//bien :)
                cursos[i].setPath(newPath);
                cursos[i].setNRC(nrcAux);

                updateCourses();
                std::cout<<"Su Curso ha sido actualizado (Enter para volver al inicio)"<<std::endl;
                system("PAUSE");

            }else if(option=="2"){

                std::string ID;
                std::cout<<"BannerID del nuevo profesor:    ";
                std::cin>>ID;
                
                Faculty* nuevoProfesor=fm->getFacultyByID(ID);
                std::string newPath=cursos[i].getNRC()+"_"+ID+".txt";
                rename(c_str(cursos[i].getPath()),c_str(newPath));
                cursos[i].setPath(newPath);
                cursos[i].setProfesor(nuevoProfesor);
                
                updateCourses(); 
                std::cout<<"Su Curso ha sido actualizado (Enter para volver al inicio)"<<std::endl;
                system("PAUSE");

            }else if(option=="3"){

                int creditosAux;
                std::cout<<"Creditos nuevos:     ";
                std::cin>>creditosAux;
                
                cursos[i].setCreditos(creditosAux);
                
                updateCourses();
                std::cout<<"Su Curso ha sido actualizado (Enter para volver al inicio)"<<std::endl;
                system("PAUSE");

            }else{

                system("clear");
                std::cout<<"No se ingreso una opcion valida"<<std::endl,
                editCourse();

            }    

            showClassByID(cursos[i].getNRC());     
        }
    }
}    ;

void CourseManager::showCourses(){

    std::cout<<"Cursos disponibles"<<std::endl;
    
    for(int i=0;i<numCursos;i++){

        std::cout<<"NRC"<<std::setw(10)<<"Creditos"<<std::setw(10)<<"Profesor"<<std::endl;
        std::cout<<cursos[i].getNRC()<<std::setw(10)<<cursos[i].getCreditos()<<" "<<cursos[i].getProfesor()->getNombre()<<cursos[i].getProfesor()->getApellido()<<std::endl;
    
    }
    std::cout<<"\n\n Para regresar presione Enter"<<std::endl;
    system("PAUSE");

};


void CourseManager::showClassByID(std::string nrc){

    for(int i=0;i<numCursos;i++){

        if(cursos[i].getNRC()==nrc){

            std::cout<<"NRC:"<<cursos[i].getNRC()<<std::endl;
            std::cout<<"Creditos:"<<cursos[i].getCreditos()<<std::endl;
            std::cout<<"Profesor:"<<cursos[i].getProfesor()->getNombre()<<" "<<cursos[i].getProfesor()->getApellido()<<std::endl;
            std::cout<<"Estudiantes:"<<std::endl;

            for(int j=0;j<cursos[i].getTotalEstudiantes();j++){

                std::cout<<cursos[i].getStudents()[j].getBannerID()<<"\t"<<cursos[i].getStudents()[j].getNombre()<<"\t"<<cursos[i].getStudents()[j].getApellido()<<std::endl;
            
            }

            break;  

        }  

        std::cout<<"No se encontro clase con ese NRC"<<std::endl;     

    }

    std::cout<<"Para regresar ingrese Enter"<<std::endl;
    system("PAUSE");
}

void CourseManager::deleteCourse(std::string nrc){

    for(int i=0;i<numCursos;i++){

        if(cursos[i].getNRC()==nrc){

            std::ofstream output;
            output.open("courses.txt", std::ofstream::out | std::ofstream::trunc);
            output<<numCursos-1<<"\n";

            for(int j=0;j<i-1;j++){   

                output<<cursos[i].getNRC()<<" "<<cursos[i].getCreditos()<<" "<<cursos[i].getProfesor()->getBannerID()<<" "<<cursos[i].getPath();

            }

            for(int j=i+1;j<numCursos;j++){

                output<<cursos[i].getNRC()<<" "<<cursos[i].getCreditos()<<" "<<cursos[i].getProfesor()->getBannerID()<<" "<<cursos[i].getPath();

            }

            output.close();

        }

    }

    delete[] cursos;
    loadCourses();
};

Course* CourseManager::getCourseByNRC(std::string nrc_){

    for(int i = 0; i<numCursos;i++){

        if(cursos[i].getNRC()==nrc_){

            return &cursos[i];

        }
    
    }

}
/*
void CourseManager::addStudentToClass(Course* curso_,Student* estudiante_){
    
    for(int i =0; i <numCursos;i++){

        if(curso_==&cursos[i]){

            std::ofstream estudiantes;
            estudiantes.open(cursos[i].getPath(),std::ios::app);
            estudiantes<<estudiante_->getBannerID()<<" "<<"0";
            estudiantes.close();
            delete[] cursos;
            loadCourses();

        }

    }

}


void CourseManager::addFacultyToClass(Course* curso_,Faculty* profesor_){

    for(int i=0 ;i<numCursos;i++){

        if(curso_==&cursos[i]){

            cursos[i].setProfesor(profesor_);
            std::string newPath=cursos[i].getNRC()+"_"+profesor_->getBannerID()+".txt";
            rename(cursos[i].getPath(),newPath)
            cursos[i].setPath(newPath);
            updateCourses();

        }
    }
}*/
