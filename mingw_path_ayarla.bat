@echo off
echo MinGW PATH ayari yapiliyor...

REM Mevcut PATH'e MinGW ekleme
setx PATH "%PATH%;C:\mingw64\bin" /M

echo.
echo PATH ayari tamamlandi!
echo Yeni terminal acarak 'gcc --version' komutunu test edin.
echo.
pause
