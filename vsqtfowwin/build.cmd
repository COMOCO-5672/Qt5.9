@echo off
title qmake and nmake build prompt
set VCINSTALLDIR=D:\Program Files (x86)\Microsoft Visual Studio 14.0\VC
set QTDIR=D:\Qt\Qt5.12.10\5.12.10\msvc2015_64
set PATH=%VCINSTALLDIR%\bin;%QTDIR%\bin;%PATH%
call "%VCINSTALLDIR%\vcvarsall.bat" amd64
qmake vsqt.pro -spec win32-msvc "CONFIG+=debug" "CONFIG+=qml_debug"
nmake
cd debug
windeployqt vsqt.exe