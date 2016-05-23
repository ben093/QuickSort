//CSC 325 HW 2 Ben Borgstede

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <iomanip>
using namespace std;

vector<int> A;

// g++ -std=c++11 -Wall h2.cpp
// a < testfilehw2.txt

void printVector()
{
	/*cout << "Current vector " << endl;
	for(int k = 0; k < (int)A.size(); k++)
	{
		cout << A[k] << " ";
	}
	cout << endl;*/
}

int partition(int p, int r)
{	
	//generate random int for pivot
	int pivot_index = rand()%(r - p + 1) + p;
	double pivot = A[pivot_index];
	
	
	//cout << "swapping " << A[r] << " and " << pivot << endl;
	//cout << "The pivot is now on the end" << endl;
	//swap(A[r], A[pivot_index]); //pivot is now on the end
	//pivot_index = r;
	
	//set i and j
	int i = p;
	int j = r;

	
	while(i <= j)
	{
		//find elements that need to be swapped
		while(A[i] < pivot)
			i++;
		while(pivot < A[j])
			j--;				
			
		if(i <= j)
		{
			//swap the elements that were found
			//then iterate to next index's of i and j			
			
			//cout << "it seems elements " << A[i] << " and " << A[j] << " need to be swapped." << endl;
			swap(A[i], A[j]);
			
			//printVector();
			
			//iterate i and j
			i++;
			j--;
		}		
	}
	
	//return the index of the pivot to quickSort function
	return i;
}

void quickSort(int p, int r)
{
	
	//printVector();
	
	if(p < r)
	{
		int q = partition(p, r); 	//partition step
		
		quickSort(p, q - 1);
		quickSort(q, r);
	}
}

double findMean()
{
	double mean;
	
	for(int i = 0; i < (int)A.size(); i++)
	{
		mean += (double)A[i];
	}
	
	mean = mean / ((double)A.size());
	
	return mean;
}

double findMedian()
{
	double median;
	
	if(A.size() % 2 == 0)
	{
		int i = A.size() / 2;
		int j = i - 1;
		
		median = (double)A[i] + (double)A[j];
		
		return median / 2;
	}
	else
	{
		median = A.size() / 2;
	}
	
	return (double)A[median];
	
}

double findMode()
{	
	double number = A[0];
	double mode = number;
	int count = 1;
	int countMode = 1;
	
	for(int i = 1; i < (int)A.size(); i++)
	{
		if(A[i] == number)
		{
			count++;
		}
		else
		{			
			count = 1;
			number = A[i];
		}
		
		if(count > countMode)
		{
			countMode = count;
			mode = number;
		}
	}
	
	return mode;
	
	
	//int i = 0;	
	double mostCommon = A[0];
	//double previous = A[i];
	int count = 0;
	int mostCommonCount = 0;	
	
	double currentNum = A[0];
	
	for(int i = 0; i < (int)A.size(); i++)
	{
		if(A[i] == A[i+1])
		{
			count++;
			
			currentNum = A[i];
		}
		else
		{
			count = 0;
			currentNum = A[i];
		}		
		
		if(count > mostCommonCount)
		{
			mostCommonCount = count;
			mostCommon = A[i];
		}
	}
	
	cout << "There are " << mostCommonCount << " matches" << endl;
	
	return mostCommon;*/
}

int main()
{
	srand (time(NULL));
	int number;
	while (cin >> number)
	{
		A.push_back(number);
	}
	
	quickSort(0, (int)A.size() - 1);
	
	//3 decimal places
	cout << fixed << setprecision(3);	
	double mean = findMean();
	cout << "mean " << setprecision(3) << mean << endl;
	
	double median = findMedian();	
	cout << "median " << median << endl;
	
	//zero decimal places
	cout << fixed << setprecision(0);	
	double mode = findMode();	
	cout << "mode " << mode << endl;		
}