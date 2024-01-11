#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <random>
#include <chrono>
bool gameEnd = false;
bool Player1TurnEnd = false;
bool Player2TurnEnd = false;
bool playAgain = true;
int winnerPlayerNum = 0;
int checkTurn;
int checkPlayer;





class Card {
protected:
	std::string name;
	std::string type;
public:
	Card(std::string n, std::string t) :name(n), type(t) {
	}

	Card() {
	name: "";
	type: "";
	}

	virtual void PrintNameAndStats() = 0;
	virtual bool isTapped() = 0;
	virtual bool isCreature() = 0;
	virtual void tapCard() = 0;
	virtual void unTapCard() = 0;
	virtual bool isTrample() = 0;
	virtual bool isFirstStrike() = 0;
	virtual int returnAD() = 0;
	virtual int returnHP() = 0;
	virtual void takeDamage(int takenDmg) = 0;
	virtual bool isDestroyed() = 0;
	virtual std::string returnName() = 0;
	virtual std::string returnType() = 0;
	virtual std::string returnColor() = 0;
	virtual void returnToMaxHP() = 0;




};

class landCard : public Card {
protected:
	std::string manaGiven;
public:
	landCard(std::string n, std::string t, std::string m) : Card(n, t), manaGiven(m) {
	}

	landCard() : Card() {
	}

	void PrintNameAndStats() {
		std::cout << "Land: " << name << "   Mana Type: " << manaGiven;
	}
	bool isTapped() {
		return false;
	}
	bool isCreature() {
		return false;
	}
	void tapCard() {}
	void unTapCard() {}
	bool isTrample() {
		return false;
	}
	bool isFirstStrike() {
		return false;
	}
	int returnAD() {
		return 0;
	}
	int returnHP() {
		return 0;
	}
	void takeDamage(int takenDmg) {
	}
	bool isDestroyed() {
		return false;
	}
	std::string returnName() {
		return name;
	}
	std::string returnType() {
		return type;
	}
	std::string returnColor() {
		return " ";
	}
	void returnToMaxHP() {

	}


};






class creatureCard : public Card {
protected:
	int attackPower;
	int HP, maxHP;
	bool FirstStrike;
	bool Trample;
	bool tap;
	bool destroy;
	std::string mana;
	std::string cardColor;
public:
	creatureCard(std::string n, std::string t, std::string m, std::string cc, int aP, int hP, bool firstStrike, bool trample) : Card(n, t), mana(m), cardColor(cc), attackPower(aP), HP(hP), FirstStrike(firstStrike), Trample(trample), tap(false), destroy(false), maxHP(hP) {
	}

	creatureCard() {
	}

	void PrintNameAndStats() {
		std::cout << "Creature:   " << name << "   Mana: " << mana << "   Stats:" << attackPower << "/" << HP << "   Tapped:";
		if (tap) {
			std::cout << "Yes ";
		}
		else {
			std::cout << "No ";
		}
		std::cout << "First Strike: ";
		if (FirstStrike) {
			std::cout << "Yes ";
		}
		else {
			std::cout << "No ";
		}
		std::cout << "Trample: ";
		if (Trample) {
			std::cout << "Yes ";
		}
		else {
			std::cout << "No ";
		}
	}
	bool isTapped() {
		return tap;
	}
	bool isCreature() {
		return true;
	}
	void tapCard() {
		tap = true;
	}
	void unTapCard() {
		tap = false;
	}
	bool isTrample() {
		return Trample;
	}
	bool isFirstStrike() {
		return FirstStrike;
	}
	int returnAD() {
		return attackPower;
	}
	int returnHP() {
		return HP;
	}
	void takeDamage(int takenDmg) {
		HP -= takenDmg;
		if (HP <= 0) {
			destroy = true;
		}

	}
	bool isDestroyed() {
		return destroy;
	}
	std::string returnName() {
		return name;
	}
	std::string returnType() {
		return type;
	}
	std::string returnColor() {
		return cardColor;
	}
	void returnToMaxHP() {
		HP = maxHP;
	}


};









class enchantmentCard : public Card {
protected:
	std::string effects;
	std::string mana;
public:
	enchantmentCard(std::string n, std::string t, std::string m, std::string effect) :
		Card(n, t), mana(m), effects(effect) {
	}

	enchantmentCard() {
	}



	void PrintNameAndStats() {
		std::cout << "Enchantment: " << name << "   Mana: " << mana << "   Effect: " << effects;
	}
	bool isTapped() {
		return false;
	}
	bool isCreature() {
		return false;
	}
	void tapCard() {}
	void unTapCard() {}
	bool isTrample() {
		return false;
	}
	bool isFirstStrike() {
		return false;
	}
	int returnAD() {
		return 0;
	}
	int returnHP() {
		return 0;
	}
	void takeDamage(int takenDmg) {
	}
	bool isDestroyed() {
		return false;
	}
	std::string returnName() {
		return name;
	}
	std::string returnType() {
		return type;
	}
	std::string returnColor() {
		return " ";
	}
	void returnToMaxHP() {

	}


};










class sorceryCard : public Card {
protected:
	std::string effects;
	std::string mana;
public:
	sorceryCard(std::string n, std::string t, std::string m, std::string effect) :
		Card(n, t), mana(m), effects(effect) {
	}

	sorceryCard() {
	}






	void PrintNameAndStats() {
		std::cout << "Sorcery: " << name << "   Mana: " << mana << "   Effect: " << effects;
	}
	bool isTapped() {
		return false;
	}
	bool isCreature() {
		return false;
	}
	void tapCard() {}
	void unTapCard() {}
	bool isTrample() {
		return false;
	}
	bool isFirstStrike() {
		return false;
	}
	int returnAD() {
		return 0;
	}
	int returnHP() {
		return 0;
	}
	void takeDamage(int takenDmg) {
	}
	bool isDestroyed() {
		return false;
	}
	std::string returnName() {
		return name;
	}
	std::string returnType() {
		return type;
	}
	std::string returnColor() {
		return " ";
	}
	void returnToMaxHP() {

	}


};



class Player {
protected:
	int HP, PlayerNum, greenMana, blackMana, whiteMana, redMana, blueMana;
	std::vector< std::shared_ptr<Card >> HandCardsArray;
	std::vector< std::shared_ptr<Card >> CardsInPlayArray;
	std::vector< std::shared_ptr<Card >> DiscardPileArray;
	std::vector< std::shared_ptr<Card >> LibraryArray;
public:

	friend void combatPhase(Player& defender);
	friend void displayCurrentStateForP1(Player& p1, Player& p2);
	friend void displayCurrentStateForP2(Player& p1, Player& p2);
	friend void playPhase(int takeTurn, Player& p1, Player& p2);


	Player(int pnum) :PlayerNum(pnum), HP(15), greenMana(0), blackMana(0), whiteMana(0), redMana(0), blueMana(0) {
		shuffleDeck();
		std::cout << "\nDrawing player " << PlayerNum << "'s first cards:\n\n";
		for (int c = 0; c < 5; c++) {
			drawCard();
		}
	}

