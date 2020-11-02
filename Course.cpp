//
//  Course.cpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#include "Course.hpp"
#include <iostream>

Course::Course(){ }

Course::Course(std::string _nrc, Faculty* _profesor, Student* _estudiantes, Grade *_notas, int _totalEstudiantes, int _totalCreditos):
nrc(_nrc), profesor(_profesor), estudiantes(_estudiantes), totalCreditos(_totalCreditos), notas(_notas)
{
    std::cout << "Course constructor" << std::endl;
}

void Course::setProfesor(Faculty* _profesor){
    profesor = _profesor;
}

void Course::setNotas(Student* _estudiantes, Grade* _notas, int _totalEstudiantes){
    estudiantes = _estudiantes;
    notas = _notas;
    totalEstudiantes = _totalEstudiantes;
}

Faculty* Course::getProfesor(){
    return profesor;
}

Grade* Course::getGradeByStudent(Student * estudiante){
    for(int i=0; i<totalEstudiantes; i++){
        if(estudiantes[i].getBannerID() == estudiante->getBannerID()){
            return &notas[i];
        }
    }
    return nullptr;
}
