// Triangle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle()
	: m_firstSide(0)
	, m_secondSide(0)
	, m_thirdSide(0)
{
}

CTriangle::CTriangle(double firstSide, double secondSide, double thirdSide)
	: m_firstSide(firstSide)
	, m_secondSide(secondSide)
	, m_thirdSide(thirdSide)
{
	ValidateSideLength(m_firstSide, First);
	ValidateSideLength(m_secondSide, Second);
	ValidateSideLength(m_thirdSide, Third);
	if (m_firstSide >(m_secondSide + m_thirdSide))
	{
		throw std::domain_error("First side is too large!");
	}
	if (m_secondSide > (m_firstSide + m_thirdSide))
	{
		throw std::domain_error("Second side is too large!");
	}
	if (m_thirdSide > (m_firstSide + m_secondSide))
	{
		throw std::domain_error("Third side is too large!");
	}
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

void CTriangle::ValidateSideLength(double side, Index sideName)
{
	if (side < 0)
	{
		throw std::invalid_argument(sideName + "-nd(rd) side can't be negative!");
	}
}
