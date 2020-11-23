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
            system("cls");
            pantalla1();
        }else if(option=="2"){
            system("cls");
            pantallaVer();
        }else{
            system("cls");
            std::cout<<"Ingrese una opción válida"<<std::endl;
            pantallaInit();
            
        }
    }
    exit(-1);
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
        system("cls");
        pantalla1();
    
    }
}


void Interfaz::pantallaVer(){
    
    std::string userAux,contraseniaAux,opcion;
    std::cout<<"Si desea regresar al inicio ingrese el numero 0 en Usuario"<<std::endl;
    
    std::cout<<"Usuario:    ";
    std::cin>>userAux;
    
    std::cout<<"Contrasenia:    ";
    std::cin>>contraseniaAux;
    
    if(userAux=="0"){
    
        pantalla1();
    
    }
    
    this->userActual=um.validateCredentials(userAux,contraseniaAux);


    if (userActual==nullptr){
    
        system("cls");
        std::cout<<"Credenciales invalidas"<<std::endl;
        pantallaVer();
    
    }else{
    
        pantalla2(userActual);
    }

}

void Interfaz::pantalla1_1(){
    
    std::cout<<"1.Mostrar Usuarios\n2.Editar Usuarios\n3.Regresar"<<std::endl;
    std::string option;
    std::cin>>option;
    Students* estudiantes=sm->getAllStudents();
    Faculty* profesores=fm->getAllFaculty();
    
    if(option=="1"){

        for(int i=0;i<(sizeof(estudiantes)/sizeof(estudiantes[0]));i++){
            sm.showStudent(estudiantes[i].getBannerID());
        }
        for(int i=0;i<(sizeof(profesores)/sizeof(profesores[0]);i++){
            fm.showFaculty(profesores[i].getBannerID());   
        }
        
        std::cout<<"Para regresar presione enter"<<std::endl,
        system("PAUSE");
        pantalla1_1();
    

    } else if(option=="2"){
        
        std::string banner;
        std::cout<<"Banner Id del usuario que quiere editar"<<std::endl;
        std::cin>>banner
        User* userActual;

        int aux=0
        
        while(aux=0){
        
            for(int i=0;i<(sizeof(estudiantes)/sizeof(estudiantes[0]));i++){
                if(bannerID)
            }
            for(int i=0;i<(sizeof(profesores)/sizeof(profesores[0]);i++){
                fm.showFaculty(profesores[i].getBannerID());   
            }
         
        }

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
    std::cout<<"1.Crear Profesor\n2.Editar Profesor\n3.Mostrar Profesores\n4.Borrar Profesor\n5.Regresar"<<std::endl;
    std::string option;
    std::cin>>option;
    if(option=="1"){
        
    }else if(option=="2"){
       
    }else if(option=="3"  {
       
    }else if(option=="4"){
        
    }else if(option=="5"){
        system("cls");
        pantalla1();

    }else{
        system("cls");
        pantalla1_3();
    }
}

void Interfaz::pantalla2(User* usuario_){

    std::cout<<"1.Mostrar Datos\n2.Editar Datos\n3.Regresar"<<std::endl;
    std::string option;
    std::cin>>option;
    
    if(option=="1"){
    
        system("cls");
        pantalla2_1(usuario_);
    
    }else if(option=="2"){
    
        system("cls");
        pantalla2_2(usuario_);
    
    }else if(option=="3"){
    
        system("cls");
        pantallaVer();
    
    }else{
    
        system("cls");
        std::cout<<"Ingresar una opción correcta"<<std::endl;
        pantalla2(usuario_);
    
    }
    
}


void Interfaz::pantalla2_1(User* usuario_){

    um.showUser(usuario_);

    std::cout<<"Para regresar presione enter"<<std::endl;
    system("PAUSE");

    pantalla2(usuario_);
}

void Interfaz::pantalla2_2(User* usuario_){

    um.editUser(usuario_);

    std::cout<<"Para regresar presione enter"<<std::endl;
    system("PAUSE");

    pantalla2(usuario_);

}