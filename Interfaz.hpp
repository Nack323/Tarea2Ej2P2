//
//  Interfaz.hpp
//  Interfaz
//
//  Created by Domenica Alvarado on 11/2/20.
//

#ifndef Interfaz_hpp
#define Interfaz_hpp

#include <stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include "StudentManager.hpp"
#include "FacultyManager.hpp"
#include "CourseManager.hpp"

class Interfaz{
    StudentManager sm;
    FacultyManager fm;
    CourseManager cm;
    UserManager um;
    User* userActual;
public:
    Interfaz();
    void pantallaInit();
    void pantalla1();
    void pantalla2(User*);
    void pantallaVer();
    void pantalla1_1();
    void pantalla1_2();
    void pantalla1_3();
    void pantalla1_4();
    void pantalla2_1(User*);
    void pantalla2_2(User*);
};
#endif
