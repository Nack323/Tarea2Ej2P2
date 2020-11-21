//
//  main.cpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#include <iostream>
#include "User.hpp"
#include "Student.hpp"
#include "GraduateStudent.hpp"
#include "UnderGraduateStudent.hpp"
#include "Grade.hpp"
#include "Faculty.hpp"
#include "Course.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    User usuario_01("0022", "Daniel", "Riofrio", "1234", "driofrioa");
    Student estudiante_01("0011", "D'hamar", "Agudelo", "1234", "dagudelo", "Matematica");
    GraduateStudent estudiante_02("0033", "Daniel_2", "Riofrio_2", "1234", "driofrioa2", "cmp2", "doctorado");
    Proxy representante("Carlos", "Riofrio", "criofrio", "1234567890");
    UnderGraduateStudent estudiante_03("0044", "Daniel_4", "Riofrio_4", "1234", "driofrioa4", "cmp4", representante);
    Grade nota(100);
    Faculty profesor("0099", "Daniel_9", "Riofrio_9", "1234", "driofrioa9", "cmp9");
    //Course curso("0012330231", &profesor, &estudiante_03, &nota, 1, 3);
    //curso.setNotas(&estudiante_03, &nota, 1);
    /*estudiante_03.setClases(&curso, 1);
    estudiante_03.calculateGPA();
    cout << "GPA: " << estudiante_03.getGPA() << endl;
    */
    return 0;
}
