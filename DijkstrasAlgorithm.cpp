// Program Name: Lab 7
//
// Description:  
//  Turning a graph into an adjacency matrix
//  Then use the Lowest Cost Algorithm to find the cheapest path
//	To connect all other destinations
//
// Author: Jason Yoon
//
// Date: 8/10/2018
//
// IDE Used: Visual Microsoft
//

#include "List.h"
#include "AdjMatrixMethods.h"
#include <iostream>
#include <string>


using namespace std;

// Use of enum just to make life a little easier
// Really controls "positions" either in Dynamic Array or position 
// of Nodes in the Lists
enum Cities { BOS, DFW, JFK, LAX, MIA, ORD, SFO };
static const char * EnumCities[] = { "BOS", "DFW", "JFK", "LAX", 
	"MIA", "ORD", "SFO" };
const char* getTextfromEnum(int value) { return EnumCities[value]; }

const int AIRPORT_LOCATIONS = 7;


int main()
{

	List<int>* adjMatrix = new List<int>[AIRPORT_LOCATIONS];
	
	// Functions in AdjMatrixMethods.h
	setUpAdjMatrix(adjMatrix); // Set up the Matrix with data
	displayAdjMatrix(adjMatrix); 
	int totalCost = 0;

	cout << endl << "Cheapest path from starting point SFO:" << endl << endl;

	totalCost = do_my_homework(adjMatrix, SFO); // Function call handles calculations

	cout << endl << "Total Cost: " << totalCost;
	

	cin.get();
	return 0;
}

