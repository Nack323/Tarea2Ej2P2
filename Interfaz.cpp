//
//  Interfaz.cpp
//  Interfaz
//
//  Created by Domenica Alvarado on 11/2/20.
//

#include "Interfaz.hpp"
#include "UserManager.hpp"

void Interfaz::pantallaInit(){
    std::string option;
    std::cout<<"Bienvenido al sistema de registro\nIngrese la opción que desea"<<std::endl;
    std::cout<<"1.Administrar Sistema\n2.Acceder Usuario\n3.Salir"<<std::endl;
    while(option!="3"){
        std::cin>>option;
        if(option=="1"){
            pantalla1();
        }else if(option=="2"){
            pantallaVer();
        }else{
            std::cout<<"Ingrese una opción válida"<<std::endl;
            pantallaInit();
            
        }
    }
}

void Interfaz::pantalla1(){
    std::cout<<"1.Administrar Sistema\n"<<std::endl;
    std::cout<<"1.Administrar Todos los Usuarios\n2.Administrar Todos los Estudiantes\n3.Administrar Todos los Profesores\n4.Administrar Todos los Cursos"<<std::endl;
    std::string option;
    std::cin>>option;
    if(option=="1"){
        pantalla1_1();
    }else if(option=="2"){
       
        pantalla1_2();
    }else if(option=="3"){
   
        pantalla1_3();
    }else if (option=="4"){
        pantalla1_4();
    }else{
   
        std::cout<<"Ingrese una de las opciones"<<std::endl;
        pantalla1();
    }
}


void Interfaz::pantallaVer(){
    FacultyManager facuAux;
    StudentManager studAux;
    UserManager userAux(facuAux.getAllFaculty(),studAux.getAllStudents());
    ;

    userAux.validateCredentials(); 
}
void Interfaz::pantalla1_1(){
    std::cout<<"1.Mostrar Usuarios\n2.Editar Usuarios\n3.Regresar"<<std::endl;
    std::string option;
    std::cin>>option;
    if(option=="1"){
        
    }else if(option=="2"){
        
    }else if(option=="3"){
        system("cls");
        pantalla1();
    }else{
        std::cout<<"Ingrese una de las opciones"<<std::endl;
        pantalla1_1();
        
    }
}

void Interfaz::pantalla1_2(){
    std::cout<<"1.Crear Estudiante\n2.Editar Estudiante\n3.Mostrar Estudiante\n4.Borrar Estudiante\n5.Regresar"<<std::endl;
    std::string option;
    std::cin>>option;
    if(option=="1"){
        
    }else if(option=="2"){
        
    }else if(option=="3"){
       
    }else if(option=="4"){
        
    }else if(option=="5"){
        system("cls");
        pantalla1();
        
    }else{
        system("cls");
        pantalla1_2();
    }
}

void Interfaz::pantalla1_3(){
    std::cout<<"1.Crear Profesor\n2.Editar Profesor\n3.Mostrar Profesores\n4.Borrar Profesor\n5.Regresar"<<std::endl;
    std::string option;
    std::cin>>option;
    if(option=="1"){
        
    }else if(option=="2"){
       
    }else if(option=="3"){
       
    }else if(option=="4"){
        
    }else if(option=="5"){
        system("cls");
        pantalla1();

    }else{
        system("cls");
        pantalla1_3();
    }
}

void Interfaz::pantalla1_4(){
    std::cout<<"1.Crear Curso\n2.Editar Curso\n3.Mostrar Curso\n4.Borrar Curso\n5.Asociar Profesor a Curso\n6.Asociar Estudiante a Curso\n7.Mostrar Lista de Curso\n8.Regresar"<<std::endl;
    std::string option;
    std::cin>>option;
    if(option=="1"){
        
    }else if(option=="2"){
        
    }else if(option=="3"){
       
    }else if(option=="4"){
        
    }else if(option=="5"){
        
    }else if(option=="6"){
        
    }else if(option=="7"){
        
    }else if(option=="8"){
        system("cls");
        pantalla1();
    }else{
        std::cout<<"Ingresar una de las opciones"<<std::endl;
        pantalla1_4();
    }
}

void Interfaz::pantalla2(){
    std::cout<<"1.Mostrar Datos\n2.Editar Datos\n3.Regresar"<<std::endl;
    std::string option;
    std::cin>>option;
    if(option=="1"){
        
    }else if(option=="2"){
        
    }else if(option=="3"){
        system("cls");
        pantallaVer();
    }else{
        system("cls");
        std::cout<<"Ingresar una opción correcta"<<std::endl;
        pantalla2();
    }
    
}
