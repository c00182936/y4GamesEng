#pragma once

class Command
{
public:
	Command();
	virtual ~Command();
	virtual void execute(int* colour) = 0;
protected:

};


class Inc:Command
{
public:
	Inc();
	~Inc();
	virtual void  execute(int* colour) {*colour += 5;}
private:

};
class Dec :Command
{
public:
	Dec();
	~Dec();
	virtual void  execute(int* colour) {*colour -= 5;}
private:

};

