cmake_minimum_required(VERSION 3.29)
project(ProCleanOrganizer C)

set(CMAKE_C_STANDARD 23)

add_executable(ProCleanOrganizer main.c
        Source/Dashboard.h
        "Source/MASTER PETUGAS.h"
        "Source/Dashboard Petugas.h")
