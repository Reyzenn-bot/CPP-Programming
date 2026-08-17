cmake_minimum_required(VERSION 4.1)
project(C++_Programming)

set(CMAKE_CXX_STANDARD 17)

# --- ១. Class_and_Object ---
add_executable(class_object Class_and_Object/class_object.cpp)
add_executable(friend_class Class_and_Object/friend_class.cpp)
add_executable(friend_function Class_and_Object/friend_function.cpp)
add_executable(friend_method Class_and_Object/friend_method.cpp)
add_executable(members Class_and_Object/members.cpp)
add_executable(nested_class Class_and_Object/nested_class.cpp)
add_executable(person Class_and_Object/person.cpp)

# --- ២. Inheritance ---
add_executable(inheritance1 Inheritance/Inheritance1.cpp)
add_executable(inheritance_single "Inheritance/inheritanceType1(single).cpp")
add_executable(inheritance_multiple "Inheritance/inheritanceType2(multiple).cpp")
add_executable(inheritance_multilevel "Inheritance/inheritanceType3(multilevel).cpp")
add_executable(inheritance_hierarchical "Inheritance/inheritanceType4(hierarchical).cpp")
add_executable(inheritance_hybrid "Inheritance/inheritanceType5(hybrid).cpp")

# --- ៣. Polymorphism ---
add_executable(virtual_function Polymorphism/virtual_function.cpp)