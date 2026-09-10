@echo off
cd /d "%~dp0"
if not exist "MyGame.exe" (
  echo MyGame.exe was not found. Download the built Windows artifact, extract it, then run this file.
  pause
  exit /b 1
)
start "Call Break" "%~dp0MyGame.exe"
