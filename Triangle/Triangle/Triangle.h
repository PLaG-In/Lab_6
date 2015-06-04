#pragma once

class CTriangle
{
public:
	CTriangle();
	CTriangle(double firstSide, double secondSide, double thirdSide);
	~CTriangle();

	enum Index
	{
		First,
		Second,
		Third
	};

	double GetFirstSide() const;
	double GetSecondSide() const;
	double GetThirdSide() const;
	double GetArea() const;
	double GetPerimeter() const;

private:
	Index m_sideName;
	double m_firstSide;
	double m_secondSide;
	double m_thirdSide;
	void static ValidateSideLength(double side, Index sideName);
};

