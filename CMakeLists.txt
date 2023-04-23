cmake_minimum_required(VERSION 3.25)
project(Registeration_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Registeration_System main.cpp Helper.h Login.h Student.cpp Student.h StudentController.h Doctor.cpp Doctor.h Course.cpp Course.h Person.cpp Person.h Regiser.h Assignment.cpp Assignment.h AssignmentSolution.cpp AssignmentSolution.h )
