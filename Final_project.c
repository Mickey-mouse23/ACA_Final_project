/*
 * This code defines various functions for processing instructions and performing ALU functionalities.
 * It includes functions for formatting the instruction, processing the instruction, and performing ALU operations.
 * The code also includes global variables for storing registers, memory, and status flags.
 * The functions in this code handle commands such as MOV, LOAD, STORE, AND, ADD, OR, ASR, ASL, and MUL.
 * The code is designed to process instructions in a specific format and perform the corresponding operations.
 * It also includes functions for performing actions on registers and memory based on the instruction.
 * The code is well-commented and organized for easy understanding and modification.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#define R 0
#define W 1

char * instruction=0;
char * instruction_1 =0;
int register_array[3];
// registers to store main ones.

char array[127];

int registers[10];
int memory_replicate[10]={1000,2000,3000,4000,5000,6000,7000,8000,9000,10000};
int load_store_flag=0;

int register_status[10]={R,R,R,R,R,R,R,R,R,R};
int memory_status[10]={R,R,R,R,R,R,R,R,R,R};


char* instruction_format(char *);
void process_instruction(char *);
void alu_functionality(int argc, char * argv[]);
void perform_register_action(int argc, char * argv[]);

/*
 *This function takes command as the input and it does remove the extra spaces
 *This shown in the form of various escape sequences and replicate them with spaces instead
 * And avoids multiple spaces in case if they exist and replace them with one.
 * To conclude formats the string/ command with new char with single spaces.
 *
 * Arguments : Pointer to string which stores command.
 *
 * Returns Pointer to char array which stores formatted string. */
char* instruction_format(char *str)
{
	// charecter pointer used for storing the pointer to the memory allocated for command storage.
	//char array[127];
	//char* array;
	//array= (char*)malloc(127*sizeof(char));
    char a=0; // stores prev char while iterating through the command.initialised as 0.
    int i=0; // used for indexing the command.
    char* str_d=str; // string pointer duplication
    // just iterating through the loop and converting the special escape sequences to space so as to avoid double spacing.
    while(*str_d != '\0')
    		{
    			if((*str_d == ' ' || *str_d == '\t' || *str_d == '\n' || *str_d == '\r' || *str_d == '\f' || *str_d == '\v'))
    			{
    				*str_d=' '; // replaces with space.
    			}
    			str_d++;
    		}
    // iterates throughout the command.
    while(*str!= '\0')
    {
    	// a stores the previous char in the command. If bothe are not equal then
    	// copies the content of string to the array specified for command.
    	if(a != *str)
    	{
    		*(array+i)=*str;
    		i++;
    		a=*str; // and current char is stored into a for next iteration.
		    str++; // moves further.
    	}
    	// In case char replicates/ repeats now and if it is not a space then copies into array.
    	// In case if it is space escapes that char and moves further.
    	if(a == *str)
    	{
    	    if(a!=' ')
    	    {
                *(array+i)=*str;
    		    i++;
    	    }
    	       a=*str; // and current char is stored into a for next iteration.
		       str++;// moves further.
    	}

    }
   *(array+i)=*str;  // copies \0 indicating end.
    return array;
}



/**
 * @brief Performs various ALU functionalities based on the given command.
 * 
 * @param argc The number of command line arguments.
 * @param argv An array of command line arguments.
 */

