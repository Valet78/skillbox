File handling is used to store data permanently in a computer. Using file handling we can store our data in secondary memory (Hard disk).
How to achieve the File Handling

For achieving file handling we need to follow the following steps:
 STEP 1-Naming a file
 STEP 2-Opening a file
 STEP 3-Writing data into the file
 STEP 4-Reading data from the file
 STEP 5-Closing a file.

Streams in C++ :
We give input to the executing program and the execution program gives back the output. The sequence of bytes given as input to the executing 
program and the sequence of bytes that comes as output from the executing program are called stream. In other words, streams are nothing but 
the flow of data in a sequence.

The input and output operation between the executing program and the devices like keyboard and monitor are known as “console I/O operation”. 
The input and output operation between the executing program and files are known as “disk I/O operation”.

Classes for File stream operations :
The I/O system of C++ contains a set of classes which define the file handling methods. These include ifstream, ofstream and fstream classes. 
These classes are derived from fstream and from the corresponding iostream class. These classes, designed to manage the disk files, are declared
in fstream and therefore we must include this file in any program that uses files. 