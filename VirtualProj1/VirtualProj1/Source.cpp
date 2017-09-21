#include <iostream>
#include <vector>
using namespace std;
class Api
{
public:
	virtual void draw() = 0;
};
class MyApi :public Api
{
public:
	void draw() { cout << "handled api has drawn" << endl; };
};


class Plant
{
public:

	virtual void Draw()=0;

};
class Rose :public Plant
{
public:
	void Draw()
	{
		cout << "draw rose goes here" << endl;
	}

};
class Carrot :public Plant
{
public:
	void Draw()
	{
		cout << "carrot has been drawn" << endl;
	}
};
class Scallion
{
public:
	void setApi(Api* nuApi) { myApi = nuApi; }
	void Draw() {
		myApi->draw();
	}
private:
	Api* myApi;
};

class Factory
{
public:

	virtual Plant* CreateRose() = 0;
	virtual Plant* CreateCarrot() = 0;
private:

};
class plantFactory :public Factory
{
public:
	Plant* CreateRose()
	{
		return new Rose;
	}
	Plant* CreateCarrot()
	{
		return new Carrot;
	}
	
};




int main()
{
	cout << "factory stuff" << endl;
	Factory* factory = new plantFactory;
	vector<Plant*> plants;
	for (size_t i = 0; i < 3; i++)
	{
	plants.push_back(factory->CreateCarrot());
	plants.push_back(factory->CreateRose());
	}
	for (size_t i = 0; i < plants.size(); i++)
	{
		plants[i]->Draw();
	}
	Scallion *scall = new Scallion();
	Api*tempApi = new MyApi();
	scall->setApi(tempApi);
	scall->Draw();


	system("PAUSE");
	return 0;
}