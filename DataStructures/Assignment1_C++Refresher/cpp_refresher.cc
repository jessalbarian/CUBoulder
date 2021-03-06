// Copyright 2015 Jessie Albarian
// All rights reserved.


#include "cpp_refresher.h"
#include <iostream>

using namespace std;

void PrintHelloWorld() {
  // Here you need to cout something (I recommend "Hello, world!" because
  // Computer Science, naturally).
  // Don't forget to include iostream!
   cout << "Hello, world!" << endl;
}

void CallUberFunctions() {
  // There is a magic function, called "UberFunction" that is capable of taking
  // anything for an argument. You need to call "UberFunction" with the
  // following types: int, int* int** and char[]
  // You also need to call "OtherUberFunction" in the namespace
  // "uber_namespace" once, with no arguments.
  // The first one has been done for you:
	int * p1;				// declare pointer 1
	int ** p2;				// declare pointer 2
	char arr[] = "hello";	// declare character array
	
	UberFunction(42);
	UberFunction(p1);
	UberFunction(p2);
	UberFunction(arr);
	
	uber_namespace::OtherUberFunction();	//call function from namespace; use namespaceName::functionName
}


void Loops(int number_of_times) {
  // Call "DoesAwesomeLoopyThings" without passing in anything,
  // "number_of_times" times. Some type of a loop is a good candidate for this.
	
	for (int i = 0; i < number_of_times; i++){ // call function from 0 - number_of_times, incrementing by 1
		DoesAwesomeLoopyThings();
	}
}

void CopyArrayOnHeap(const char* str) {
  // This ones a bit more tricky! The char* str here is a C style string.
  // Remember that C strings end in a NULL, aka a 0
  // Hint: You can find the length of the string knowing that piece of
  // information.
  // The goal is to create another C string (a char*) on the heap of the exact
  // same size as str, including the 0 at the end.
  // Then clean up memory by freeing the string on the heap.
  // You MUST use "new" and "delete", you cannot use malloc and free.
  
  int len = 1;							//initialize length
  for (int i = 0; str[i] != '\0'; i++){	//get length of str
	len++;								//increment by 1 for each element in array
  }
  char* myStr = new char[len];				// create another C string; new returns a pointer
  delete myStr;								// delete string to clean up memory
}

void UseingObjects(UberClass& uber_class_1, UberClass* uber_class_2,
                   UberClass** uber_class_3) {
  // UbserCLass is a class with a member function (also called a method) called
  // "UberMethod" and a member variable (often just called a member) called
  // "uber_member".
  // For each of the instances of the UberClass that was passed in (aka. for
  // each of the objects) you need to call the member function (the method)
  // You also need to set the member variable to 42.

  uber_class_1.UberMethod();
  (*uber_class_2).UberMethod();
  (**uber_class_3).UberMethod();
  
  uber_class_1.uber_member = 42;
  (*uber_class_2).uber_member = 42;
  (**uber_class_3).uber_member = 42;
   
}

// Extra Credit
void InPlaceReverse(char* str) {
  // This is a really tricky one! You must reverse the order of the C string
  // without allocating a new C string. Think about how to do this without
  // creating a second string, it's possible, I promise :)
  
  int len = 0;								//initialize length
  for (int i = 0; str[i] != '\0'; i++) {	//get length of str
	len++;									//increment by 1 for each element in array
  }
  	char temp;
	int j, i;

	for (i = 0, j = len-1; i <= len/2; j--, i++) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
