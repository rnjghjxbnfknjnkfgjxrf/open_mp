@echo off
IF NOT exist ".\venv\" (
  echo Creating Python virtual environment...
  python -m venv venv
  .\venv\Scripts\activate.bat
  echo Installing dependencies...
  pip install -r requirements.txt
)
IF NOT exist ".\open_mp.exe" (
  echo Building executable...
  g++ .\open_mp.cpp -fopenmp -o open_mp.exe
)
echo Running
.\open_mp.exe