	void playPhase(int takeTurn, Player& p1, Player& p2) {
		std::string name;
		int chosenCard = -1;
		while (chosenCard != 0) {
			std::cout << "Your cards : \n";
			for (int c = 0; c < HandCardsArray.size(); c++) {
				std::cout << c + 1 << ". ";
				HandCardsArray.at(c)->PrintNameAndStats();
				std::cout << "\n";
			}
			std::cout << "\nPlease choose one: (Enter '0' to end your play phase)";
			std::cin >> chosenCard;

			if (chosenCard == 0 || chosenCard < 0 || chosenCard > HandCardsArray.size()) {
				break;
			}

			name = HandCardsArray.at(chosenCard - 1)->returnName();




			if (name == "Forest" || name == "Island" || name == "Mountain" || name == "Plain" || name == "Swamp") {


				if (checkTurn != takeTurn || (checkPlayer != PlayerNum && checkTurn == takeTurn)) {


					if (name == "Forest") {
						greenMana++;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					}
					else if (name == "Island") {
						blueMana++;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					}
					else if (name == "Mountain") {
						redMana++;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					}
					else if (name == "Plain") {
						whiteMana++;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					}
					else if (name == "Swamp") {
						blackMana++;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					}


				}
				else {
					std::cout << "You can't play more land cards this turn.";
				}

				checkTurn = takeTurn;
				checkPlayer = PlayerNum;

			}








			while (name == "Soldier") {
				if (whiteMana >= 1) {
					whiteMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}


			while (name == "ArmoredPegasus") {
				if (whiteMana >= 2) {
					whiteMana -= 2;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && blackMana >= 1) {
					whiteMana--;
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && redMana >= 1) {
					whiteMana--;
					redMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && greenMana >= 1) {
					whiteMana--;
					greenMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && blueMana >= 1) {
					whiteMana--;
					blueMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}






			while (name == "WhiteKnight") {
				if (whiteMana >= 2) {
					whiteMana -= 2;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}






			while (name == "AngryBear") {

				if (greenMana >= 1 && greenMana + blackMana + whiteMana + redMana + blueMana >= 3) {
					greenMana--;

					if (greenMana >= 1) {
						greenMana--;
					}
					else if (blackMana >= 1) {
						blackMana--;
					}
					else if (whiteMana >= 1) {
						whiteMana--;

					}
					else if (redMana >= 1) {
						redMana--;

					}
					else if (blueMana >= 1) {
						blueMana--;

					}


					if (greenMana >= 1) {
						greenMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blackMana >= 1) {
						blackMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (whiteMana >= 1) {
						whiteMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (redMana >= 1) {
						redMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blueMana >= 1) {
						blueMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}

				}

				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}











			while (name == "Guard") {

				if (whiteMana >= 2 && greenMana + blackMana + whiteMana + redMana + blueMana >= 4) {
					whiteMana -= 2;


					if (greenMana >= 1) {
						greenMana--;
					}
					else if (blackMana >= 1) {
						blackMana--;
					}
					else if (whiteMana >= 1) {
						whiteMana--;

					}
					else if (redMana >= 1) {
						redMana--;

					}
					else if (blueMana >= 1) {
						blueMana--;

					}


					if (greenMana >= 1) {
						greenMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blackMana >= 1) {
						blackMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (whiteMana >= 1) {
						whiteMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (redMana >= 1) {
						redMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blueMana >= 1) {
						blueMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}


				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}









			while (name == "Werewolf") {


				if (whiteMana >= 1 && greenMana >= 1 && greenMana + blackMana + whiteMana + redMana + blueMana >= 4) {
					whiteMana--;
					greenMana--;


					if (greenMana >= 1) {
						greenMana--;
					}
					else if (blackMana >= 1) {
						blackMana--;
					}
					else if (whiteMana >= 1) {
						whiteMana--;

					}
					else if (redMana >= 1) {
						redMana--;

					}
					else if (blueMana >= 1) {
						blueMana--;

					}


					if (greenMana >= 1) {
						greenMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blackMana >= 1) {
						blackMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (whiteMana >= 1) {
						whiteMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (redMana >= 1) {
						redMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blueMana >= 1) {
						blueMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}



				}




				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}










			while (name == "Skeleton") {
				if (blackMana >= 1) {
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}









			while (name == "Ghost") {

				if (blackMana >= 1 && greenMana + blackMana + whiteMana + redMana + blueMana >= 2) {
					blackMana--;

					if (greenMana >= 1) {
						greenMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blackMana >= 1) {
						blackMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (whiteMana >= 1) {
						whiteMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (redMana >= 1) {
						redMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blueMana >= 1) {
						blueMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}


				}



				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}









			while (name == "BlackKnight") {
				if (blackMana >= 2) {
					blackMana -= 2;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}











			while (name == "OrcManiac") {

				if (redMana >= 1 && greenMana + blackMana + whiteMana + redMana + blueMana >= 3) {
					redMana--;

					if (greenMana >= 1) {
						greenMana--;
					}
					else if (blackMana >= 1) {
						blackMana--;
					}
					else if (whiteMana >= 1) {
						whiteMana--;

					}
					else if (redMana >= 1) {
						redMana--;

					}
					else if (blueMana >= 1) {
						blueMana--;

					}


					if (greenMana >= 1) {
						greenMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blackMana >= 1) {
						blackMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (whiteMana >= 1) {
						whiteMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (redMana >= 1) {
						redMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blueMana >= 1) {
						blueMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}



				}

				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}














			while (name == "Hobgoblin") {

				if (redMana >= 1 && blackMana >= 1 && greenMana + blackMana + whiteMana + redMana + blueMana >= 3) {
					redMana--;
					blackMana--;

					if (greenMana >= 1) {
						greenMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blackMana >= 1) {
						blackMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (whiteMana >= 1) {
						whiteMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (redMana >= 1) {
						redMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blueMana >= 1) {
						blueMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}





				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}



			}











			while (name == "Vampire") {

				if (blackMana >= 1 && greenMana + blackMana + whiteMana + redMana + blueMana >= 4) {
					blackMana--;


					if (greenMana >= 1) {
						greenMana--;
					}
					else if (blackMana >= 1) {
						blackMana--;
					}
					else if (whiteMana >= 1) {
						whiteMana--;

					}
					else if (redMana >= 1) {
						redMana--;

					}
					else if (blueMana >= 1) {
						blueMana--;

					}

					if (greenMana >= 1) {
						greenMana--;
					}
					else if (blackMana >= 1) {
						blackMana--;
					}
					else if (whiteMana >= 1) {
						whiteMana--;

					}
					else if (redMana >= 1) {
						redMana--;

					}
					else if (blueMana >= 1) {
						blueMana--;

					}



					if (greenMana >= 1) {
						greenMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blackMana >= 1) {
						blackMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (whiteMana >= 1) {
						whiteMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (redMana >= 1) {
						redMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blueMana >= 1) {
						blueMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}




				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}


			}









			while (name == "Dishenchant") {
				if (whiteMana >= 2) {
					whiteMana -= 2;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && blackMana >= 1) {
					whiteMana--;
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && redMana >= 1) {
					whiteMana--;
					redMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && greenMana >= 1) {
					whiteMana--;
					greenMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && blueMana >= 1) {
					whiteMana--;
					blueMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}













			while (name == "LightningBolt") {
				int choice, c2 = 1;
				std::vector<int>tempArray;
				if (greenMana >= 2) {
					greenMana -= 2;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);


					while (1) {
						std::cout << "\nDo you want to deal 2 damage to player or a creature card(enter 1 for player,2 for creature card, 0 for cancel)\n";

						if (PlayerNum == 1) {

							std::cin >> choice;

							if (choice == 0) {
								break;
							}
							else if (choice != 1 || choice != 2) {
								std::cout << "\nPlease choose an appropriate number\n";
								continue;
							}


							if (choice == 1) {
								p2.takeDamage(2);
								break;
							}
							if (choice == 2) {
								std::cout << "\nPlease choice enemy creature\n";



								for (int c = 0; c < p2.CardsInPlayArray.size(); c++) {
									if (p2.CardsInPlayArray.at(c)->isCreature() == true) {

										std::cout << c2 << ". ";
										p2.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no creature to damage with your LightningBolt\n";
									continue;
								}



								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								p2.CardsInPlayArray.at(tempArray.at(choice - 1))->takeDamage(2);

								if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->isDestroyed() == true) {
									p2.DiscardPileArray.push_back(p2.CardsInPlayArray.at(tempArray.at(choice - 1)));
									p2.CardsInPlayArray.erase(p2.CardsInPlayArray.begin() + tempArray.at(choice - 1));

								}
								break;
							}


						}

						else if (PlayerNum == 2) {



							std::cin >> choice;

							if (choice == 0) {
								break;
							}
							else if (choice != 1 || choice != 2) {
								std::cout << "\nPlease choose an appropriate number\n";
								continue;
							}


							if (choice == 1) {
								p1.takeDamage(2);
								break;
							}
							if (choice == 2) {
								std::cout << "\nPlease choice enemy creature\n";



								for (int c = 0; c < p1.CardsInPlayArray.size(); c++) {
									if (p1.CardsInPlayArray.at(c)->isCreature() == true) {

										std::cout << c2 << ". ";
										p1.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no creature to damage with your LightningBolt\n";
									continue;
								}



								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								p1.CardsInPlayArray.at(tempArray.at(choice - 1))->takeDamage(2);

								if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->isDestroyed() == true) {
									p1.DiscardPileArray.push_back(p1.CardsInPlayArray.at(tempArray.at(choice - 1)));
									p1.CardsInPlayArray.erase(p1.CardsInPlayArray.begin() + tempArray.at(choice - 1));

								}
								break;
							}

						}

					}




					break;
				}
				else if (greenMana >= 1 && blackMana >= 1) {
					greenMana--;
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					while (1) {
						std::cout << "\nDo you want to deal 2 damage to player or a creature card(enter 1 for player,2 for creature card, 0 for cancel)\n";

						if (PlayerNum == 1) {

							std::cin >> choice;

							if (choice == 0) {
								break;
							}
							else if (choice != 1 || choice != 2) {
								std::cout << "\nPlease choose an appropriate number\n";
								continue;
							}


							if (choice == 1) {
								p2.takeDamage(2);
								break;
							}
							if (choice == 2) {
								std::cout << "\nPlease choice enemy creature\n";



								for (int c = 0; c < p2.CardsInPlayArray.size(); c++) {
									if (p2.CardsInPlayArray.at(c)->isCreature() == true) {

										std::cout << c2 << ". ";
										p2.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no creature to damage with your LightningBolt\n";
									continue;
								}



								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								p2.CardsInPlayArray.at(tempArray.at(choice - 1))->takeDamage(2);

								if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->isDestroyed() == true) {
									p2.DiscardPileArray.push_back(p2.CardsInPlayArray.at(tempArray.at(choice - 1)));
									p2.CardsInPlayArray.erase(p2.CardsInPlayArray.begin() + tempArray.at(choice - 1));

								}
								break;
							}


						}

						else if (PlayerNum == 2) {



							std::cin >> choice;

							if (choice == 0) {
								break;
							}
							else if (choice != 1 || choice != 2) {
								std::cout << "\nPlease choose an appropriate number\n";
								continue;
							}


							if (choice == 1) {
								p1.takeDamage(2);
								break;
							}
							if (choice == 2) {
								std::cout << "\nPlease choice enemy creature\n";



								for (int c = 0; c < p1.CardsInPlayArray.size(); c++) {
									if (p1.CardsInPlayArray.at(c)->isCreature() == true) {

										std::cout << c2 << ". ";
										p1.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no creature to damage with your LightningBolt\n";
									continue;
								}



								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								p1.CardsInPlayArray.at(tempArray.at(choice - 1))->takeDamage(2);

								if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->isDestroyed() == true) {
									p1.DiscardPileArray.push_back(p1.CardsInPlayArray.at(tempArray.at(choice - 1)));
									p1.CardsInPlayArray.erase(p1.CardsInPlayArray.begin() + tempArray.at(choice - 1));

								}
								break;
							}

						}

					}



					break;
				}
				else if (greenMana >= 1 && redMana >= 1) {
					greenMana--;
					redMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					while (1) {
						std::cout << "\nDo you want to deal 2 damage to player or a creature card(enter 1 for player,2 for creature card, 0 for cancel)\n";

						if (PlayerNum == 1) {

							std::cin >> choice;

							if (choice == 0) {
								break;
							}
							else if (choice != 1 || choice != 2) {
								std::cout << "\nPlease choose an appropriate number\n";
								continue;
							}


							if (choice == 1) {
								p2.takeDamage(2);
								break;
							}
							if (choice == 2) {
								std::cout << "\nPlease choice enemy creature\n";



								for (int c = 0; c < p2.CardsInPlayArray.size(); c++) {
									if (p2.CardsInPlayArray.at(c)->isCreature() == true) {

										std::cout << c2 << ". ";
										p2.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no creature to damage with your LightningBolt\n";
									continue;
								}



								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								p2.CardsInPlayArray.at(tempArray.at(choice - 1))->takeDamage(2);

								if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->isDestroyed() == true) {
									p2.DiscardPileArray.push_back(p2.CardsInPlayArray.at(tempArray.at(choice - 1)));
									p2.CardsInPlayArray.erase(p2.CardsInPlayArray.begin() + tempArray.at(choice - 1));

								}
								break;
							}


						}

						else if (PlayerNum == 2) {



							std::cin >> choice;

							if (choice == 0) {
								break;
							}
							else if (choice != 1 || choice != 2) {
								std::cout << "\nPlease choose an appropriate number\n";
								continue;
							}


							if (choice == 1) {
								p1.takeDamage(2);
								break;
							}
							if (choice == 2) {
								std::cout << "\nPlease choice enemy creature\n";



								for (int c = 0; c < p1.CardsInPlayArray.size(); c++) {
									if (p1.CardsInPlayArray.at(c)->isCreature() == true) {

										std::cout << c2 << ". ";
										p1.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no creature to damage with your LightningBolt\n";
									continue;
								}



								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								p1.CardsInPlayArray.at(tempArray.at(choice - 1))->takeDamage(2);

								if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->isDestroyed() == true) {
									p1.DiscardPileArray.push_back(p1.CardsInPlayArray.at(tempArray.at(choice - 1)));
									p1.CardsInPlayArray.erase(p1.CardsInPlayArray.begin() + tempArray.at(choice - 1));

								}
								break;
							}

						}

					}



					break;
				}
				else if (greenMana >= 1 && whiteMana >= 1) {
					greenMana--;
					whiteMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					while (1) {
						std::cout << "\nDo you want to deal 2 damage to player or a creature card(enter 1 for player,2 for creature card, 0 for cancel)\n";

						if (PlayerNum == 1) {

							std::cin >> choice;

							if (choice == 0) {
								break;
							}
							else if (choice != 1 || choice != 2) {
								std::cout << "\nPlease choose an appropriate number\n";
								continue;
							}


							if (choice == 1) {
								p2.takeDamage(2);
								break;
							}
							if (choice == 2) {
								std::cout << "\nPlease choice enemy creature\n";



								for (int c = 0; c < p2.CardsInPlayArray.size(); c++) {
									if (p2.CardsInPlayArray.at(c)->isCreature() == true) {

										std::cout << c2 << ". ";
										p2.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no creature to damage with your LightningBolt\n";
									continue;
								}



								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								p2.CardsInPlayArray.at(tempArray.at(choice - 1))->takeDamage(2);

								if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->isDestroyed() == true) {
									p2.DiscardPileArray.push_back(p2.CardsInPlayArray.at(tempArray.at(choice - 1)));
									p2.CardsInPlayArray.erase(p2.CardsInPlayArray.begin() + tempArray.at(choice - 1));

								}
								break;
							}


						}

						else if (PlayerNum == 2) {



							std::cin >> choice;

							if (choice == 0) {
								break;
							}
							else if (choice != 1 || choice != 2) {
								std::cout << "\nPlease choose an appropriate number\n";
								continue;
							}


							if (choice == 1) {
								p1.takeDamage(2);
								break;
							}
							if (choice == 2) {
								std::cout << "\nPlease choice enemy creature\n";



								for (int c = 0; c < p1.CardsInPlayArray.size(); c++) {
									if (p1.CardsInPlayArray.at(c)->isCreature() == true) {

										std::cout << c2 << ". ";
										p1.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no creature to damage with your LightningBolt\n";
									continue;
								}



								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								p1.CardsInPlayArray.at(tempArray.at(choice - 1))->takeDamage(2);

								if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->isDestroyed() == true) {
									p1.DiscardPileArray.push_back(p1.CardsInPlayArray.at(tempArray.at(choice - 1)));
									p1.CardsInPlayArray.erase(p1.CardsInPlayArray.begin() + tempArray.at(choice - 1));

								}
								break;
							}

						}

					}



					break;
				}
				else if (greenMana >= 1 && blueMana >= 1) {
					greenMana--;
					blueMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);

					while (1) {
						std::cout << "\nDo you want to deal 2 damage to player or a creature card(enter 1 for player,2 for creature card, 0 for cancel)\n";

						if (PlayerNum == 1) {

							std::cin >> choice;

							if (choice == 0) {
								break;
							}
							else if (choice != 1 || choice != 2) {
								std::cout << "\nPlease choose an appropriate number\n";
								continue;
							}


							if (choice == 1) {
								p2.takeDamage(2);
								break;
							}
							if (choice == 2) {
								std::cout << "\nPlease choice enemy creature\n";



								for (int c = 0; c < p2.CardsInPlayArray.size(); c++) {
									if (p2.CardsInPlayArray.at(c)->isCreature() == true) {

										std::cout << c2 << ". ";
										p2.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no creature to damage with your LightningBolt\n";
									continue;
								}



								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								p2.CardsInPlayArray.at(tempArray.at(choice - 1))->takeDamage(2);

								if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->isDestroyed() == true) {
									p2.DiscardPileArray.push_back(p2.CardsInPlayArray.at(tempArray.at(choice - 1)));
									p2.CardsInPlayArray.erase(p2.CardsInPlayArray.begin() + tempArray.at(choice - 1));

								}
								break;
							}


						}

						else if (PlayerNum == 2) {



							std::cin >> choice;

							if (choice == 0) {
								break;
							}
							else if (choice != 1 || choice != 2) {
								std::cout << "\nPlease choose an appropriate number\n";
								continue;
							}


							if (choice == 1) {
								p1.takeDamage(2);
								break;
							}
							if (choice == 2) {
								std::cout << "\nPlease choice enemy creature\n";



								for (int c = 0; c < p1.CardsInPlayArray.size(); c++) {
									if (p1.CardsInPlayArray.at(c)->isCreature() == true) {

										std::cout << c2 << ". ";
										p1.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no creature to damage with your LightningBolt\n";
									continue;
								}



								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								p1.CardsInPlayArray.at(tempArray.at(choice - 1))->takeDamage(2);

								if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->isDestroyed() == true) {
									p1.DiscardPileArray.push_back(p1.CardsInPlayArray.at(tempArray.at(choice - 1)));
									p1.CardsInPlayArray.erase(p1.CardsInPlayArray.begin() + tempArray.at(choice - 1));

								}
								break;
							}

						}

					}



					break;
				}



				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}






			while (name == "Flood") {
				int choice, c2 = 1;
				std::vector<int>tempArray;

				if (greenMana >= 1 && whiteMana >= 1 && greenMana + blackMana + whiteMana + redMana + blueMana >= 3) {
					greenMana--;
					whiteMana--;



					if (greenMana >= 1) {
						greenMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);


						while (1) {

							if (PlayerNum == 1) {
								std::cout << "\nPlease choose an enemy land to destroy\n";

								for (int c = 0; c < p2.CardsInPlayArray.size(); c++) {
									if (p2.CardsInPlayArray.at(c)->returnType() == "LandCard") {

										std::cout << c2 << ". ";
										p2.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no enemy land to destroy.\n";
									break;
								}


								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Forest") {
									p2.greenMana--;
								}
								else if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Island") {
									p2.blueMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Mountain") {
									p2.redMana--;
								}
								else if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Plain") {
									p2.whiteMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Swamp") {
									p2.blackMana--;
								}


								p2.DiscardPileArray.push_back(p2.CardsInPlayArray.at(tempArray.at(choice - 1)));
								p2.CardsInPlayArray.erase(p2.CardsInPlayArray.begin() + tempArray.at(choice - 1));
								break;




							}



							else if (PlayerNum == 2) {


								std::cout << "\nPlease choose an enemy land to destroy\n";

								for (int c = 0; c < p1.CardsInPlayArray.size(); c++) {
									if (p1.CardsInPlayArray.at(c)->returnType() == "LandCard") {

										std::cout << c2 << ". ";
										p1.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no enemy land to destroy.\n";
									break;
								}


								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Forest") {
									p1.greenMana--;
								}
								else if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Island") {
									p1.blueMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Mountain") {
									p1.redMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Plain") {
									p1.whiteMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Swamp") {
									p1.blackMana--;
								}


								p1.DiscardPileArray.push_back(p1.CardsInPlayArray.at(tempArray.at(choice - 1)));
								p1.CardsInPlayArray.erase(p1.CardsInPlayArray.begin() + tempArray.at(choice - 1));
								break;




							}



						}








						break;
					}
					else if (blackMana >= 1) {
						blackMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);



						while (1) {

							if (PlayerNum == 1) {
								std::cout << "\nPlease choose an enemy land to destroy\n";

								for (int c = 0; c < p2.CardsInPlayArray.size(); c++) {
									if (p2.CardsInPlayArray.at(c)->returnType() == "LandCard") {

										std::cout << c2 << ". ";
										p2.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no enemy land to destroy.\n";
									break;
								}


								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Forest") {
									p2.greenMana--;
								}
								else if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Island") {
									p2.blueMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Mountain") {
									p2.redMana--;
								}
								else if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Plain") {
									p2.whiteMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Swamp") {
									p2.blackMana--;
								}


								p2.DiscardPileArray.push_back(p2.CardsInPlayArray.at(tempArray.at(choice - 1)));
								p2.CardsInPlayArray.erase(p2.CardsInPlayArray.begin() + tempArray.at(choice - 1));
								break;




							}



							else if (PlayerNum == 2) {


								std::cout << "\nPlease choose an enemy land to destroy\n";

								for (int c = 0; c < p1.CardsInPlayArray.size(); c++) {
									if (p1.CardsInPlayArray.at(c)->returnType() == "LandCard") {

										std::cout << c2 << ". ";
										p1.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no enemy land to destroy.\n";
									break;
								}


								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Forest") {
									p1.greenMana--;
								}
								else if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Island") {
									p1.blueMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Mountain") {
									p1.redMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Plain") {
									p1.whiteMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Swamp") {
									p1.blackMana--;
								}


								p1.DiscardPileArray.push_back(p1.CardsInPlayArray.at(tempArray.at(choice - 1)));
								p1.CardsInPlayArray.erase(p1.CardsInPlayArray.begin() + tempArray.at(choice - 1));
								break;




							}



						}





						break;
					}
					else if (whiteMana >= 1) {
						whiteMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);




						while (1) {

							if (PlayerNum == 1) {
								std::cout << "\nPlease choose an enemy land to destroy\n";

								for (int c = 0; c < p2.CardsInPlayArray.size(); c++) {
									if (p2.CardsInPlayArray.at(c)->returnType() == "LandCard") {

										std::cout << c2 << ". ";
										p2.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no enemy land to destroy.\n";
									break;
								}


								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Forest") {
									p2.greenMana--;
								}
								else if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Island") {
									p2.blueMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Mountain") {
									p2.redMana--;
								}
								else if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Plain") {
									p2.whiteMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Swamp") {
									p2.blackMana--;
								}


								p2.DiscardPileArray.push_back(p2.CardsInPlayArray.at(tempArray.at(choice - 1)));
								p2.CardsInPlayArray.erase(p2.CardsInPlayArray.begin() + tempArray.at(choice - 1));
								break;




							}



							else if (PlayerNum == 2) {


								std::cout << "\nPlease choose an enemy land to destroy\n";

								for (int c = 0; c < p1.CardsInPlayArray.size(); c++) {
									if (p1.CardsInPlayArray.at(c)->returnType() == "LandCard") {

										std::cout << c2 << ". ";
										p1.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no enemy land to destroy.\n";
									break;
								}


								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Forest") {
									p1.greenMana--;
								}
								else if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Island") {
									p1.blueMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Mountain") {
									p1.redMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Plain") {
									p1.whiteMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Swamp") {
									p1.blackMana--;
								}


								p1.DiscardPileArray.push_back(p1.CardsInPlayArray.at(tempArray.at(choice - 1)));
								p1.CardsInPlayArray.erase(p1.CardsInPlayArray.begin() + tempArray.at(choice - 1));
								break;




							}



						}





						break;
					}
					else if (redMana >= 1) {
						redMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);





						while (1) {

							if (PlayerNum == 1) {
								std::cout << "\nPlease choose an enemy land to destroy\n";

								for (int c = 0; c < p2.CardsInPlayArray.size(); c++) {
									if (p2.CardsInPlayArray.at(c)->returnType() == "LandCard") {

										std::cout << c2 << ". ";
										p2.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no enemy land to destroy.\n";
									break;
								}


								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Forest") {
									p2.greenMana--;
								}
								else if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Island") {
									p2.blueMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Mountain") {
									p2.redMana--;
								}
								else if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Plain") {
									p2.whiteMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Swamp") {
									p2.blackMana--;
								}


								p2.DiscardPileArray.push_back(p2.CardsInPlayArray.at(tempArray.at(choice - 1)));
								p2.CardsInPlayArray.erase(p2.CardsInPlayArray.begin() + tempArray.at(choice - 1));
								break;




							}



							else if (PlayerNum == 2) {


								std::cout << "\nPlease choose an enemy land to destroy\n";

								for (int c = 0; c < p1.CardsInPlayArray.size(); c++) {
									if (p1.CardsInPlayArray.at(c)->returnType() == "LandCard") {

										std::cout << c2 << ". ";
										p1.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no enemy land to destroy.\n";
									break;
								}


								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Forest") {
									p1.greenMana--;
								}
								else if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Island") {
									p1.blueMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Mountain") {
									p1.redMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Plain") {
									p1.whiteMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Swamp") {
									p1.blackMana--;
								}


								p1.DiscardPileArray.push_back(p1.CardsInPlayArray.at(tempArray.at(choice - 1)));
								p1.CardsInPlayArray.erase(p1.CardsInPlayArray.begin() + tempArray.at(choice - 1));
								break;




							}



						}







						break;
					}
					else if (blueMana >= 1) {
						blueMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);




						while (1) {

							if (PlayerNum == 1) {
								std::cout << "\nPlease choose an enemy land to destroy\n";

								for (int c = 0; c < p2.CardsInPlayArray.size(); c++) {
									if (p2.CardsInPlayArray.at(c)->returnType() == "LandCard") {

										std::cout << c2 << ". ";
										p2.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no enemy land to destroy.\n";
									break;
								}


								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Forest") {
									p2.greenMana--;
								}
								else if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Island") {
									p2.blueMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Mountain") {
									p2.redMana--;
								}
								else if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Plain") {
									p2.whiteMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Swamp") {
									p2.blackMana--;
								}


								p2.DiscardPileArray.push_back(p2.CardsInPlayArray.at(tempArray.at(choice - 1)));
								p2.CardsInPlayArray.erase(p2.CardsInPlayArray.begin() + tempArray.at(choice - 1));
								break;




							}



							else if (PlayerNum == 2) {


								std::cout << "\nPlease choose an enemy land to destroy\n";

								for (int c = 0; c < p1.CardsInPlayArray.size(); c++) {
									if (p1.CardsInPlayArray.at(c)->returnType() == "LandCard") {

										std::cout << c2 << ". ";
										p1.CardsInPlayArray.at(c)->PrintNameAndStats();
										c2++;
										std::cout << "\n";
										tempArray.push_back(c);
									}
								}

								if (tempArray.size() == 0) {
									std::cout << "\nThere is no enemy land to destroy.\n";
									break;
								}


								std::cin >> choice;


								if (choice > tempArray.size() || choice <= 0) {
									std::cout << "\nPlease choose an appropriate number\n";
									continue;
								}



								if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Forest") {
									p1.greenMana--;
								}
								else if (p2.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Island") {
									p1.blueMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Mountain") {
									p1.redMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Plain") {
									p1.whiteMana--;
								}
								else if (p1.CardsInPlayArray.at(tempArray.at(choice - 1))->returnName() == "Swamp") {
									p1.blackMana--;
								}


								p1.DiscardPileArray.push_back(p1.CardsInPlayArray.at(tempArray.at(choice - 1)));
								p1.CardsInPlayArray.erase(p1.CardsInPlayArray.begin() + tempArray.at(choice - 1));
								break;




							}



						}





						break;
					}

				}


				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}






			while (name == "Reanimate") {
				if (blackMana >= 1) {
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
				}
			}









			while (name == "Plague") {
				if (blackMana >= 1 && greenMana + blackMana + whiteMana + redMana + blueMana >= 3) {
					blackMana--;

					if (greenMana >= 1) {
						greenMana--;
					}
					else if (blackMana >= 1) {
						blackMana--;
					}
					else if (whiteMana >= 1) {
						whiteMana--;

					}
					else if (redMana >= 1) {
						redMana--;

					}
					else if (blueMana >= 1) {
						blueMana--;

					}



					if (greenMana >= 1) {
						greenMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);











						break;
					}
					else if (blackMana >= 1) {
						blackMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (whiteMana >= 1) {
						whiteMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (redMana >= 1) {
						redMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blueMana >= 1) {
						blueMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}


				}


				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}









			while (name == "Terror") {
				if (blackMana >= 2) {
					blackMana -= 2;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (blackMana >= 1 && whiteMana >= 1) {
					whiteMana--;
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (blackMana >= 1 && greenMana >= 1) {
					greenMana--;
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (blackMana >= 1 && redMana >= 1) {
					redMana--;
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (blackMana >= 1 && blueMana >= 1) {
					blueMana--;
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}







			while (name == "Rage") {
				if (greenMana >= 1) {
					greenMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}










			while (name == "HolyWar") {
				if (whiteMana >= 2) {
					whiteMana -= 2;

					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && blackMana >= 1) {
					whiteMana--;
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && redMana >= 1) {
					whiteMana--;
					redMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && greenMana >= 1) {
					whiteMana--;
					greenMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && blueMana >= 1) {
					whiteMana--;
					blueMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}












			while (name == "HolyLight") {
				if (whiteMana >= 2) {
					whiteMana -= 2;

					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && blackMana >= 1) {
					whiteMana--;
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && redMana >= 1) {
					whiteMana--;
					redMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && greenMana >= 1) {
					whiteMana--;
					greenMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (whiteMana >= 1 && blueMana >= 1) {
					whiteMana--;
					blueMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}











			while (name == "UnholyWar") {
				if (blackMana >= 2) {
					blackMana -= 2;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (blackMana >= 1 && whiteMana >= 1) {
					whiteMana--;
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (blackMana >= 1 && greenMana >= 1) {
					greenMana--;
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (blackMana >= 1 && redMana >= 1) {
					redMana--;
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else if (blackMana >= 1 && blueMana >= 1) {
					blueMana--;
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}








			while (name == "Restrain") {

				if (redMana >= 1 && greenMana + blackMana + whiteMana + redMana + blueMana >= 3) {
					redMana--;

					if (greenMana >= 1) {
						greenMana--;
					}
					else if (blackMana >= 1) {
						blackMana--;
					}
					else if (whiteMana >= 1) {
						whiteMana--;

					}
					else if (redMana >= 1) {
						redMana--;

					}
					else if (blueMana >= 1) {
						blueMana--;

					}



					if (greenMana >= 1) {
						greenMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blackMana >= 1) {
						blackMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (whiteMana >= 1) {
						whiteMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (redMana >= 1) {
						redMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}
					else if (blueMana >= 1) {
						blueMana--;
						CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
						HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
						break;
					}


				}



				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}





			while (name == "Slow") {
				if (blackMana >= 1) {
					blackMana--;
					CardsInPlayArray.push_back(HandCardsArray.at(chosenCard - 1));
					HandCardsArray.erase(HandCardsArray.begin() + chosenCard - 1);
					break;
				}
				else {
					std::cout << "\nNot enough Mana\n" << std::endl;
					break;
				}
			}



		}


	}





	void takeDamage(int takenDamage) {
		std::cout << "\n\n";
		std::cout << "You took damage! Old HP: " << HP;
		HP -= takenDamage;
		std::cout << " New HP:" << HP;
		std::cout << "\n\n";
		if (HP <= 0) {
			std::cout << " \nYou died.\n";
			gameEnd = true;
			if (PlayerNum == 1) {
				winnerPlayerNum = 2;
			}
			else if (PlayerNum == 2) {
				winnerPlayerNum = 1;
			}
		}

	}




	void combatPhase(Player& defender) {

		int givenNum = -1;
		std::vector<int>creaturesCanAttack;
		std::vector<int>creaturesCanDefend;
		std::vector<int>chosenCardsToAttack;
		std::vector<int>chosenCardsToDefend;
		std::vector<int> alreadyChosenCardsDefender;

		int c2 = 1, c3 = 0;
		for (int c = 0; c < CardsInPlayArray.size(); c++) {

			if (CardsInPlayArray.at(c)->isCreature()) {
				c3++;
			}
		}
		if (c3 >= 1) {



			std::cout << "Player " << PlayerNum << "'s attack phase:\n\n";
			std::cout << "Player " << PlayerNum << ", these are your creature cards that you can attack with.\n\n";

			for (int c = 0; c < CardsInPlayArray.size(); c++) {

				if (CardsInPlayArray.at(c)->isCreature() == true) {
					std::cout << c2 << ". ";
					CardsInPlayArray.at(c)->PrintNameAndStats();
					c2++;
					creaturesCanAttack.push_back(c);
					std::cout << "\n";
				}
			}

			std::cout << "\nPlayer " << PlayerNum << ", please choose cards to attack with.(Enter '0' to start/pass your combat phase)\n";
			while (givenNum != 0)
			{
				bool check = false;


				std::cin >> givenNum;

				if (givenNum == 0) {
					break;
				}

				if (givenNum > creaturesCanAttack.size() || givenNum < 0) {
					std::cout << "\n\n\nERROR\n\n\n";
					continue;
				}

				if (CardsInPlayArray.at(creaturesCanAttack.at(givenNum - 1))->isTapped()) {
					std::cout << "\nThis card is tapped, you cant play this card.\n";
					continue;
				}




				/*
				std::cout << "DEBUG1";

				for (int c = 0; c < alreadyChosenCardsAttacker.size(); c++) {


					std::cout << "DEBUG2";
					if (alreadyChosenCardsAttacker.at(c) == givenNum) {
						std::cout << "You already choose this card.\n";
						check = true;
						break;
					}
				}

				if (check = true) {
					continue;
				}

				std::cout << "DEBUG3";

				alreadyChosenCardsAttacker.push_back(givenNum);
				*/


				chosenCardsToAttack.push_back(creaturesCanAttack.at(givenNum - 1));

				CardsInPlayArray.at(creaturesCanAttack.at(givenNum - 1))->tapCard();
			}


			if (chosenCardsToAttack.size() > 0) {


				std::cout << "Player " << defender.PlayerNum << "'s defend phase:\n";



				std::cout << "Enemy is attacking with these cards:\n";

				for (int c = 0; c < chosenCardsToAttack.size(); c++) {
					std::cout << c + 1 << ". ";
					CardsInPlayArray.at(chosenCardsToAttack.at(c))->PrintNameAndStats();
					std::cout << "\n";
				}
				c2 = 1;
				bool chck = false;
				std::cout << "\nPlayer " << defender.PlayerNum << ", these are your untapped cards  you can defend with. To defend, type its number.\n";
				for (int c = 0; c < defender.CardsInPlayArray.size(); c++) {
					if ((defender.CardsInPlayArray.at(c)->isCreature() == true) && (defender.CardsInPlayArray.at(c)->isTapped() == false)) {
						std::cout << c2 << ". ";
						defender.CardsInPlayArray.at(c)->PrintNameAndStats();
						c2++;
						creaturesCanDefend.push_back(c);
						std::cout << "\n";
						chck = true;
					}

				}

				if (defender.CardsInPlayArray.size() == 0 || chck == false) {
					std::cout << "\n\nYou have no creatures to defend.\n\n";
				}


				givenNum = -1;




				for (int c = 0; c < chosenCardsToAttack.size(); c++) {
					bool check = false;
					std::cout << "Player " << defender.PlayerNum << ", please choose card to defend this attacker.(Enter '0' for not defending this card)\n\n";
					CardsInPlayArray.at(chosenCardsToAttack.at(c))->PrintNameAndStats();
					std::cout << "\n";


					std::cin >> givenNum;




					if (givenNum == 0) {
						chosenCardsToDefend.push_back(0);
						continue;
					}
					else if (givenNum > creaturesCanDefend.size() || givenNum < 0) {
						while (givenNum > creaturesCanDefend.size() || givenNum <= 0) {

							std::cout << "\n\n\nPlease choose appropriate number.\n\n\n";
						}
					}

					if (givenNum == 0) {
						chosenCardsToDefend.push_back(0);
						continue;
					}

					for (int c = 0; c < alreadyChosenCardsDefender.size(); c++) {

						if (alreadyChosenCardsDefender.at(c) == givenNum) {
							std::cout << "You already choose this card.\n";
							check = true;
							break;
						}
					}
					if (check = true) {
						c--;
						continue;
					}

					alreadyChosenCardsDefender.push_back(givenNum);

					chosenCardsToDefend.push_back(creaturesCanDefend.at(givenNum - 1));

				}




				for (int c = 0; c < chosenCardsToAttack.size(); c++) {
					if (chosenCardsToDefend.at(c) != 0) {




						if (CardsInPlayArray.at(chosenCardsToAttack.at(c))->isFirstStrike() == true && defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->isFirstStrike() == true) {
							defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->takeDamage(CardsInPlayArray.at(chosenCardsToAttack.at(c))->returnAD());
							CardsInPlayArray.at(chosenCardsToAttack.at(c))->takeDamage(defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->returnAD());

							if ((CardsInPlayArray.at(chosenCardsToAttack.at(c))->isTrample() == true) && (defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->returnHP() < 0)) {


								defender.takeDamage(defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->returnHP() * (-1));


							}

						}
						else if (CardsInPlayArray.at(chosenCardsToAttack.at(c))->isFirstStrike() == true && defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->isFirstStrike() == false) {
							defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->takeDamage(CardsInPlayArray.at(chosenCardsToAttack.at(c))->returnAD());
							if (defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->isDestroyed() == false) {
								CardsInPlayArray.at(chosenCardsToAttack.at(c))->takeDamage(defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->returnAD());
							}

							if ((CardsInPlayArray.at(chosenCardsToAttack.at(c))->isTrample() == true) && (defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->returnHP() < 0)) {


								defender.takeDamage(defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->returnHP() * (-1));


							}


						}
						else if (CardsInPlayArray.at(chosenCardsToAttack.at(c))->isFirstStrike() == false && defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->isFirstStrike() == true) {
							CardsInPlayArray.at(chosenCardsToAttack.at(c))->takeDamage(defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->returnAD());
							if (CardsInPlayArray.at(chosenCardsToAttack.at(c))->isDestroyed() == false) {
								defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->takeDamage(defender.CardsInPlayArray.at(chosenCardsToAttack.at(c))->returnAD());
							}


							if ((CardsInPlayArray.at(chosenCardsToAttack.at(c))->isTrample() == true) && (defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->returnHP() < 0)) {

								if (CardsInPlayArray.at(chosenCardsToAttack.at(c))->isDestroyed() == false) {
									defender.takeDamage(defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->returnHP() * (-1));
								}

							}



						}
						else if (CardsInPlayArray.at(chosenCardsToAttack.at(c))->isFirstStrike() == false && defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->isFirstStrike() == false) {
							defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->takeDamage(CardsInPlayArray.at(chosenCardsToAttack.at(c))->returnAD());
							CardsInPlayArray.at(chosenCardsToAttack.at(c))->takeDamage(defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->returnAD());
						}


						if ((CardsInPlayArray.at(chosenCardsToAttack.at(c))->isTrample() == true) && (defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->returnHP() < 0)) {


							defender.takeDamage(defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->returnHP() * (-1));


						}



					}
					else {
						defender.takeDamage(CardsInPlayArray.at(chosenCardsToAttack.at(c))->returnAD());
					}

				}

				for (int c = 0; c < chosenCardsToAttack.size(); c++) {

					if (CardsInPlayArray.at(chosenCardsToAttack.at(c))->isDestroyed() == true) {
						DiscardPileArray.push_back(CardsInPlayArray.at(chosenCardsToAttack.at(c)));
						CardsInPlayArray.erase(CardsInPlayArray.begin() + chosenCardsToAttack.at(c));
					}

				}
				for (int c = 0; c < chosenCardsToDefend.size(); c++) {
					if (chosenCardsToDefend.at(c) != 0) {
						if (defender.CardsInPlayArray.at(chosenCardsToDefend.at(c))->isDestroyed() == true) {
							defender.DiscardPileArray.push_back(defender.CardsInPlayArray.at(chosenCardsToDefend.at(c)));
							defender.CardsInPlayArray.erase(defender.CardsInPlayArray.begin() + chosenCardsToDefend.at(c));
						}
					}


				}
			}
		}



	}

	void drawCard() {
		if (LibraryArray.size() >= 1) {

			if ((HandCardsArray.size()) < 7) {
				HandCardsArray.push_back(LibraryArray.at((LibraryArray.size()) - 1));
				LibraryArray.pop_back();
				std::cout << "You draw ";
				HandCardsArray.at((HandCardsArray.size()) - 1)->PrintNameAndStats();
				std::cout << "\n";
			}
			else {
				std::cout << "Your hand is full.\n";

			}

		}
		else {

			std::cout << "Your library is empty!\n";
			gameEnd = true;
			if (PlayerNum == 1) {
				winnerPlayerNum = 2;
			}
			else {
				winnerPlayerNum = 1;
			}

		}

	}

	void untapAllCardsAndRefreshMana(Player& p) {
		std::string name;
		int c;
		for (c = 0; c < CardsInPlayArray.size(); c++) {
			CardsInPlayArray.at(c)->unTapCard();
		}

		greenMana = 0;
		blueMana = 0;
		redMana = 0;
		whiteMana = 0;
		blackMana = 0;


		c = 0;

		for (c; c < CardsInPlayArray.size(); c++) {


			name = CardsInPlayArray.at(c)->returnName();


			if (name == "Forest") {
				greenMana++;
			}
			else if (name == "Island") {
				blueMana++;
			}
			else if (name == "Mountain") {
				redMana++;
			}
			else if (name == "Plain") {
				whiteMana++;
			}
			else if (name == "Swamp") {
				blackMana++;
			}

		}



	}

	void printHP() {
		std::cout << HP;
	}

	void shuffleDeck() {


		HandCardsArray.clear();
		CardsInPlayArray.clear();
		DiscardPileArray.clear();
		LibraryArray.clear();

		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::vector<int>randNumArray;
		randNumArray.reserve(27);
		for (int c = 1; c < 27; c++) {
			randNumArray.push_back(c);
		}
		shuffle(randNumArray.begin(), randNumArray.end(), std::default_random_engine(seed));





		if (PlayerNum == 1) {


			for (int c = 0; c < 26; c++) {


				switch (randNumArray[c]) {
				case 1:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Plain", "LandCard", "W"));
					break;
				case 2:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Plain", "LandCard", "W"));
					break;
				case 3:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Plain", "LandCard", "W"));
					break;
				case 4:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Plain", "LandCard", "W"));
					break;
				case 5:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Plain", "LandCard", "W"));
					break;
				case 6:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Forest", "LandCard", "G"));
					break;
				case 7:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Forest", "LandCard", "G"));
					break;
				case 8:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Forest", "LandCard", "G"));
					break;
				case 9:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Island", "LandCard", "L"));
					break;
				case 10:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("Soldier", "CreatureCard", "W", "White", 1, 1, false, false));
					break;
				case 11:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("Soldier", "CreatureCard", "W", "White", 1, 1, false, false));
					break;
				case 12:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("Soldier", "CreatureCard", "W", "White", 1, 1, false, false));
					break;
				case 13:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("ArmoredPegasus", "CreatureCard", "1W", "White", 1, 2, false, false));
					break;
				case 14:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("ArmoredPegasus", "CreatureCard", "1W", "White", 1, 2, false, false));
					break;
				case 15:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("WhiteKnight", "CreatureCard", "WW", "White", 2, 2, true, false));
					break;
				case 16:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("WhiteKnight", "CreatureCard", "WW", "White", 2, 2, true, false));
					break;
				case 17:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("AngryBear", "CreatureCard", "2G", "Green", 3, 2, false, true));
					break;
				case 18:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("Guard", "CreatureCard", "2WW", "White", 2, 5, false, false));
					break;
				case 19:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("Werewolf", "CreatureCard", "2GW", "Green", 4, 6, false, false));
					break;
				case 20:
					LibraryArray.push_back((std::shared_ptr<Card>)new sorceryCard("Disenchant", "SorceryCard", "1W", "Destroy 1 Target Enchantment"));
					break;
				case 21:
					LibraryArray.push_back((std::shared_ptr<Card>)new sorceryCard("LightningBold", "SorceryCard", "1G", "Deal 2 dmg to target creature or player"));
					break;
				case 22:
					LibraryArray.push_back((std::shared_ptr<Card>)new sorceryCard("Flood", "SorceryCard", "1GW", "Destroy 1 Target Land"));
					break;
				case 23:
					LibraryArray.push_back((std::shared_ptr<Card>)new sorceryCard("Flood", "SorceryCard", "1GW", "Destroy 1 Target Land"));
					break;
				case 24:
					LibraryArray.push_back((std::shared_ptr<Card>)new enchantmentCard("Rage", "EnchantmentCard", "G", "1 Target creature gains Trample"));
					break;
				case 25:
					LibraryArray.push_back((std::shared_ptr<Card>)new enchantmentCard("HolyWar", "EnchantmentCard", "1W", "All white creatures gain +1/+1"));
					break;
				case 26:
					LibraryArray.push_back((std::shared_ptr<Card>)new enchantmentCard("HolyLight", "EnchantmentCard", "1W", "All black creatures gain -1/-1"));
					break;


				}

			}

		}


		else if (PlayerNum == 2) {

			for (int c = 0; c < 26; c++) {


				switch (randNumArray[c]) {
				case 1:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Swamp", "LandCard", "B"));
					break;
				case 2:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Swamp", "LandCard", "B"));
					break;
				case 3:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Swamp", "LandCard", "B"));
					break;
				case 4:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Swamp", "LandCard", "B"));
					break;
				case 5:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Swamp", "LandCard", "B"));
					break;
				case 6:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Mountain", "LandCard", "R"));
					break;
				case 7:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Mountain", "LandCard", "R"));
					break;
				case 8:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Mountain", "LandCard", "R"));
					break;
				case 9:
					LibraryArray.push_back((std::shared_ptr<Card>)new landCard("Island", "LandCard", "L"));
					break;
				case 10:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("Skeleton", "CreatureCard", "B", "Black", 1, 1, false, false));
					break;
				case 11:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("Skeleton", "CreatureCard", "B", "Black", 1, 1, false, false));
					break;
				case 12:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("Skeleton", "CreatureCard", "B", "Black", 1, 1, false, false));
					break;
				case 13:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("Ghost", "CreatureCard", "1B", "Black", 2, 1, false, false));
					break;
				case 14:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("Ghost", "CreatureCard", "1B", "Black", 2, 1, false, false));
					break;
				case 15:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("BlackKnight", "CreatureCard", "BB", "Black", 2, 2, true, false));
					break;
				case 16:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("BlackKnight", "CreatureCard", "BB", "Black", 2, 2, true, false));
					break;
				case 17:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("OrcManiac", "CreatureCard", "2R", "Red", 4, 1, false, false));
					break;
				case 18:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("Hobgoblin", "CreatureCard", "1RB", "Red", 3, 3, false, false));
					break;
				case 19:
					LibraryArray.push_back((std::shared_ptr<Card>)new creatureCard("Vampire", "CreatureCard", "3B", "Black", 6, 3, false, false));
					break;
				case 20:
					LibraryArray.push_back((std::shared_ptr<Card>)new sorceryCard("Reanimate", "SorceryCard", "B", "Return 1 character card from discard to hand"));
					break;
				case 21:
					LibraryArray.push_back((std::shared_ptr<Card>)new sorceryCard("Plague", "SorceryCard", "2B", "Deal 1 dmg to all creatures"));
					break;
				case 22:
					LibraryArray.push_back((std::shared_ptr<Card>)new sorceryCard("Terror", "SorceryCard", "1B", "Destroy 1 Target Creature"));
					break;
				case 23:
					LibraryArray.push_back((std::shared_ptr<Card>)new sorceryCard("Terror", "SorceryCard", "1B", "Destroy 1 Target Creature"));
					break;
				case 24:
					LibraryArray.push_back((std::shared_ptr<Card>)new enchantmentCard("UnholyWar", "EnchantmentCard", "1B", "All black creatures gain +2/+0"));
					break;
				case 25:
					LibraryArray.push_back((std::shared_ptr<Card>)new enchantmentCard("Restrain", "EnchantmentCard", "2R", "All green creatures lose Trample"));
					break;
				case 26:
					LibraryArray.push_back((std::shared_ptr<Card>)new enchantmentCard("Slow", "EnchantmentCard", "B", "1 Target creature loses First Strike"));
					break;


				}

			}

		}



	}
	void displayCurrentStateForP1(Player& p1, Player& p2) {


		std::cout << "Your cards in play:\n";
		for (int c = 0; c < p1.CardsInPlayArray.size(); c++) {
			std::cout << c + 1 << ". ";
			p1.CardsInPlayArray.at(c)->PrintNameAndStats();
			std::cout << "\n";
		}
		std::cout << "\n";
		std::cout << "Enemy cards in play:\n";
		for (int c = 0; c < p2.CardsInPlayArray.size(); c++) {
			std::cout << c + 1 << ". ";
			p2.CardsInPlayArray.at(c)->PrintNameAndStats();
			std::cout << "\n";
		}
		std::cout << "\n";

		std::cout << "Your cards in hand\n";
		for (int c = 0; c < p1.HandCardsArray.size(); c++) {
			std::cout << c + 1 << ". ";
			p1.HandCardsArray.at(c)->PrintNameAndStats();
			std::cout << "\n";
		}
		std::cout << "\n";


		std::cout << "Your mana:" << "\nG: " << p1.greenMana << "\nB: " << p1.blackMana << "\nW: " << p1.whiteMana << "\nR: " << p1.redMana << "\nL: " << p1.blueMana << "\n";

		std::cout << "Your HP: ";
		p1.printHP();
		std::cout << "\nEnemy HP: ";
		p2.printHP();

	}

	void displayCurrentStateForP2(Player& p1, Player& p2) {
		std::cout << "Your cards in play:\n";
		for (int c = 0; c < p2.CardsInPlayArray.size(); c++) {
			std::cout << c + 1 << ". ";
			p2.CardsInPlayArray.at(c)->PrintNameAndStats();
			std::cout << "\n";
		}
		std::cout << "\n";
		std::cout << "Enemy cards in play:\n";
		for (int c = 0; c < p1.CardsInPlayArray.size(); c++) {
			std::cout << c + 1 << ". ";
			p1.CardsInPlayArray.at(c)->PrintNameAndStats();
			std::cout << "\n";
		}
		std::cout << "\n";

		std::cout << "Your cards in hand\n";
		for (int c = 0; c < p2.HandCardsArray.size(); c++) {
			std::cout << c + 1 << ". ";
			p2.HandCardsArray.at(c)->PrintNameAndStats();
			std::cout << "\n";
		}
		std::cout << "\n";

		std::cout << "Your mana:" << "\nG: " << p2.greenMana << "\nB: " << p2.blackMana << "\nW: " << p2.whiteMana << "\nR: " << p2.redMana << "\nL: " << p2.blueMana << "\n";

		std::cout << "Your HP: ";
		p2.printHP();
		std::cout << "\nEnemy HP: ";
		p1.printHP();

	}


	void cardsRegainHP() {
		int c;
		for (c = 0; c < CardsInPlayArray.size(); c++) {
			CardsInPlayArray.at(c)->returnToMaxHP();
		}
	}



};




