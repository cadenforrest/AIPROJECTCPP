## SETUP

Ensure that the folder AIPROJECTCPP has been downloaded onto your system. 

In a linux terminal, navigate to AIPROJECTCPP. 

```bash
cd/your_file_path_here/AIPROJECTCPP
```

List the files inside the directory.

```bash
ls
```

You should see the following files listed in your terminal: 

Conclusion-c_w424.cpp
Conclusion-c_w424.h
Variable-c_w424.cpp
Variable-c_w424.h
main-c_w424.cpp

## COMPILING

We will now compile the program.

First, check that a version of g++ is installed on your machine.

```bash
g++ --version
```

If g++ is installed, we are ready to compile our program. Inside of AIPROJECTCPP/, compile Conclusion.cpp into an object file.

```bash
g++ -c Conclusion-c_w424.cpp
```

Compile Variable.cpp into an object file.

```bash
g++ -c Variable-c_w424.cpp
```

Compile main.cpp into an object file.

```bash
g++ -c main-c_w424.cpp
```

List the files inside of the directory. 

```bash
ls
```

You should now see three additional files: 

Conclusion-c_w424.o
Variable-c_w424.o
main-c_w424.o

Finally, compile and link the programs into an executable.

```bash
g++ Conclusion-c_w424.o Variable-c_w424.o main-c_w424.o -o Project1-c_w424
```

## USAGE

You can now run the program.

```bash
./Project1-c_w424
```

The program will first print the variable list followed by the knowledge base. 

You will be prompted with our first diagnosis question, to which you will respond YES or NO: 

```bash
Is the patient female?: 
```

You will be asked questions about the patient's symptoms until a diagnosis is reached. At that point, the program will print the diagnosis, print treatment for their specific cancer, and print a list of suggested treatments to mitigate their symptoms.

Happy diagnosing!