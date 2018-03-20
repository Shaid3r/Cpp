#include <iostream>

template <typename T1, typename T2>
struct Example
{
	/*jakieś inne metody*/

	void Print() 
	{
		std::cout << "Oryginalny szablon\n";
	} 
};

template <typename T1>
struct Example<T1, int> 
{
	/*jakieś inne metody*/

	void Print()
	{
		std::cout << "Szablon z częściowej specjalizacji\n";
	}
};

template <>
struct Example<int, int> 
{
	/*jakieś inne metody*/

	void Print()
	{
		std::cout << "Szablon z jawnej specjalizacji\n";
	}
};


int main () 
{

	Example<char, char> obj;
	// Example<double, int> obj;
	// Example<int, int> obj;
	
	obj.Print();

	return 0;
}