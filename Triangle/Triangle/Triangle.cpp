// Triangle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(double firstSide, double secondSide, double thirdSide)
	: m_firstSide(firstSide)
	, m_secondSide(secondSide)
	, m_thirdSide(thirdSide)
{
	IncorrectSideLength(m_firstSide, "First");
	IncorrectSideLength(m_secondSide, "Second");
	IncorrectSideLength(m_thirdSide, "Third");
	SideErrors(m_firstSide, m_secondSide, m_thirdSide);
}

CTriangle::~CTriangle()
{
}

double CTriangle::GetFirstSide() const
{
	return m_firstSide;
}

double CTriangle::GetSecondSide() const
{
	return m_secondSide;
}

double CTriangle::GetThirdSide() const
{
	return m_thirdSide;
}

double CTriangle::GetPerimeter() const
{
	return (m_firstSide + m_secondSide + m_thirdSide);
}

double CTriangle::GetArea() const
{
	double const halfPerimeter = GetPerimeter() / 2;
	return sqrt(halfPerimeter * (halfPerimeter - m_firstSide) *
		(halfPerimeter - m_secondSide) * (halfPerimeter - m_thirdSide));
}

void CTriangle::IncorrectSideLength(double side, std::string num)
{
	if (side < 0)
	{
		throw std::invalid_argument(num + " side can't be negative!");
	}
}

void CTriangle::SideErrors(double firstSide, double secondSide, double thirdSide)
{
	if (firstSide > (secondSide + thirdSide))
	{
		throw std::domain_error("First side is too large!");
	}
	if (secondSide > (firstSide + thirdSide))
	{
		throw std::domain_error("Second side is too large!");
	}
	if (thirdSide > (firstSide + secondSide))
	{
		throw std::domain_error("Third side is too large!");
	}
}