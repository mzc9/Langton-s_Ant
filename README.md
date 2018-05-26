## Langton's_Ant

The goal of this project is to simulate Langton's Ant (https://en.wikipedia.org/wiki/Langton%27s_ant), a cellular automaton that follows two simple rules with each step in a matrix of cells.  

The project was created during course work in C++ and designed to run in a Linux terminal.

### Description of Program: 
To implement a simulation of Langton's Ant, showing the
 movement of the ant with a change in color based on two rules:
 1) In a white square, ant turns right 90 degrees and changes the square from white to black
 2) In a black square, the ant turn left 90 degrees and changes the square from black to white
 
 #### Input: User-defined:
        (i) Grid size
        (ii) The simulation continues for a user-defined number of steps.
        (iii) Starting location of the ant
#### Output: 
    Along with instructions and prompts, Blank grid with borders on the right and left delineating 
    the boundaries.
    Grid cell if black shown with "#", while white is just blank space
   #### Ant is shown as "*"
   
Specifications of the project are given in the specs.txt file.

Design decisions are in the design document which includes the test plan and the test results.  Changes made to the program as a result of the test plan are also included in this document.

To run the program, ensure that all files from the code folder are downloaded in the same location. Run the make command in the terminal.