// alu functionalities and instructions
void alu_functionality(int argc, char * argv[])
{
                  
	if(!strcmp(*argv,"MOV"))
	{
        printf("\rIn MOV command \r\n");
		if(argc ==3 ) 
		{
			*(registers+register_array[0])= *(registers+register_array[1]);
			printf("\rIn MOV commands Execution stage \r\n");
			int a = register_array[0];
			register_status[a] = R;
		}
		else
		{
			printf("\rInvalid Mov command\r\n");
		}
	}
	else if(!strcmp(*argv,"LOAD"))
	{
        printf("\rIn LOAD command \r\n");
		if(argc ==4 && register_array[2]!=100) 
		{
			*(registers+register_array[0])= *(registers+register_array[1]) + *(register_array[2]+memory_replicate);
			printf("\rIn LOAD commands Execution Stage \r\n");
			register_status[register_array[0]] = R;
			memory_status[register_array[2]] = R;
		}
		else
		{
			printf("\rInvalid LOAD command\r\n");
		}
	}
    else if(!strcmp(*argv,"STORE"))
	{
        printf("\rIn STORE command \r\n");
		//if(argc ==4 && register_array[2]!=100) 
		if(argc ==3)
		{
			*(register_array[0]+memory_replicate)= *(registers+register_array[1]);
			printf("\rIn STORE commands Execution stage \r\n");
			memory_status[register_array[1]] = R;
		}
		else
		{
			printf("\rInvalid STORE command\r\n");
		}
	}
	else if(!strcmp(*argv,"AND"))
	{
        printf("\rIn AND command \r\n");
		if(argc ==4 && register_array[2]!=100 && register_array[1]!=100 && register_array[0]!=100) 
		{
			*(registers+register_array[0])= *(registers+register_array[1]) & *(registers+ register_array[2]);
			printf("\rIn AND commands Execution stage \r\n");
			int a = register_array[0];
			register_status[a] = R;
		}
		else
		{
			printf("\rInvalid and command\r\n");
		}
	}
	else if(!strcmp(*argv,"ADD"))
	{
        printf("\rIn ADD command \r\n");
		if(argc ==4 && register_array[2]!=100 && register_array[1]!=100 && register_array[0]!=100) 
		{
			*(registers+register_array[0])= *(registers+register_array[1]) + *(registers+ register_array[2]);
			 printf("\rIn ADD commands Execution Stage \r\n");
			int a = register_array[0];
			register_status[a] = R;
		}
		else
		{
			printf("\rInvalid add command\r\n");
		}
	}
	else if(!strcmp(*argv,"OR"))
	{
        printf("\rIn OR command \r\n");
		if(argc ==4 && register_array[2]!=100 && register_array[1]!=100 && register_array[0]!=100) 
		{
			*(registers+register_array[0])= *(registers+register_array[1]) | *(registers+ register_array[2]);
			printf("\rIn OR commands Execution Stage \r\n");
			int a = register_array[0];
			register_status[a] = R;
		}
		else
		{
			printf("\rInvalid add command\r\n");
		}
	}
	else if(!strcmp(*argv,"ASR"))
	{
        printf("\rIn Right Shift command \r\n");
		if(argc ==4 && register_array[2]!=100 && register_array[1]!=100 && register_array[0]!=100) 
		{
			*(registers+register_array[0])= *(registers+register_array[1]) >> *(registers+ register_array[2]);
			printf("\rIn Right Shift commands Execution stage \r\n");
			int a = register_array[0];
			register_status[a] = R;
		}
		else
		{
			printf("\rInvalid ASR command\r\n");
		}
	}
	else if(!strcmp(*argv,"ASL"))
	{
        printf("\rIn Left Shift command \r\n");
		if(argc ==4 && register_array[2]!=100 && register_array[1]!=100 && register_array[0]!=100) 
		{
			*(registers+register_array[0])= *(registers+register_array[1]) << *(registers+ register_array[2]);
			 printf("\rIn Left Shift commands Executio stage \r\n");
			int a = register_array[0];
			register_status[a] = R;
		}
		else
		{
			printf("\rInvalid ASL command\r\n");
		}
	}
	else if(!strcmp(*argv,"MUL"))
	{
        printf("\rIn MUL command \r\n");
		if(argc ==4 && register_array[2]!=100 && register_array[1]!=100 && register_array[0]!=100) 
		{
			*(registers+register_array[0])= *(registers+register_array[1]) * (*(registers+ register_array[2]));
			printf("\rIn MUL commands Execution stage \r\n");
			int a = register_array[0];
			register_status[a] = R;
		}
		else
		{
			printf("\rInvalid mul command\r\n");
		}
	}
	else
	{
		printf("\r\nUnknown Command ( %s )",*argv);
	}
	// for(int i=0;i<10;i++)
	// {
	// 	printf("\rValue in Register R%d is %d\r\n",i,array[i]);
	// } 
}

