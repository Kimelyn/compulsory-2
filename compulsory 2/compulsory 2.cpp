#include <cstdlib>
#include <time.h>
#include <iostream>

int cards[14] = {};
int amount = 100; // hold player's balance amount
int houseamount; // hold house's balance amount
int bettingAmount = 0; //how much we bet
int total = 0; // player sum
int housetotal = 0; // house sum
bool flag = true;

int randnum() { //get a random number from 1-10 & other 3 kinds of 10 & ace(1 or 11)

	srand(time(NULL));
	int cards = rand() % 14 + 1;
	int sumtotal = 0;

	if (cards == 11) {
		std::cout << "Knight\n";
		cards = 10;
	}
	else if (cards == 12) {
		std::cout << "Queen\n";
		cards = 10;
	}
	else if (cards == 13) {
		std::cout << "King\n";
		cards = 10;
	}
	else if (cards == 14) {
		std::cout << "Ace! Do you want it to count as 1 or 11?\n";
		int choice = 0;
		do {
			std::cin >> choice;
			if (choice == 1) {
				cards = 1;
			}
			else if (choice == 11) {
				cards = 11;
			}
			else {
				std::cout << "invalid input\n";
			}
		} while (choice != 1 && choice != 11);
	}
	else {
		std::cout << cards << "\n";

	}
	sumtotal += cards;
	return cards;

}

void again() //player hit or stand
{
	int option = 0;

	do {
		std::cout << "pick a card again?:\n";
		std::cout << "1.yes";
		std::cout << "2.no";
		std::cin >> option;
		switch (option) {
		case 1:
			std::cout << "This is your new card\n";
			total += randnum();
			std::cout << "Your sum is " << total << "\n";
			if (total > 22) {
				flag = false;
				std::cout << "You went over 21";
			}
			break;
		case 2:
			std::cout << "Your turn is over\n";
			flag = false;
			break;
		default:
			std::cout << "invalid input\n";
			break;
		}
	} while (flag == true);
	void house();
}
void houseagain() //house hit or stand
{
	int option = 0;

	do {
		std::cout << "pick a card again?:\n";
		std::cout << "1.yes";
		std::cout << "2.no";

		std::cin >> option;
		switch (option) {
		case 1:
			std::cout << "This is House new card\n";
			housetotal += randnum();
			std::cout << "House's sum is " << housetotal << "\n";
			if (housetotal > 22) {
				flag = false;
				std::cout << "You went over 21.";
			}
			else if (housetotal > 15 && housetotal <= 21) {
				std::cout << "Time to determine the winner \n";
				flag = false;
			}
			break;

		case 2:
			std::cout << "Time to determine the winner \n";
			flag = false;
			break;
		default:
			std::cout << "invalid input\n";
			break;
		}
	} while (flag == true);
	void winner();

}
void player() {
	total += randnum();
	again();

}
void house() {
	std::cout << " House is turn\n";
	housetotal += randnum();
	houseagain();
}
void winner() { //declare the winner and whoever gets the money, or draw
	if (total > housetotal && total <= 21) {
		std::cout << " You won against the AI! \n";
		std::cout << " You won $ " << bettingAmount;
		amount = amount + bettingAmount;
		houseamount = houseamount - bettingAmount;
	}
	else if (total < housetotal && total <= 21) {
		std::cout << " You lost against the AI! \n";
		std::cout << " You lost $ " << bettingAmount << "\n";
		amount = amount - bettingAmount;
		houseamount = houseamount + bettingAmount;
	}
	else if (total == housetotal && total <= 21) {
		std::cout << "It is a draw\n";
		std::cout << "No money lost\n";
		amount = amount;
		houseamount = houseamount;
	}
	else if (total > housetotal && total > 21) {
		std::cout << " You lost against the AI! \n";
		std::cout << " You lost $ " << bettingAmount << "\n";
		amount = amount - bettingAmount;
		houseamount = houseamount + bettingAmount;
	}
	else if (total < housetotal && housetotal > 21) {
		std::cout << " You won against the AI! \n";
		std::cout << " You won $ " << bettingAmount;
		amount = amount + bettingAmount;
		houseamount = houseamount - bettingAmount;
	}
	else {
		std::cout << "No one won\n";
		std::cout << "No money lost\n";
		amount = amount;
		houseamount = houseamount;
	}
	std::cout << "\n" << ", You have $ " << amount << "\n";
	std::cout << "\n" << ", House have $ " << houseamount << "\n";
	if (amount == 0)
	{
		std::cout << "You have no money to play ";

	}
	if (houseamount == 0)
	{
		std::cout << "House have no money to play ";

	}

	return;
}
int main() {//introduction
	std::cout << "Welcome to simple\n";
	std::cout << " ---------------\n";
	std::cout << "{Blackjack game!}\n";
	std::cout << " ---------------\n";
	std::cout << "\n";
	std::cout << "You will be playing against AI\n";
	char choice;
	do {
		std::cout << " Your current balance is $ " << amount << "\n";
		houseamount = amount;
		// Get player's betting amount
		do
		{
			std::cout << " Enter money to bet : $";
			std::cin >> bettingAmount;
			if (bettingAmount > amount) {
				std::cout << "Your betting amount is more than your current balance\n"
					<< " Re-enter amount\n ";
			}
			else if (bettingAmount < 10) {
				std::cout << "Bet more\n"
					<< " Re-enter amount\n ";
			}
		} while (bettingAmount > amount || bettingAmount <= 10);
		//player's first card
		std::cout << "This is your first card\n";
		std::cin.get();
		player();
		house();
		winner();
		std::cout << "   Do you want to play again (y/n)? ";//asked to play again after determining the winner

		std::cin >> choice;
		system("cls");
	} while (choice != 'n');

	system("pause");
	return 0;
}
