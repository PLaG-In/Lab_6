// main.cpp : Defines the enttempRectry point for the console application.
//

#include "stdafx.h"
#include "Triangle.h"

using namespace std;

CTriangle InputParameters()
{
	double firstSide, secondSide, thirdSide;

	if (!(cin >> firstSide >> secondSide >> thirdSide))
	{
		if (cin.eof())
		{
			exit(0);
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw invalid_argument("Incorrect input!");
		}
	}
	return CTriangle(firstSide, secondSide, thirdSide);
}

int main()
{
	while (true)
	{
		try
		{
			cout << "Input triangle sides: ";
			CTriangle trian(InputParameters());
			cout << "Perimeter = " << trian.GetPerimeter() << endl;
			cout << "Area = " << trian.GetArea() << endl;
		}
		catch (exception const& e)
		{
			cerr << e.what() << endl;
		}
	}

	return 0;
}