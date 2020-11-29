//
//  main.cpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#include <iostream>
#include "StudentManager.hpp"
#include "Interfaz.hpp"
#include "FacultyManager.hpp"
#include "UserManager.hpp"
#include "CourseManager.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    StudentManager sm{"./data/estudiantes_pregrado.txt","./data/estudiantes_posgrado.txt"};
    FacultyManager fm{"./data/profesores.txt"};
    CourseManager cm{"",&sm,&fm};//sale error en courseManager
    UserManager um{&fm,&sm};
    Interfaz interfaz{&sm,&fm,&cm,&um};
    interfaz.pantallaInit();

    return 0;
}
