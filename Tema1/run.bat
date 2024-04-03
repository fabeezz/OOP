@echo off
REM Compile each source file
g++ -c main.cpp -o obj/main.o
g++ -c src/player.cpp -o obj/player.o
g++ -c src/item.cpp -o obj/item.o
g++ -c src/case.cpp -o obj/case.o

REM Link object files to create an executable
g++ obj/main.o obj/player.o obj/item.o obj/case.o -o case_simulator

REM Run the executable
case_simulator

pause