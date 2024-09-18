@echo off
REM Ustawienie zmiennych
set SRC_DIR=.
set BUILD_DIR=%SRC_DIR%\build
set INCLUDE_DIR=%SRC_DIR%

REM Utwórz katalog build, jeśli nie istnieje
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

REM Nazwy plików
set SRC_FILE=gameR.cpp
set OBJ_FILE=gameR.o
set LIB_FILE=libgameR.a
set MAIN_FILE=main.cpp
set EXE_FILE=program.exe

REM Kompilacja pliku źródłowego do pliku obiektowego
echo Kompilowanie %SRC_FILE% do %OBJ_FILE%
g++ -c %SRC_DIR%\%SRC_FILE% -o %BUILD_DIR%\%OBJ_FILE% -I%INCLUDE_DIR%

REM Tworzenie biblioteki statycznej z pliku obiektowego
echo Tworzenie %LIB_FILE% z %OBJ_FILE%
ar rcs %BUILD_DIR%\%LIB_FILE% %BUILD_DIR%\%OBJ_FILE%

REM Kompilacja pliku main.cpp, linkowanie z biblioteką
echo Kompilowanie %MAIN_FILE% do %EXE_FILE%
g++ %SRC_DIR%\%MAIN_FILE% -o %BUILD_DIR%\%EXE_FILE% -L%BUILD_DIR% -lgameR -I%INCLUDE_DIR%

REM Uruchamianie programu
echo Uruchamianie %EXE_FILE%
cd /d "%BUILD_DIR%"
start cmd /k "%EXE_FILE%"

REM Kończenie
echo Proces zakończony
pause
