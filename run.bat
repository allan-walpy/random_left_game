if not exist .\out mkdir out
g++ .\src\app.cpp -o .\out\app.exe && cd .\out\ && app.exe || cd ..
