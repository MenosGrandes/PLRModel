if not exist "bin" mkdir bin
g++ src/main.cpp -o bin/PLRModel -std=c++11
"bin/PLRModel.exe" > src/graph/data.txt
cd src/graph
python draw.py