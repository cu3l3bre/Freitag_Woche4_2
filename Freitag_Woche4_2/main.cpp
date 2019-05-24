#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Instrument
{
public:
	virtual void spielen()
	{
		cout << "Instrument wird gespielt" << endl;
	}

};


class Gitarre : public Instrument
{
public:
	void spielen()
	{
		cout << "Kling Klang" << endl;
	}

};


class Trompete : public Instrument
{
public:
	void spielen()
	{
		cout << "Troet Troet" << endl;
	}

};



int main()
{
	cout << "Programm zum Freitag Woche4 Nr 2: Statisches Binden" << endl << endl;

	Instrument instrument1;
	instrument1.spielen();

	Gitarre gitarre1;
	gitarre1.spielen();
	
	Trompete trompete1;
	trompete1.spielen();

	
	Instrument instrument2;
	instrument2 = trompete1;
	instrument2.spielen();


	Instrument* pInstrument;
	pInstrument = &trompete1;
	pInstrument->spielen();

	cout << sizeof(Instrument) << endl;




	// Liste von Instrumenten

	// so würde immer nur die methode von instrument ausgeführt, da  gitaare und trompete auf instrument wieder reduziert wird
	/*vector<Instrument> orchester;

	orchester.push_back(gitarre1);
	orchester.push_back(trompete1);

	for (int i = 0; i < orchester.size(); i++)
	{
		orchester[i].spielen();
	}
	*/

	vector<Instrument*> orchester;

	Gitarre *pGitarre = new Gitarre;


	orchester.push_back(&gitarre1);
	orchester.push_back(&trompete1);
	orchester.push_back(pGitarre);


	for (int i = 0; i < orchester.size(); i++)
	{
		orchester[i]->spielen();
	}

	delete pGitarre;




	cout << endl;
	system("pause");
	return 0;
}