@echo off
REM Compile each source file
g++ -c main.cpp -o main.o
g++ -c player.cpp -o player.o
g++ -c item.cpp -o item.o
g++ -c case.cpp -o case.o

REM Link object files to create an executable
g++ main.o player.o item.o case.o -o case_simulator

REM Run the executable
case_simulator

pause

