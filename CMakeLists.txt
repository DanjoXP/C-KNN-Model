cmake_minimum_required(VERSION 4.2)
project(KNN)

set(CMAKE_CXX_STANDARD 23)

add_executable(KNN src/main.cpp
        headers/dataPoint.h
        src/dataPoint.cpp
        src/knn.cpp
        headers/knn.h)
