@echo off
echo Sayi Tahmin Oyunu derleniyor...

REM GCC ile derleme (MinGW kurulu ise)
if exist "C:\MinGW\bin\gcc.exe" (
    echo GCC ile derleme yapiliyor...
    gcc sayi_tahmin_oyunu.c -o sayi_tahmin_oyunu.exe
    if %errorlevel% == 0 (
        echo Derleme basarili!
        echo Oyun baslatiliyor...
        sayi_tahmin_oyunu.exe
    ) else (
        echo Derleme hatasi!
    )
) else if exist "C:\Program Files\Microsoft Visual Studio\*" (
    echo Visual Studio derleyicisi araniyor...
    REM Visual Studio derleyicisi varsa
    cl sayi_tahmin_oyunu.c
    if %errorlevel% == 0 (
        echo Derleme basarili!
        echo Oyun baslatiliyor...
        sayi_tahmin_oyunu.exe
    ) else (
        echo Derleme hatasi!
    )
) else (
    echo Hata: C derleyicisi bulunamadi!
    echo Lutfen MinGW veya Visual Studio yukleyin.
    echo.
    echo MinGW indirmek icin: https://www.mingw-w64.org/
    echo Visual Studio indirmek icin: https://visualstudio.microsoft.com/
)

pause