int main()
{
	int round = 1;

	std::cout << "Magic The Gathering Lite\n\n";
	system("pause");
	std::cout << "\n\n";


	Player player1(1), player2(2);



	while ((gameEnd == false) && (playAgain == true)) {

		std::cout << "\n***Round " << round << "***\n\n";
		std::cout << "\n**Player 1's Turn:**\n\n";
		player1.displayCurrentStateForP1(player1, player2);
		if (round != 1) {
			std::cout << "\n*Phase 1: Draw*\n\n";
			player1.drawCard();
			if (gameEnd) {
				continue;
			}
		}

		player1.untapAllCardsAndRefreshMana(player1);
		std::cout << "\n*Phase 2: Play*\n\n";
		player1.playPhase(round, player1, player2);
		std::cout << "\n*Phase 3: Combat*\n\n";
		player1.combatPhase(player2);
		if (gameEnd) {
			continue;
		}
		std::cout << "\n*Phase 4: Play*\n\n";
		player1.playPhase(round, player1, player2);
		std::cout << "\n*Player 1's Round is over.*\n\n";


		std::cout << "\n**Player 2's Turn:**\n\n";
		player2.displayCurrentStateForP2(player1, player2);
		if (round != 1) {
			std::cout << "\n*Phase 1: Draw*\n\n";
			player2.drawCard();
			if (gameEnd) {
				continue;
			}
		}

		player2.untapAllCardsAndRefreshMana(player2);
		std::cout << "\n*Phase 2: Play*\n\n";
		player2.playPhase(round, player1, player2);
		std::cout << "\n*Phase 3: Combat*\n\n";
		player2.combatPhase(player1);
		if (gameEnd) {
			continue;
		}
		std::cout << "\n*Phase 4: Play*\n\n";
		player2.playPhase(round, player1, player2);
		std::cout << "\nPlayer 2's round is over.*\n\n";


		std::cout << "**End of round** " << round << "\n\n";
		round += 1;
		player1.cardsRegainHP();
		player2.cardsRegainHP();


		if (gameEnd == true) {
			char choice;

			std::cout << "The game has ended.\n\nPlayer " << winnerPlayerNum << " Won!\n\n Remaining HP of Player1: ";
			player1.printHP();
			std::cout << "\nRemaining HP of Player2: ";
			player2.printHP();
			std::cout << "\n\nWould you like to play again ? y, n\n";
			std::cin >> choice;
			std::cout << "\n";
			if (choice == 'y') {
				playAgain = true;
				gameEnd = false;
				player1 = Player(1);
				player2 = Player(2);
				std::cout << "Game is starting\n\n";
			}
			else if (choice == 'n') {
				playAgain == false;
				std::cout << "Thanks for playing!\n\n";
			}
		}

	}


	system("pause");


}