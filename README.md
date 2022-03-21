# Matrix
is a static library, used to simplify the matrix's operations in linear algebra.
 
 
 ------------- 
 # HOW TO USE
  To use the library you should download only the /Matrix folder ( it contains the "matrix.h" header and the .a library file).
 
  In the code include the library using : 
  #include "Matrix/matrix.h"
 
 comand line to simply compile your program using GCC compiler : 
 g++ YOURFILENAME.cpp -LMatrix -lMatrix -o EXECUTABLE_NAME

 -------------
 To modify the Makefile: 
   - replace 'del' with 'rm' if you are using linux.
   - please use your own makefile for projects.
 
