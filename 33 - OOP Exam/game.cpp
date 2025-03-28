#include <windows.h>
#include "game.h"

std::random_device dev;
std::mt19937 rnd(dev());
std::uniform_int_distribution<unsigned> coin(0, 100);

int main()
{
	Character* player1 = new Character(100, 50, 15, 15, 25, "char1");
	Character* player2 = new Character(*player1);
	std::string name1, name2;

	std::cout << "Player1 choose your name: ";
	std::cin >> name1;
	player1->SetName(name1);
	system("cls");

	std::cout << "Player2 choose your name: ";
	std::cin >> name2;
	player2->SetName(name2);
	system("cls");

	std::cout << "I throw a coin and...\n";
	Sleep(3000);
	unsigned cointoss = coin(rnd);
	bool its_firsts_turn;
	if (cointoss == 0) {
		std::cout << "It's edge...\n";
		player1->~Character();
		player2->~Character();
		return 0;
	}
	if (cointoss > 50) {
		std::cout << player2->GetName() << " is going first!\n";
		its_firsts_turn = false;
	}
	else {
		std::cout << player1->GetName() << " is going first!\n";
		its_firsts_turn = true;
	}


	while (1)
	{
		std::string phrase;
		if (its_firsts_turn) {
			std::cout << *player1 << "Your phrase: ";
			std::cin >> phrase;
		}
		else {
			std::cout << *player2 << "Your phrase: ";
			std::cin >> phrase;
		}

		system("cls");
		std::cout << phrase << "\n";
		int damageTaken = (its_firsts_turn ? player2->RecieveDamage(*player1) : player1->RecieveDamage(*player2));
		if (damageTaken == -1)
		{
			if (its_firsts_turn) {
				delete player2;
				std::cout << player1->GetName() << " win!";
			}
			else {
				delete player1;
				std::cout << player2->GetName() << " win!";
			}
			return 0;
		}
		else
		{
			std::cout << "You loose " << damageTaken << " HP!\n";
			its_firsts_turn = !its_firsts_turn;
		}
	}
}