/**
 * @brief Performs the register action based on the command line arguments.
 *
 * This function takes the command line arguments and assigns values to the register_array based on the provided arguments.
 * If the argument matches any of the register names (r0-r9), the corresponding value is assigned to the register_array.
 * If the argument does not match any register name, the value 100 is assigned to the register_array.
 * If the number of arguments is 3, the value 200 is assigned to the third element of the register_array.
 *
 * @param argc The number of command line arguments.
 * @param argv An array of strings containing the command line arguments.
 */

void perform_register_action(int argc, char * argv[]) 
{
	for(int i=1; i<argc; i++)
	{
		if(strcmp(*(argv+i), "r0") == 0)
		{
			register_array[i-1]=0;
		}
		else if (strcmp(*(argv+i), "r1") == 0 | strcmp(*(argv+i), "1") == 0)
		{
			register_array[i-1]=1;
		}
		else if (strcmp(*(argv+i), "r2") == 0 | strcmp(*(argv+i), "2") == 0)
		{
			register_array[i-1]=2;
		}
		else if (strcmp(*(argv+i), "r3") == 0 | strcmp(*(argv+i), "3") == 0)
		{
			register_array[i-1]=3;
		}
		else if (strcmp(*(argv+i), "r4") == 0 | strcmp(*(argv+i), "4") == 0)
		{
			register_array[i-1]=4;
		}
		else if (strcmp(*(argv+i), "r5") == 0 | strcmp(*(argv+i), "5") == 0)
		{
			register_array[i-1]=5;
		}
		else if (strcmp(*(argv+i), "r6") == 0 | strcmp(*(argv+i), "6") == 0)
		{
			register_array[i-1]=6;
		}
		else if (strcmp(*(argv+i), "r7") == 0 | strcmp(*(argv+i), "7") == 0)
		{
			register_array[i-1]=7;
		}
		else if (strcmp(*(argv+i), "r8") == 0 | strcmp(*(argv+i), "8") == 0)
		{
			register_array[i-1]=8;
		}
		else if (strcmp(*(argv+i), "r9") == 0 | strcmp(*(argv+i), "9") == 0  )
		{
			register_array[i-1]=9;
		}
		else
		{
			register_array[i-1]=100;
		}
	}
	if(argc==3)
	{
		register_array[2]=200;
	}
}


/**
 * @brief Processes an instruction by parsing the input command and executing the corresponding actions.
 *
 * This function takes a string input as a command and performs the following steps:
 * 1. Allocates memory for the command string.
 * 2. Copies the input command to the allocated memory.
 * 3. Parses the command to extract individual arguments.
 * 4. Converts the first argument to uppercase.
 * 5. Calls functions to perform register actions and ALU functionality based on the parsed arguments.
 *
 * @param input The input command string.
 */

void process_instruction(char *input)
{
    //char* rest = (char*)malloc(strlen(input) + 1); // Allocate memory for the string
	int a = strlen(input)+1;
	char rest[a];
    strcpy(rest, input); // Copy the command to the allocated memory

	char *p = rest; //  p acts a pointer to the rest string with formatted string/command.
	char *end;
	// find end of string
	for (end = rest; *end != '\0'; end++)
		;
	// parameters to store the strings in the command and count of strings.
	char *argv[10];
	int argc = 0;
	// sets memory to 0 which are allocated for storing strings of command.
	memset(argv, 0, sizeof(argv));
	int i=1;
	// In case of formatted command contains space at first arg[0] is allocated with value
	// from 2nd position/ index in the command.If not argv[0] takes *p.
	if(*p== ' ')
	{
		argv[0]=(p+1);
	}else
	{
		argv[0]=p;
	}
	// Iterates through the command and finds the space in the command
	// and allocates pointer to the char after the space to the argv array.
	for (p = argv[0]; p < end; p++)
	{
		if(*p == ' ' && *(p+1)!='\0')
		{
			argv[i]=p+1;
			i++;
		}
	}
	// fills the spaces in the formatted string with \0 marking end for every substring in the command.
	for (p = rest; p < end; p++)
		{
			if((*p==' ')&& (p!=rest))
			{
				*p='\0';
			}
		}
	argc=i; // takes count of sub strings including command.
	argv[argc] = NULL;
	if (argc == 0) // no command
		return;
	char * string= argv[0];
	int j=0;
	while(*(string+j) != '\0')
	{
		*(string+j)= toupper(*(string+j));
		j++;
	}
	perform_register_action(argc,argv);
	//register_status_machine(argc,argv);
	alu_functionality(argc,argv);
	//free(rest); // frees dynamically allocated memory.
}



