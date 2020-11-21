#include <iostream>
#include "CourseManager.hpp"

void CourseManager::loadCourses(){

    std::ifstream input;
    input.open(pathCursos);
    input>>numCursos;
    cursos=new Course[numCursos];

    for(int i=0;i<numCursos;i++){

        std::string nrcAux,creditosAux,profeAux,pathAux;

        //Cambiar esto 
        int x=3;
        Faculty* profesores=fm->getAllFaculty(x);
        Student* estudiantes=sm->getAllStudents(x);
        int numberEst;
        Faculty profesor;

        input>>nrcAux>>creditosAux>>profeAux>>pathAux;

        for(int j=0;j<(sizeof(profesores)/sizeof(profesores[0]));i++){
            if(profeAux==profesores[j].getBannerID()){
                profesor=profesores[j];
            }
        }

        std::string* BannerID;
        std::ifstream fileEst;
        Student* clase;
        Grade* notas;
        
        
        fileEst.open(pathAux);
        fileEst>>numberEst;

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
        }
        fileEst.close();

        cursos[i]=Course(nrcAux,&profesor,clase,notas,numberEst,stoi(creditosAux),pathAux);
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
    delete[] cursos;
    loadCourses(); 
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

                std::string newPath=nrcAux+"_"+cursos[i].getProfesor()->getBannerID();
                rename(cursos[i].getPath(),newPath);
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
                std::string newPath=cursos[i].getNRC()+"_"+ID;
                rename(cursos[i].getPath(),newPath);
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
