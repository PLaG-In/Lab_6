// Test_Triangle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Triangle/Triangle.h"

BOOST_AUTO_TEST_CASE(DefineTriangleParameters)
{
	CTriangle trian(18, 10, 10);
	BOOST_CHECK_EQUAL(trian.GetFirstSide(), 18);
	BOOST_CHECK_EQUAL(trian.GetSecondSide(), 10);
	BOOST_CHECK_EQUAL(trian.GetThirdSide(), 10);
}

BOOST_AUTO_TEST_CASE(DefineTriangleNegativeParameters)
{
	BOOST_CHECK_THROW(CTriangle trian(-18, 10, 10), std::invalid_argument);
	BOOST_CHECK_THROW(CTriangle trian(22, -9, 14), std::invalid_argument);
	BOOST_CHECK_THROW(CTriangle trian(13, 27, -15), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CreateIncorrectTriangle)
{
	BOOST_CHECK_THROW(CTriangle trian(26, 4, 86), std::domain_error);
	BOOST_CHECK_THROW(CTriangle trian(94, 18, 10), std::domain_error);
	BOOST_CHECK_THROW(CTriangle trian(5, 94, 4), std::domain_error);
}

//BOOST_AUTO_TEST_CASE(CreateTriangleByDefault)
//{
//	CTriangle trian();
//}

BOOST_AUTO_TEST_CASE(DegenerateTriangleParameters)
{
	{
		CTriangle trian(18, 18, 36);
	}
	{
		CTriangle trian(12, 24, 12);
	}
	{
		CTriangle trian(20, 7, 13);
	}
	{
		CTriangle trian(0, 7, 7);
	}
	{
		CTriangle trian(4, 0, 4);
	}
	{
		CTriangle trian(3, 3, 0);
	}
	{
		CTriangle trian(0, 0, 0);
	}
}

BOOST_AUTO_TEST_CASE(DefineTrianglePerimeter)
{
	{
		CTriangle trian(9, 15, 8);
		BOOST_CHECK_EQUAL(trian.GetPerimeter(), 32);
	}
	{
		CTriangle trian(16, 12, 16);
		BOOST_CHECK_EQUAL(trian.GetPerimeter(), 44);
	}
	{
		CTriangle trian(6, 6, 6);
		BOOST_CHECK_EQUAL(trian.GetPerimeter(), 18);
	}
	{
		CTriangle trian(0, 0, 0);
		BOOST_CHECK_EQUAL(trian.GetPerimeter(), 0);
	}
}

BOOST_AUTO_TEST_CASE(DefineTriangleArea)
{
	{
		CTriangle trian(12, 5, 13);
		BOOST_CHECK_EQUAL(trian.GetArea(), 30);
	}
	{
		CTriangle trian(0, 5, 5);
		BOOST_CHECK_EQUAL(trian.GetArea(), 0);
	}
	{
		CTriangle trian(13, 10, 13);
		BOOST_CHECK_EQUAL(trian.GetArea(), 60);
	}
	{
		CTriangle trian(0, 0, 0);
		BOOST_CHECK_EQUAL(trian.GetArea(), 0);
	}
}