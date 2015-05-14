#pragma once

class CTriangle
{
public:
	CTriangle();
	CTriangle(double firstSide, double secondSide, double thirdSide);
	~CTriangle();

	double GetFirstSide() const;
	double GetSecondSide() const;
	double GetThirdSide() const;
	double GetArea() const;
	double GetPerimeter() const;

private:
	double m_firstSide;
	double m_secondSide;
	double m_thirdSide;
	void IncorrectSideLength(double side, std::string num);
	void SideErrors(double firstSide, double secondSide, double thirdSide);
};

