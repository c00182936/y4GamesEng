#pragma once
class TestingBed
{
public:
	TestingBed();
	~TestingBed();
	int testCase1(int x, int y);
private:

};

TestingBed::TestingBed()
{
}

TestingBed::~TestingBed()
{
}

inline int TestingBed::testCase1(int x, int y)
{
	int max;
	if (x > y)
	{
		max = x;
	}
	else
	{
		max = x;
	}
	return max;
}
