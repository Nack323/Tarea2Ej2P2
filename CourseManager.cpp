#include <iostream>
#include "CourseManager.hpp"


void CourseManager::loadCourses(){

    std::ifstream input;
    input.open(this->pathCursos);
    input>>numCursos;
    ArrayList<Course*> cursosAux=cursos;
    

    for(int i=0;i<this->numCursos;i++){

        std::string nrcAux,creditosAux,profeAux,pathAux;
        Faculty* profesor;

        input>>nrcAux>>creditosAux>>profeAux>>pathAux;

        Course* cursoAux;
        std::cout << "Check 1" << std::endl;
        cursoAux= new Course();
        std::cout << "Check 2" << std::endl;
        cursoAux->setNRC(nrcAux);
        cursoAux->setCreditos(std::stoi(creditosAux));
        cursos.add(cursoAux);
        cursos[i]->setPath(pathAux);

        profesor=fm->getFacultyByID(profeAux);
        cursos[i]->setProfesor(profesor);

        std::ifstream fileEst;    
        int numberEst;

        std::string pathEstudiantes="./data/"+cursos[i]->getPath();

        fileEst.open(pathEstudiantes);
        fileEst>>numberEst;

        for(int j=0;j<numberEst;j++){

            std::string BannerIDAux;
            std::string notaAux;
            
            Grade nota;

            fileEst>>BannerIDAux>>notaAux;

            nota=Grade(std::stof(notaAux));

            cursos[i]->addStudentGrade(sm->getStudentByID(BannerIDAux),nota);

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
        file<<cursos[i]->getNRC()<<" "<<cursos[i]->getCreditos()<<" "<<cursos[i]->getProfesor()->getBannerID()<<" "<<cursos[i]->getPath()<<std::endl;
    }

    file.close();
    delete[] &cursos;
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


    
    Course cursoAux{NRCAux,std::stoi(creditosAux)};
    cursoAux.setProfesor(fm->getFacultyByID(ProfesorAux));
    cursos.add(&cursoAux);
    updateCourses();
} 

void CourseManager::editCourse(){

    std::string option,NRCAux;
    std::cout<<"NRC del curso a editar"<<std::endl;
    std::cin>>NRCAux;

    for(int i=0;i<numCursos;i++){

        if(cursos[i]->getNRC()==NRCAux){

            std::cout<<"Que desea cambiar de su Curso\n1.NRC\n2.Profesor\n3.Numero de Creditos"<<std::endl;
            std::cin>>option;

            if(option=="1"){

                std::string nrcAux;
                std::cout<< "Nuevo NRC:    ";
                std::cin>>nrcAux;

                std::string newPath=nrcAux+"_"+cursos[i]->getProfesor()->getBannerID()+".txt";
                rename(cursos[i]->getPath().c_str(),newPath.c_str());//bien :)
                cursos[i]->setPath(newPath);
                cursos[i]->setNRC(nrcAux);

                updateCourses();
                std::cout<<"Su Curso ha sido actualizado"<<std::endl;

            }else if(option=="2"){

                std::string ID;
                std::cout<<"BannerID del nuevo profesor:    ";
                std::cin>>ID;
                
                Faculty* nuevoProfesor=fm->getFacultyByID(ID);
                std::string newPath=cursos[i]->getNRC()+"_"+ID+".txt";
                rename(cursos[i]->getPath().c_str(),newPath.c_str());
                cursos[i]->setPath(newPath);
                cursos[i]->setProfesor(nuevoProfesor);
                nuevoProfesor->addClass(cursos[i]);
                
                updateCourses(); 
                std::cout<<"Su Curso ha sido actualizado"<<std::endl;

            }else if(option=="3"){

                int creditosAux;
                std::cout<<"Creditos nuevos:     ";
                std::cin>>creditosAux;
                
                cursos[i]->setCreditos(creditosAux);
                
                updateCourses();
                std::cout<<"Su Curso ha sido actualizado"<<std::endl;
    

            }else{
 
                std::cout<<"No se ingreso una opcion valida"<<std::endl,
                editCourse();

            }    

            showClassByID(cursos[i]->getNRC());     
        }
    }
}    ;

void CourseManager::showCourses(){

    std::cout<<"Cursos disponibles"<<std::endl;
    
    for(int i=0;i<numCursos;i++){

        std::cout << cursos[i]->to_string() << std::endl;;
    
    }


};


void CourseManager::showClassByID(std::string nrc){

    for(int i=0;i<numCursos;i++){

        if(cursos[i]->getNRC()==nrc){

            std::cout<<"NRC"<<std::setw(10)<<"Creditos"<<std::setw(10)<<"Profesor"<<std::endl;
            cursos[i]->to_string();
            std::cout<<"Estudiantes"<<std::endl;
            std::deque<Student*> stu=cursos[i]->getAllStudents();


            for(int j=0;j<stu.size();j++){
                stu[j]->to_string();
            }

            break;  

        }  

        std::cout<<"No se encontro clase con ese NRC"<<std::endl;     

    }

}

void CourseManager::deleteCourse(std::string nrc){

    for(int i=0;i<cursos.getSize();i++){

        if(cursos[i]->getNRC()==nrc){

            numCursos--;
            cursos.deleteAt(i);

        }

    }

    updateCourses();
};

Course* CourseManager::getCourseByNRC(std::string nrc_){

    for(int i = 0; i<numCursos;i++){

        if(cursos[i]->getNRC()==nrc_){

            return cursos[i];

        }
    
    }
    Course* Cour=nullptr;
    return Cour;

}

