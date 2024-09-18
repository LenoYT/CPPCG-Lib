@echo off
set SRC_DIR=.
set BUILD_DIR=%SRC_DIR%\build
set INCLUDE_DIR=%SRC_DIR%

if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

set SRC_FILE=gameR.cpp
set OBJ_FILE=gameR.o
set LIB_FILE=libgameR.a
set MAIN_FILE=main.cpp
set EXE_FILE=program.exe

echo C: %SRC_FILE% :: %OBJ_FILE%
g++ -c %SRC_DIR%\%SRC_FILE% -o %BUILD_DIR%\%OBJ_FILE% -I%INCLUDE_DIR%

echo Mak %LIB_FILE% : %OBJ_FILE%
ar rcs %BUILD_DIR%\%LIB_FILE% %BUILD_DIR%\%OBJ_FILE%

echo C: %MAIN_FILE% :: %EXE_FILE%
g++ %SRC_DIR%\%MAIN_FILE% -o %BUILD_DIR%\%EXE_FILE% -L%BUILD_DIR% -lgameR -I%INCLUDE_DIR%

echo R: %EXE_FILE% in new cmd proccess
cd /d "%BUILD_DIR%"
start cmd /k "%EXE_FILE%"

REM End
pause
echo Ended
