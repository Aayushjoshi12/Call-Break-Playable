@echo off
cd /d "%~dp0"
if not exist "MyGame.exe" (
  echo MyGame.exe was not found in this folder.
  echo.
  echo If you downloaded the repo/source code ZIP, that will NOT include the game EXE.
  echo Download the GitHub Actions artifact named Call-Break-Playable-Windows instead.
  echo Then extract that ZIP and run Play-Call-Break.bat from inside the extracted folder.
  echo.
  echo Build page:
  echo https://github.com/Aayushjoshi12/Call-Break-Playable/actions/runs/34600423301
  echo.
  pause
  exit /b 1
)
start "Call Break" "%~dp0MyGame.exe"