/**
 * @brief Processes the instruction order.
 * 
 * This function takes a command string as input and processes it to perform the corresponding action.
 * It parses the command string, separates the arguments, and converts the first argument to uppercase.
 * It then checks the first argument and sets the load_store_flag accordingly.
 * Finally, it calls the perform_register_action function to execute the command with the arguments.
 * 
 * @param input The command string to be processed.
 */

void process_instruction_order(char *input)
{
	    //char* rest = (char*)malloc(strlen(input) + 1); // Allocate memory for the string
	int a = strlen(input)+1;
	char rest[a];
    strcpy(rest, input); // Copy the command to the allocated memory

	char *p = rest; //  p acts a pointer to the rest string with formatted string/command.
	char *end;
	// find end of string
	for (end = rest; *end != '\0'; end++)
		;
	// parameters to store the strings in the command and count of strings.
	char *argv[10];
	int argc = 0;
	// sets memory to 0 which are allocated for storing strings of command.
	memset(argv, 0, sizeof(argv));
	int i=1;
	// In case of formatted command contains space at first arg[0] is allocated with value
	// from 2nd position/ index in the command.If not argv[0] takes *p.
	if(*p== ' ')
	{
		argv[0]=(p+1);
	}else
	{
		argv[0]=p;
	}
	// Iterates through the command and finds the space in the command
	// and allocates pointer to the char after the space to the argv array.
	for (p = argv[0]; p < end; p++)
	{
		if(*p == ' ' && *(p+1)!='\0')
		{
			argv[i]=p+1;
			i++;
		}
	}
	// fills the spaces in the formatted string with \0 marking end for every substring in the command.
	for (p = rest; p < end; p++)
		{
			if((*p==' ')&& (p!=rest))
			{
				*p='\0';
			}
		}
	argc=i; // takes count of sub strings including command.
	argv[argc] = NULL;
	if (argc == 0) // no command
		return;
	char * string= argv[0];
	int j=0;
	while(*(string+j) != '\0')
	{
		*(string+j)= toupper(*(string+j));
		j++;
	}
	if(strcmp(*argv, "LOAD") ==0)
	{
		load_store_flag=1;
	}
	if(strcmp(*argv, "STORE") ==0)
	{
		load_store_flag=2;
	}
	perform_register_action(argc,argv);
}

/**
 * Executes the out_of_order function.
 * 
 * This function takes an array of instructions and an array of register availability as parameters.
 * It processes the instructions in an out-of-order manner, updating the register availability accordingly.
 * 
 * @param instruction An array of instructions.
 * @param register_avail An array representing the availability of registers.
 */

void out_of_order(char instruction[10][16], int register_avail[10][10])
{
	// for(int i=0;i<10;i++)
	// {
    // 	printf("%s\n",instruction[i]);
	// }
	for(int i=0;i<10;i++)
	{
		instruction_1 = instruction_format(instruction[i]);
		process_instruction_order(instruction_1);
		if(i==0)
		{
			int a = register_array[0];
			register_avail[0][a]=2;
			if(load_store_flag ==2)
			{
				register_avail[0][a]=1000;
			}
			register_avail[0][register_array[1]]= 1000;
			if(register_array[2] != 200 && load_store_flag!=1)
			{
				register_avail[0][register_array[2]]= 1000;
			}
		}
		else
		{	
			for(int j=0;j<10;j++)
			{
				register_avail[i][j]=register_avail[i-1][j];
				if(register_avail[i][j] !=0)
				{
					register_avail[i][j]--;
				}
			}
			int a = register_array[0];
			register_avail[i][a]=2;
			if(load_store_flag ==2)
			{
				register_avail[i][a]=1000;
			}
			register_avail[i][register_array[1]]= 1000;
			if(register_array[2] != 200 && load_store_flag!=1)
			{
				register_avail[i][register_array[2]]= 1000;
			}
		}
		//printf("\r\n aneesh\r\n");
	}
}

