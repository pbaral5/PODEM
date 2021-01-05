#include "input.h"
/***************************************************************************************************
Command Instructions
***************************************************************************************************/
//To Compile: make
//To Run: ./project c17.isc 
/***************************************************************************************************
 Main Function
***************************************************************************************************/
int main(int argc,char **argv)
{
    
P();

FILE *Isc,*Pat,*Res;                  //File pointers used for .isc, .pattern, and .res files
int Npi,Npo,Tgat,Tot;                     //Tot no of PIs,Pos,Maxid,Tot no of patterns in.vec,.fau
GATE *Node,*graph;                           //Structure to store the ckt given in .isc file 
PATTERN vector[Mpt];                       
clock_t Start,End;                    //Clock variables to calculate the Cputime
double Cpu;                           //Total cpu time
int i,j;                              //Temporary variables
int gat,value,initialgate,initialvalue,type;


/****************PART 1.-Read the .isc file and store the information in Node structure***********/
Npi=Npo=Tgat=0;                                //Intialize values of all variables
gat=19;
type=1;
value=0;
initialgate=gat;
initialvalue=value;
Isc=fopen(argv[1],"r");                        //File pointer to open .isc file 
Node=(GATE *) malloc(Mnod * sizeof(GATE));     //Dynamic memory allocation for Node structure
Tgat=ReadIsc(Isc,Node);                        //Read .isc file and return index of last node
fclose(Isc);       
            //Close file pointer for .isc file
PrintGats(Node,Tgat);                          //Print the information of each active gate in Node structure after reading .isc file
CountPri(Node,Tgat,&Npi,&Npo);                 //Count the No of Pis and Pos
printf("\n\nNpi: %d Npo: %d\n",Npi,Npo);       //Print the no of primary inputs and outputs
for(i=1;i<=Tgat;i++)
{
	//InitiGat(Node,i);
	Node[i].Val=2;
	printf("Node[%d] value is %d\n",i,Node[i].Val);
}
/***************************************************************************************************/
	/*Pat=fopen(argv[2],"r");                           //file pointer to open .vec file
	Tot=0; Tot=ReadVec(Pat,vector);                   //read .vec file and store in vector structure and return tot number of patterns
	
	printf("\nTot No of Pattern: %d",Tot);             //print total number of patterns in .vec file
	fclose(Pat);                                      //close file pointer for .vec file
	printf("\nIndex\tInputVector\n");
	for(int a=0;a<Tot;a++){  printf("%d\t%s",a,vector[a].piv); } //print all members of vector structure

	Res=fopen(argv[3],"w");   */                        //file pointer to open .out file for printing results

	//Perform Logic Simulationfor each Input vector and print the Pos .val in output file
Res=fopen(argv[2],"w");
//graph=(GATE *) malloc(Mnod * sizeof(GATE));
while(Node[initialgate].Val!=initialvalue){
	gat=initialgate;
	type=1;
	value=initialvalue;
	//graph=(GATE *) malloc(Mnod * sizeof(GATE));
	
printf("the initial gate is %d",gat);
	backtrace(Node,&gat,&value);
	printf("the gate is %d",gat);
Node[gat].Val=value;
/*..........................................................................*/
	//simulateCircuit(Node, Tgat, vector, Tot, Res );
	simulateCircuit(Node, Tgat, &gat,&value, Res );
//gat=initialgate;
printf("the  final gate%s has value  %d",Node[initialgate].Name,Node[initialgate].Val);
}
/*..........................................................................*/

	//fclose(Res);                                                  //close file pointer for .out file
/****************************************************************************************************************************/



/***************************************************************************************************/

ClearGat(Node,Tgat); 
 free(Node);                                      //Clear memeory for all members of Node
return 0;
}//end of main
/****************************************************************************************************************************/

