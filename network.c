#include "stdio.h"
#include "stdlib.h"

/*
Kevin Jiang
CMDA 3634 - HW #1
Last updated: 09.15.2017
 */
/**
Initialize struct
 */
typedef struct {

  // Start your Q4.1 code
  int total;
  int maxNodes;
  int* connections;
  int* source;
  int* destination;
  int* page_rank;
  // End your Q4.1 code

}Network;

/**
Network Reader
 */
Network networkReader(char* filename){
  
  // Start your Q4.2 code
  int size, total, maxNodes;
  Network *n = malloc(sizeof(Network));
  
  (*n).connections = malloc(total*sizeof(int));
  (*n).source = malloc(total*sizeof(int));
  (*n).destination = malloc(total*sizeof(int));            
  
  FILE* pt_file = fopen(filename, "r");
  fscanf(pt_file, "%d, %d", &total, &maxNodes);
  (*n).total = total;
  (*n).maxNodes = maxNodes;
  
  // printf("The total and max nodes:\n %d, %d\n", (*n).total, (*n).maxNodes); // TEST total & maxNodes

  // int c[(*n).total];
 
  int source_temp, destination_temp;
  int i = 0;
 
  while(fscanf(pt_file, "%*c %d,%*c %d", &source_temp, &destination_temp) != EOF) {
    // printf(" temp_source %d  temp_dest %d\n", source_temp, destination_temp); // TEST temps
    
    (*n).source[i] = source_temp;
    (*n).destination[i] = destination_temp;
    
    // printf(" real_source: %d  real_dest: %d\n", (*n).source[i], (*n).destination[i]); // TEST reals

    // store count of nodes into "connection    
    (*n).connections[(*n).source[i]]++;
    
    // printf("connections[%d]: %d\n\n ", (*n).source[i], (*n).connections[(*n).source[i]]);  // TEST connections array
    
    i++;
  }
  
  fclose(pt_file);

  return *n;
  // End your Q4.2 code

}

/**
Main Method
 */
int main(int argc, char** argv){

  // Reads the input filename of the data file
  char* filename = argv[1];

  // Reads the input of the node number, stores in i
  int i = atoi(argv[2]);

  // Start your Q4.3 code
  Network n = networkReader("numbers.csv");

  int expectedConnections = n.connections[i];
  
  printf("Node %d is connected to %d nodes.\n", i, expectedConnections); 
  printf("Those nodes are:\n ");  // ADD NODE VALUES HERE (but not really)

  int j;
  int connectionsFound = 0;
  for(j = 0; j < n.total*n.maxNodes; j++) {
    if(n.source[j] == i) {
      printf(" %d\n ", n.destination[j]);
	  connectionsFound++;
	  if(connectionsFound >= expectedConnections)
		break;
    } else if(expectedConnections == 0) {
      printf("No such nodes exist.\n");
      break;
    }
  }
  // End your Q4.3 code
}
