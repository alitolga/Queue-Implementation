SOME EXPLANATIONS
1)	In the patients file, after the patient’s name, the first integer is the arrival time and the second integer is the treatment time. The third variable is the patient’s code.
2)	The patients are given a minimum treatment time based on their codes. (RED: 1, YELLOW: 2, GREEN: 3)


This readme is for using this program.

For Linux:

- Simply open your command line in Linux.
- Go to the folder containing the program with the cd command.
- Write g++ *.cpp to compile all cpp files. (The output will be a.out by default, you can change it with the -o parameter.)
- Write ./a.out to run the program.

For Windows - Visual Studio IDE:

- Simply open a New Empty C++ Project.
- Add the .cpp files to the source files and the .h files to the header files.
- Build and run the program.

BE CAREFUL about leaving an enter, space or any other character
at the end of the "patientsInfo.txt" file. The program can misjudge
that character at the end of the file for a patient and enter an infinite loop.