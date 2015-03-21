#include <stdio.h>
#include "dynamicArray.h"


int main(int argc, char** argv)
{
	dynamicArray<char> arr;

	//arr.Insert(0, 'a');
	//arr.Insert(1, 'b');
	//arr.Insert(2, 'c');

	int n = arr.Pop();
	n = arr.Pop();
	arr.PushBack('d');
	arr.PushBack('e');
	arr.PushBack('f');
	arr.PrintArray();
	


	getchar();
	return 0;
}