/**
 * @brief Reorders the instructions based on certain conditions.
 * 
 * This function takes an array of instructions and an array of register availability as input.
 * It iterates through the instructions and checks if certain conditions are met for reordering.
 * If the conditions are met, it swaps the current instruction with the previous one.
 * Finally, it calls the "out_of_order" function to handle any remaining out-of-order instructions.
 * 
 * @param instruction The array of instructions.
 * @param register_avail The array of register availability.
 */

void instruction_order(char instruction[10][16], int register_avail[10][10])
{
	char instruction_dupe[16];
	int register_dupe[10];

	for(int k=2;k<10;k++)
	{
	for(int i=2;i<10;i++)
	{
		instruction_1 = instruction_format(instruction[i]);
		process_instruction_order(instruction_1);
		if(register_array[2]==200)
		{
			if((register_avail[i-1][register_array[0]]==0) && (register_avail[i-1][register_array[1]]==0)   ||
				(register_avail[i-1][register_array[0]]==0) && (register_avail[i-1][register_array[1]]>=900))
			{
				for(int j=0;j<16;j++)
				{
					instruction_dupe[j]=instruction[i][j];
					instruction[i][j]= instruction[i-1][j];
					instruction[i-1][j]=instruction_dupe[j];
				}
			} 
		}

		if(register_array[2]>=0  && register_array[2]<=9)
		{
			if(((register_avail[i-1][register_array[0]]==0) && (register_avail[i-1][register_array[1]]==0)  && (register_avail[i-1][register_array[2]]==0))
				||((register_avail[i-1][register_array[0]]==0) && (register_avail[i-1][register_array[1]]>=900)  && (register_avail[i-1][register_array[2]]>=900)) )
			{
				for(int j=0;j<16;j++)
				{
					instruction_dupe[j]=instruction[i][j];
					instruction[i][j]= instruction[i-1][j];
					instruction[i-1][j]=instruction_dupe[j];
				}
			} 
		}
		out_of_order(instruction,register_avail);
	}
	}


}

/**
 * @file main.c
 * @brief This file contains the main function for executing out-of-order instruction execution.
 *
 * The main function prompts the user to enter instructions, fetches the instructions, and performs out-of-order execution.
 * It also allows the user to enter register values and displays the values in the registers and memory after execution.
 *
 * @return 0 on successful execution.
 */
int main()
{
	char instruction[10][16];
	int register_avail[10][10];
	printf("\r Enter instructions\r\n");
	for(int i=0;i<10;i++)
	{
    scanf(" %[^\n]", instruction[i]);
    //printf("%s\n",instruction[i]);
	}
	printf("\r INSTRUCTION SEQUENCE BEFORE REORDERING \r\n");
	for(int i=0;i<10;i++)
	{
   // printf(" %[^\n]", instruction[i]);
    printf("%s\n",instruction[i]);
	}
	printf("\r Fetching of Instructions is done\r\n");
	printf("\r OUT OF ORDER EXECUTION IMPLEMENTATION STARTS\r\n");
	for(int i=0 ; i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			register_avail[i][j]=0;
		}
	}
	out_of_order(instruction,register_avail);
	instruction_order(instruction,register_avail);
	printf("\r\nOUT OF ORDER EXECUTION DONE\r\n");
	for(int i=1;i<10;i++)
	{
		printf("\rEnter register %d value\r\n",i);
		scanf("%d",&registers[i]);
	} 
	for(int i=0;i<10;i++)
	{
		printf("\rValue in Register R%d is %d\r\n",i,registers[i]);
	} 
	for(int i=0;i<10;i++)
	{
    	printf("\r%s\r\n",instruction[i]);
		// after this function execution my instruction contains only spaces that to not more than 1 space
		// at a stretch.
    	instruction_1 = instruction_format(instruction[i]);
    	process_instruction(instruction_1);
	}
	for(int i=0;i<10;i++)
	{
		printf("\rValue in Register R%d is %d\r\n",i,registers[i]);
	} 
	for(int i=0;i<10;i++)
	{
		printf("\rmemory[%d] is %d\r\n",i,memory_replicate[i]);
	}
	

    //instruction_disassemble(instruction);
	//printf("\r\n aneesh      %d   \r\n",register_status[1]);
    return 0;
}

