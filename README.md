# ACA Final project
This is the Final Project for the course of ECEN 5593 Advanced Computer Architecture in University of Colorado Boulder

## Project Description
This repository contains a C program that simulates out-of-order instruction execution. The program processes a sequence of instructions, performs out-of-order execution, and displays the values in registers and memory after execution.

## File
[Final_project.c](./Final_project.c): Main program that prompts the user to enter instructions, performs out-of-order execution, and displays register and memory values.

## How to Use
- Compile the program using a C compiler (e.g., gcc -o out_of_order Final_project.c).
- Run the compiled executable (./out_of_order).
- Enter a sequence of instructions when prompted.
- Enter register values as required.
- View the output, which includes the initial and final values in registers and memory.

## Instructions
The supported instructions follow a specific format. Each instruction is entered as a command with optional arguments. The program processes commands such as MOV, LOAD, STORE, AND, ADD, OR, ASR, ASL, and MUL. The instructions are case-insensitive.

## Example
![WhatsApp Image 2023-12-11 at 19 47 13_e3d2a6b2](https://github.com/Mickey-mouse23/ACA_Final_project/assets/70874185/4ba96175-fbd8-491e-b738-0b3b831f84b5)

![WhatsApp Image 2023-12-11 at 19 47 30_8100078d](https://github.com/Mickey-mouse23/ACA_Final_project/assets/70874185/0cbe349f-0ab1-4c76-8c5d-cee61d61b19d)

![WhatsApp Image 2023-12-11 at 19 47 51_1c779949](https://github.com/Mickey-mouse23/ACA_Final_project/assets/70874185/ebb1999d-1fbf-4e44-b676-02331d012951)

![WhatsApp Image 2023-12-11 at 19 48 04_6a1f4ed6](https://github.com/Mickey-mouse23/ACA_Final_project/assets/70874185/1f562ca0-5758-444a-93cc-046c9b9312ed)

## Notes
- The program ensures proper formatting of input instructions by removing extra spaces.
- Register and memory values are displayed before and after execution.
- Unknown commands are handled and reported.

Feel free to explore and modify the code for different scenarios and instructions.

## Contributors
- Leburu Aniketh Reddy
- Aneesh Gurram
