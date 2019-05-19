#ifndef LAB7_ADJMATRIX
#define LAB7_ADJMATRIX
#include <iostream>


template <class T>
void setUpAdjMatrix(List<T> matrix[]);

template <class T>
void displayAdjMatrix(List<T> matrix[]);

template <class T>
int do_my_homework(List<T> matrix[], int start);

template <class T>
void markVisitedNodes(List<T> matrix[], int position);


template <class T>
int do_my_homework(List<T> matrix[], int start) {
	int minPosition = 0;
	int totalCost = 0;

	for (int index = 0; index < AIRPORT_LOCATIONS; index++) {
		cout << getTextfromEnum(start);
		if (index < AIRPORT_LOCATIONS - 1)
			cout << " --> "; 
	
		// This function gets the calculation to not revisit old paths
		markVisitedNodes(matrix, start);

		totalCost += matrix[start].returnCost();

		// Change the position or index of the array
		start = matrix[start].findMinPosition_inList();
	}

	return totalCost;
}


template <class T>
void markVisitedNodes(List<T> matrix[], int position) {
	// If this airport was visited then a bool value in the Node
	// will turn to "true" for all of the "column" nodes of the Array of Lists
	// So a statement could be made "if node bool value == true then skip"
	for (int index = 0; index < AIRPORT_LOCATIONS; index++)
		matrix[index].setMarker(position);
}


template <class T>
void setUpAdjMatrix(List<T> matrix[]) {

	matrix[BOS].add(0);
	matrix[BOS].add(0);
	matrix[BOS].add(187);
	matrix[BOS].add(0);
	matrix[BOS].add(1258);
	matrix[BOS].add(867);
	matrix[BOS].add(2704);

	matrix[DFW].add(0);
	matrix[DFW].add(0);
	matrix[DFW].add(0);
	matrix[DFW].add(1235);
	matrix[DFW].add(1121);
	matrix[DFW].add(802);
	matrix[DFW].add(1464);

	matrix[JFK].add(187);
	matrix[JFK].add(0);
	matrix[JFK].add(0);
	matrix[JFK].add(0);
	matrix[JFK].add(1090);
	matrix[JFK].add(740);
	matrix[JFK].add(0);

	matrix[LAX].add(0);
	matrix[LAX].add(1235);
	matrix[LAX].add(0);
	matrix[LAX].add(0);
	matrix[LAX].add(2342);
	matrix[LAX].add(0);
	matrix[LAX].add(337);

	matrix[MIA].add(1258);
	matrix[MIA].add(1121);
	matrix[MIA].add(1090);
	matrix[MIA].add(2342);
	matrix[MIA].add(0);
	matrix[MIA].add(0);
	matrix[MIA].add(0);

	matrix[ORD].add(867);
	matrix[ORD].add(802);
	matrix[ORD].add(740);
	matrix[ORD].add(0);
	matrix[ORD].add(0);
	matrix[ORD].add(0);
	matrix[ORD].add(1846);

	matrix[SFO].add(2704);
	matrix[SFO].add(1464);
	matrix[SFO].add(0);
	matrix[SFO].add(337);
	matrix[SFO].add(0);
	matrix[SFO].add(1846);
	matrix[SFO].add(0);
}


template <class T>
void displayAdjMatrix(List<T> matrix[]) {
	cout << "Displaying Adjacency Matrix:" << endl;
	cout << "\tBOS\tDFW\tJFK\tLAX\tMIA\tORD\tSFO" << endl;
	cout << "BOS" << "     "; matrix[BOS].displayList();
	cout << "\nDFW" << "     "; matrix[DFW].displayList();
	cout << "\nJFK" << "     "; matrix[JFK].displayList();
	cout << "\nLAX" << "     "; matrix[LAX].displayList();
	cout << "\nMIA" << "     "; matrix[MIA].displayList();
	cout << "\nORD" << "     "; matrix[ORD].displayList();
	cout << "\nSFO" << "     "; matrix[SFO].displayList();
	cout << endl;
}


#endif