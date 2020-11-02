//
//  Course.hpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#ifndef Course_hpp
#define Course_hpp

//=================================
// forward declared dependencies
class Student;
class Faculty;

#include <stdio.h>
#include <string>
#include "Student.hpp"
#include "Faculty.hpp"
#include "Grade.hpp"

class Course{
private:
    std::string nrc;
    Faculty *profesor;
    Student *estudiantes;
    Grade *notas;
    int totalEstudiantes;
    int totalCreditos;
public:
    Course();
    Course(std::string, Faculty*, Student*, Grade*, int, int);
    void setProfesor(Faculty*);
    void setNotas(Student*, Grade*, int);
    Faculty* getProfesor();
    Grade *getGradeByStudent(Student*);
};

#endif /* Course_hpp */
