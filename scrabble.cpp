#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>

#define SIZE 8

int main()
{
	char moje[SIZE];

	int i = 0;
	int sort = 0;

	std::ifstream slownik("slowa.txt", std::ios::out);
	
	std::string pomocnicza;
	std::string powtorki;
    std::string ze_slownika;
	
	std::vector <std::string> zgodne_wyrazy;
	
    for(i = 0; i<7; ++i) //pobieranie liter z reki
    {
        std::cout << "Podaj " << i + 1 << ". litere:" << std::endl;
        std::cin >> moje[i];
    }

	//pobranie litery z planszy
    std::cout << "Podaj litere z planszy: " << std::endl;
    std::cin >> moje[SIZE - 1];

	//wyswietlenie liter
	std::cout << "\nTwoje litery: ";
	for(i = 0; i<8; ++i)
    {
        std::cout << moje[i];
    }

	std::cout<< "\n\nLadowanie wyrazow..." << std::endl;

do{
		getline(slownik, ze_slownika); //pobranie slowa ze slownika
		powtorki = moje;

        if(ze_slownika.length() < 9) //sprawdzenie czy pobrane slowo nie jest dluzsze ni¿ 7 posiadanych liter + 1 z planszy
        {
			for(i=0;i<ze_slownika.length();++i) //wpisywanie do zmiennej pomocniczej liter pokrywajacych sie z posiadanymi literami
            {
                for(int j = 0; j < 8; ++j)
                {
                    if(ze_slownika[i] == powtorki[j])
                    {
						pomocnicza.push_back(powtorki[j]);
						powtorki[j] = '0'; //zerowanie wykorzystanej litery
					}
                }
            }

			 if(pomocnicza == ze_slownika) //sprawdzenie czy uzyskana slowo w zmiennej pomocniczej == wyrazowi ze slownika
                {
					//sortowanie.resize(sort);
					zgodne_wyrazy.push_back(pomocnicza);
					sort++;	
				}
                
	pomocnicza.clear();

        }
}
	
while(ze_slownika != "");

sort--;

for(i = 0; i < sort ; i++) //sortowanie wg dlugosci wyrazu
{
	std::string temp;

	for(int j = 0; j<sort - i; ++j)
	{
		if(zgodne_wyrazy[j].length() < zgodne_wyrazy[j+1].length())
		{		
			temp = zgodne_wyrazy[j];
			zgodne_wyrazy[j] = zgodne_wyrazy[j+1];
			zgodne_wyrazy[j+1] = temp;
		}
	}
}

for (i = 0; i < sort; ++i) //wypisanie wyrazow kompatybilnych z posiadanymi literami
{
	std::cout<< std::endl;
	std::cout << zgodne_wyrazy[i];
}

slownik.close();

return 0;
}