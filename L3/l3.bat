@rem Script de compilare pentru Laboratorul 3
@echo off
g++ -c -o Vector2.o Vector2.cpp
g++ -c -o main.o main.cpp
g++ -o main main.o Vector2.o
main.exe
@echo on
pause