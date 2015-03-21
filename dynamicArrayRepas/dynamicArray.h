
template<class TYPE>
class dynamicArray
{
	//Properties
private:
	TYPE* content;
	int numElements;
	int allocatedMemory;

public:

	dynamicArray()
	{
		Reallocate(1);
		numElements = 0;
		allocatedMemory = 0;
	}

	~dynamicArray()
	{
		Clear();
	}

	int GetElements(){ return numElements; }
	int GetMemory(){ return allocatedMemory; }




	void Reallocate(const int size)
	{
		if (size > 0)//new doesn't accept a size 0 or less
		{
			content = new TYPE [size];
			numElements = size;
			allocatedMemory = size;
		}
	}

	


	void PushBack(const TYPE value)
	{
		if (numElements > 0) //In case the content has been reallocated at least once.
		{
			if (allocatedMemory > numElements)
			{
				content[numElements] = value;
				numElements++;
			}
			else
			{
				TYPE* tmp = new TYPE[numElements + 1];
				CopyArray(tmp, content, 0, numElements-1);
				tmp[numElements]=value;
				delete[] content;
				content = tmp;
				numElements++;
				allocatedMemory++;
			}

		}
		else//In case the content is post constructed and not allocated (empty) 
		{
			//Reallocate(1);
			numElements++;
			allocatedMemory++;
			content[0] = value;
		}
	
	}

	const TYPE Pop()
	{
		if (numElements > 0)
		{
			numElements--;
			return content[numElements - 1];
		}
	}

	void Insert(const int position, const TYPE value)
	{
		if (position >= 0 && position <= numElements && allocatedMemory != 0)
		{ 
					TYPE* tmp = new TYPE[numElements+1];
					
					/*
					 * we construct a tmp array in 3 steps,
					 * 1: We copy content to tmp from start until the position that is going to be filled with value.
					 * 2: We copy the value to tmp position (where we want it)
				     * 3: We copy the rest of the array to tmp
					 */
					CopyArray(tmp, content, 0, position);
					tmp[position] = value;
					numElements++;
					CopyArray(tmp, content, position+1, numElements);


					
					//Once tmp is fully constructed..
					if (allocatedMemory == 0)
						delete[] content;

					content = tmp;//!!!!!
					
					allocatedMemory++;
				
				
		}
		if (allocatedMemory == 0)//If there's any
		{
			content[0] = value;
			numElements++;
			allocatedMemory++;
		}
	}

	void Clear()
	{
	
		delete[] content;
	
	}

	void CopyArray(TYPE* dst,TYPE* src, const unsigned int offset, const unsigned int until)
	{
		for (int i = offset; i <= until; i++)
		{
			dst[i] = src[i];
		}
	
	}

	//Debug purposes only

	void PrintArray()
	{
		if (numElements == 0)
			printf("The array is empty"); 

		for (int i = 0; i < numElements; i++)
		{
			printf("%c",content[i]);//We manually change % because i don't know how to make the program detect its type (it doesn't really matter cause its for debugging)
		}
	}



};