// Maurizio Brancato // Samuel Noel // Christopher Hebert
// Nov 26, 2017
// Exam four

#define _CRT_SECURE_NO_WARNINGS  //turns off switch
#define PAUSE system("pause") // pause screen
#define CLS system("cls") // clears the screen
#define FLUSH myFlush() // clears the keyboard buffer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20
#include <time.h>
#include <math.h>

void myFlush();

/////////// SLOT MACHINE PROTOTYPES ///////////////////////////////////

int getRanNum();
void jackpot();
void myFlush();
int slotMachine(int);
int slotMachineMenu(int);
void slotRules();

////////////// BLACKJACK PROTOTYPES ////////////////////////////////

// Card Prototypes
void heartA();
void heart2();
void heart3();
void heart4();
void heart5();
void heart6();
void heart7();
void heart8();
void heart9();
void heart10();
void heart11();
void heart12();
void heart13();
void diamondA();
void diamond2();
void diamond3();
void diamond4();
void diamond5();
void diamond6();
void diamond7();
void diamond8();
void diamond9();
void diamond10();
void diamond11();
void diamond12();
void diamond13();
void spadesA();
void spades2();
void spades3();
void spades4();
void spades5();
void spades6();
void spades7();
void spades8();
void spades9();
void spades10();
void spades11();
void spades12();
void spades13();
void clubsA();
void clubs2();
void clubs3();
void clubs4();
void clubs5();
void clubs6();
void clubs7();
void clubs8();
void clubs9();
void clubs10();
void clubs11();
void clubs12();
void clubs13();
//======================================================================================
// Function Prototypes
int aceDrawn(int, int);
int blackJack(int);
int blackJackMenu(int);
int blackJackProgram(int);
void blackJackRules();
int drawFunction(int[], int, int[], int, int, int);
void displayHand(int[], int);

/////// POKER PROTOTYPES //////////////////////////////////////////////////////

void pokerGame();
void showCardsonHand(char cardA1[], char cardA2[], char cardA3[], char cardA4[], char cardA5[], char cardA6[], char cardB1[], char cardB2[], char cardB3[], char cardB4[], char cardB5[], char cardB6[]);
void firstCardOfPlayer(int theRandNumber, char cardA1[], char cardA2[], char cardA3[], char cardA4[], char cardA5[], char cardA6[]);
void secondCardOfPlayer(int theRandNumber2, char cardB1[], char cardB2[], char cardB3[], char cardB4[], char cardB5[], char cardB6[]);
void firstCardOnTable(int theRandNumber3, char cardC1[], char cardC2[], char cardC3[], char cardC4[], char cardC5[], char cardC6[]);
void secondCardOnTable(int theRandNumber4, char cardD1[], char cardD2[], char cardD3[], char cardD4[], char cardD5[], char cardD6[]);
void thirdCardOnTable(int theRandNumber5, char cardE1[], char cardE2[], char cardE3[], char cardE4[], char cardE5[], char cardE6[]);
void fourthCardOnTable(int theRandNumber6, char cardF1[], char cardF2[], char cardF3[], char cardF4[], char cardF5[], char cardF6[]);
void firstCardOfOpponent(int theRandNumber7, char cardG1[], char cardG2[], char cardG3[], char cardG4[], char cardG5[], char cardG6[]);
void secondCardOfOpponent(int theRandNumber8, char cardH1[], char cardH2[], char cardH3[], char cardH4[], char cardH5[], char cardH6[]);
void showCardsOnTableA(char cardC1[], char cardC2[], char cardC3[], char cardC4[], char cardC5[], char cardC6[]);
void showCardsOnTableB(char cardC1[], char cardC2[], char cardC3[], char cardC4[], char cardC5[], char cardC6[], char cardD1[], char cardD2[], char cardD3[], char cardD4[], char cardD5[], char cardD6[]);
void showCardsOnTableC(char cardC1[], char cardC2[], char cardC3[], char cardC4[], char cardC5[], char cardC6[], char cardD1[], char cardD2[], char cardD3[], char cardD4[], char cardD5[], char cardD6[], char cardE1[], char cardE2[], char cardE3[], char cardE4[], char cardE5[], char cardE6[]);
void showCardsOnTable(char cardC1[], char cardC2[], char cardC3[], char cardC4[], char cardC5[], char cardC6[], char cardD1[], char cardD2[], char cardD3[], char cardD4[], char cardD5[], char cardD6[], char cardE1[], char cardE2[], char cardE3[], char cardE4[], char cardE5[], char cardE6[], char cardF1[], char cardF2[], char cardF3[], char cardF4[], char cardF5[], char cardF6[]);
void showCardsopponent(char cardG1[], char cardG2[], char cardG3[], char cardG4[], char cardG5[], char cardG6[], char cardH1[], char cardH2[], char cardH3[], char cardH4[], char cardH5[], char cardH6[]);
void firstValuesOfPlayer(int theRandNumber, float numa1, float numa2, float colora);
void secondValueOfPlayer(int theRandNumber2, float numb1, float numb2, float colorb);
void firstValueOnTable(int theRandNumber3, float numc1, float numc2, float colorc);
void secondValueOnTable(int theRandNumber4, float numd1, float numd2, float colord);
void thirdValueOnTable(int theRandNumber5, float nume1, float nume2, float colore);
void fourthValueOnTable(int theRandNumber6, float numf1, float numf2, float colorf);
void firstValueOfOpponent(int theRandNumber7, float numg1, float numg2, float colorg);
void secondValueOfOpponent(int theRandNumber8, float numh1, float numh2, float colorh);
void winningSystem(int userMoney, int betAmount, int betcount, float numa1, float numa2, float colora, float numb1, float numb2, float colorb, float numc1, float numc2, float colorc, float numd1, float numd2, float colord, float nume1, float nume2, float colore, float numf1, float numf2, float colorf, float numg1, float numg2, float colorg, float numh1, float numh2, float colorh);
char endGame();

////////////// MAIN //////////////////////////////////////////////////////////////


main() {
	int userChoice=0;
	int cash = 200;
	srand((unsigned)time(NULL));

	do {

		printf("\n\t***********************\n");
		printf("\t*****  MAIN MENU  *****\n");
		printf("\t***********************\n");
		printf("\t ENTER 1 TO PLAY SLOT MACHINE\n");
		printf("\t ENTER 2 TO PLAY BLACKJACK\n");
		printf("\t ENTER 3 TO PLAY POKER\n");
		printf("\tEnter 4 to quit\n");
		printf("\n\tEnter your selection: ");

		// Get User Choice
		scanf("%i", &userChoice); FLUSH;
		userChoice = toupper(userChoice); // Makes user input uppercase

		switch (userChoice)
		{
		case 1:
			cash = slotMachineMenu(cash);
			break;
		case 2:
			cash = blackJackProgram(cash);
			break;
		case 3:
			pokerGame();
			break;
		case 4:
			printf("\n\n\t thank you for playing in our casino!!\n\n");
			
			break;
		default: printf("wrong input, enter a number from 1 to 4...");
		}
getchar();
		CLS; 
		
	} while (userChoice != 4);
	
	
}

void myFlush() {
	while (getchar() != '\n');
}


///// FUNCTIONS  SLOT MACHINE //////////////////////////////////////

void slotRules() {
	CLS;
	printf("=============\n");
	printf(" How to Play\n");
	printf("=============\n");
	printf("\n\tThe slot machine consists of three windows each containing a number.\n");
	printf("\tOnce the lever is pulled the numbers will be randomly generated between 1-7.\n");
	printf("\tEach pull of the lever will cost you $10, however you only need to match 2 numbers to win.\n");
	printf("\tYou will win in each of these circumstances:\n");
	printf("\t\twhen you match 2 numbers, 3 numbers, and match all 3 7's.\n");
	printf("\tThe prizes are as follows:\n");
	printf("\t\t2 Numbers: $15\n");
	printf("\t\t3 Numbers: $200\n");
	printf("\t\t3 7's: JACKPOT = $1,000\n");
	PAUSE;

}

int slotMachineMenu(int cash) {
	int menuChoice = 0;
	do {
		CLS;
		printf("\t =====================\t\t===================\n");
		printf("\t = Slot Machine Menu =\t\t cash: %i\n", cash);
		printf("\t =====================\t\t===================\n");
		printf("\t 1. Play Slots!\n");
		printf("\t 2. Rules & How to play.\n");
		printf("\t 3. Quit.\n\t");
		printf("Select option(1-3): ");
		scanf("%i", &menuChoice);
		FLUSH;

		switch (menuChoice) {
		case 1:
			cash = slotMachine(cash);
			break;
		case 2:
			slotRules();
			break;
		case 3:
			printf("=================================");
			printf("= Thanks for playing the slots! =");
			printf("=================================");
			PAUSE;
			break;
		default:
			printf("Invalid selection please choose from options 1-3");
			break;
		}
	} while (menuChoice != 3);
}

int slotMachine(int cash) {
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	char slotChoice = 'Y'; //choice to keep playing
	int cashWon = 0;



	do {
		CLS;
		printf("\t  ============ cash: $%i ================\n", cash);
		printf("\t=============== Welcome!! ===================\n");
		printf("\t=============================================\n");
		printf("\t===============SLOT MACHINE==================\n");
		printf("\t=============================================\n");
		printf("\n");
		printf("\t\t===!!!JACKPOT BABY!!!===\n");
		printf("\t\t========================\n");
		printf("\t\t=== 0 === 0 === 0 ===\n");
		printf("\t\t========================\n");
		printf("\t\t===!!!JACKPOT BABY!!!===\n");
		printf("\n");
		printf("\t=============================================\n");
		printf("\t===============SLOT MACHINE==================\n");
		printf("\t=============================================\n");
		printf("** Press 'enter' to pull the lever and spin the slots **\n");
		PAUSE;


		num1 = getRanNum();
		num2 = getRanNum();
		num3 = getRanNum();
		cash = cash - 10;
		cashWon = cashWon - 10;
		CLS;
		printf("\t  ============ cash: $%i ================\n", cash);
		printf("\t=============================================\n");
		printf("\t===============SLOT MACHINE==================\n");
		printf("\t=============================================\n");
		printf("\n");
		printf("\t\t===!!!JACKPOT BABY!!!===\n");
		printf("\t\t========================\n");
		printf("\t\t=== %i === %i === %i ===\n", num1, num2, num3);
		printf("\t\t========================\n");
		printf("\t\t===!!!JACKPOT BABY!!!===\n");
		printf("\n");
		printf("\t=============================================\n");
		printf("\t===============SLOT MACHINE==================\n");
		printf("\t=============================================\n");

		PAUSE;
		CLS;



		if (num1 == num2 && num1 == num3) {
			if (num1 == 7 && num2 == 7 && num3 == 7) {
				CLS;
				jackpot();
				cash = cash + 1000;
				cashWon = cashWon + 1000;
				printf("You won the jackpot of $1000!! Your cash now equals #%i\n", cash);
				PAUSE;
			}
			else {
				CLS;
				cash = cash + 200;
				cashWon = cashWon + 200;
				printf("YOU WON $200!! Your cash now equals #%i\n", cash);
				PAUSE;
			}
		}

		if (num1 == num2 && num1 != num3) {
			CLS;
			cash = cash + 15;
			cashWon = cashWon + 15;
			printf("you won $15! your cash now equals $%i\n", cash);
			PAUSE;
		}
		if (num1 == num3 && num1 != num2) {
			CLS;
			cash = cash + 15;
			cashWon = cashWon + 15;
			printf("you won $15! your cash now equals $%i\n", cash);
			PAUSE;
		}
		if (num2 == num3 && num2 != num1) {
			CLS;
			cash = cash + 15;
			cashWon = cashWon + 15;
			printf("you won $15! your cash now equals $%i\n", cash);
			PAUSE;
		}
		if (num1 != num2 && num2 != num3 && num1 != num3) {
			cashWon = cashWon - 10;
			CLS;
			printf("No win. better luck next time! cash equals $%i\n", cash);
			PAUSE;
		}

		printf("\nwould you like to play again? [Y]es or [N]o?\n");
		scanf("%c", &slotChoice);
		slotChoice = toupper(slotChoice);
		FLUSH;
		while (slotChoice != 'Y' && slotChoice != 'N') {
			CLS;
			printf("Invalid selection. Plese input 'Y' to play again or 'N' to quit.\n");
			scanf("%c", slotChoice);
			FLUSH;
			slotChoice = toupper(slotChoice);
		}

		if (cash == 0) {
			slotChoice = 'N';
		}
	} while (slotChoice == 'Y');
	return cash;
}

int getRanNum() {
	int result;
	int UB = 7, LB = 1;
	result = LB + rand() % (UB - LB + 1);
	return result;
}

void jackpot() {

	printf("                                                                                                          \n");
	printf("     o999999o      o999999o             O99999999999o                                                     \n");
	printf("     o999999o     o999999o           o999999999999999999o             o9999999o                o9999999o  \n");
	printf("     o999999o     o999999o        o9999999o       o9999999o           o9999999o                o9999999o  \n");
	printf("     o999999o     o999999o       o9999999o         o99999999oo        o9999999o                o9999999o  \n");
	printf("      o99999999999999999o      o9999999o            o9999999o        o9999999o                 o9999999o  \n");
	printf("        o99999999999o          o9999999o             o9999999o        o9999999o                o9999999o  \n");
	printf("           o999999o             o9999999o           o9999999o         o9999999o               o9999999o   \n");
	printf("           o999999o               o9999999o        o99999999o           o9999999o            o9999999o    \n");
	printf("           o999999o                 o999999o      o999999999o            o9999999o         o9999999o      \n");
	printf("           o999999o                   o99999999999999999o                  o9999999o      o99999999o      \n");
	printf("           o999999o                     o9999999999999o                       o99999999999999999o         \n");
	printf("           o999999o                                                            o999999999999999o          \n");
	printf("\n");
	printf("\n");
	printf("                                                         o99999o         o99999999999o           o999999o \n");
	printf("     o999999o                        o9999999o          o9999999o        o9999999999999o         o999999o \n");
	printf("     o999999o                        o9999999o           o99999o         o99999999999999o        o999999o \n");
	printf("     o999999o                        o9999999o                           o9999999o o999999o      o999999o \n");
	printf("     o999999o                        o9999999o          o9999999o        o9999999o   o99999o     o999999o \n");
	printf("     o999999o                        o9999999o          o9999999o        o9999999o    o99999o    o999999o \n");
	printf("     o999999o                        o9999999o          o9999999o        o9999999o     o99999o   o999999o \n");
	printf("     o999999o        o9999o          o999999O           o9999999o        o9999999o      o99999o  o999999o \n");
	printf("     o999999o       o999999o        o99999999o          o9999999o        o9999999o        o9999999999999o \n");
	printf("     o99999999ooooo9999999999ooooooo999999999o          o9999999o        o9999999o         o999999999999o \n");
	printf("     o999999999999999999999999999999999999999o          o9999999o        o9999999o          o99999999999o \n");
	printf("      o999999999999999999999999999999999999o            o9999999o        o9999999o           o9999999999o \n");
	printf("                                                                                                          \n");


}

//////// FUNCTIONS BLACKJACK //////////////////////////////////////////////////


int aceDrawn(int hand, int identity) {
	int ace;
	if (identity == 0) {
		if (hand < 11) {
			ace = 11;
		}
		else {
			ace = 1;
		}
	}
	else {
		printf("You have drawn an ACE! Current hand total is %i. Would you like the card to value 1 or 11?", hand);
		scanf("%i", &ace);
		while (ace != 1 && ace != 11) {
			printf("Invalid input please enter the value you wish: '1' or '11'");
			scanf("%i", &ace);
		}

		hand = hand + ace;
	}
	return hand;

}
//decides or asks player to choose 1 or 11

int blackJack(int cash) {
	char blackjackReplay = 'Y';//indicates play again

	do {

		int cardsInHand[52] = { 0 }, houseHand[52] = { 0 };//stores player and house hands
		int hand = 0, numDraw = 0, counter = 0, bet = 0;//player hand value and number of draws
		int house = 0, houseDraw = 0, houseChoice = 0; //house hand value, number of draws, and choice to stay
		int  overallDraw = 0, previous[52] = { 0 };// overall draws and all cards drawn from deck
		char choice = 'H';// indicates hit or stay
		int endLoop = 0;
		int player = 1, computer = 0;// signals weather player or computer
									 //initial draw

		CLS;
		printf("\t===============================\n");
		printf("\twelcome to the Blackjack table!\n");
		printf("\t===============================\n");
		printf("\tYou have $%i. How much would you like to bet this round? $", cash);
		scanf("%i", &bet);
		while (bet > 50) {
			CLS;
			printf("\tSorry invalid bet amount. House limits bets to no more than $50 for Blackjack.\n");
			printf("\tPlease enter a valid bet amount.\n\t$");
			scanf("%i", &bet);
		}
		FLUSH;
		printf("\tThe round will begin with the dealers draw.\n");
		PAUSE;
		CLS;
		printf("**House Hand**\n");
		house = drawFunction(houseHand, house, previous, houseDraw, overallDraw, computer);
		houseDraw++;
		overallDraw++;

		house = drawFunction(houseHand, house, previous, houseDraw, overallDraw, computer);
		houseDraw++;
		overallDraw++;
		PAUSE;
		CLS;
		printf("**Your Hand**\n");
		hand = drawFunction(cardsInHand, hand, previous, numDraw, overallDraw, player);
		numDraw++;
		overallDraw++;

		hand = drawFunction(cardsInHand, hand, previous, numDraw, overallDraw, player);
		numDraw++;
		overallDraw++;
		PAUSE;

		do {
			if (choice != 'S') {
				CLS;
				printf("=============\n");
				printf("= Your Hand =\n");
				printf("=============\n");
				displayHand(cardsInHand, numDraw);
				printf("\tYour hand total is currently %i.\n", hand);
				printf("\t======================================\n");
				printf("\t= Would you like to [H]it or [S]tay? =\n");
				printf("\t======================================\n");
				scanf("%c", &choice);
				choice = toupper(choice);
				FLUSH;
				while (choice != 'H' && choice != 'S') {
					printf("\n\tInvalid input please input either 'H' for HIT or 'S' for STAY? ");
					scanf("%c", &choice);
					choice = toupper(choice);
					FLUSH;
				}

				if (choice == 'H') {
					CLS;
					printf("**Your Draw**\n");
					hand = drawFunction(cardsInHand, hand, previous, numDraw, overallDraw, player);
					numDraw++;
					overallDraw++;
					PAUSE;
					CLS;
					printf("**Your current hand**\n");
					displayHand(cardsInHand, numDraw);
					printf("\tYour hand currently equals %i.\n", hand);
					printf("\tIt is now the houses turn, please ");
					PAUSE;
				}
				else {
					CLS;
					printf("\tYou Have chosen to stay. The house will now play their turn.\n");
					PAUSE;
				}
			}
			if (hand < 21) {
				if (house < 17) {
					CLS;
					printf("**House draw**\n");
					house = drawFunction(houseHand, house, previous, houseDraw, overallDraw, computer);
					houseDraw++;
					overallDraw++;
					PAUSE;
					CLS;
					printf("==============\n");
					printf("= House Hand =\n");
					printf("==============\n");
					displayHand(houseHand, houseDraw);
					printf("\tHouse hand currently equals %i.\n", house);
					printf("\t=================================\n");
					PAUSE;
				}
				else {
					CLS;
					displayHand(houseHand, houseDraw);
					printf("\tHouse hand equals %i. House Stays\n", house);
					printf("\t===================================\n");
					houseChoice = 1;
					PAUSE;
				}
			}
			if (house > 21 || hand > 21) {
				houseChoice = 1;
				choice = 'S';
			}
			if (choice == 'S' && houseChoice == 1)
				endLoop = 1;


		} while (endLoop != 1);

		if (house > hand) {
			if (house > 21) {
				CLS;
				printf("House hand: %i.\n", house);
				printf("Your hand: %i.\n", hand);
				printf("\t|**************************************|\n");
				printf("\t| House BUST! Congratulations you won! |\n");
				printf("\t|______________________________________|\n");
				cash = cash + bet;
			}
			else {
				CLS;
				printf("House hand: %i.\n", house);
				printf("Your hand: %i.\n", hand);
				printf("\t|**********************************|\n");
				printf("\t| House hand was larger. You lost. |\n");
				printf("\t|__________________________________|\n");
				cash = cash - bet;
			}
		}
		if (hand > house) {
			if (hand > 21) {
				CLS;
				printf("House hand: %i.\n", house);
				printf("Your hand: %i.\n", hand);
				printf("\t|*****************************************|\n");
				printf("\t| BUST! Your hand went over 21, you lose. |\n");
				printf("\t|_________________________________________|\n");
				cash = cash - bet;
			}
			else {
				CLS;
				printf("House hand: %i.\n", house);
				printf("Your hand: %i.\n", hand);
				printf("\t|***************************************************************|\n");
				printf("\t| Congratulations you scored %i without going over 21. You WIN! |\n", hand);
				printf("\t|_______________________________________________________________|\n");
				cash = cash + bet;
			}
		}
		if (hand == house) {
			CLS;
			printf("House hand: %i.\n", house);
			printf("Your hand: %i.\n", hand);
			printf("\t|*********************************|\n");
			printf("\t| Tie hands no winner this round. |\n");
			printf("\t|_________________________________|\n");

		}
		FLUSH;
		printf("\n\twould you like to play another round? [Y]es or [N]o? ");
		scanf("%c", &blackjackReplay);
		blackjackReplay = toupper(blackjackReplay);
		FLUSH;
		while (blackjackReplay != 'Y' && blackjackReplay != 'N') {
			printf("\n\tInvalid input please select either 'Y' for YES or 'N' for NO? ");
			FLUSH;
			scanf("%c", &blackjackReplay);
			blackjackReplay = toupper(blackjackReplay);
		}

		PAUSE;
	} while (blackjackReplay == 'Y');
	return cash;
}
//blackjack game

int blackJackMenu(int cash) {
	int result = 0;
	CLS;
	printf("\t _______________\t _______________\t _______________\t _______________\n");
	printf("\t|               |\t|               |\t|               |\t|               |\n");
	printf("\t|      ACE      |\t|      ACE      |\t|      ACE      |\t|      ACE      |\n");
	printf("\t|      OF       |\t|      OF       |\t|      OF       |\t|      OF       |\n");
	printf("\t|    HEARTS     |\t|   DIAMONDS    |\t|    SPADES     |\t|     CLUBS     |\n");
	printf("\t|               |\t|               |\t|               |\t|               |\n");
	printf("\t|     AA AA     |\t|       A       |\t|       A       |\t|      A A      |\n");
	printf("\t|      AAA      |\t|      AAA      |\t|      AAA      |\t|       A       |\n");
	printf("\t|       A       |\t|       A       |\t|     AA AA     |\t|      A A      |\n");
	printf("\t|               |\t|               |\t|       A       |\t|               |\n");
	printf("\t|               |\t|               |\t|               |\t|               |\n");
	printf("\t|_______________|\t|_______________|\t|_______________|\t|_______________|\n");

	printf("\t ==================\t\t===================\n");
	printf("\t = Blackjack Menu =\t\t cash: %i\n", cash);
	printf("\t ==================\t\t===================\n");
	printf("\t 1. Play Blackjack!\n");
	printf("\t 2. Rules & How to play.\n");
	printf("\t 3. Quit.\n\t");
	printf("Select option(1-3): ");
	scanf("%i", &result);
	return result;
}
//displays blackjack menu

int blackJackProgram(int cash) {
	int menu;
	srand((unsigned)time(NULL));

	do {
		menu = blackJackMenu(cash);

		switch (menu) {
		case 1:
			cash = blackJack(cash);
			break;
		case 2:
			blackJackRules();
			break;
		case 3:
			printf("=================================\n");
			printf("= Thanks for playing blackjack! =\n");
			printf("=================================\n");
			PAUSE;
			break;
		default:
			CLS;
			printf("\tInvalid selection. Please select from options 1-3.\n\t");
			PAUSE;
			break;

		}
	} while (menu != 3);
	return cash;
}
//contains menu and the menu contains the game

void blackJackRules() {
	CLS;
	printf("\t\t===============\n");
	printf("\t\t==   RULES   ==\n");
	printf("\t\t===============\n");

	printf("\t===========\n");
	printf("\t= Premise =\n");
	printf("\t===========\n");
	printf("\tThe premise of Blackjack(also commonly known as 21) is fairly simple but important to know before playing.\n");
	printf("\tThe object of the game is to compete with the dealer to get as close to 21 without going over.\n");
	printf("\tThe game begins with the dealer and the player recieving 2 cards each.\n");
	printf("\tThe player can then decide weather to HIT or STAY.\n");
	printf("\tHITTING will result in the player recieving another card.\n");
	printf("\tSTAYING will result in the player withdrawing from making any more moves for that game and their current score will be final.\n");
	printf("\tThe dealer will continue drawing until their hand equals 17 or higher\n");
	printf("\tGoing over 21 will result in a BUST, and the player will lose that round(same rule applies for the dealer).\n");
	printf("\tLOSING will result in the loss of your bet amount.\n");
	printf("\tWINNING will result in the doubling of your bet amount.\n");
	printf("\tA TIE will result in niether a win or loss of bet. The bet will simply be returned to the players cash.\n");
	printf("\tThere is a maximum bet of $50 per round.\n\n");

	printf("\t===============\n");
	printf("\t= Card Values =\n");
	printf("\t===============\n");
	printf("\tNUMBERED CARDS:\n");
	printf("\tNumberd cards have a corresponding value to their number\n");
	printf("\tExample: 2 of hearts will equal a value of 2 being added to your hand total. \n");
	printf("\t _______________\n");
	printf("\t|               |\n");
	printf("\t|      2        |\n");
	printf("\t|      OF       |\n");
	printf("\t|    HEARTS     |\n");
	printf("\t|               |\n");
	printf("\t|     22 22     |\n");
	printf("\t|      222      |\n");
	printf("\t|       2       |\n");
	printf("\t|               |\n");
	printf("\t|               |\n");
	printf("\t|_______________|\n");
	printf("\n\tFACE CARDS:\n");
	printf("\tFace cards consist of King, Queen, Jack, and Ace(Aces are unique and explained in the next section)\n");
	printf("\tThe face cards King, Queen, and Jack all carry values of 10. \n");
	printf("\t _______________\n");
	printf("\t|               |\n");
	printf("\t|      K        |\n");
	printf("\t|      OF       |\n");
	printf("\t|   DIAMONDS    |\n");
	printf("\t|               |\n");
	printf("\t|       K       |\n");
	printf("\t|      KKK      |\n");
	printf("\t|       K       |\n");
	printf("\t|               |\n");
	printf("\t|               |\n");
	printf("\t|_______________|\n");
	printf("\n\tACES:");
	printf("\n\t Aces carry a variable value of either 1 or 11 which the player can decide to thier advantage.\n");
	printf("\t _______________\n");
	printf("\t|               |\n");
	printf("\t|      ACE      |\n");
	printf("\t|      OF       |\n");
	printf("\t|     CLUBS     |\n");
	printf("\t|               |\n");
	printf("\t|      A A      |\n");
	printf("\t|       A       |\n");
	printf("\t|      A A      |\n");
	printf("\t|               |\n");
	printf("\t|               |\n");
	printf("\t|_______________|\n");
	printf("\n\t*** Now you are all set to play! GOOD LUCK! ***\n\n\n\n\n\n\n\n\n");
	printf("**** please scroll all the way up to read from beggining. ****\n\n\n\n");

	PAUSE;
}
//displays the rules for blackjack

int drawFunction(int cardsInHand[], int hand, int previous[], int numDraw, int overallDraw, int identity) {
	int draw = 0, a = 0, i = 0;
	int const LB = 1;
	int const UB = 52;
	draw = LB + rand() % (UB - LB + 1);

	for (i = 0; i < overallDraw; i++) {
		if (draw == previous[a]) {
			draw = LB + rand() % (UB - LB + 1);
			a++;
		}
	}
	cardsInHand[numDraw] = draw;
	previous[overallDraw] = draw;

	switch (draw) {
	case 1:
		heartA();
		hand = aceDrawn(hand, identity);
		break;
	case 2:
		heart2();
		hand = hand + 2;
		break;
	case 3:
		heart3();
		hand = hand + 3;
		break;
	case 4:
		heart4();
		hand = hand + 4;
		break;
	case 5:
		heart5();
		hand = hand + 5;
		break;
	case 6:
		heart6();
		hand = hand + 6;
		break;
	case 7:
		heart7();
		hand = hand + 7;
		break;
	case 8:
		heart8();
		hand = hand + 8;
		break;
	case 9:
		heart9();
		hand = hand + 9;
		break;
	case 10:
		heart10();
		hand = hand + 10;
		break;
	case 11:
		heart11();
		hand = hand + 10;
		break;
	case 12:
		heart12();
		hand = hand + 10;
		break;
	case 13:
		heart13();
		hand = hand + 10;
		break;
	case 14:
		diamondA();
		hand = aceDrawn(hand, identity);
		break;
	case 15:
		diamond2();
		hand = hand + 2;
		break;
	case 16:
		diamond3();
		hand = hand + 3;
		break;
	case 17:
		diamond4();
		hand = hand + 4;
		break;
	case 18:
		diamond5();
		hand = hand + 5;
		break;
	case 19:
		diamond6();
		hand = hand + 6;
		break;
	case 20:
		diamond7();
		hand = hand + 7;
		break;
	case 21:
		diamond8();
		hand = hand + 8;
		break;
	case 22:
		diamond9();
		hand = hand + 9;
		break;
	case 23:
		diamond10();
		hand = hand + 10;
		break;
	case 24:
		diamond11();
		hand = hand + 10;
		break;
	case 25:
		diamond12();
		hand = hand + 10;
		break;
	case 26:
		diamond13();
		hand = hand + 10;
		break;
	case 27:
		spadesA();
		hand = aceDrawn(hand, identity);
		break;
	case 28:
		spades2();
		hand = hand + 2;
		break;
	case 29:
		spades3();
		hand = hand + 3;
		break;
	case 30:
		spades4();
		hand = hand + 4;
		break;
	case 31:
		spades5();
		hand = hand + 5;
		break;
	case 32:
		spades6();
		hand = hand + 6;
		break;
	case 33:
		spades7();
		hand = hand + 7;
		break;
	case 34:
		spades8();
		hand = hand + 8;
		break;
	case 35:
		spades9();
		hand = hand + 9;
		break;
	case 36:
		spades10();
		hand = hand + 10;
		break;
	case 37:
		spades11();
		hand = hand + 10;
		break;
	case 38:
		spades12();
		hand = hand + 10;
		break;
	case 39:
		spades13();
		hand = hand + 10;
		break;
	case 40:
		clubsA();
		hand = aceDrawn(hand, identity);
		break;
	case 41:
		clubs2();
		hand = hand + 2;
		break;
	case 42:
		clubs3();
		hand = hand + 3;
		break;
	case 43:
		clubs4();
		hand = hand + 4;
		break;
	case 44:
		clubs5();
		hand = hand + 5;
		break;
	case 45:
		clubs6();
		hand = hand + 6;
		break;
	case 46:
		clubs7();
		hand = hand + 7;
		break;
	case 47:
		clubs8();
		hand = hand + 8;
		break;
	case 48:
		clubs9();
		hand = hand + 9;
		break;
	case 49:
		clubs10();
		hand = hand + 10;
		break;
	case 50:
		clubs11();
		hand = hand + 10;
		break;
	case 51:
		clubs12();
		hand = hand + 10;
		break;
	case 52:
		clubs13();
		hand = hand + 10;
		break;
	}//end switch
	return hand;
}// end drawFunction
 //creates a random number and that number selects a card from a switch

void displayHand(int handarray[], int draws) {
	int i = 0;
	for (i = 0; i < draws; i++) {
		switch (handarray[i]) {
		case 1:
			heartA();
			break;
		case 2:
			heart2();
			break;
		case 3:
			heart3();
			break;
		case 4:
			heart4();
			break;
		case 5:
			heart5();
			break;
		case 6:
			heart6();
			break;
		case 7:
			heart7();
			break;
		case 8:
			heart8();
			break;
		case 9:
			heart9();
			break;
		case 10:
			heart10();
			break;
		case 11:
			heart11();
			break;
		case 12:
			heart12();
			break;
		case 13:
			heart13();
			break;
		case 14:
			diamondA();
			break;
		case 15:
			diamond2();
			break;
		case 16:
			diamond3();
			break;
		case 17:
			diamond4();
			break;
		case 18:
			diamond5();
			break;
		case 19:
			diamond6();
			break;
		case 20:
			diamond7();
			break;
		case 21:
			diamond8();
			break;
		case 22:
			diamond9();
			break;
		case 23:
			diamond10();
			break;
		case 24:
			diamond11();
			break;
		case 25:
			diamond12();
			break;
		case 26:
			diamond13();
			break;
		case 27:
			spadesA();
			break;
		case 28:
			spades2();
			break;
		case 29:
			spades3();
			break;
		case 30:
			spades4();
			break;
		case 31:
			spades5();
			break;
		case 32:
			spades6();
			break;
		case 33:
			spades7();
			break;
		case 34:
			spades8();
			break;
		case 35:
			spades9();
			break;
		case 36:
			spades10();
			break;
		case 37:
			spades11();
			break;
		case 38:
			spades12();
			break;
		case 39:
			spades13();
			break;
		case 40:
			clubsA();
			break;
		case 41:
			clubs2();
			break;
		case 42:
			clubs3();
			break;
		case 43:
			clubs4();
			break;
		case 44:
			clubs5();
			break;
		case 45:
			clubs6();
			break;
		case 46:
			clubs7();
			break;
		case 47:
			clubs8();
			break;
		case 48:
			clubs9();
			break;
		case 49:
			clubs10();
			break;
		case 50:
			clubs11();
			break;
		case 51:
			clubs12();
			break;
		case 52:
			clubs13();
			break;
		}
	}
}
//displays the cards that have been drawn for wither the player or house

/////////////////////////////////////////////////////////////////////////////////
//Card Functions
/////////////////////////////////////////////////////////////////////////////////
//hearts
void heartA() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      ACE      |\n");
	printf("|      OF       |\n");
	printf("|    HEARTS     |\n");
	printf("|               |\n");
	printf("|     AA AA     |\n");
	printf("|      AAA      |\n");
	printf("|       A       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void heart2() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      2        |\n");
	printf("|      OF       |\n");
	printf("|    HEARTS     |\n");
	printf("|               |\n");
	printf("|     22 22     |\n");
	printf("|      222      |\n");
	printf("|       2       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void heart3() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      3        |\n");
	printf("|      OF       |\n");
	printf("|    HEARTS     |\n");
	printf("|               |\n");
	printf("|     33 33     |\n");
	printf("|      333      |\n");
	printf("|       3       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void heart4() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      4        |\n");
	printf("|      OF       |\n");
	printf("|    HEARTS     |\n");
	printf("|               |\n");
	printf("|     44 44     |\n");
	printf("|      444      |\n");
	printf("|       4       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void heart5() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      5        |\n");
	printf("|      OF       |\n");
	printf("|    HEARTS     |\n");
	printf("|               |\n");
	printf("|     55 55     |\n");
	printf("|      555      |\n");
	printf("|       5       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void heart6() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      6        |\n");
	printf("|      OF       |\n");
	printf("|    HEARTS     |\n");
	printf("|               |\n");
	printf("|     66 66     |\n");
	printf("|      666      |\n");
	printf("|       6       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void heart7() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      7        |\n");
	printf("|      OF       |\n");
	printf("|    HEARTS     |\n");
	printf("|               |\n");
	printf("|     77 77     |\n");
	printf("|      777      |\n");
	printf("|       7       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void heart8() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      8        |\n");
	printf("|      OF       |\n");
	printf("|    HEARTS     |\n");
	printf("|               |\n");
	printf("|     88 88     |\n");
	printf("|      888      |\n");
	printf("|       8       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void heart9() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      9        |\n");
	printf("|      OF       |\n");
	printf("|    HEARTS     |\n");
	printf("|               |\n");
	printf("|     99 99     |\n");
	printf("|      999      |\n");
	printf("|       9       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void heart10() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      10       |\n");
	printf("|      OF       |\n");
	printf("|    HEARTS     |\n");
	printf("|               |\n");
	printf("|     10 10     |\n");
	printf("|      010      |\n");
	printf("|       10      |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void heart11() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      J        |\n");
	printf("|      OF       |\n");
	printf("|    HEARTS     |\n");
	printf("|               |\n");
	printf("|     JJ JJ     |\n");
	printf("|      JJJ      |\n");
	printf("|       J       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void heart12() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      Q        |\n");
	printf("|      OF       |\n");
	printf("|    HEARTS     |\n");
	printf("|               |\n");
	printf("|     QQ QQ     |\n");
	printf("|      QQQ      |\n");
	printf("|       Q       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void heart13() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      K        |\n");
	printf("|      OF       |\n");
	printf("|    HEARTS     |\n");
	printf("|               |\n");
	printf("|     KK KK     |\n");
	printf("|      KKK      |\n");
	printf("|       K       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
//diamond
void diamondA() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      ACE      |\n");
	printf("|      OF       |\n");
	printf("|   DIAMONDS    |\n");
	printf("|               |\n");
	printf("|       A       |\n");
	printf("|      AAA      |\n");
	printf("|       A       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void diamond2() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      2        |\n");
	printf("|      OF       |\n");
	printf("|   DIAMONDS    |\n");
	printf("|               |\n");
	printf("|       2       |\n");
	printf("|      222      |\n");
	printf("|       2       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void diamond3() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      3        |\n");
	printf("|      OF       |\n");
	printf("|   DIAMONDS    |\n");
	printf("|               |\n");
	printf("|       3       |\n");
	printf("|      333      |\n");
	printf("|       3       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void diamond4() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      4        |\n");
	printf("|      OF       |\n");
	printf("|   DIAMONDS    |\n");
	printf("|               |\n");
	printf("|       4       |\n");
	printf("|      444      |\n");
	printf("|       4       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void diamond5() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      5        |\n");
	printf("|      OF       |\n");
	printf("|   DIAMONDS    |\n");
	printf("|               |\n");
	printf("|       5       |\n");
	printf("|      555      |\n");
	printf("|       5       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void diamond6() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      6        |\n");
	printf("|      OF       |\n");
	printf("|   DIAMONDS    |\n");
	printf("|               |\n");
	printf("|       6       |\n");
	printf("|      666      |\n");
	printf("|       6       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void diamond7() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      7        |\n");
	printf("|      OF       |\n");
	printf("|   DIAMONDS    |\n");
	printf("|               |\n");
	printf("|       7       |\n");
	printf("|      777      |\n");
	printf("|       7       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void diamond8() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      8        |\n");
	printf("|      OF       |\n");
	printf("|   DIAMONDS    |\n");
	printf("|               |\n");
	printf("|       8       |\n");
	printf("|      888      |\n");
	printf("|       8       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void diamond9() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      9        |\n");
	printf("|      OF       |\n");
	printf("|   DIAMONDS    |\n");
	printf("|               |\n");
	printf("|       9       |\n");
	printf("|      999      |\n");
	printf("|       9       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void diamond10() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      10       |\n");
	printf("|      OF       |\n");
	printf("|   DIAMONDS    |\n");
	printf("|               |\n");
	printf("|      10       |\n");
	printf("|     1010      |\n");
	printf("|      10       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void diamond11() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      J        |\n");
	printf("|      OF       |\n");
	printf("|   DIAMONDS    |\n");
	printf("|               |\n");
	printf("|       J       |\n");
	printf("|      JJJ      |\n");
	printf("|       J       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void diamond12() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      Q        |\n");
	printf("|      OF       |\n");
	printf("|   DIAMONDS    |\n");
	printf("|               |\n");
	printf("|       Q       |\n");
	printf("|      QQQ      |\n");
	printf("|       Q       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void diamond13() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      K        |\n");
	printf("|      OF       |\n");
	printf("|   DIAMONDS    |\n");
	printf("|               |\n");
	printf("|       K       |\n");
	printf("|      KKK      |\n");
	printf("|       K       |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
//spades
void spadesA() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      ACE      |\n");
	printf("|      OF       |\n");
	printf("|    SPADES     |\n");
	printf("|               |\n");
	printf("|       A       |\n");
	printf("|      AAA      |\n");
	printf("|     AA AA     |\n");
	printf("|       A       |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void spades2() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      2        |\n");
	printf("|      OF       |\n");
	printf("|    SPADES     |\n");
	printf("|               |\n");
	printf("|       2       |\n");
	printf("|      222      |\n");
	printf("|     22 22     |\n");
	printf("|       2       |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void spades3() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      3        |\n");
	printf("|      OF       |\n");
	printf("|    SPADES     |\n");
	printf("|               |\n");
	printf("|       3       |\n");
	printf("|      333      |\n");
	printf("|     33 33     |\n");
	printf("|       3       |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void spades4() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      4        |\n");
	printf("|      OF       |\n");
	printf("|    SPADES     |\n");
	printf("|               |\n");
	printf("|       4       |\n");
	printf("|      444      |\n");
	printf("|     44 44     |\n");
	printf("|       4       |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void spades5() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      5        |\n");
	printf("|      OF       |\n");
	printf("|    SPADES     |\n");
	printf("|               |\n");
	printf("|       5       |\n");
	printf("|      555      |\n");
	printf("|     55 55     |\n");
	printf("|       5       |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void spades6() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      6        |\n");
	printf("|      OF       |\n");
	printf("|    SPADES     |\n");
	printf("|               |\n");
	printf("|       6       |\n");
	printf("|      666      |\n");
	printf("|     66 66     |\n");
	printf("|       6       |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void spades7() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      7        |\n");
	printf("|      OF       |\n");
	printf("|    SPADES     |\n");
	printf("|               |\n");
	printf("|       7       |\n");
	printf("|      777      |\n");
	printf("|     77 77     |\n");
	printf("|       7       |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void spades8() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      8        |\n");
	printf("|      OF       |\n");
	printf("|    SPADES     |\n");
	printf("|               |\n");
	printf("|       8       |\n");
	printf("|      888      |\n");
	printf("|     88 88     |\n");
	printf("|       8       |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void spades9() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      9        |\n");
	printf("|      OF       |\n");
	printf("|    SPADES     |\n");
	printf("|               |\n");
	printf("|       9       |\n");
	printf("|      999      |\n");
	printf("|     99 99     |\n");
	printf("|       9       |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void spades10() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      10       |\n");
	printf("|      OF       |\n");
	printf("|    SPADES     |\n");
	printf("|               |\n");
	printf("|       10      |\n");
	printf("|      010      |\n");
	printf("|     10 10     |\n");
	printf("|       10      |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void spades11() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      J        |\n");
	printf("|      OF       |\n");
	printf("|    SPADES     |\n");
	printf("|               |\n");
	printf("|       J       |\n");
	printf("|      JJJ      |\n");
	printf("|     JJ JJ     |\n");
	printf("|       J       |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void spades12() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      Q        |\n");
	printf("|      OF       |\n");
	printf("|    SPADES     |\n");
	printf("|               |\n");
	printf("|       Q       |\n");
	printf("|      QQQ      |\n");
	printf("|     QQ QQ     |\n");
	printf("|       Q       |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void spades13() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      K        |\n");
	printf("|      OF       |\n");
	printf("|    SPADES     |\n");
	printf("|               |\n");
	printf("|       K       |\n");
	printf("|      KKK      |\n");
	printf("|     KK KK     |\n");
	printf("|       K       |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
//clubs
void clubsA() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      ACE      |\n");
	printf("|      OF       |\n");
	printf("|     CLUBS     |\n");
	printf("|               |\n");
	printf("|      A A      |\n");
	printf("|       A       |\n");
	printf("|      A A      |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void clubs2() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      2        |\n");
	printf("|      OF       |\n");
	printf("|     CLUBS     |\n");
	printf("|               |\n");
	printf("|      2 2      |\n");
	printf("|       2       |\n");
	printf("|      2 2      |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void clubs3() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      3        |\n");
	printf("|      OF       |\n");
	printf("|     CLUBS     |\n");
	printf("|               |\n");
	printf("|      3 3      |\n");
	printf("|       3       |\n");
	printf("|      3 3      |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void clubs4() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      4        |\n");
	printf("|      OF       |\n");
	printf("|     CLUBS     |\n");
	printf("|               |\n");
	printf("|      4 4      |\n");
	printf("|       4       |\n");
	printf("|      4 4      |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void clubs5() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      5        |\n");
	printf("|      OF       |\n");
	printf("|     CLUBS     |\n");
	printf("|               |\n");
	printf("|      5 5      |\n");
	printf("|       5       |\n");
	printf("|      5 5      |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void clubs6() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      6        |\n");
	printf("|      OF       |\n");
	printf("|     CLUBS     |\n");
	printf("|               |\n");
	printf("|      6 6      |\n");
	printf("|       6       |\n");
	printf("|      6 6      |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void clubs7() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      7        |\n");
	printf("|      OF       |\n");
	printf("|     CLUBS     |\n");
	printf("|               |\n");
	printf("|      7 7      |\n");
	printf("|       7       |\n");
	printf("|      7 7      |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void clubs8() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      8        |\n");
	printf("|      OF       |\n");
	printf("|     CLUBS     |\n");
	printf("|               |\n");
	printf("|      8 8      |\n");
	printf("|       8       |\n");
	printf("|      8 8      |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void clubs9() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      9        |\n");
	printf("|      OF       |\n");
	printf("|     CLUBS     |\n");
	printf("|               |\n");
	printf("|      9 9      |\n");
	printf("|       9       |\n");
	printf("|      9 9      |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void clubs10() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      10       |\n");
	printf("|      OF       |\n");
	printf("|     CLUBS     |\n");
	printf("|               |\n");
	printf("|     10 10     |\n");
	printf("|       10      |\n");
	printf("|     10 10     |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void clubs11() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      J        |\n");
	printf("|      OF       |\n");
	printf("|     CLUBS     |\n");
	printf("|               |\n");
	printf("|      J J      |\n");
	printf("|       J       |\n");
	printf("|      J J      |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void clubs12() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      Q        |\n");
	printf("|      OF       |\n");
	printf("|     CLUBS     |\n");
	printf("|               |\n");
	printf("|      Q Q      |\n");
	printf("|       Q       |\n");
	printf("|      Q Q      |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}
void clubs13() {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      K        |\n");
	printf("|      OF       |\n");
	printf("|     CLUBS     |\n");
	printf("|               |\n");
	printf("|      K K      |\n");
	printf("|       K       |\n");
	printf("|      K K      |\n");
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}

////////// FUNCTIONS POKER ///////////////////////////////////////////////

void pokerGame() {
	int theRandNumber = 0, theRandNumber2 = 0, theRandNumber3 = 0, theRandNumber4 = 0, theRandNumber5 = 0, theRandNumber6 = 0, theRandNumber7 = 0, theRandNumber8 = 0;
	char cardA1[SIZE], cardA2[SIZE], cardA3[SIZE], cardA4[SIZE], cardA5[SIZE], cardA6[SIZE];
	char cardB1[SIZE], cardB2[SIZE], cardB3[SIZE], cardB4[SIZE], cardB5[SIZE], cardB6[SIZE];
	char cardC1[SIZE], cardC2[SIZE], cardC3[SIZE], cardC4[SIZE], cardC5[SIZE], cardC6[SIZE];
	char cardD1[SIZE], cardD2[SIZE], cardD3[SIZE], cardD4[SIZE], cardD5[SIZE], cardD6[SIZE];
	char cardE1[SIZE], cardE2[SIZE], cardE3[SIZE], cardE4[SIZE], cardE5[SIZE], cardE6[SIZE];
	char cardF1[SIZE], cardF2[SIZE], cardF3[SIZE], cardF4[SIZE], cardF5[SIZE], cardF6[SIZE];
	char cardG1[SIZE], cardG2[SIZE], cardG3[SIZE], cardG4[SIZE], cardG5[SIZE], cardG6[SIZE];
	char cardH1[SIZE], cardH2[SIZE], cardH3[SIZE], cardH4[SIZE], cardH5[SIZE], cardH6[SIZE];
	float numa1 = 0, numa2 = 0, colora = 0;
	float numb1 = 0, numb2 = 0, colorb = 0;
	float numc1 = 0, numc2 = 0, colorc = 0;
	float numd1 = 0, numd2 = 0, colord = 0;
	float nume1 = 0, nume2 = 0, colore = 0;
	float  numf1 = 0, numf2 = 0, colorf = 0;
	float numg1 = 0, numg2 = 0, colorg = 0;
	float numh1 = 0, numh2 = 0, colorh = 0;
	int const LB = 1;
	int const UB = 52;
	int userMoney = 0, betAmount = 0, betcount = 0;
	char playAgain = ' ';
	srand((unsigned)time(NULL)); // seed the rand function

	do {
		// to create one random number for each card that need to be shown
		do { // the do while makes shure that all random numbers are diferent
			theRandNumber = LB + rand() % (UB - LB + 1);
			theRandNumber2 = LB + rand() % (UB - LB + 1);
			theRandNumber3 = LB + rand() % (UB - LB + 1);
			theRandNumber4 = LB + rand() % (UB - LB + 1);
			theRandNumber5 = LB + rand() % (UB - LB + 1);
			theRandNumber6 = LB + rand() % (UB - LB + 1);
			theRandNumber7 = LB + rand() % (UB - LB + 1);
			theRandNumber8 = LB + rand() % (UB - LB + 1);
		} while (theRandNumber == theRandNumber2 || theRandNumber == theRandNumber3 || theRandNumber == theRandNumber4 || theRandNumber == theRandNumber5 || theRandNumber == theRandNumber6 || theRandNumber == theRandNumber7 || theRandNumber == theRandNumber8 || theRandNumber2 == theRandNumber3 || theRandNumber2 == theRandNumber4 || theRandNumber2 == theRandNumber5 || theRandNumber2 == theRandNumber6 || theRandNumber2 == theRandNumber7 || theRandNumber2 == theRandNumber8 || theRandNumber3 == theRandNumber4 || theRandNumber3 == theRandNumber5 || theRandNumber3 == theRandNumber6 || theRandNumber3 == theRandNumber7 || theRandNumber3 == theRandNumber8 || theRandNumber4 == theRandNumber5 || theRandNumber4 == theRandNumber6 || theRandNumber4 == theRandNumber7 || theRandNumber4 == theRandNumber8 || theRandNumber5 == theRandNumber6 || theRandNumber5 == theRandNumber7 || theRandNumber5 == theRandNumber8 || theRandNumber6 == theRandNumber7 || theRandNumber6 == theRandNumber8 || theRandNumber7 == theRandNumber8);






		firstCardOfPlayer(theRandNumber, cardA1, cardA2, cardA3, cardA4, cardA5, cardA6);
		secondCardOfPlayer(theRandNumber2, cardB1, cardB2, cardB3, cardB4, cardB5, cardB6);
		firstCardOnTable(theRandNumber3, cardC1, cardC2, cardC3, cardC4, cardC5, cardC6);
		secondCardOnTable(theRandNumber4, cardD1, cardD2, cardD3, cardD4, cardD5, cardD6);
		thirdCardOnTable(theRandNumber5, cardE1, cardE2, cardE3, cardE4, cardE5, cardE6);
		fourthCardOnTable(theRandNumber6, cardF1, cardF2, cardF3, cardF4, cardF5, cardF6);
		firstCardOfOpponent(theRandNumber7, cardG1, cardG2, cardG3, cardG4, cardG5, cardG6);
		secondCardOfOpponent(theRandNumber8, cardH1, cardH2, cardH3, cardH4, cardH5, cardH6);

		userMoney = 500;


		CLS;
		printf("\n\n\t<RULES>\n");
		printf("\t<ROYAL FLUSH IS BETTER THAN STRAIGHT FLUSH>\n");
		printf("\t<STRAIGHT FLUSH IS BETTER THAN FOUR OF A KIND>\n");
		printf("\t<FOUR OF A KIND IS BETTER THAN FULL HOUSE>\n");
		printf("\t<FULL HOUSE IS BETTER THAN FLUSH>\n");
		printf("\t<FLUSH IS BETTER THAN STRAIGHT>\n");
		printf("\t<STRAIGHT IS BETTER THAN THREE OF A KIND>\n");
		printf("\t<THREE OF A KIND IS BETTER THAN TWO PAIR>\n");
		printf("\t<TWO PAIR IS BETTER THAN ONE PAIR>\n");
		printf("\t<ONE PAIR IS BETTER THAN HIGH CARD>\n\n ");
		printf("\t<READY TO PLAY??> \n\n");
		PAUSE; CLS;

		printf("\n\n\t<THESE ARE YOUR CARDS>\n\n"); //show your cards

		showCardsonHand(cardA1, cardA2, cardA3, cardA4, cardA5, cardA6, cardB1, cardB2, cardB3, cardB4, cardB5, cardB6);
		getchar();

		printf("\n\n\t<CARDS ON TABLE>\n\n"); //show only the first card on table

		showCardsOnTableA(cardC1, cardC2, cardC3, cardC4, cardC5, cardC6);

		printf("\n\nyou have %i dollars to bet\n", userMoney);
		printf("how much you want to bet?\n");
		scanf("%i", &betAmount);
		userMoney = userMoney - betAmount;
		betcount = betcount + betAmount;
		betAmount = 0;

		getchar();
		CLS;

		printf("\n\n\t<THESE ARE YOUR CARDS>\n\n"); //show your cards

		showCardsonHand(cardA1, cardA2, cardA3, cardA4, cardA5, cardA6, cardB1, cardB2, cardB3, cardB4, cardB5, cardB6);

		printf("\n\n\t<CARDS ON TABLE>\n\n"); //show only the first and second card on table

		showCardsOnTableB(cardC1, cardC2, cardC3, cardC4, cardC5, cardC6, cardD1, cardD2, cardD3, cardD4, cardD5, cardD6);

		printf("\n\nyou have %i dollars to bet\n", userMoney);
		printf("how much you want to bet?\n");
		scanf("%i", &betAmount);
		userMoney = userMoney - betAmount;
		betcount = betcount + betAmount;
		betAmount = 0;

		getchar();
		CLS;

		printf("\n\n\t<THESE ARE YOUR CARDS>\n\n"); //show your cards

		showCardsonHand(cardA1, cardA2, cardA3, cardA4, cardA5, cardA6, cardB1, cardB2, cardB3, cardB4, cardB5, cardB6);

		printf("\n\n\t<CARDS ON TABLE>\n\n"); //show only the first, second and third card on table

		showCardsOnTableC(cardC1, cardC2, cardC3, cardC4, cardC5, cardC6, cardD1, cardD2, cardD3, cardD4, cardD5, cardD6, cardE1, cardE2, cardE3, cardE4, cardE5, cardE6);

		printf("\n\nyou have %i dollars to bet\n", userMoney);
		printf("how much you want to bet?\n");
		scanf("%i", &betAmount);
		userMoney = userMoney - betAmount;
		betcount = betcount + betAmount;
		betAmount = 0;

		getchar();
		CLS;

		printf("\n\n\t<THESE ARE YOUR CARDS>\n\n"); //show your cards

		showCardsonHand(cardA1, cardA2, cardA3, cardA4, cardA5, cardA6, cardB1, cardB2, cardB3, cardB4, cardB5, cardB6);

		printf("\n\n\t<CARDS ON TABLE>\n\n"); //show all cards on table

		showCardsOnTable(cardC1, cardC2, cardC3, cardC4, cardC5, cardC6, cardD1, cardD2, cardD3, cardD4, cardD5, cardD6, cardE1, cardE2, cardE3, cardE4, cardE5, cardE6, cardF1, cardF2, cardF3, cardF4, cardF5, cardF6);

		printf("\n\nyou have %i dollars to bet\n", userMoney);
		printf("how much you want to bet?\n");
		scanf("%i", &betAmount);
		userMoney = userMoney - betAmount;
		betcount = betcount + betAmount;
		betAmount = 0;

		getchar();

		CLS;

		printf("\n\n\t<THESE ARE YOUR CARDS>\n\n"); //show your cards

		showCardsonHand(cardA1, cardA2, cardA3, cardA4, cardA5, cardA6, cardB1, cardB2, cardB3, cardB4, cardB5, cardB6);

		printf("\n\n\t<CARDS ON TABLE>\n\n"); //show all cards on table

		showCardsOnTable(cardC1, cardC2, cardC3, cardC4, cardC5, cardC6, cardD1, cardD2, cardD3, cardD4, cardD5, cardD6, cardE1, cardE2, cardE3, cardE4, cardE5, cardE6, cardF1, cardF2, cardF3, cardF4, cardF5, cardF6);

		printf("\n\t<OPPONENT CARDS>\n\n");

		showCardsopponent(cardG1, cardG2, cardG3, cardG4, cardG5, cardG6, cardH1, cardH2, cardH3, cardH4, cardH5, cardH6);
		getchar();

		//this is to get the values of the cards
		switch (theRandNumber) {
		case 1:

			numa1 = 11;
			numa2 = 1;
			colora = 1;

			break;
		case 2:


			numa1 = 2;
			colora = 1;
			break;
		case 3:


			numa1 = 3;
			colora = 1;
			break;
		case 4:

			numa1 = 4;
			colora = 1;
			break;
		case 5:

			numa1 = 5;
			colora = 1;
			break;
		case 6:


			numa1 = 6;
			colora = 1;
			break;
		case 7:


			numa1 = 7;
			colora = 1;
			break;
		case 8:

			numa1 = 8;
			colora = 1;
			break;
		case 9:


			numa1 = 9;
			colora = 1;
			break;
		case 10:


			numa1 = 10;
			colora = 1;
			break;
		case 11:


			numa1 = 10.1;
			colora = 1;
			break;
		case 12:

			numa1 = 10.2;
			colora = 1;
			break;
		case 13:

			numa1 = 10.3;
			colora = 1;
			break;
		case 14:

			numa1 = 11;
			numa2 = 1;
			colora = 2;
			break;
		case 15:

			numa1 = 2;
			colora = 2;
			break;
		case 16:

			numa1 = 3;
			colora = 2;
			break;
		case 17:

			numa1 = 4;
			colora = 2;
			break;
		case 18:

			numa1 = 5;
			colora = 2;
			break;
		case 19:

			numa1 = 6;
			colora = 2;
			break;
		case 20:

			numa1 = 7;
			colora = 2;
			break;
		case 21:

			numa1 = 8;
			colora = 2;
			break;
		case 22:

			numa1 = 9;
			colora = 2;
			break;
		case 23:

			numa1 = 10;
			colora = 2;
			break;
		case 24:

			numa1 = 10.1;
			colora = 2;
			break;
		case 25:

			numa1 = 10.2;
			colora = 2;
			break;
		case 26:

			numa1 = 10.3;
			colora = 2;
			break;
		case 27:

			numa1 = 11;
			numa2 = 1;
			colora = 3;
			break;
		case 28:

			numa1 = 2;
			colora = 3;
			break;
		case 29:

			numa1 = 3;
			colora = 3;
			break;
		case 30:

			numa1 = 4;
			colora = 3;
			break;
		case 31:

			numa1 = 5;
			colora = 3;
			break;
		case 32:

			numa1 = 6;
			colora = 3;
			break;
		case 33:

			numa1 = 7;
			colora = 3;
			break;
		case 34:

			numa1 = 8;
			colora = 3;
			break;
		case 35:

			numa1 = 9;
			colora = 3;
			break;
		case 36:

			numa1 = 10;
			colora = 3;
			break;
		case 37:

			numa1 = 10.1;
			colora = 3;
			break;
		case 38:

			numa1 = 10.2;
			colora = 3;
			break;
		case 39:

			numa1 = 10.3;
			colora = 3;
			break;
		case 40:

			numa1 = 11;
			numa2 = 1;
			colora = 4;
			break;
		case 41:

			numa1 = 2;
			colora = 4;
			break;
		case 42:

			numa1 = 3;
			colora = 4;
			break;
		case 43:

			numa1 = 4;
			colora = 4;
			break;
		case 44:

			numa1 = 5;
			colora = 4;
			break;
		case 45:

			numa1 = 6;
			colora = 4;
			break;
		case 46:

			numa1 = 7;
			colora = 4;
			break;
		case 47:

			numa1 = 8;
			colora = 4;
			break;
		case 48:

			numa1 = 9;
			colora = 4;
			break;
		case 49:

			numa1 = 10;
			colora = 4;
			break;
		case 50:

			numa1 = 10.1;
			colora = 4;
			break;
		case 51:

			numa1 = 10.2;
			colora = 4;
			break;
		case 52:

			numa1 = 10.3;
			colora = 4;
			break;

		}
		switch (theRandNumber2) {
		case 1:

			numb1 = 11;
			numb2 = 1;
			colorb = 1;

			break;
		case 2:

			numb1 = 2;
			colorb = 1;
			break;
		case 3:

			numb1 = 3;
			colorb = 1;
			break;
		case 4:

			numb1 = 4;
			colorb = 1;
			break;
		case 5:

			numb1 = 5;
			colorb = 1;
			break;
		case 6:

			numb1 = 6;
			colorb = 1;
			break;
		case 7:

			numb1 = 7;
			colorb = 1;
			break;
		case 8:

			numb1 = 8;
			colorb = 1;
			break;
		case 9:

			numb1 = 9;
			colorb = 1;
			break;
		case 10:

			numb1 = 10;
			colorb = 1;
			break;
		case 11:

			numb1 = 10.1;
			colorb = 1;
			break;
		case 12:

			numb1 = 10.2;
			colorb = 1;
			break;
		case 13:

			numb1 = 10.3;
			colorb = 1;
			break;
		case 14:

			numb1 = 11;
			numb2 = 1;
			colorb = 2;
			break;
		case 15:

			numb1 = 2;
			colorb = 2;
			break;
		case 16:

			numb1 = 3;
			colorb = 2;
			break;
		case 17:

			numb1 = 4;
			colorb = 2;
			break;
		case 18:

			numb1 = 5;
			colorb = 2;
			break;
		case 19:

			numb1 = 6;
			colorb = 2;
			break;
		case 20:

			numb1 = 7;
			colorb = 2;
			break;
		case 21:

			numb1 = 8;
			colorb = 2;
			break;
		case 22:

			numb1 = 9;
			colorb = 2;
			break;
		case 23:

			numb1 = 10;
			colorb = 2;
			break;
		case 24:

			numb1 = 10.1;
			colorb = 2;
			break;
		case 25:

			numb1 = 10.2;
			colorb = 2;
			break;
		case 26:

			numb1 = 10.3;
			colorb = 2;
			break;
		case 27:

			numb1 = 11;
			numb2 = 1;
			colorb = 3;
			break;
		case 28:

			numb1 = 2;
			colorb = 3;
			break;
		case 29:

			numb1 = 3;
			colorb = 3;
			break;
		case 30:

			numb1 = 4;
			colorb = 3;
			break;
		case 31:

			numb1 = 5;
			colorb = 3;
			break;
		case 32:

			numb1 = 6;
			colorb = 3;
			break;
		case 33:

			numb1 = 7;
			colorb = 3;
			break;
		case 34:

			numb1 = 8;
			colorb = 3;
			break;
		case 35:

			numb1 = 9;
			colorb = 3;
			break;
		case 36:

			numb1 = 10;
			colorb = 3;
			break;
		case 37:

			numb1 = 10.1;
			colorb = 3;
			break;
		case 38:

			numb1 = 10.2;
			colorb = 3;
			break;
		case 39:

			numb1 = 10.3;
			colorb = 3;
			break;
		case 40:

			numb1 = 11;
			numb2 = 1;
			colorb = 4;
			break;
		case 41:

			numb1 = 2;
			colorb = 4;
			break;
		case 42:

			numb1 = 3;
			colorb = 4;
			break;
		case 43:

			numb1 = 4;
			colorb = 4;
			break;
		case 44:

			numb1 = 5;
			colorb = 4;
			break;
		case 45:

			numb1 = 6;
			colorb = 4;
			break;
		case 46:

			numb1 = 7;
			colorb = 4;
			break;
		case 47:

			numb1 = 8;
			colorb = 4;
			break;
		case 48:

			numb1 = 9;
			colorb = 4;
			break;
		case 49:

			numb1 = 10;
			colorb = 4;
			break;
		case 50:

			numb1 = 10.1;
			colorb = 4;
			break;
		case 51:

			numb1 = 10.2;
			colorb = 4;
			break;
		case 52:

			numb1 = 10.3;
			colorb = 4;
			break;

		}
		switch (theRandNumber3) {
		case 1:

			numc1 = 11;
			numc2 = 1;
			colorc = 1;

			break;
		case 2:

			numc1 = 2;
			colorc = 1;
			break;
		case 3:

			numc1 = 3;
			colorc = 1;
			break;
		case 4:

			numc1 = 4;
			colorc = 1;
			break;
		case 5:

			numc1 = 5;
			colorc = 1;
			break;
		case 6:

			numc1 = 6;
			colorc = 1;
			break;
		case 7:

			numc1 = 7;
			colorc = 1;
			break;
		case 8:

			numc1 = 8;
			colorc = 1;
			break;
		case 9:

			numc1 = 9;
			colorc = 1;
			break;
		case 10:

			numc1 = 10;
			colorc = 1;
			break;
		case 11:

			numc1 = 10.1;
			colorc = 1;
			break;
		case 12:

			numc1 = 10.2;
			colorc = 1;
			break;
		case 13:

			numc1 = 10.3;
			colorc = 1;
			break;
		case 14:

			numc1 = 11;
			numc2 = 1;
			colorc = 2;
			break;
		case 15:

			numc1 = 2;
			colorc = 2;
			break;
		case 16:

			numc1 = 3;
			colorc = 2;
			break;
		case 17:

			numc1 = 4;
			colorc = 2;
			break;
		case 18:

			numc1 = 5;
			colorc = 2;
			break;
		case 19:

			numc1 = 6;
			colorc = 2;
			break;
		case 20:

			numc1 = 7;
			colorc = 2;
			break;
		case 21:

			numc1 = 8;
			colorc = 2;
			break;
		case 22:

			numc1 = 9;
			colorc = 2;
			break;
		case 23:

			numc1 = 10;
			colorc = 2;
			break;
		case 24:

			numc1 = 10.1;
			colorc = 2;
			break;
		case 25:

			numc1 = 10.2;
			colorc = 2;
			break;
		case 26:

			numc1 = 10.3;
			colorc = 2;
			break;
		case 27:

			numc1 = 11;
			numc2 = 1;
			colorc = 3;
			break;
		case 28:

			numc1 = 2;
			colorc = 3;
			break;
		case 29:

			numc1 = 3;
			colorc = 3;
			break;
		case 30:

			numc1 = 4;
			colorc = 3;
			break;
		case 31:

			numc1 = 5;
			colorc = 3;
			break;
		case 32:

			numc1 = 6;
			colorc = 3;
			break;
		case 33:

			numc1 = 7;
			colorc = 3;
			break;
		case 34:

			numc1 = 8;
			colorc = 3;
			break;
		case 35:

			numc1 = 9;
			colorc = 3;
			break;
		case 36:

			numc1 = 10;
			colorc = 3;
			break;
		case 37:

			numc1 = 10.1;
			colorc = 3;
			break;
		case 38:

			numc1 = 10.2;
			colorc = 3;
			break;
		case 39:

			numc1 = 10.3;
			colorc = 3;
			break;
		case 40:

			numc1 = 11;
			numc2 = 1;
			colorc = 4;
			break;
		case 41:

			numc1 = 2;
			colorc = 4;
			break;
		case 42:

			numc1 = 3;
			colorc = 4;
			break;
		case 43:

			numc1 = 4;
			colorc = 4;
			break;
		case 44:

			numc1 = 5;
			colorc = 4;
			break;
		case 45:

			numc1 = 6;
			colorc = 4;
			break;
		case 46:

			numc1 = 7;
			colorc = 4;
			break;
		case 47:

			numc1 = 8;
			colorc = 4;
			break;
		case 48:

			numc1 = 9;
			colorc = 4;
			break;
		case 49:

			numc1 = 10;
			colorc = 4;
			break;
		case 50:

			numc1 = 10.1;
			colorc = 4;
			break;
		case 51:

			numc1 = 10.2;
			colorc = 4;
			break;
		case 52:

			numc1 = 10.3;
			colorc = 4;
			break;

		}
		switch (theRandNumber4) {
		case 1:

			numd1 = 11;
			numd2 = 1;
			colord = 1;

			break;
		case 2:

			numd1 = 2;
			colord = 1;
			break;
		case 3:

			numd1 = 3;
			colord = 1;
			break;
		case 4:

			numd1 = 4;
			colord = 1;
			break;
		case 5:

			numd1 = 5;
			colord = 1;
			break;
		case 6:

			numd1 = 6;
			colord = 1;
			break;
		case 7:

			numd1 = 7;
			colord = 1;
			break;
		case 8:
			numd1 = 8;
			colord = 1;
			break;
		case 9:

			numd1 = 9;
			colord = 1;
			break;
		case 10:

			numd1 = 10;
			colord = 1;
			break;
		case 11:

			numd1 = 10.1;
			colord = 1;
			break;
		case 12:

			numd1 = 10.2;
			colord = 1;
			break;
		case 13:

			numd1 = 10.3;
			colord = 1;
			break;
		case 14:

			numd1 = 11;
			numd2 = 1;
			colord = 2;
			break;
		case 15:

			numd1 = 2;
			colord = 2;
			break;
		case 16:

			numd1 = 3;
			colord = 2;
			break;
		case 17:

			numd1 = 4;
			colord = 2;
			break;
		case 18:

			numd1 = 5;
			colord = 2;
			break;
		case 19:

			numd1 = 6;
			colord = 2;
			break;
		case 20:

			numd1 = 7;
			colord = 2;
			break;
		case 21:

			numd1 = 8;
			colord = 2;
			break;
		case 22:

			numd1 = 9;
			colord = 2;
			break;
		case 23:

			numd1 = 10;
			colord = 2;
			break;
		case 24:

			numd1 = 10.1;
			colord = 2;
			break;
		case 25:

			numd1 = 10.2;
			colord = 2;
			break;
		case 26:

			numd1 = 10.3;
			colord = 2;
			break;
		case 27:

			numd1 = 11;
			numd2 = 1;
			colord = 3;
			break;
		case 28:

			numd1 = 2;
			colord = 3;
			break;
		case 29:

			numd1 = 3;
			colord = 3;
			break;
		case 30:

			numd1 = 4;
			colord = 3;
			break;
		case 31:

			numd1 = 5;
			colord = 3;
			break;
		case 32:

			numd1 = 6;
			colord = 3;
			break;
		case 33:

			numd1 = 7;
			colord = 3;
			break;
		case 34:

			numd1 = 8;
			colord = 3;
			break;
		case 35:

			numd1 = 9;
			colord = 3;
			break;
		case 36:

			numd1 = 10;
			colord = 3;
			break;
		case 37:

			numd1 = 10.1;
			colord = 3;
			break;
		case 38:

			numd1 = 10.2;
			colord = 3;
			break;
		case 39:

			numd1 = 10.3;
			colord = 3;
			break;
		case 40:

			numd1 = 11;
			numd2 = 1;
			colord = 4;
			break;
		case 41:

			numd1 = 2;
			colord = 4;
			break;
		case 42:

			numd1 = 3;
			colord = 4;
			break;
		case 43:

			numd1 = 4;
			colord = 4;
			break;
		case 44:

			numd1 = 5;
			colord = 4;
			break;
		case 45:

			numd1 = 6;
			colord = 4;
			break;
		case 46:

			numd1 = 7;
			colord = 4;
			break;
		case 47:

			numd1 = 8;
			colord = 4;
			break;
		case 48:

			numd1 = 9;
			colord = 4;
			break;
		case 49:

			numd1 = 10;
			colord = 4;
			break;
		case 50:

			numd1 = 10.1;
			colord = 4;
			break;
		case 51:

			numd1 = 10.2;
			colord = 4;
			break;
		case 52:

			numd1 = 10.3;
			colord = 4;
			break;

		}
		switch (theRandNumber5) {
		case 1:

			nume1 = 11;
			nume2 = 1;
			colore = 1;

			break;
		case 2:

			nume1 = 2;
			colore = 1;
			break;
		case 3:

			nume1 = 3;
			colore = 1;
			break;
		case 4:

			nume1 = 4;
			colore = 1;
			break;
		case 5:

			nume1 = 5;
			colore = 1;
			break;
		case 6:

			nume1 = 6;
			colore = 1;
			break;
		case 7:

			nume1 = 7;
			colore = 1;
			break;
		case 8:

			nume1 = 8;
			colore = 1;
			break;
		case 9:

			nume1 = 9;
			colore = 1;
			break;
		case 10:

			nume1 = 10;
			colore = 1;
			break;
		case 11:

			nume1 = 10.1;
			colore = 1;
			break;
		case 12:

			nume1 = 10.2;
			colore = 1;
			break;
		case 13:

			nume1 = 10.3;
			colore = 1;
			break;
		case 14:

			nume1 = 11;
			nume2 = 1;
			colore = 2;
			break;
		case 15:

			nume1 = 2;
			colore = 2;
			break;
		case 16:

			nume1 = 3;
			colore = 2;
			break;
		case 17:

			nume1 = 4;
			colore = 2;
			break;
		case 18:

			nume1 = 5;
			colore = 2;
			break;
		case 19:

			nume1 = 6;
			colore = 2;
			break;
		case 20:

			nume1 = 7;
			colore = 2;
			break;
		case 21:

			nume1 = 8;
			colore = 2;
			break;
		case 22:

			nume1 = 9;
			colore = 2;
			break;
		case 23:

			nume1 = 10;
			colore = 2;
			break;
		case 24:

			nume1 = 10.1;
			colore = 2;
			break;
		case 25:

			nume1 = 10.2;
			colore = 2;
			break;
		case 26:

			nume1 = 10.3;
			colore = 2;
			break;
		case 27:

			nume1 = 11;
			nume2 = 1;
			colore = 3;
			break;
		case 28:

			nume1 = 2;
			colore = 3;
			break;
		case 29:

			nume1 = 3;
			colore = 3;
			break;
		case 30:

			nume1 = 4;
			colore = 3;
			break;
		case 31:

			nume1 = 5;
			colore = 3;
			break;
		case 32:

			nume1 = 6;
			colore = 3;
			break;
		case 33:

			nume1 = 7;
			colore = 3;
			break;
		case 34:

			nume1 = 8;
			colore = 3;
			break;
		case 35:

			nume1 = 9;
			colore = 3;
			break;
		case 36:

			nume1 = 10;
			colore = 3;
			break;
		case 37:

			nume1 = 10.1;
			colore = 3;
			break;
		case 38:

			nume1 = 10.2;
			colore = 3;
			break;
		case 39:

			nume1 = 10.3;
			colore = 3;
			break;
		case 40:

			nume1 = 11;
			nume2 = 1;
			colore = 4;
			break;
		case 41:

			nume1 = 2;
			colore = 4;
			break;
		case 42:

			nume1 = 3;
			colore = 4;
			break;
		case 43:

			nume1 = 4;
			colore = 4;
			break;
		case 44:

			nume1 = 5;
			colore = 4;
			break;
		case 45:

			nume1 = 6;
			colore = 4;
			break;
		case 46:

			nume1 = 7;
			colore = 4;
			break;
		case 47:

			nume1 = 8;
			colore = 4;
			break;
		case 48:

			nume1 = 9;
			colore = 4;
			break;
		case 49:

			nume1 = 10;
			colore = 4;
			break;
		case 50:

			nume1 = 10.1;
			colore = 4;
			break;
		case 51:

			nume1 = 10.2;
			colore = 4;
			break;
		case 52:

			nume1 = 10.3;
			colore = 4;
			break;

		}
		switch (theRandNumber6) {
		case 1:

			numf1 = 11;
			numf2 = 1;
			colorf = 1;

			break;
		case 2:

			numf1 = 2;
			colorf = 1;
			break;
		case 3:

			numf1 = 3;
			colorf = 1;
			break;
		case 4:

			numf1 = 4;
			colorf = 1;
			break;
		case 5:

			numf1 = 5;
			colorf = 1;
			break;
		case 6:

			numf1 = 6;
			colorf = 1;
			break;
		case 7:

			numf1 = 7;
			colorf = 1;
			break;
		case 8:

			numf1 = 8;
			colorf = 1;
			break;
		case 9:

			numf1 = 9;
			colorf = 1;
			break;
		case 10:

			numf1 = 10;
			colorf = 1;
			break;
		case 11:

			numf1 = 10.1;
			colorf = 1;
			break;
		case 12:

			numf1 = 10.2;
			colorf = 1;
			break;
		case 13:

			numf1 = 10.3;
			colorf = 1;
			break;
		case 14:

			numf1 = 11;
			numf2 = 1;
			colorf = 2;
			break;
		case 15:

			numf1 = 2;
			colorf = 2;
			break;
		case 16:

			numf1 = 3;
			colorf = 2;
			break;
		case 17:

			numf1 = 4;
			colorf = 2;
			break;
		case 18:

			numf1 = 5;
			colorf = 2;
			break;
		case 19:

			numf1 = 6;
			colorf = 2;
			break;
		case 20:

			numf1 = 7;
			colorf = 2;
			break;
		case 21:

			numf1 = 8;
			colorf = 2;
			break;
		case 22:

			numf1 = 9;
			colorf = 2;
			break;
		case 23:

			numf1 = 10;
			colorf = 2;
			break;
		case 24:

			numf1 = 10.1;
			colorf = 2;
			break;
		case 25:

			numf1 = 10.2;
			colorf = 2;
			break;
		case 26:

			numf1 = 10.3;
			colorf = 2;
			break;
		case 27:

			numf1 = 11;
			numf2 = 1;
			colorf = 3;
			break;
		case 28:

			numf1 = 2;
			colorf = 3;
			break;
		case 29:

			numf1 = 3;
			colorf = 3;
			break;
		case 30:

			numf1 = 4;
			colorf = 3;
			break;
		case 31:

			numf1 = 5;
			colorf = 3;
			break;
		case 32:

			numf1 = 6;
			colorf = 3;
			break;
		case 33:

			numf1 = 7;
			colorf = 3;
			break;
		case 34:

			numf1 = 8;
			colorf = 3;
			break;
		case 35:

			numf1 = 9;
			colorf = 3;
			break;
		case 36:

			numf1 = 10;
			colorf = 3;
			break;
		case 37:

			numf1 = 10.1;
			colorf = 3;
			break;
		case 38:

			numf1 = 10.2;
			colorf = 3;
			break;
		case 39:

			numf1 = 10.3;
			colorf = 3;
			break;
		case 40:

			numf1 = 11;
			numf2 = 1;
			colorf = 4;
			break;
		case 41:

			numf1 = 2;
			colorf = 4;
			break;
		case 42:

			numf1 = 3;
			colorf = 4;
			break;
		case 43:

			numf1 = 4;
			colorf = 4;
			break;
		case 44:

			numf1 = 5;
			colorf = 4;
			break;
		case 45:

			numf1 = 6;
			colorf = 4;
			break;
		case 46:

			numf1 = 7;
			colorf = 4;
			break;
		case 47:

			numf1 = 8;
			colorf = 4;
			break;
		case 48:

			numf1 = 9;
			colorf = 4;
			break;
		case 49:

			numf1 = 10;
			colorf = 4;
			break;
		case 50:

			numf1 = 10.1;
			colorf = 4;
			break;
		case 51:

			numf1 = 10.2;
			colorf = 4;
			break;
		case 52:

			numf1 = 10.3;
			colorf = 4;
			break;

		}
		switch (theRandNumber7) {
		case 1:

			numg1 = 11;
			numg2 = 1;
			colorg = 1;

			break;
		case 2:

			numg1 = 2;
			colorg = 1;
			break;
		case 3:

			numg1 = 3;
			colorg = 1;
			break;
		case 4:

			numg1 = 4;
			colorg = 1;
			break;
		case 5:

			numg1 = 5;
			colorg = 1;
			break;
		case 6:

			numg1 = 6;
			colorg = 1;
			break;
		case 7:

			numg1 = 7;
			colorg = 1;
			break;
		case 8:

			numg1 = 8;
			colorg = 1;
			break;
		case 9:

			numg1 = 9;
			colorg = 1;
			break;
		case 10:

			numg1 = 10;
			colorg = 1;
			break;
		case 11:

			numg1 = 10.1;
			colorg = 1;
			break;
		case 12:

			numg1 = 10.2;
			colorg = 1;
			break;
		case 13:

			numg1 = 10.3;
			colorg = 1;
			break;
		case 14:

			numg1 = 11;
			numg2 = 1;
			colorg = 2;
			break;
		case 15:

			numg1 = 2;
			colorg = 2;
			break;
		case 16:

			numg1 = 3;
			colorg = 2;
			break;
		case 17:

			numg1 = 4;
			colorg = 2;
			break;
		case 18:

			numg1 = 5;
			colorg = 2;
			break;
		case 19:

			numg1 = 6;
			colorg = 2;
			break;
		case 20:

			numg1 = 7;
			colorg = 2;
			break;
		case 21:

			numg1 = 8;
			colorg = 2;
			break;
		case 22:

			numg1 = 9;
			colorg = 2;
			break;
		case 23:

			numg1 = 10;
			colorg = 2;
			break;
		case 24:

			numg1 = 10.1;
			colorg = 2;
			break;
		case 25:

			numg1 = 10.2;
			colorg = 2;
			break;
		case 26:

			numg1 = 10.3;
			colorg = 2;
			break;
		case 27:

			numg1 = 11;
			numg2 = 1;
			colorg = 3;
			break;
		case 28:

			numg1 = 2;
			colorg = 3;
			break;
		case 29:

			numg1 = 3;
			colorg = 3;
			break;
		case 30:

			numg1 = 4;
			colorg = 3;
			break;
		case 31:

			numg1 = 5;
			colorg = 3;
			break;
		case 32:

			numg1 = 6;
			colorg = 3;
			break;
		case 33:

			numg1 = 7;
			colorg = 3;
			break;
		case 34:

			numg1 = 8;
			colorg = 3;
			break;
		case 35:

			numg1 = 9;
			colorg = 3;
			break;
		case 36:

			numg1 = 10;
			colorg = 3;
			break;
		case 37:

			numg1 = 10.1;
			colorg = 3;
			break;
		case 38:

			numg1 = 10.2;
			colorg = 3;
			break;
		case 39:

			numg1 = 10.3;
			colorg = 3;
			break;
		case 40:

			numg1 = 11;
			numg2 = 1;
			colorg = 4;
			break;
		case 41:

			numg1 = 2;
			colorg = 4;
			break;
		case 42:

			numg1 = 3;
			colorg = 4;
			break;
		case 43:

			numg1 = 4;
			colorg = 4;
			break;
		case 44:

			numg1 = 5;
			colorg = 4;
			break;
		case 45:

			numg1 = 6;
			colorg = 4;
			break;
		case 46:

			numg1 = 7;
			colorg = 4;
			break;
		case 47:

			numg1 = 8;
			colorg = 4;
			break;
		case 48:

			numg1 = 9;
			colorg = 4;
			break;
		case 49:

			numg1 = 10;
			colorg = 4;
			break;
		case 50:

			numg1 = 10.1;
			colorg = 4;
			break;
		case 51:

			numg1 = 10.2;
			colorg = 4;
			break;
		case 52:

			numg1 = 10.3;
			colorg = 4;
			break;

		}
		switch (theRandNumber8) {
		case 1:

			numh1 = 11;
			numh2 = 1;
			colorh = 1;

			break;
		case 2:

			numh1 = 2;
			colorh = 1;
			break;
		case 3:

			numh1 = 3;
			colorh = 1;
			break;
		case 4:

			numh1 = 4;
			colorh = 1;
			break;
		case 5:

			numh1 = 5;
			colorh = 1;
			break;
		case 6:

			numh1 = 6;
			colorh = 1;
			break;
		case 7:

			numh1 = 7;
			colorh = 1;
			break;
		case 8:

			numh1 = 8;
			colorh = 1;
			break;
		case 9:

			numh1 = 9;
			colorh = 1;
			break;
		case 10:

			numh1 = 10;
			colorh = 1;
			break;
		case 11:

			numh1 = 10.1;
			colorh = 1;
			break;
		case 12:

			numh1 = 10.2;
			colorh = 1;
			break;
		case 13:

			numh1 = 10.3;
			colorh = 1;
			break;
		case 14:

			numh1 = 11;
			numh2 = 1;
			colorh = 2;
			break;
		case 15:

			numh1 = 2;
			colorh = 2;
			break;
		case 16:

			numh1 = 3;
			colorh = 2;
			break;
		case 17:

			numh1 = 4;
			colorh = 2;
			break;
		case 18:

			numh1 = 5;
			colorh = 2;
			break;
		case 19:

			numh1 = 6;
			colorh = 2;
			break;
		case 20:

			numh1 = 7;
			colorh = 2;
			break;
		case 21:

			numh1 = 8;
			colorh = 2;
			break;
		case 22:

			numh1 = 9;
			colorh = 2;
			break;
		case 23:

			numh1 = 10;
			colorh = 2;
			break;
		case 24:

			numh1 = 10.1;
			colorh = 2;
			break;
		case 25:

			numh1 = 10.2;
			colorh = 2;
			break;
		case 26:

			numh1 = 10.3;
			colorh = 2;
			break;
		case 27:

			numh1 = 11;
			numh2 = 1;
			colorh = 3;
			break;
		case 28:

			numh1 = 2;
			colorh = 3;
			break;
		case 29:

			numh1 = 3;
			colorh = 3;
			break;
		case 30:

			numh1 = 4;
			colorh = 3;
			break;
		case 31:

			numh1 = 5;
			colorh = 3;
			break;
		case 32:

			numh1 = 6;
			colorh = 3;
			break;
		case 33:

			numh1 = 7;
			colorh = 3;
			break;
		case 34:

			numh1 = 8;
			colorh = 3;
			break;
		case 35:

			numh1 = 9;
			colorh = 3;
			break;
		case 36:

			numh1 = 10;
			colorh = 3;
			break;
		case 37:

			numh1 = 10.1;
			colorh = 3;
			break;
		case 38:

			numh1 = 10.2;
			colorh = 3;
			break;
		case 39:

			numh1 = 10.3;
			colorh = 3;
			break;
		case 40:

			numh1 = 11;
			numh2 = 1;
			colorh = 4;
			break;
		case 41:

			numh1 = 2;
			colorh = 4;
			break;
		case 42:

			numh1 = 3;
			colorh = 4;
			break;
		case 43:

			numh1 = 4;
			colorh = 4;
			break;
		case 44:

			numh1 = 5;
			colorh = 4;
			break;
		case 45:

			numh1 = 6;
			colorh = 4;
			break;
		case 46:

			numh1 = 7;
			colorh = 4;
			break;
		case 47:

			numh1 = 8;
			colorh = 4;
			break;
		case 48:

			numh1 = 9;
			colorh = 4;
			break;
		case 49:

			numh1 = 10;
			colorh = 4;
			break;
		case 50:

			numh1 = 10.1;
			colorh = 4;
			break;
		case 51:

			numh1 = 10.2;
			colorh = 4;
			break;
		case 52:

			numh1 = 10.3;
			colorh = 4;
			break;

		}


		winningSystem(userMoney, betAmount, betcount, numa1, numa2, colora, numb1, numb2, colorb, numc1, numc2, colorc, numd1, numd2, colord, nume1, nume2, colore, numf1, numf2, colorf, numg1, numg2, colorg, numh1, numh2, colorh);


		playAgain = endGame();

	} while (playAgain != 'N');
	printf("\n\n\t<THANKS FOR PLAYING!!>\n\n");
}

//========================================================

void showCardsonHand(char cardA1[], char cardA2[], char cardA3[], char cardA4[], char cardA5[], char cardA6[], char cardB1[], char cardB2[], char cardB3[], char cardB4[], char cardB5[], char cardB6[]) {

	printf(" _______________\t\t _______________\n");
	printf("|               |\t\t|               |\n");
	printf("|      %s      |\t\t|      %s      |\n", cardA1, cardB1);
	printf("|      %s       |\t\t|      %s       |\n", cardA2, cardB2);
	printf("|    %s   |\t\t|    %s   |\n", cardA3, cardB3);
	printf("|               |\t\t|               |\n");
	printf("|     %s     |\t\t|     %s     |\n", cardA4, cardB4);
	printf("|     %s     |\t\t|     %s     |\n", cardA5, cardB5);
	printf("|     %s     |\t\t|     %s     |\n", cardA6, cardB6);
	printf("|               |\t\t|               |\n");
	printf("|               |\t\t|               |\n");
	printf("|_______________|\t\t|_______________|\n");

}

void showCardsOnTableA(char cardC1[], char cardC2[], char cardC3[], char cardC4[], char cardC5[], char cardC6[]) {
	printf(" _______________\n");
	printf("|               |\n");
	printf("|      %s      |\n", cardC1);
	printf("|      %s       |\n", cardC2);
	printf("|    %s   |\n", cardC3);
	printf("|               |\n");
	printf("|     %s     |\n", cardC4);
	printf("|     %s     |\n", cardC5);
	printf("|     %s     |\n", cardC6);
	printf("|               |\n");
	printf("|               |\n");
	printf("|_______________|\n");
}

void showCardsOnTableB(char cardC1[], char cardC2[], char cardC3[], char cardC4[], char cardC5[], char cardC6[], char cardD1[], char cardD2[], char cardD3[], char cardD4[], char cardD5[], char cardD6[]) {
	printf(" _______________\t\t _______________\n");
	printf("|               |\t\t|               |\n");
	printf("|      %s      |\t\t|      %s      |\n", cardC1, cardD1);
	printf("|      %s       |\t\t|      %s       |\n", cardC2, cardD2);
	printf("|    %s   |\t\t|    %s   |\n", cardC3, cardD3);
	printf("|               |\t\t|               |\n");
	printf("|     %s     |\t\t|     %s     |\n", cardC4, cardD4);
	printf("|     %s     |\t\t|     %s     |\n", cardC5, cardD5);
	printf("|     %s     |\t\t|     %s     |\n", cardC6, cardD6);
	printf("|               |\t\t|               |\n");
	printf("|               |\t\t|               |\n");
	printf("|_______________|\t\t|_______________|\n");
}

void showCardsOnTableC(char cardC1[], char cardC2[], char cardC3[], char cardC4[], char cardC5[], char cardC6[], char cardD1[], char cardD2[], char cardD3[], char cardD4[], char cardD5[], char cardD6[], char cardE1[], char cardE2[], char cardE3[], char cardE4[], char cardE5[], char cardE6[]) {
	printf(" _______________\t\t _______________\t\t _______________\n");
	printf("|               |\t\t|               |\t\t|               |\n");
	printf("|      %s      |\t\t|      %s      |\t\t|      %s      |\n", cardC1, cardD1, cardE1);
	printf("|      %s       |\t\t|      %s       |\t\t|      %s       |\n", cardC2, cardD2, cardE2);
	printf("|    %s   |\t\t|    %s   |\t\t|    %s   |\n", cardC3, cardD3, cardE3);
	printf("|               |\t\t|               |\t\t|               |\n");
	printf("|     %s     |\t\t|     %s     |\t\t|     %s     |\n", cardC4, cardD4, cardE4);
	printf("|     %s     |\t\t|     %s     |\t\t|     %s     |\n", cardC5, cardD5, cardE5);
	printf("|     %s     |\t\t|     %s     |\t\t|     %s     |\n", cardC6, cardD6, cardE6);
	printf("|               |\t\t|               |\t\t|               |\n");
	printf("|               |\t\t|               |\t\t|               |\n");
	printf("|_______________|\t\t|_______________|\t\t|_______________|\n");
}

void showCardsOnTable(char cardC1[], char cardC2[], char cardC3[], char cardC4[], char cardC5[], char cardC6[], char cardD1[], char cardD2[], char cardD3[], char cardD4[], char cardD5[], char cardD6[], char cardE1[], char cardE2[], char cardE3[], char cardE4[], char cardE5[], char cardE6[], char cardF1[], char cardF2[], char cardF3[], char cardF4[], char cardF5[], char cardF6[]) {

	printf(" _______________\t\t _______________\t\t _______________\t\t _______________\n");
	printf("|               |\t\t|               |\t\t|               |\t\t|               |\n");
	printf("|      %s      |\t\t|      %s      |\t\t|      %s      |\t\t|      %s      |\n", cardC1, cardD1, cardE1, cardF1);
	printf("|      %s       |\t\t|      %s       |\t\t|      %s       |\t\t|      %s       |\n", cardC2, cardD2, cardE2, cardF2);
	printf("|    %s   |\t\t|    %s   |\t\t|    %s   |\t\t|    %s   |\n", cardC3, cardD3, cardE3, cardF3);
	printf("|               |\t\t|               |\t\t|               |\t\t|               |\n");
	printf("|     %s     |\t\t|     %s     |\t\t|     %s     |\t\t|     %s     |\n", cardC4, cardD4, cardE4, cardF4);
	printf("|     %s     |\t\t|     %s     |\t\t|     %s     |\t\t|     %s     |\n", cardC5, cardD5, cardE5, cardF5);
	printf("|     %s     |\t\t|     %s     |\t\t|     %s     |\t\t|     %s     |\n", cardC6, cardD6, cardE6, cardF6);
	printf("|               |\t\t|               |\t\t|               |\t\t|               |\n");
	printf("|               |\t\t|               |\t\t|               |\t\t|               |\n");
	printf("|_______________|\t\t|_______________|\t\t|_______________|\t\t|_______________|\n");
}

void showCardsopponent(char cardG1[], char cardG2[], char cardG3[], char cardG4[], char cardG5[], char cardG6[], char cardH1[], char cardH2[], char cardH3[], char cardH4[], char cardH5[], char cardH6[]) {

	printf(" _______________\t\t _______________\n");
	printf("|               |\t\t|               |\n");
	printf("|      %s      |\t\t|      %s      |\n", cardG1, cardH1);
	printf("|      %s       |\t\t|      %s       |\n", cardG2, cardH2);
	printf("|    %s   |\t\t|    %s   |\n", cardG3, cardH3);
	printf("|               |\t\t|               |\n");
	printf("|     %s     |\t\t|     %s     |\n", cardG4, cardH4);
	printf("|     %s     |\t\t|     %s     |\n", cardG5, cardH5);
	printf("|     %s     |\t\t|     %s     |\n", cardG6, cardH6);
	printf("|               |\t\t|               |\n");
	printf("|               |\t\t|               |\n");
	printf("|_______________|\t\t|_______________|\n");

}

void firstCardOfPlayer(int theRandNumber, char cardA1[], char cardA2[], char cardA3[], char cardA4[], char cardA5[], char cardA6[]) {
	// 1=hearts, 2=diamonds, 3=spades, 4=clubs
	int numa1 = 0, numa2 = 0, colora = 0;
	switch (theRandNumber) {
	case 1:

		strcpy(cardA1, "ACE");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " HEARTS ");
		strcpy(cardA4, "AA AA");
		strcpy(cardA5, " AAA ");
		strcpy(cardA6, "  A  ");

		numa1 = 11;
		numa2 = 1;
		colora = 1;

		break;
	case 2:

		strcpy(cardA1, " 2 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " HEARTS ");
		strcpy(cardA4, "22 22");
		strcpy(cardA5, " 222 ");
		strcpy(cardA6, "  2  ");


		numa1 = 2;
		colora = 1;
		break;
	case 3:

		strcpy(cardA1, " 3 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " HEARTS ");
		strcpy(cardA4, "33 33");
		strcpy(cardA5, " 333 ");
		strcpy(cardA6, "  3  ");


		numa1 = 3;
		colora = 1;
		break;
	case 4:

		strcpy(cardA1, " 4 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " HEARTS ");
		strcpy(cardA4, "44 44");
		strcpy(cardA5, " 444 ");
		strcpy(cardA6, "  4  ");


		numa1 = 4;
		colora = 1;
		break;
	case 5:

		strcpy(cardA1, " 5 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " HEARTS ");
		strcpy(cardA4, "55 55");
		strcpy(cardA5, " 555 ");
		strcpy(cardA6, "  5  ");


		numa1 = 5;
		colora = 1;
		break;
	case 6:

		strcpy(cardA1, " 6 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " HEARTS ");
		strcpy(cardA4, "66 66");
		strcpy(cardA5, " 666 ");
		strcpy(cardA6, "  6  ");


		numa1 = 6;
		colora = 1;
		break;
	case 7:

		strcpy(cardA1, " 7 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " HEARTS ");
		strcpy(cardA4, "77 77");
		strcpy(cardA5, " 777 ");
		strcpy(cardA6, "  7  ");


		numa1 = 7;
		colora = 1;
		break;
	case 8:

		strcpy(cardA1, " 8 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " HEARTS ");
		strcpy(cardA4, "88 88");
		strcpy(cardA5, " 888 ");
		strcpy(cardA6, "  8  ");


		numa1 = 8;
		colora = 1;
		break;
	case 9:

		strcpy(cardA1, " 9 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " HEARTS ");
		strcpy(cardA4, "99 99");
		strcpy(cardA5, " 999 ");
		strcpy(cardA6, "  9  ");


		numa1 = 9;
		colora = 1;
		break;
	case 10:

		strcpy(cardA1, "10 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " HEARTS ");
		strcpy(cardA4, "10 10");
		strcpy(cardA5, " 010 ");
		strcpy(cardA6, " 10  ");


		numa1 = 10;
		colora = 1;
		break;
	case 11:

		strcpy(cardA1, " J ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " HEARTS ");
		strcpy(cardA4, "JJ JJ");
		strcpy(cardA5, " JJJ ");
		strcpy(cardA6, "  J  ");


		numa1 = 11;
		colora = 1;
		break;
	case 12:

		strcpy(cardA1, " Q ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " HEARTS ");
		strcpy(cardA4, "QQ QQ");
		strcpy(cardA5, " QQQ ");
		strcpy(cardA6, "  Q  ");


		numa1 = 12;
		colora = 1;
		break;
	case 13:

		strcpy(cardA1, " K ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " HEARTS ");
		strcpy(cardA4, "KK KK");
		strcpy(cardA5, " KKK ");
		strcpy(cardA6, "  K  ");


		numa1 = 13;
		colora = 1;
		break;
	case 14:

		strcpy(cardA1, "ACE");
		strcpy(cardA2, "OF");
		strcpy(cardA3, "DIAMONDS");
		strcpy(cardA4, "  A  ");
		strcpy(cardA5, " AAA ");
		strcpy(cardA6, "  A  ");


		numa1 = 11;
		numa2 = 1;
		colora = 2;
		break;
	case 15:

		strcpy(cardA1, " 2 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, "DIAMONDS");
		strcpy(cardA4, "  2  ");
		strcpy(cardA5, " 222 ");
		strcpy(cardA6, "  2  ");


		numa1 = 2;
		colora = 2;
		break;
	case 16:

		strcpy(cardA1, " 3 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, "DIAMONDS");
		strcpy(cardA4, "  3  ");
		strcpy(cardA5, " 333 ");
		strcpy(cardA6, "  3  ");


		numa1 = 3;
		colora = 2;
		break;
	case 17:

		strcpy(cardA1, " 4 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, "DIAMONDS");
		strcpy(cardA4, "  4  ");
		strcpy(cardA5, " 444 ");
		strcpy(cardA6, "  4  ");


		numa1 = 4;
		colora = 2;
		break;
	case 18:

		strcpy(cardA1, " 5 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, "DIAMONDS");
		strcpy(cardA4, "  5  ");
		strcpy(cardA5, " 555 ");
		strcpy(cardA6, "  5  ");


		numa1 = 5;
		colora = 2;
		break;
	case 19:

		strcpy(cardA1, " 6 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, "DIAMONDS");
		strcpy(cardA4, "  6  ");
		strcpy(cardA5, " 666 ");
		strcpy(cardA6, "  6  ");


		numa1 = 6;
		colora = 2;
		break;
	case 20:

		strcpy(cardA1, " 7 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, "DIAMONDS");
		strcpy(cardA4, "  7  ");
		strcpy(cardA5, " 777 ");
		strcpy(cardA6, "  7  ");


		numa1 = 7;
		colora = 2;
		break;
	case 21:

		strcpy(cardA1, " 8 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, "DIAMONDS");
		strcpy(cardA4, "  8  ");
		strcpy(cardA5, " 888 ");
		strcpy(cardA6, "  8  ");


		numa1 = 8;
		colora = 2;
		break;
	case 22:

		strcpy(cardA1, " 9 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, "DIAMONDS");
		strcpy(cardA4, "  9  ");
		strcpy(cardA5, " 999 ");
		strcpy(cardA6, "  9  ");


		numa1 = 9;
		colora = 2;
		break;
	case 23:

		strcpy(cardA1, "10 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, "DIAMONDS");
		strcpy(cardA4, " 10  ");
		strcpy(cardA5, "1010 ");
		strcpy(cardA6, " 10  ");


		numa1 = 10;
		colora = 2;
		break;
	case 24:

		strcpy(cardA1, " J ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, "DIAMONDS");
		strcpy(cardA4, "  J  ");
		strcpy(cardA5, " JJJ ");
		strcpy(cardA6, "  J  ");


		numa1 = 11;
		colora = 2;
		break;
	case 25:

		strcpy(cardA1, " Q ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, "DIAMONDS");
		strcpy(cardA4, "  Q  ");
		strcpy(cardA5, " QQQ ");
		strcpy(cardA6, "  Q  ");


		numa1 = 12;
		colora = 2;
		break;
	case 26:

		strcpy(cardA1, " K ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, "DIAMONDS");
		strcpy(cardA4, "  K  ");
		strcpy(cardA5, " KKK ");
		strcpy(cardA6, "  K  ");


		numa1 = 13;
		colora = 2;
		break;
	case 27:

		strcpy(cardA1, "ACE");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " SPADES ");
		strcpy(cardA4, "  A  ");
		strcpy(cardA5, "AA AA");
		strcpy(cardA6, "  A  ");


		numa1 = 11;
		numa2 = 1;
		colora = 3;
		break;
	case 28:

		strcpy(cardA1, " 2 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " SPADES ");
		strcpy(cardA4, "  2  ");
		strcpy(cardA5, "22 22");
		strcpy(cardA6, "  2  ");


		numa1 = 2;
		colora = 3;
		break;
	case 29:

		strcpy(cardA1, " 3 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " SPADES ");
		strcpy(cardA4, "  3  ");
		strcpy(cardA5, "33 33");
		strcpy(cardA6, "  3  ");


		numa1 = 3;
		colora = 3;
		break;
	case 30:

		strcpy(cardA1, " 4 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " SPADES ");
		strcpy(cardA4, "  4  ");
		strcpy(cardA5, "44 44");
		strcpy(cardA6, "  4  ");


		numa1 = 4;
		colora = 3;
		break;
	case 31:

		strcpy(cardA1, " 5 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " SPADES ");
		strcpy(cardA4, "  5  ");
		strcpy(cardA5, "55 55");
		strcpy(cardA6, "  5  ");


		numa1 = 5;
		colora = 3;
		break;
	case 32:

		strcpy(cardA1, " 6 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " SPADES ");
		strcpy(cardA4, "  6  ");
		strcpy(cardA5, "66 66");
		strcpy(cardA6, "  6  ");


		numa1 = 6;
		colora = 3;
		break;
	case 33:

		strcpy(cardA1, " 7 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " SPADES ");
		strcpy(cardA4, "  7  ");
		strcpy(cardA5, "77 77");
		strcpy(cardA6, "  7  ");


		numa1 = 7;
		colora = 3;
		break;
	case 34:

		strcpy(cardA1, " 8 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " SPADES ");
		strcpy(cardA4, "  8  ");
		strcpy(cardA5, "88 88");
		strcpy(cardA6, "  8  ");


		numa1 = 8;
		colora = 3;
		break;
	case 35:

		strcpy(cardA1, " 9 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " SPADES ");
		strcpy(cardA4, "  9  ");
		strcpy(cardA5, "99 99");
		strcpy(cardA6, "  9  ");


		numa1 = 9;
		colora = 3;
		break;
	case 36:

		strcpy(cardA1, "10 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " SPADES ");
		strcpy(cardA4, " 10  ");
		strcpy(cardA5, "10 10");
		strcpy(cardA6, " 10  ");


		numa1 = 10;
		colora = 3;
		break;
	case 37:

		strcpy(cardA1, " J ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " SPADES ");
		strcpy(cardA4, "  J  ");
		strcpy(cardA5, "JJ JJ");
		strcpy(cardA6, "  J  ");


		numa1 = 11;
		colora = 3;
		break;
	case 38:

		strcpy(cardA1, " Q ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " SPADES ");
		strcpy(cardA4, "  Q  ");
		strcpy(cardA5, "QQ QQ");
		strcpy(cardA6, "  Q  ");


		numa1 = 12;
		colora = 3;
		break;
	case 39:

		strcpy(cardA1, " K ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " SPADES ");
		strcpy(cardA4, "  K  ");
		strcpy(cardA5, "KK KK");
		strcpy(cardA6, "  K  ");


		numa1 = 13;
		colora = 3;
		break;
	case 40:

		strcpy(cardA1, "ACE");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " CLUBS  ");
		strcpy(cardA4, " A A ");
		strcpy(cardA5, "  A  ");
		strcpy(cardA6, " A A ");


		numa1 = 1;
		numa2 = 11;
		colora = 4;
		break;
	case 41:

		strcpy(cardA1, " 2 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " CLUBS  ");
		strcpy(cardA4, " 2 2 ");
		strcpy(cardA5, "  2  ");
		strcpy(cardA6, " 2 2 ");


		numa1 = 2;
		colora = 4;
		break;
	case 42:

		strcpy(cardA1, " 3 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " CLUBS  ");
		strcpy(cardA4, " 3 3 ");
		strcpy(cardA5, "  3  ");
		strcpy(cardA6, " 3 3 ");


		numa1 = 3;
		colora = 4;
		break;
	case 43:

		strcpy(cardA1, " 4 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " CLUBS  ");
		strcpy(cardA4, " 4 4 ");
		strcpy(cardA5, "  4  ");
		strcpy(cardA6, " 4 4 ");


		numa1 = 4;
		colora = 4;
		break;
	case 44:

		strcpy(cardA1, " 5 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " CLUBS  ");
		strcpy(cardA4, " 5 5 ");
		strcpy(cardA5, "  5  ");
		strcpy(cardA6, " 5 5 ");


		numa1 = 5;
		colora = 4;
		break;
	case 45:

		strcpy(cardA1, " 6 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " CLUBS  ");
		strcpy(cardA4, " 6 6 ");
		strcpy(cardA5, "  6  ");
		strcpy(cardA6, " 6 6 ");


		numa1 = 6;
		colora = 4;
		break;
	case 46:

		strcpy(cardA1, " 7 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " CLUBS  ");
		strcpy(cardA4, " 7 7 ");
		strcpy(cardA5, "  7  ");
		strcpy(cardA6, " 7 7 ");


		numa1 = 7;
		colora = 4;
		break;
	case 47:

		strcpy(cardA1, " 8 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " CLUBS  ");
		strcpy(cardA4, " 8 8 ");
		strcpy(cardA5, "  8  ");
		strcpy(cardA6, " 8 8 ");


		numa1 = 8;
		colora = 4;
		break;
	case 48:

		strcpy(cardA1, " 9 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " CLUBS  ");
		strcpy(cardA4, " 9 9 ");
		strcpy(cardA5, "  9  ");
		strcpy(cardA6, " 9 9 ");


		numa1 = 9;
		colora = 4;
		break;
	case 49:

		strcpy(cardA1, "10 ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " CLUBS  ");
		strcpy(cardA4, "10 10");
		strcpy(cardA5, " 10  ");
		strcpy(cardA6, "10 10");


		numa1 = 10;
		colora = 4;
		break;
	case 50:

		strcpy(cardA1, " J ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " CLUBS  ");
		strcpy(cardA4, "JJ JJ");
		strcpy(cardA5, "  J  ");
		strcpy(cardA6, "JJ JJ");


		numa1 = 11;
		colora = 4;
		break;
	case 51:

		strcpy(cardA1, " Q ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " CLUBS  ");
		strcpy(cardA4, "QQ QQ");
		strcpy(cardA5, "  Q  ");
		strcpy(cardA6, "QQ QQ");


		numa1 = 12;
		colora = 4;
		break;
	case 52:

		strcpy(cardA1, " K ");
		strcpy(cardA2, "OF");
		strcpy(cardA3, " CLUBS  ");
		strcpy(cardA4, "KK KK");
		strcpy(cardA5, "  K  ");
		strcpy(cardA6, "KK KK");


		numa1 = 13;
		colora = 4;
		break;

	}


}

void secondCardOfPlayer(int theRandNumber2, char cardB1[], char cardB2[], char cardB3[], char cardB4[], char cardB5[], char cardB6[]) {
	int numb1 = 0, numb2 = 0, colorb = 0;
	// 1=hearts, 2=diamonds, 3=spades, 4=clubs

	switch (theRandNumber2) {
	case 1:

		strcpy(cardB1, "ACE");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " HEARTS ");
		strcpy(cardB4, "AA AA");
		strcpy(cardB5, " AAA ");
		strcpy(cardB6, "  A  ");

		numb1 = 11;
		numb2 = 1;
		colorb = 1;

		break;
	case 2:

		strcpy(cardB1, " 2 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " HEARTS ");
		strcpy(cardB4, "22 22");
		strcpy(cardB5, " 222 ");
		strcpy(cardB6, "  2  ");


		numb1 = 2;
		colorb = 1;
		break;
	case 3:

		strcpy(cardB1, " 3 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " HEARTS ");
		strcpy(cardB4, "33 33");
		strcpy(cardB5, " 333 ");
		strcpy(cardB6, "  3  ");


		numb1 = 3;
		colorb = 1;
		break;
	case 4:

		strcpy(cardB1, " 4 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " HEARTS ");
		strcpy(cardB4, "44 44");
		strcpy(cardB5, " 444 ");
		strcpy(cardB6, "  4  ");


		numb1 = 4;
		colorb = 1;
		break;
	case 5:

		strcpy(cardB1, " 5 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " HEARTS ");
		strcpy(cardB4, "55 55");
		strcpy(cardB5, " 555 ");
		strcpy(cardB6, "  5  ");


		numb1 = 5;
		colorb = 1;
		break;
	case 6:

		strcpy(cardB1, " 6 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " HEARTS ");
		strcpy(cardB4, "66 66");
		strcpy(cardB5, " 666 ");
		strcpy(cardB6, "  6  ");


		numb1 = 6;
		colorb = 1;
		break;
	case 7:

		strcpy(cardB1, " 7 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " HEARTS ");
		strcpy(cardB4, "77 77");
		strcpy(cardB5, " 777 ");
		strcpy(cardB6, "  7  ");


		numb1 = 7;
		colorb = 1;
		break;
	case 8:

		strcpy(cardB1, " 8 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " HEARTS ");
		strcpy(cardB4, "88 88");
		strcpy(cardB5, " 888 ");
		strcpy(cardB6, "  8  ");


		numb1 = 8;
		colorb = 1;
		break;
	case 9:

		strcpy(cardB1, " 9 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " HEARTS ");
		strcpy(cardB4, "99 99");
		strcpy(cardB5, " 999 ");
		strcpy(cardB6, "  9  ");


		numb1 = 9;
		colorb = 1;
		break;
	case 10:

		strcpy(cardB1, "10 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " HEARTS ");
		strcpy(cardB4, "10 10");
		strcpy(cardB5, " 010 ");
		strcpy(cardB6, " 10  ");


		numb1 = 10;
		colorb = 1;
		break;
	case 11:

		strcpy(cardB1, " J ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " HEARTS ");
		strcpy(cardB4, "JJ JJ");
		strcpy(cardB5, " JJJ ");
		strcpy(cardB6, "  J  ");


		numb1 = 11;
		colorb = 1;
		break;
	case 12:

		strcpy(cardB1, " Q ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " HEARTS ");
		strcpy(cardB4, "QQ QQ");
		strcpy(cardB5, " QQQ ");
		strcpy(cardB6, "  Q  ");


		numb1 = 12;
		colorb = 1;
		break;
	case 13:

		strcpy(cardB1, " K ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " HEARTS ");
		strcpy(cardB4, "KK KK");
		strcpy(cardB5, " KKK ");
		strcpy(cardB6, "  K  ");


		numb1 = 13;
		colorb = 1;
		break;
	case 14:

		strcpy(cardB1, "ACE");
		strcpy(cardB2, "OF");
		strcpy(cardB3, "DIAMONDS");
		strcpy(cardB4, "  A  ");
		strcpy(cardB5, " AAA ");
		strcpy(cardB6, "  A  ");


		numb1 = 1;
		numb2 = 11;
		colorb = 2;
		break;
	case 15:

		strcpy(cardB1, " 2 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, "DIAMONDS");
		strcpy(cardB4, "  2  ");
		strcpy(cardB5, " 222 ");
		strcpy(cardB6, "  2  ");


		numb1 = 2;
		colorb = 2;
		break;
	case 16:

		strcpy(cardB1, " 3 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, "DIAMONDS");
		strcpy(cardB4, "  3  ");
		strcpy(cardB5, " 333 ");
		strcpy(cardB6, "  3  ");


		numb1 = 3;
		colorb = 2;
		break;
	case 17:

		strcpy(cardB1, " 4 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, "DIAMONDS");
		strcpy(cardB4, "  4  ");
		strcpy(cardB5, " 444 ");
		strcpy(cardB6, "  4  ");


		numb1 = 4;
		colorb = 2;
		break;
	case 18:

		strcpy(cardB1, " 5 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, "DIAMONDS");
		strcpy(cardB4, "  5  ");
		strcpy(cardB5, " 555 ");
		strcpy(cardB6, "  5  ");


		numb1 = 5;
		colorb = 2;
		break;
	case 19:

		strcpy(cardB1, " 6 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, "DIAMONDS");
		strcpy(cardB4, "  6  ");
		strcpy(cardB5, " 666 ");
		strcpy(cardB6, "  6  ");


		numb1 = 6;
		colorb = 2;
		break;
	case 20:

		strcpy(cardB1, " 7 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, "DIAMONDS");
		strcpy(cardB4, "  7  ");
		strcpy(cardB5, " 777 ");
		strcpy(cardB6, "  7  ");


		numb1 = 7;
		colorb = 2;
		break;
	case 21:

		strcpy(cardB1, " 8 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, "DIAMONDS");
		strcpy(cardB4, "  8  ");
		strcpy(cardB5, " 888 ");
		strcpy(cardB6, "  8  ");


		numb1 = 8;
		colorb = 2;
		break;
	case 22:

		strcpy(cardB1, " 9 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, "DIAMONDS");
		strcpy(cardB4, "  9  ");
		strcpy(cardB5, " 999 ");
		strcpy(cardB6, "  9  ");


		numb1 = 9;
		colorb = 2;
		break;
	case 23:

		strcpy(cardB1, "10 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, "DIAMONDS");
		strcpy(cardB4, " 10  ");
		strcpy(cardB5, "1010 ");
		strcpy(cardB6, " 10  ");


		numb1 = 10;
		colorb = 2;
		break;
	case 24:

		strcpy(cardB1, " J ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, "DIAMONDS");
		strcpy(cardB4, "  J  ");
		strcpy(cardB5, " JJJ ");
		strcpy(cardB6, "  J  ");


		numb1 = 11;
		colorb = 2;
		break;
	case 25:

		strcpy(cardB1, " Q ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, "DIAMONDS");
		strcpy(cardB4, "  Q  ");
		strcpy(cardB5, " QQQ ");
		strcpy(cardB6, "  Q  ");


		numb1 = 12;
		colorb = 2;
		break;
	case 26:

		strcpy(cardB1, " K ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, "DIAMONDS");
		strcpy(cardB4, "  K  ");
		strcpy(cardB5, " KKK ");
		strcpy(cardB6, "  K  ");


		numb1 = 13;
		colorb = 2;
		break;
	case 27:

		strcpy(cardB1, "ACE");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " SPADES ");
		strcpy(cardB4, "  A  ");
		strcpy(cardB5, "AA AA");
		strcpy(cardB6, "  A  ");


		numb1 = 1;
		numb2 = 11;
		colorb = 3;
		break;
	case 28:

		strcpy(cardB1, " 2 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " SPADES ");
		strcpy(cardB4, "  2  ");
		strcpy(cardB5, "22 22");
		strcpy(cardB6, "  2  ");


		numb1 = 2;
		colorb = 3;
		break;
	case 29:

		strcpy(cardB1, " 3 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " SPADES ");
		strcpy(cardB4, "  3  ");
		strcpy(cardB5, "33 33");
		strcpy(cardB6, "  3  ");


		numb1 = 3;
		colorb = 3;
		break;
	case 30:

		strcpy(cardB1, " 4 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " SPADES ");
		strcpy(cardB4, "  4  ");
		strcpy(cardB5, "44 44");
		strcpy(cardB6, "  4  ");


		numb1 = 4;
		colorb = 3;
		break;
	case 31:

		strcpy(cardB1, " 5 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " SPADES ");
		strcpy(cardB4, "  5  ");
		strcpy(cardB5, "55 55");
		strcpy(cardB6, "  5  ");


		numb1 = 5;
		colorb = 3;
		break;
	case 32:

		strcpy(cardB1, " 6 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " SPADES ");
		strcpy(cardB4, "  6  ");
		strcpy(cardB5, "66 66");
		strcpy(cardB6, "  6  ");


		numb1 = 6;
		colorb = 3;
		break;
	case 33:

		strcpy(cardB1, " 7 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " SPADES ");
		strcpy(cardB4, "  7  ");
		strcpy(cardB5, "77 77");
		strcpy(cardB6, "  7  ");


		numb1 = 7;
		colorb = 3;
		break;
	case 34:

		strcpy(cardB1, " 8 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " SPADES ");
		strcpy(cardB4, "  8  ");
		strcpy(cardB5, "88 88");
		strcpy(cardB6, "  8  ");


		numb1 = 8;
		colorb = 3;
		break;
	case 35:

		strcpy(cardB1, " 9 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " SPADES ");
		strcpy(cardB4, "  9  ");
		strcpy(cardB5, "99 99");
		strcpy(cardB6, "  9  ");


		numb1 = 9;
		colorb = 3;
		break;
	case 36:

		strcpy(cardB1, "10 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " SPADES ");
		strcpy(cardB4, " 10  ");
		strcpy(cardB5, "10 10");
		strcpy(cardB6, " 10  ");


		numb1 = 10;
		colorb = 3;
		break;
	case 37:

		strcpy(cardB1, " J ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " SPADES ");
		strcpy(cardB4, "  J  ");
		strcpy(cardB5, "JJ JJ");
		strcpy(cardB6, " J  ");


		numb1 = 11;
		colorb = 3;
		break;
	case 38:

		strcpy(cardB1, " Q ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " SPADES ");
		strcpy(cardB4, "  Q  ");
		strcpy(cardB5, "QQ QQ");
		strcpy(cardB6, "  Q  ");


		numb1 = 12;
		colorb = 3;
		break;
	case 39:

		strcpy(cardB1, " K ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " SPADES ");
		strcpy(cardB4, "  K  ");
		strcpy(cardB5, "KK KK");
		strcpy(cardB6, "  K  ");


		numb1 = 13;
		colorb = 3;
		break;
	case 40:

		strcpy(cardB1, "ACE");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " CLUBS  ");
		strcpy(cardB4, " A A ");
		strcpy(cardB5, "  A  ");
		strcpy(cardB6, " A A ");


		numb1 = 1;
		numb2 = 11;
		colorb = 4;
		break;
	case 41:

		strcpy(cardB1, " 2 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " CLUBS  ");
		strcpy(cardB4, " 2 2 ");
		strcpy(cardB5, "  2  ");
		strcpy(cardB6, " 2 2 ");


		numb1 = 2;
		colorb = 4;
		break;
	case 42:

		strcpy(cardB1, " 3 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " CLUBS  ");
		strcpy(cardB4, " 3 3 ");
		strcpy(cardB5, "  3  ");
		strcpy(cardB6, " 3 3 ");


		numb1 = 3;
		colorb = 4;
		break;
	case 43:

		strcpy(cardB1, " 4 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " CLUBS  ");
		strcpy(cardB4, " 4 4 ");
		strcpy(cardB5, "  4  ");
		strcpy(cardB6, " 4 4 ");


		numb1 = 4;
		colorb = 4;
		break;
	case 44:

		strcpy(cardB1, " 5 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " CLUBS  ");
		strcpy(cardB4, " 5 5 ");
		strcpy(cardB5, "  5  ");
		strcpy(cardB6, " 5 5 ");


		numb1 = 5;
		colorb = 4;
		break;
	case 45:

		strcpy(cardB1, " 6 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " CLUBS  ");
		strcpy(cardB4, " 6 6 ");
		strcpy(cardB5, "  6  ");
		strcpy(cardB6, " 6 6 ");


		numb1 = 6;
		colorb = 4;
		break;
	case 46:

		strcpy(cardB1, " 7 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " CLUBS  ");
		strcpy(cardB4, " 7 7 ");
		strcpy(cardB5, "  7  ");
		strcpy(cardB6, " 7 7 ");


		numb1 = 7;
		colorb = 4;
		break;
	case 47:

		strcpy(cardB1, " 8 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " CLUBS  ");
		strcpy(cardB4, " 8 8 ");
		strcpy(cardB5, "  8  ");
		strcpy(cardB6, " 8 8 ");


		numb1 = 8;
		colorb = 4;
		break;
	case 48:

		strcpy(cardB1, " 9 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " CLUBS  ");
		strcpy(cardB4, " 9 9 ");
		strcpy(cardB5, "  9  ");
		strcpy(cardB6, " 9 9 ");


		numb1 = 9;
		colorb = 4;
		break;
	case 49:

		strcpy(cardB1, "10 ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " CLUBS  ");
		strcpy(cardB4, "10 10");
		strcpy(cardB5, " 10  ");
		strcpy(cardB6, "10 10");


		numb1 = 10;
		colorb = 4;
		break;
	case 50:

		strcpy(cardB1, " J ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " CLUBS  ");
		strcpy(cardB4, "JJ JJ");
		strcpy(cardB5, "  J  ");
		strcpy(cardB6, "JJ JJ");


		numb1 = 11;
		colorb = 4;
		break;
	case 51:

		strcpy(cardB1, " Q ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " CLUBS  ");
		strcpy(cardB4, "QQ QQ");
		strcpy(cardB5, "  Q ");
		strcpy(cardB6, "QQ QQ");


		numb1 = 12;
		colorb = 4;
		break;
	case 52:

		strcpy(cardB1, " K ");
		strcpy(cardB2, "OF");
		strcpy(cardB3, " CLUBS  ");
		strcpy(cardB4, "KK KK");
		strcpy(cardB5, "  K  ");
		strcpy(cardB6, "KK KK");


		numb1 = 13;
		colorb = 4;
		break;

	}

}

void firstCardOnTable(int theRandNumber3, char cardC1[], char cardC2[], char cardC3[], char cardC4[], char cardC5[], char cardC6[]) {
	int numc1 = 0, numc2 = 0, colorc = 0;
	// 1=hearts, 2=diamonds, 3=spades, 4=clubs

	switch (theRandNumber3) {
	case 1:

		strcpy(cardC1, "ACE");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " HEARTS ");
		strcpy(cardC4, "AA AA");
		strcpy(cardC5, " AAA ");
		strcpy(cardC6, "  A  ");

		numc1 = 11;
		numc2 = 1;
		colorc = 1;

		break;
	case 2:

		strcpy(cardC1, " 2 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " HEARTS ");
		strcpy(cardC4, "22 22");
		strcpy(cardC5, " 222 ");
		strcpy(cardC6, "  2  ");


		numc1 = 2;
		colorc = 1;
		break;
	case 3:

		strcpy(cardC1, " 3 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " HEARTS ");
		strcpy(cardC4, "33 33");
		strcpy(cardC5, " 333 ");
		strcpy(cardC6, "  3  ");


		numc1 = 3;
		colorc = 1;
		break;
	case 4:

		strcpy(cardC1, " 4 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " HEARTS ");
		strcpy(cardC4, "44 44");
		strcpy(cardC5, " 444 ");
		strcpy(cardC6, "  4  ");


		numc1 = 4;
		colorc = 1;
		break;
	case 5:

		strcpy(cardC1, " 5 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " HEARTS ");
		strcpy(cardC4, "55 55");
		strcpy(cardC5, " 555 ");
		strcpy(cardC6, "  5  ");


		numc1 = 5;
		colorc = 1;
		break;
	case 6:

		strcpy(cardC1, " 6 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " HEARTS ");
		strcpy(cardC4, "66 66");
		strcpy(cardC5, " 666 ");
		strcpy(cardC6, "  6  ");


		numc1 = 6;
		colorc = 1;
		break;
	case 7:

		strcpy(cardC1, " 7 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " HEARTS ");
		strcpy(cardC4, "77 77");
		strcpy(cardC5, " 777 ");
		strcpy(cardC6, "  7  ");


		numc1 = 7;
		colorc = 1;
		break;
	case 8:

		strcpy(cardC1, " 8 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " HEARTS ");
		strcpy(cardC4, "88 88");
		strcpy(cardC5, " 888 ");
		strcpy(cardC6, "  8  ");


		numc1 = 8;
		colorc = 1;
		break;
	case 9:

		strcpy(cardC1, " 9 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " HEARTS ");
		strcpy(cardC4, "99 99");
		strcpy(cardC5, " 999 ");
		strcpy(cardC6, "  9  ");


		numc1 = 9;
		colorc = 1;
		break;
	case 10:

		strcpy(cardC1, "10 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " HEARTS ");
		strcpy(cardC4, "10 10");
		strcpy(cardC5, " 010 ");
		strcpy(cardC6, " 10  ");


		numc1 = 10;
		colorc = 1;
		break;
	case 11:

		strcpy(cardC1, " J ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " HEARTS ");
		strcpy(cardC4, "JJ JJ");
		strcpy(cardC5, " JJJ ");
		strcpy(cardC6, "  J  ");


		numc1 = 11;
		colorc = 1;
		break;
	case 12:

		strcpy(cardC1, " Q ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " HEARTS ");
		strcpy(cardC4, "QQ QQ");
		strcpy(cardC5, " QQQ ");
		strcpy(cardC6, "  Q  ");


		numc1 = 12;
		colorc = 1;
		break;
	case 13:

		strcpy(cardC1, " K ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " HEARTS ");
		strcpy(cardC4, "KK KK");
		strcpy(cardC5, " KKK ");
		strcpy(cardC6, "  K  ");


		numc1 = 13;
		colorc = 1;
		break;
	case 14:

		strcpy(cardC1, "ACE");
		strcpy(cardC2, "OF");
		strcpy(cardC3, "DIAMONDS");
		strcpy(cardC4, "  A  ");
		strcpy(cardC5, " AAA ");
		strcpy(cardC6, "  A  ");


		numc1 = 1;
		numc2 = 11;
		colorc = 2;
		break;
	case 15:

		strcpy(cardC1, " 2 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, "DIAMONDS");
		strcpy(cardC4, "  2  ");
		strcpy(cardC5, " 222 ");
		strcpy(cardC6, "  2  ");


		numc1 = 2;
		colorc = 2;
		break;
	case 16:

		strcpy(cardC1, " 3 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, "DIAMONDS");
		strcpy(cardC4, "  3  ");
		strcpy(cardC5, " 333 ");
		strcpy(cardC6, "  3  ");


		numc1 = 3;
		colorc = 2;
		break;
	case 17:

		strcpy(cardC1, " 4 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, "DIAMONDS");
		strcpy(cardC4, "  4  ");
		strcpy(cardC5, " 444 ");
		strcpy(cardC6, "  4  ");


		numc1 = 4;
		colorc = 2;
		break;
	case 18:

		strcpy(cardC1, " 5 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, "DIAMONDS");
		strcpy(cardC4, "  5  ");
		strcpy(cardC5, " 555 ");
		strcpy(cardC6, "  5  ");


		numc1 = 5;
		colorc = 2;
		break;
	case 19:

		strcpy(cardC1, " 6 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, "DIAMONDS");
		strcpy(cardC4, "  6  ");
		strcpy(cardC5, " 666 ");
		strcpy(cardC6, "  6  ");


		numc1 = 6;
		colorc = 2;
		break;
	case 20:

		strcpy(cardC1, " 7 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, "DIAMONDS");
		strcpy(cardC4, "  7  ");
		strcpy(cardC5, " 777 ");
		strcpy(cardC6, "  7  ");


		numc1 = 7;
		colorc = 2;
		break;
	case 21:

		strcpy(cardC1, " 8 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, "DIAMONDS");
		strcpy(cardC4, "  8  ");
		strcpy(cardC5, " 888 ");
		strcpy(cardC6, "  8  ");


		numc1 = 8;
		colorc = 2;
		break;
	case 22:

		strcpy(cardC1, " 9 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, "DIAMONDS");
		strcpy(cardC4, "  9  ");
		strcpy(cardC5, " 999 ");
		strcpy(cardC6, "  9  ");


		numc1 = 9;
		colorc = 2;
		break;
	case 23:

		strcpy(cardC1, "10 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, "DIAMONDS");
		strcpy(cardC4, " 10  ");
		strcpy(cardC5, "1010 ");
		strcpy(cardC6, " 10  ");


		numc1 = 10;
		colorc = 2;
		break;
	case 24:

		strcpy(cardC1, " J ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, "DIAMONDS");
		strcpy(cardC4, "  J  ");
		strcpy(cardC5, " JJJ ");
		strcpy(cardC6, "  J  ");


		numc1 = 11;
		colorc = 2;
		break;
	case 25:

		strcpy(cardC1, " Q ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, "DIAMONDS");
		strcpy(cardC4, "  Q  ");
		strcpy(cardC5, " QQQ ");
		strcpy(cardC6, "  Q  ");


		numc1 = 12;
		colorc = 2;
		break;
	case 26:

		strcpy(cardC1, " K ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, "DIAMONDS");
		strcpy(cardC4, "  K  ");
		strcpy(cardC5, " KKK ");
		strcpy(cardC6, "  K  ");


		numc1 = 13;
		colorc = 2;
		break;
	case 27:

		strcpy(cardC1, "ACE");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " SPADES ");
		strcpy(cardC4, "  A  ");
		strcpy(cardC5, "AA AA");
		strcpy(cardC6, "  A  ");


		numc1 = 1;
		numc2 = 11;
		colorc = 3;
		break;
	case 28:

		strcpy(cardC1, " 2 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " SPADES ");
		strcpy(cardC4, "  2  ");
		strcpy(cardC5, "22 22");
		strcpy(cardC6, "  2  ");


		numc1 = 2;
		colorc = 3;
		break;
	case 29:

		strcpy(cardC1, " 3 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " SPADES ");
		strcpy(cardC4, "  3  ");
		strcpy(cardC5, "33 33");
		strcpy(cardC6, "  3  ");


		numc1 = 3;
		colorc = 3;
		break;
	case 30:

		strcpy(cardC1, " 4 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " SPADES ");
		strcpy(cardC4, "  4  ");
		strcpy(cardC5, "44 44");
		strcpy(cardC6, "  4  ");


		numc1 = 4;
		colorc = 3;
		break;
	case 31:

		strcpy(cardC1, " 5 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " SPADES ");
		strcpy(cardC4, "  5  ");
		strcpy(cardC5, "55 55");
		strcpy(cardC6, "  5  ");


		numc1 = 5;
		colorc = 3;
		break;
	case 32:

		strcpy(cardC1, " 6 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " SPADES ");
		strcpy(cardC4, "  6  ");
		strcpy(cardC5, "66 66");
		strcpy(cardC6, "  6  ");


		numc1 = 6;
		colorc = 3;
		break;
	case 33:

		strcpy(cardC1, " 7 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " SPADES ");
		strcpy(cardC4, "  7  ");
		strcpy(cardC5, "77 77");
		strcpy(cardC6, "  7  ");


		numc1 = 7;
		colorc = 3;
		break;
	case 34:

		strcpy(cardC1, " 8 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " SPADES ");
		strcpy(cardC4, "  8  ");
		strcpy(cardC5, "88 88");
		strcpy(cardC6, "  8  ");


		numc1 = 8;
		colorc = 3;
		break;
	case 35:

		strcpy(cardC1, " 9 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " SPADES ");
		strcpy(cardC4, "  9  ");
		strcpy(cardC5, "99 99");
		strcpy(cardC6, "  9  ");


		numc1 = 9;
		colorc = 3;
		break;
	case 36:

		strcpy(cardC1, "10 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " SPADES ");
		strcpy(cardC4, " 10  ");
		strcpy(cardC5, "10 10");
		strcpy(cardC6, " 10  ");


		numc1 = 10;
		colorc = 3;
		break;
	case 37:

		strcpy(cardC1, " J ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " SPADES ");
		strcpy(cardC4, "  J  ");
		strcpy(cardC5, "JJ JJ");
		strcpy(cardC6, "  J  ");


		numc1 = 11;
		colorc = 3;
		break;
	case 38:

		strcpy(cardC1, " Q ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " SPADES ");
		strcpy(cardC4, "  Q  ");
		strcpy(cardC5, "QQ QQ");
		strcpy(cardC6, "  Q  ");


		numc1 = 12;
		colorc = 3;
		break;
	case 39:

		strcpy(cardC1, " K ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " SPADES ");
		strcpy(cardC4, "  K  ");
		strcpy(cardC5, "KK KK");
		strcpy(cardC6, "  K  ");


		numc1 = 13;
		colorc = 3;
		break;
	case 40:

		strcpy(cardC1, "ACE");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " CLUBS  ");
		strcpy(cardC4, " A A ");
		strcpy(cardC5, "  A  ");
		strcpy(cardC6, " A A ");


		numc1 = 1;
		numc2 = 11;
		colorc = 4;
		break;
	case 41:

		strcpy(cardC1, " 2 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " CLUBS  ");
		strcpy(cardC4, " 2 2 ");
		strcpy(cardC5, "  2  ");
		strcpy(cardC6, " 2 2 ");


		numc1 = 2;
		colorc = 4;
		break;
	case 42:

		strcpy(cardC1, " 3 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " CLUBS  ");
		strcpy(cardC4, " 3 3 ");
		strcpy(cardC5, "  3  ");
		strcpy(cardC6, " 3 3 ");


		numc1 = 3;
		colorc = 4;
		break;
	case 43:

		strcpy(cardC1, " 4 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " CLUBS  ");
		strcpy(cardC4, " 4 4 ");
		strcpy(cardC5, "  4  ");
		strcpy(cardC6, " 4 4 ");


		numc1 = 4;
		colorc = 4;
		break;
	case 44:

		strcpy(cardC1, " 5 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " CLUBS  ");
		strcpy(cardC4, " 5 5 ");
		strcpy(cardC5, "  5  ");
		strcpy(cardC6, " 5 5 ");


		numc1 = 5;
		colorc = 4;
		break;
	case 45:

		strcpy(cardC1, " 6 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " CLUBS  ");
		strcpy(cardC4, " 6 6 ");
		strcpy(cardC5, "  6  ");
		strcpy(cardC6, " 6 6 ");


		numc1 = 6;
		colorc = 4;
		break;
	case 46:

		strcpy(cardC1, " 7 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " CLUBS  ");
		strcpy(cardC4, " 7 7 ");
		strcpy(cardC5, "  7  ");
		strcpy(cardC6, " 7 7 ");


		numc1 = 7;
		colorc = 4;
		break;
	case 47:

		strcpy(cardC1, " 8 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " CLUBS  ");
		strcpy(cardC4, " 8 8 ");
		strcpy(cardC5, "  8  ");
		strcpy(cardC6, " 8 8 ");


		numc1 = 8;
		colorc = 4;
		break;
	case 48:

		strcpy(cardC1, " 9 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " CLUBS  ");
		strcpy(cardC4, " 9 9 ");
		strcpy(cardC5, "  9  ");
		strcpy(cardC6, " 9 9 ");


		numc1 = 9;
		colorc = 4;
		break;
	case 49:

		strcpy(cardC1, "10 ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " CLUBS  ");
		strcpy(cardC4, "10 10");
		strcpy(cardC5, " 10  ");
		strcpy(cardC6, "10 10");


		numc1 = 10;
		colorc = 4;
		break;
	case 50:

		strcpy(cardC1, " J ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " CLUBS  ");
		strcpy(cardC4, "JJ JJ");
		strcpy(cardC5, "  J  ");
		strcpy(cardC6, "JJ JJ");


		numc1 = 11;
		colorc = 4;
		break;
	case 51:

		strcpy(cardC1, " Q ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " CLUBS  ");
		strcpy(cardC4, "QQ QQ");
		strcpy(cardC5, "  Q  ");
		strcpy(cardC6, "QQ QQ");


		numc1 = 12;
		colorc = 4;
		break;
	case 52:

		strcpy(cardC1, " K ");
		strcpy(cardC2, "OF");
		strcpy(cardC3, " CLUBS  ");
		strcpy(cardC4, "KK KK");
		strcpy(cardC5, "  K  ");
		strcpy(cardC6, "KK KK");


		numc1 = 13;
		colorc = 4;
		break;

	}

}

void secondCardOnTable(int theRandNumber4, char cardD1[], char cardD2[], char cardD3[], char cardD4[], char cardD5[], char cardD6[]) {
	// 1=hearts, 2=diamonds, 3=spades, 4=clubs
	int numd1 = 0, numd2 = 0, colord = 0;
	switch (theRandNumber4) {
	case 1:

		strcpy(cardD1, "ACE");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " HEARTS ");
		strcpy(cardD4, "AA AA");
		strcpy(cardD5, " AAA ");
		strcpy(cardD6, "  A  ");

		numd1 = 11;
		numd2 = 1;
		colord = 1;

		break;
	case 2:

		strcpy(cardD1, " 2 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " HEARTS ");
		strcpy(cardD4, "22 22");
		strcpy(cardD5, " 222 ");
		strcpy(cardD6, "  2  ");


		numd1 = 2;
		colord = 1;
		break;
	case 3:

		strcpy(cardD1, " 3 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " HEARTS ");
		strcpy(cardD4, "33 33");
		strcpy(cardD5, " 333 ");
		strcpy(cardD6, "  3  ");


		numd1 = 3;
		colord = 1;
		break;
	case 4:

		strcpy(cardD1, " 4 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " HEARTS ");
		strcpy(cardD4, "44 44");
		strcpy(cardD5, " 444 ");
		strcpy(cardD6, "  4  ");


		numd1 = 4;
		colord = 1;
		break;
	case 5:

		strcpy(cardD1, " 5 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " HEARTS ");
		strcpy(cardD4, "55 55");
		strcpy(cardD5, " 555 ");
		strcpy(cardD6, "  5  ");


		numd1 = 5;
		colord = 1;
		break;
	case 6:

		strcpy(cardD1, " 6 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " HEARTS ");
		strcpy(cardD4, "66 66");
		strcpy(cardD5, " 666 ");
		strcpy(cardD6, "  6  ");


		numd1 = 6;
		colord = 1;
		break;
	case 7:

		strcpy(cardD1, " 7 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " HEARTS ");
		strcpy(cardD4, "77 77");
		strcpy(cardD5, " 777 ");
		strcpy(cardD6, "  7  ");


		numd1 = 7;
		colord = 1;
		break;
	case 8:

		strcpy(cardD1, " 8 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " HEARTS ");
		strcpy(cardD4, "88 88");
		strcpy(cardD5, " 888 ");
		strcpy(cardD6, "  8  ");


		numd1 = 8;
		colord = 1;
		break;
	case 9:

		strcpy(cardD1, " 9 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " HEARTS ");
		strcpy(cardD4, "99 99");
		strcpy(cardD5, " 999 ");
		strcpy(cardD6, "  9  ");


		numd1 = 9;
		colord = 1;
		break;
	case 10:

		strcpy(cardD1, "10 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " HEARTS ");
		strcpy(cardD4, "10 10");
		strcpy(cardD5, " 010 ");
		strcpy(cardD6, " 10  ");


		numd1 = 10;
		colord = 1;
		break;
	case 11:

		strcpy(cardD1, " J ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " HEARTS ");
		strcpy(cardD4, "JJ JJ");
		strcpy(cardD5, " JJJ ");
		strcpy(cardD6, "  J  ");


		numd1 = 11;
		colord = 1;
		break;
	case 12:

		strcpy(cardD1, " Q ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " HEARTS ");
		strcpy(cardD4, "QQ QQ");
		strcpy(cardD5, " QQQ ");
		strcpy(cardD6, "  Q  ");


		numd1 = 12;
		colord = 1;
		break;
	case 13:

		strcpy(cardD1, " K ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " HEARTS ");
		strcpy(cardD4, "KK KK");
		strcpy(cardD5, " KKK ");
		strcpy(cardD6, "  K  ");


		numd1 = 13;
		colord = 1;
		break;
	case 14:

		strcpy(cardD1, "ACE");
		strcpy(cardD2, "OF");
		strcpy(cardD3, "DIAMONDS");
		strcpy(cardD4, "  A  ");
		strcpy(cardD5, " AAA ");
		strcpy(cardD6, "  A  ");


		numd1 = 1;
		numd2 = 11;
		colord = 2;
		break;
	case 15:

		strcpy(cardD1, " 2 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, "DIAMONDS");
		strcpy(cardD4, "  2  ");
		strcpy(cardD5, " 222 ");
		strcpy(cardD6, "  2  ");


		numd1 = 2;
		colord = 2;
		break;
	case 16:

		strcpy(cardD1, " 3 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, "DIAMONDS");
		strcpy(cardD4, "  3  ");
		strcpy(cardD5, " 333 ");
		strcpy(cardD6, "  3  ");


		numd1 = 3;
		colord = 2;
		break;
	case 17:

		strcpy(cardD1, " 4 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, "DIAMONDS");
		strcpy(cardD4, "  4  ");
		strcpy(cardD5, " 444 ");
		strcpy(cardD6, "  4  ");


		numd1 = 4;
		colord = 2;
		break;
	case 18:

		strcpy(cardD1, " 5 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, "DIAMONDS");
		strcpy(cardD4, "  5  ");
		strcpy(cardD5, " 555 ");
		strcpy(cardD6, "  5  ");


		numd1 = 5;
		colord = 2;
		break;
	case 19:

		strcpy(cardD1, " 6 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, "DIAMONDS");
		strcpy(cardD4, "  6  ");
		strcpy(cardD5, " 666 ");
		strcpy(cardD6, "  6  ");


		numd1 = 6;
		colord = 2;
		break;
	case 20:

		strcpy(cardD1, " 7 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, "DIAMONDS");
		strcpy(cardD4, "  7  ");
		strcpy(cardD5, " 777 ");
		strcpy(cardD6, "  7  ");


		numd1 = 7;
		colord = 2;
		break;
	case 21:

		strcpy(cardD1, " 8 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, "DIAMONDS");
		strcpy(cardD4, "  8  ");
		strcpy(cardD5, " 888 ");
		strcpy(cardD6, "  8  ");


		numd1 = 8;
		colord = 2;
		break;
	case 22:

		strcpy(cardD1, " 9 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, "DIAMONDS");
		strcpy(cardD4, "  9  ");
		strcpy(cardD5, " 999 ");
		strcpy(cardD6, "  9  ");


		numd1 = 9;
		colord = 2;
		break;
	case 23:

		strcpy(cardD1, "10 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, "DIAMONDS");
		strcpy(cardD4, " 10  ");
		strcpy(cardD5, "1010 ");
		strcpy(cardD6, " 10  ");


		numd1 = 10;
		colord = 2;
		break;
	case 24:

		strcpy(cardD1, " J ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, "DIAMONDS");
		strcpy(cardD4, "  J  ");
		strcpy(cardD5, " JJJ ");
		strcpy(cardD6, "  J  ");


		numd1 = 11;
		colord = 2;
		break;
	case 25:

		strcpy(cardD1, " Q ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, "DIAMONDS");
		strcpy(cardD4, "  Q  ");
		strcpy(cardD5, " QQQ ");
		strcpy(cardD6, "  Q  ");


		numd1 = 12;
		colord = 2;
		break;
	case 26:

		strcpy(cardD1, " K ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, "DIAMONDS");
		strcpy(cardD4, "  K  ");
		strcpy(cardD5, " KKK ");
		strcpy(cardD6, "  K  ");


		numd1 = 13;
		colord = 2;
		break;
	case 27:

		strcpy(cardD1, "ACE");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " SPADES ");
		strcpy(cardD4, "  A  ");
		strcpy(cardD5, "AA AA");
		strcpy(cardD6, "  A  ");


		numd1 = 1;
		numd2 = 11;
		colord = 3;
		break;
	case 28:

		strcpy(cardD1, " 2 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " SPADES ");
		strcpy(cardD4, "  2  ");
		strcpy(cardD5, "22 22");
		strcpy(cardD6, "  2  ");


		numd1 = 2;
		colord = 3;
		break;
	case 29:

		strcpy(cardD1, " 3 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " SPADES ");
		strcpy(cardD4, "  3  ");
		strcpy(cardD5, "33 33");
		strcpy(cardD6, "  3  ");


		numd1 = 3;
		colord = 3;
		break;
	case 30:

		strcpy(cardD1, " 4 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " SPADES ");
		strcpy(cardD4, "  4  ");
		strcpy(cardD5, "44 44");
		strcpy(cardD6, "  4  ");


		numd1 = 4;
		colord = 3;
		break;
	case 31:

		strcpy(cardD1, " 5 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " SPADES ");
		strcpy(cardD4, "  5  ");
		strcpy(cardD5, "55 55");
		strcpy(cardD6, "  5  ");


		numd1 = 5;
		colord = 3;
		break;
	case 32:

		strcpy(cardD1, " 6 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " SPADES ");
		strcpy(cardD4, "  6  ");
		strcpy(cardD5, "66 66");
		strcpy(cardD6, "  6  ");


		numd1 = 6;
		colord = 3;
		break;
	case 33:

		strcpy(cardD1, " 7 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " SPADES ");
		strcpy(cardD4, "  7  ");
		strcpy(cardD5, "77 77");
		strcpy(cardD6, "  7  ");


		numd1 = 7;
		colord = 3;
		break;
	case 34:

		strcpy(cardD1, " 8 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " SPADES ");
		strcpy(cardD4, "  8  ");
		strcpy(cardD5, "88 88");
		strcpy(cardD6, "  8  ");


		numd1 = 8;
		colord = 3;
		break;
	case 35:

		strcpy(cardD1, " 9 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " SPADES ");
		strcpy(cardD4, "  9  ");
		strcpy(cardD5, "99 99");
		strcpy(cardD6, "  9  ");


		numd1 = 9;
		colord = 3;
		break;
	case 36:

		strcpy(cardD1, "10 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " SPADES ");
		strcpy(cardD4, " 10  ");
		strcpy(cardD5, "10 10");
		strcpy(cardD6, " 10  ");


		numd1 = 10;
		colord = 3;
		break;
	case 37:

		strcpy(cardD1, " J ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " SPADES ");
		strcpy(cardD4, "  J  ");
		strcpy(cardD5, "JJ JJ");
		strcpy(cardD6, "  J  ");


		numd1 = 11;
		colord = 3;
		break;
	case 38:

		strcpy(cardD1, " Q ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " SPADES ");
		strcpy(cardD4, "  Q  ");
		strcpy(cardD5, "QQ QQ");
		strcpy(cardD6, "  Q  ");


		numd1 = 12;
		colord = 3;
		break;
	case 39:

		strcpy(cardD1, " K ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " SPADES ");
		strcpy(cardD4, "  K  ");
		strcpy(cardD5, "KK KK");
		strcpy(cardD6, "  K  ");


		numd1 = 13;
		colord = 3;
		break;
	case 40:

		strcpy(cardD1, "ACE");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " CLUBS  ");
		strcpy(cardD4, " A A ");
		strcpy(cardD5, "  A  ");
		strcpy(cardD6, " A A ");


		numd1 = 1;
		numd2 = 11;
		colord = 4;
		break;
	case 41:

		strcpy(cardD1, " 2 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " CLUBS  ");
		strcpy(cardD4, " 2 2 ");
		strcpy(cardD5, "  2  ");
		strcpy(cardD6, " 2 2 ");


		numd1 = 2;
		colord = 4;
		break;
	case 42:

		strcpy(cardD1, " 3 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " CLUBS  ");
		strcpy(cardD4, " 3 3 ");
		strcpy(cardD5, "  3  ");
		strcpy(cardD6, " 3 3 ");


		numd1 = 3;
		colord = 4;
		break;
	case 43:

		strcpy(cardD1, " 4 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " CLUBS  ");
		strcpy(cardD4, " 4 4 ");
		strcpy(cardD5, "  4  ");
		strcpy(cardD6, " 4 4 ");


		numd1 = 4;
		colord = 4;
		break;
	case 44:

		strcpy(cardD1, " 5 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " CLUBS  ");
		strcpy(cardD4, " 5 5 ");
		strcpy(cardD5, "  5  ");
		strcpy(cardD6, " 5 5 ");


		numd1 = 5;
		colord = 4;
		break;
	case 45:

		strcpy(cardD1, " 6 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " CLUBS  ");
		strcpy(cardD4, " 6 6 ");
		strcpy(cardD5, "  6  ");
		strcpy(cardD6, " 6 6 ");


		numd1 = 6;
		colord = 4;
		break;
	case 46:

		strcpy(cardD1, " 7 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " CLUBS  ");
		strcpy(cardD4, " 7 7 ");
		strcpy(cardD5, "  7  ");
		strcpy(cardD6, " 7 7 ");


		numd1 = 7;
		colord = 4;
		break;
	case 47:

		strcpy(cardD1, " 8 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " CLUBS  ");
		strcpy(cardD4, " 8 8 ");
		strcpy(cardD5, "  8  ");
		strcpy(cardD6, " 8 8 ");


		numd1 = 8;
		colord = 4;
		break;
	case 48:

		strcpy(cardD1, " 9 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " CLUBS  ");
		strcpy(cardD4, " 9 9 ");
		strcpy(cardD5, "  9  ");
		strcpy(cardD6, " 9 9 ");


		numd1 = 9;
		colord = 4;
		break;
	case 49:

		strcpy(cardD1, "10 ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " CLUBS  ");
		strcpy(cardD4, "10 10");
		strcpy(cardD5, " 10  ");
		strcpy(cardD6, "10 10");


		numd1 = 10;
		colord = 4;
		break;
	case 50:

		strcpy(cardD1, " J ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " CLUBS  ");
		strcpy(cardD4, "JJ JJ");
		strcpy(cardD5, "  J  ");
		strcpy(cardD6, "JJ JJ");


		numd1 = 11;
		colord = 4;
		break;
	case 51:

		strcpy(cardD1, " Q ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " CLUBS  ");
		strcpy(cardD4, "QQ QQ");
		strcpy(cardD5, "  Q  ");
		strcpy(cardD6, "QQ QQ");


		numd1 = 12;
		colord = 4;
		break;
	case 52:

		strcpy(cardD1, " K ");
		strcpy(cardD2, "OF");
		strcpy(cardD3, " CLUBS  ");
		strcpy(cardD4, "KK KK");
		strcpy(cardD5, "  K  ");
		strcpy(cardD6, "KK KK");


		numd1 = 13;
		colord = 4;
		break;

	}

}

void thirdCardOnTable(int theRandNumber5, char cardE1[], char cardE2[], char cardE3[], char cardE4[], char cardE5[], char cardE6[]) {
	int nume1 = 0, nume2 = 0, colore = 0;
	// 1=hearts, 2=diamonds, 3=spades, 4=clubs

	switch (theRandNumber5) {
	case 1:

		strcpy(cardE1, "ACE");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " HEARTS ");
		strcpy(cardE4, "AA AA");
		strcpy(cardE5, " AAA ");
		strcpy(cardE6, "  A  ");

		nume1 = 11;
		nume2 = 1;
		colore = 1;

		break;
	case 2:

		strcpy(cardE1, " 2 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " HEARTS ");
		strcpy(cardE4, "22 22");
		strcpy(cardE5, " 222 ");
		strcpy(cardE6, "  2  ");


		nume1 = 2;
		colore = 1;
		break;
	case 3:

		strcpy(cardE1, " 3 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " HEARTS ");
		strcpy(cardE4, "33 33");
		strcpy(cardE5, " 333 ");
		strcpy(cardE6, "  3  ");


		nume1 = 3;
		colore = 1;
		break;
	case 4:

		strcpy(cardE1, " 4 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " HEARTS ");
		strcpy(cardE4, "44 44");
		strcpy(cardE5, " 444 ");
		strcpy(cardE6, "  4  ");


		nume1 = 4;
		colore = 1;
		break;
	case 5:

		strcpy(cardE1, " 5 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " HEARTS ");
		strcpy(cardE4, "55 55");
		strcpy(cardE5, " 555 ");
		strcpy(cardE6, "  5  ");


		nume1 = 5;
		colore = 1;
		break;
	case 6:

		strcpy(cardE1, " 6 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " HEARTS ");
		strcpy(cardE4, "66 66");
		strcpy(cardE5, " 666 ");
		strcpy(cardE6, "  6  ");


		nume1 = 6;
		colore = 1;
		break;
	case 7:

		strcpy(cardE1, " 7 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " HEARTS ");
		strcpy(cardE4, "77 77");
		strcpy(cardE5, " 777 ");
		strcpy(cardE6, "  7  ");


		nume1 = 7;
		colore = 1;
		break;
	case 8:

		strcpy(cardE1, " 8 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " HEARTS ");
		strcpy(cardE4, "88 88");
		strcpy(cardE5, " 888 ");
		strcpy(cardE6, "  8  ");


		nume1 = 8;
		colore = 1;
		break;
	case 9:

		strcpy(cardE1, " 9 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " HEARTS ");
		strcpy(cardE4, "99 99");
		strcpy(cardE5, " 999 ");
		strcpy(cardE6, "  9  ");


		nume1 = 9;
		colore = 1;
		break;
	case 10:

		strcpy(cardE1, "10 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " HEARTS ");
		strcpy(cardE4, "10 10");
		strcpy(cardE5, " 010 ");
		strcpy(cardE6, " 10  ");


		nume1 = 10;
		colore = 1;
		break;
	case 11:

		strcpy(cardE1, " J ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " HEARTS ");
		strcpy(cardE4, "JJ JJ");
		strcpy(cardE5, " JJJ ");
		strcpy(cardE6, "  J  ");


		nume1 = 11;
		colore = 1;
		break;
	case 12:

		strcpy(cardE1, " Q ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " HEARTS ");
		strcpy(cardE4, "QQ QQ");
		strcpy(cardE5, " QQQ ");
		strcpy(cardE6, "  Q  ");


		nume1 = 12;
		colore = 1;
		break;
	case 13:

		strcpy(cardE1, " K ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " HEARTS ");
		strcpy(cardE4, "KK KK");
		strcpy(cardE5, " KKK ");
		strcpy(cardE6, "  K  ");


		nume1 = 13;
		colore = 1;
		break;
	case 14:

		strcpy(cardE1, "ACE");
		strcpy(cardE2, "OF");
		strcpy(cardE3, "DIAMONDS");
		strcpy(cardE4, "  A  ");
		strcpy(cardE5, " AAA ");
		strcpy(cardE6, "  A  ");


		nume1 = 1;
		nume2 = 11;
		colore = 2;
		break;
	case 15:

		strcpy(cardE1, " 2 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, "DIAMONDS");
		strcpy(cardE4, "  2  ");
		strcpy(cardE5, " 222 ");
		strcpy(cardE6, "  2  ");


		nume1 = 2;
		colore = 2;
		break;
	case 16:

		strcpy(cardE1, " 3 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, "DIAMONDS");
		strcpy(cardE4, "  3  ");
		strcpy(cardE5, " 333 ");
		strcpy(cardE6, "  3  ");


		nume1 = 3;
		colore = 2;
		break;
	case 17:

		strcpy(cardE1, " 4 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, "DIAMONDS");
		strcpy(cardE4, "  4  ");
		strcpy(cardE5, " 444 ");
		strcpy(cardE6, "  4  ");


		nume1 = 4;
		colore = 2;
		break;
	case 18:

		strcpy(cardE1, " 5 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, "DIAMONDS");
		strcpy(cardE4, "  5  ");
		strcpy(cardE5, " 555 ");
		strcpy(cardE6, "  5  ");


		nume1 = 5;
		colore = 2;
		break;
	case 19:

		strcpy(cardE1, " 6 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, "DIAMONDS");
		strcpy(cardE4, "  6  ");
		strcpy(cardE5, " 666 ");
		strcpy(cardE6, "  6  ");


		nume1 = 6;
		colore = 2;
		break;
	case 20:

		strcpy(cardE1, " 7 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, "DIAMONDS");
		strcpy(cardE4, "  7  ");
		strcpy(cardE5, " 777 ");
		strcpy(cardE6, "  7  ");


		nume1 = 7;
		colore = 2;
		break;
	case 21:

		strcpy(cardE1, " 8 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, "DIAMONDS");
		strcpy(cardE4, "  8  ");
		strcpy(cardE5, " 888 ");
		strcpy(cardE6, "  8  ");


		nume1 = 8;
		colore = 2;
		break;
	case 22:

		strcpy(cardE1, " 9 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, "DIAMONDS");
		strcpy(cardE4, "  9  ");
		strcpy(cardE5, " 999 ");
		strcpy(cardE6, "  9  ");


		nume1 = 9;
		colore = 2;
		break;
	case 23:

		strcpy(cardE1, "10 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, "DIAMONDS");
		strcpy(cardE4, " 10  ");
		strcpy(cardE5, "1010 ");
		strcpy(cardE6, " 10  ");


		nume1 = 10;
		colore = 2;
		break;
	case 24:

		strcpy(cardE1, " J ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, "DIAMONDS");
		strcpy(cardE4, "  J  ");
		strcpy(cardE5, " JJJ ");
		strcpy(cardE6, "  J  ");


		nume1 = 11;
		colore = 2;
		break;
	case 25:

		strcpy(cardE1, " Q ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, "DIAMONDS");
		strcpy(cardE4, "  Q  ");
		strcpy(cardE5, " QQQ ");
		strcpy(cardE6, "  Q  ");


		nume1 = 12;
		colore = 2;
		break;
	case 26:

		strcpy(cardE1, " K ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, "DIAMONDS");
		strcpy(cardE4, "  K  ");
		strcpy(cardE5, " KKK ");
		strcpy(cardE6, "  K  ");


		nume1 = 13;
		colore = 2;
		break;
	case 27:

		strcpy(cardE1, "ACE");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " SPADES ");
		strcpy(cardE4, "  A  ");
		strcpy(cardE5, "AA AA");
		strcpy(cardE6, "  A  ");


		nume1 = 1;
		nume2 = 11;
		colore = 3;
		break;
	case 28:

		strcpy(cardE1, " 2 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " SPADES ");
		strcpy(cardE4, "  2  ");
		strcpy(cardE5, "22 22");
		strcpy(cardE6, "  2  ");


		nume1 = 2;
		colore = 3;
		break;
	case 29:

		strcpy(cardE1, " 3 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " SPADES ");
		strcpy(cardE4, "  3  ");
		strcpy(cardE5, "33 33");
		strcpy(cardE6, "  3  ");


		nume1 = 3;
		colore = 3;
		break;
	case 30:

		strcpy(cardE1, " 4 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " SPADES ");
		strcpy(cardE4, "  4  ");
		strcpy(cardE5, "44 44");
		strcpy(cardE6, "  4  ");


		nume1 = 4;
		colore = 3;
		break;
	case 31:

		strcpy(cardE1, " 5 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " SPADES ");
		strcpy(cardE4, "  5  ");
		strcpy(cardE5, "55 55");
		strcpy(cardE6, "  5  ");


		nume1 = 5;
		colore = 3;
		break;
	case 32:

		strcpy(cardE1, " 6 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " SPADES ");
		strcpy(cardE4, "  6  ");
		strcpy(cardE5, "66 66");
		strcpy(cardE6, "  6  ");


		nume1 = 6;
		colore = 3;
		break;
	case 33:

		strcpy(cardE1, " 7 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " SPADES ");
		strcpy(cardE4, "  7  ");
		strcpy(cardE5, "77 77");
		strcpy(cardE6, "  7  ");


		nume1 = 7;
		colore = 3;
		break;
	case 34:

		strcpy(cardE1, " 8 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " SPADES ");
		strcpy(cardE4, "  8  ");
		strcpy(cardE5, "88 88");
		strcpy(cardE6, "  8  ");


		nume1 = 8;
		colore = 3;
		break;
	case 35:

		strcpy(cardE1, " 9 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " SPADES ");
		strcpy(cardE4, "  9  ");
		strcpy(cardE5, "99 99");
		strcpy(cardE6, "  9  ");


		nume1 = 9;
		colore = 3;
		break;
	case 36:

		strcpy(cardE1, "10 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " SPADES ");
		strcpy(cardE4, " 10  ");
		strcpy(cardE5, "10 10");
		strcpy(cardE6, " 10  ");


		nume1 = 10;
		colore = 3;
		break;
	case 37:

		strcpy(cardE1, " J ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " SPADES ");
		strcpy(cardE4, "  J  ");
		strcpy(cardE5, "JJ JJ");
		strcpy(cardE6, "  J  ");


		nume1 = 11;
		colore = 3;
		break;
	case 38:

		strcpy(cardE1, " Q ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " SPADES ");
		strcpy(cardE4, "  Q  ");
		strcpy(cardE5, "QQ QQ");
		strcpy(cardE6, "  Q  ");


		nume1 = 12;
		colore = 3;
		break;
	case 39:

		strcpy(cardE1, " K ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " SPADES ");
		strcpy(cardE4, "  K  ");
		strcpy(cardE5, "KK KK");
		strcpy(cardE6, "  K  ");


		nume1 = 13;
		colore = 3;
		break;
	case 40:

		strcpy(cardE1, "ACE");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " CLUBS  ");
		strcpy(cardE4, " A A ");
		strcpy(cardE5, "  A  ");
		strcpy(cardE6, " A A ");


		nume1 = 1;
		nume2 = 11;
		colore = 4;
		break;
	case 41:

		strcpy(cardE1, " 2 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " CLUBS  ");
		strcpy(cardE4, " 2 2 ");
		strcpy(cardE5, "  2  ");
		strcpy(cardE6, " 2 2 ");


		nume1 = 2;
		colore = 4;
		break;
	case 42:

		strcpy(cardE1, " 3 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " CLUBS  ");
		strcpy(cardE4, " 3 3 ");
		strcpy(cardE5, "  3  ");
		strcpy(cardE6, " 3 3 ");


		nume1 = 3;
		colore = 4;
		break;
	case 43:

		strcpy(cardE1, " 4 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " CLUBS  ");
		strcpy(cardE4, " 4 4 ");
		strcpy(cardE5, "  4  ");
		strcpy(cardE6, " 4 4 ");


		nume1 = 4;
		colore = 4;
		break;
	case 44:

		strcpy(cardE1, " 5 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " CLUBS  ");
		strcpy(cardE4, " 5 5 ");
		strcpy(cardE5, "  5  ");
		strcpy(cardE6, " 5 5 ");


		nume1 = 5;
		colore = 4;
		break;
	case 45:

		strcpy(cardE1, " 6 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " CLUBS  ");
		strcpy(cardE4, " 6 6 ");
		strcpy(cardE5, "  6  ");
		strcpy(cardE6, " 6 6 ");


		nume1 = 6;
		colore = 4;
		break;
	case 46:

		strcpy(cardE1, " 7 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " CLUBS  ");
		strcpy(cardE4, " 7 7 ");
		strcpy(cardE5, "  7  ");
		strcpy(cardE6, " 7 7 ");


		nume1 = 7;
		colore = 4;
		break;
	case 47:

		strcpy(cardE1, " 8 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " CLUBS  ");
		strcpy(cardE4, " 8 8 ");
		strcpy(cardE5, "  8  ");
		strcpy(cardE6, " 8 8 ");


		nume1 = 8;
		colore = 4;
		break;
	case 48:

		strcpy(cardE1, " 9 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " CLUBS  ");
		strcpy(cardE4, " 9 9 ");
		strcpy(cardE5, "  9  ");
		strcpy(cardE6, " 9 9 ");


		nume1 = 9;
		colore = 4;
		break;
	case 49:

		strcpy(cardE1, "10 ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " CLUBS  ");
		strcpy(cardE4, "10 10");
		strcpy(cardE5, " 10  ");
		strcpy(cardE6, "10 10");


		nume1 = 10;
		colore = 4;
		break;
	case 50:

		strcpy(cardE1, " J ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " CLUBS  ");
		strcpy(cardE4, "JJ JJ");
		strcpy(cardE5, "  J  ");
		strcpy(cardE6, "JJ JJ");


		nume1 = 11;
		colore = 4;
		break;
	case 51:

		strcpy(cardE1, " Q ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " CLUBS  ");
		strcpy(cardE4, "QQ QQ");
		strcpy(cardE5, "  Q  ");
		strcpy(cardE6, "QQ QQ");


		nume1 = 12;
		colore = 4;
		break;
	case 52:

		strcpy(cardE1, " K ");
		strcpy(cardE2, "OF");
		strcpy(cardE3, " CLUBS  ");
		strcpy(cardE4, "KK KK");
		strcpy(cardE5, "  K  ");
		strcpy(cardE6, "KK KK");


		nume1 = 13;
		colore = 4;
		break;

	}


}

void fourthCardOnTable(int theRandNumber6, char cardF1[], char cardF2[], char cardF3[], char cardF4[], char cardF5[], char cardF6[]) {

	// 1=hearts, 2=diamonds, 3=spades, 4=clubs
	int numf1 = 0, numf2 = 0, colorf = 0;
	switch (theRandNumber6) {
	case 1:

		strcpy(cardF1, "ACE");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " HEARTS ");
		strcpy(cardF4, "AA AA");
		strcpy(cardF5, " AAA ");
		strcpy(cardF6, "  A  ");

		numf1 = 11;
		numf2 = 1;
		colorf = 1;

		break;
	case 2:

		strcpy(cardF1, " 2 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " HEARTS ");
		strcpy(cardF4, "22 22");
		strcpy(cardF5, " 222 ");
		strcpy(cardF6, "  2  ");


		numf1 = 2;
		colorf = 1;
		break;
	case 3:

		strcpy(cardF1, " 3 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " HEARTS ");
		strcpy(cardF4, "33 33");
		strcpy(cardF5, " 333 ");
		strcpy(cardF6, "  3  ");


		numf1 = 3;
		colorf = 1;
		break;
	case 4:

		strcpy(cardF1, " 4 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " HEARTS ");
		strcpy(cardF4, "44 44");
		strcpy(cardF5, " 444 ");
		strcpy(cardF6, "  4  ");


		numf1 = 4;
		colorf = 1;
		break;
	case 5:

		strcpy(cardF1, " 5 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " HEARTS ");
		strcpy(cardF4, "55 55");
		strcpy(cardF5, " 555 ");
		strcpy(cardF6, "  5  ");


		numf1 = 5;
		colorf = 1;
		break;
	case 6:

		strcpy(cardF1, " 6 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " HEARTS ");
		strcpy(cardF4, "66 66");
		strcpy(cardF5, " 666 ");
		strcpy(cardF6, "  6  ");


		numf1 = 6;
		colorf = 1;
		break;
	case 7:

		strcpy(cardF1, " 7 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " HEARTS ");
		strcpy(cardF4, "77 77");
		strcpy(cardF5, " 777 ");
		strcpy(cardF6, "  7  ");


		numf1 = 7;
		colorf = 1;
		break;
	case 8:

		strcpy(cardF1, " 8 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " HEARTS ");
		strcpy(cardF4, "88 88");
		strcpy(cardF5, " 888 ");
		strcpy(cardF6, "  8  ");


		numf1 = 8;
		colorf = 1;
		break;
	case 9:

		strcpy(cardF1, " 9 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " HEARTS ");
		strcpy(cardF4, "99 99");
		strcpy(cardF5, " 999 ");
		strcpy(cardF6, "  9  ");


		numf1 = 9;
		colorf = 1;
		break;
	case 10:

		strcpy(cardF1, "10 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " HEARTS ");
		strcpy(cardF4, "10 10");
		strcpy(cardF5, " 010 ");
		strcpy(cardF6, " 10  ");


		numf1 = 10;
		colorf = 1;
		break;
	case 11:

		strcpy(cardF1, " J ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " HEARTS ");
		strcpy(cardF4, "JJ JJ");
		strcpy(cardF5, " JJJ ");
		strcpy(cardF6, "  J  ");


		numf1 = 11;
		colorf = 1;
		break;
	case 12:

		strcpy(cardF1, " Q ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " HEARTS ");
		strcpy(cardF4, "QQ QQ");
		strcpy(cardF5, " QQQ ");
		strcpy(cardF6, "  Q  ");


		numf1 = 12;
		colorf = 1;
		break;
	case 13:

		strcpy(cardF1, " K ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " HEARTS ");
		strcpy(cardF4, "KK KK");
		strcpy(cardF5, " KKK ");
		strcpy(cardF6, "  K  ");


		numf1 = 13;
		colorf = 1;
		break;
	case 14:

		strcpy(cardF1, "ACE");
		strcpy(cardF2, "OF");
		strcpy(cardF3, "DIAMONDS");
		strcpy(cardF4, "  A  ");
		strcpy(cardF5, " AAA ");
		strcpy(cardF6, "  A  ");


		numf1 = 1;
		numf2 = 11;
		colorf = 2;
		break;
	case 15:

		strcpy(cardF1, " 2 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, "DIAMONDS");
		strcpy(cardF4, "  2  ");
		strcpy(cardF5, " 222 ");
		strcpy(cardF6, "  2  ");


		numf1 = 2;
		colorf = 2;
		break;
	case 16:

		strcpy(cardF1, " 3 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, "DIAMONDS");
		strcpy(cardF4, "  3  ");
		strcpy(cardF5, " 333 ");
		strcpy(cardF6, "  3  ");


		numf1 = 3;
		colorf = 2;
		break;
	case 17:

		strcpy(cardF1, " 4 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, "DIAMONDS");
		strcpy(cardF4, "  4  ");
		strcpy(cardF5, " 444 ");
		strcpy(cardF6, "  4  ");


		numf1 = 4;
		colorf = 2;
		break;
	case 18:

		strcpy(cardF1, " 5 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, "DIAMONDS");
		strcpy(cardF4, "  5  ");
		strcpy(cardF5, " 555 ");
		strcpy(cardF6, "  5  ");


		numf1 = 5;
		colorf = 2;
		break;
	case 19:

		strcpy(cardF1, " 6 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, "DIAMONDS");
		strcpy(cardF4, "  6  ");
		strcpy(cardF5, " 666 ");
		strcpy(cardF6, "  6  ");


		numf1 = 6;
		colorf = 2;
		break;
	case 20:

		strcpy(cardF1, " 7 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, "DIAMONDS");
		strcpy(cardF4, "  7  ");
		strcpy(cardF5, " 777 ");
		strcpy(cardF6, "  7  ");


		numf1 = 7;
		colorf = 2;
		break;
	case 21:

		strcpy(cardF1, " 8 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, "DIAMONDS");
		strcpy(cardF4, "  8  ");
		strcpy(cardF5, " 888 ");
		strcpy(cardF6, "  8  ");


		numf1 = 8;
		colorf = 2;
		break;
	case 22:

		strcpy(cardF1, " 9 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, "DIAMONDS");
		strcpy(cardF4, "  9  ");
		strcpy(cardF5, " 999 ");
		strcpy(cardF6, "  9  ");


		numf1 = 9;
		colorf = 2;
		break;
	case 23:

		strcpy(cardF1, "10 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, "DIAMONDS");
		strcpy(cardF4, " 10  ");
		strcpy(cardF5, "1010 ");
		strcpy(cardF6, " 10  ");


		numf1 = 10;
		colorf = 2;
		break;
	case 24:

		strcpy(cardF1, " J ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, "DIAMONDS");
		strcpy(cardF4, "  J  ");
		strcpy(cardF5, " JJJ ");
		strcpy(cardF6, "  J  ");


		numf1 = 11;
		colorf = 2;
		break;
	case 25:

		strcpy(cardF1, " Q ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, "DIAMONDS");
		strcpy(cardF4, "  Q  ");
		strcpy(cardF5, " QQQ ");
		strcpy(cardF6, "  Q  ");


		numf1 = 12;
		colorf = 2;
		break;
	case 26:

		strcpy(cardF1, " K ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, "DIAMONDS");
		strcpy(cardF4, "  K  ");
		strcpy(cardF5, " KKK ");
		strcpy(cardF6, "  K  ");


		numf1 = 13;
		colorf = 2;
		break;
	case 27:

		strcpy(cardF1, "ACE");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " SPADES ");
		strcpy(cardF4, "  A  ");
		strcpy(cardF5, "AA AA");
		strcpy(cardF6, "  A  ");


		numf1 = 1;
		numf2 = 11;
		colorf = 3;
		break;
	case 28:

		strcpy(cardF1, " 2 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " SPADES ");
		strcpy(cardF4, "  2  ");
		strcpy(cardF5, "22 22");
		strcpy(cardF6, "  2  ");


		numf1 = 2;
		colorf = 3;
		break;
	case 29:

		strcpy(cardF1, " 3 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " SPADES ");
		strcpy(cardF4, "  3  ");
		strcpy(cardF5, "33 33");
		strcpy(cardF6, "  3  ");


		numf1 = 3;
		colorf = 3;
		break;
	case 30:

		strcpy(cardF1, " 4 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " SPADES ");
		strcpy(cardF4, "  4  ");
		strcpy(cardF5, "44 44");
		strcpy(cardF6, "  4  ");


		numf1 = 4;
		colorf = 3;
		break;
	case 31:

		strcpy(cardF1, " 5 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " SPADES ");
		strcpy(cardF4, "  5  ");
		strcpy(cardF5, "55 55");
		strcpy(cardF6, "  5  ");


		numf1 = 5;
		colorf = 3;
		break;
	case 32:

		strcpy(cardF1, " 6 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " SPADES ");
		strcpy(cardF4, "  6  ");
		strcpy(cardF5, "66 66");
		strcpy(cardF6, "  6  ");


		numf1 = 6;
		colorf = 3;
		break;
	case 33:

		strcpy(cardF1, " 7 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " SPADES ");
		strcpy(cardF4, "  7  ");
		strcpy(cardF5, "77 77");
		strcpy(cardF6, "  7  ");


		numf1 = 7;
		colorf = 3;
		break;
	case 34:

		strcpy(cardF1, " 8 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " SPADES ");
		strcpy(cardF4, "  8  ");
		strcpy(cardF5, "88 88");
		strcpy(cardF6, "  8  ");


		numf1 = 8;
		colorf = 3;
		break;
	case 35:

		strcpy(cardF1, " 9 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " SPADES ");
		strcpy(cardF4, "  9  ");
		strcpy(cardF5, "99 99");
		strcpy(cardF6, "  9  ");


		numf1 = 9;
		colorf = 3;
		break;
	case 36:

		strcpy(cardF1, "10 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " SPADES ");
		strcpy(cardF4, " 10  ");
		strcpy(cardF5, "10 10");
		strcpy(cardF6, " 10  ");


		numf1 = 10;
		colorf = 3;
		break;
	case 37:

		strcpy(cardF1, " J ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " SPADES ");
		strcpy(cardF4, "  J  ");
		strcpy(cardF5, "JJ JJ");
		strcpy(cardF6, "  J  ");


		numf1 = 11;
		colorf = 3;
		break;
	case 38:

		strcpy(cardF1, " Q ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " SPADES ");
		strcpy(cardF4, "  Q  ");
		strcpy(cardF5, "QQ QQ");
		strcpy(cardF6, "  Q  ");


		numf1 = 12;
		colorf = 3;
		break;
	case 39:

		strcpy(cardF1, " K ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " SPADES ");
		strcpy(cardF4, "  K  ");
		strcpy(cardF5, "KK KK");
		strcpy(cardF6, "  K  ");


		numf1 = 13;
		colorf = 3;
		break;
	case 40:

		strcpy(cardF1, "ACE");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " CLUBS  ");
		strcpy(cardF4, " A A ");
		strcpy(cardF5, "  A  ");
		strcpy(cardF6, " A A ");


		numf1 = 1;
		numf2 = 11;
		colorf = 4;
		break;
	case 41:

		strcpy(cardF1, " 2 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " CLUBS  ");
		strcpy(cardF4, " 2 2 ");
		strcpy(cardF5, "  2  ");
		strcpy(cardF6, " 2 2 ");


		numf1 = 2;
		colorf = 4;
		break;
	case 42:

		strcpy(cardF1, " 3 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " CLUBS  ");
		strcpy(cardF4, " 3 3 ");
		strcpy(cardF5, "  3  ");
		strcpy(cardF6, " 3 3 ");


		numf1 = 3;
		colorf = 4;
		break;
	case 43:

		strcpy(cardF1, " 4 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " CLUBS  ");
		strcpy(cardF4, " 4 4 ");
		strcpy(cardF5, "  4  ");
		strcpy(cardF6, " 4 4 ");


		numf1 = 4;
		colorf = 4;
		break;
	case 44:

		strcpy(cardF1, " 5 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " CLUBS  ");
		strcpy(cardF4, " 5 5 ");
		strcpy(cardF5, "  5  ");
		strcpy(cardF6, " 5 5 ");


		numf1 = 5;
		colorf = 4;
		break;
	case 45:

		strcpy(cardF1, " 6 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " CLUBS  ");
		strcpy(cardF4, " 6 6 ");
		strcpy(cardF5, "  6  ");
		strcpy(cardF6, " 6 6 ");


		numf1 = 6;
		colorf = 4;
		break;
	case 46:

		strcpy(cardF1, " 7 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " CLUBS  ");
		strcpy(cardF4, " 7 7 ");
		strcpy(cardF5, "  7  ");
		strcpy(cardF6, " 7 7 ");


		numf1 = 7;
		colorf = 4;
		break;
	case 47:

		strcpy(cardF1, " 8 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " CLUBS  ");
		strcpy(cardF4, " 8 8 ");
		strcpy(cardF5, "  8  ");
		strcpy(cardF6, " 8 8 ");


		numf1 = 8;
		colorf = 4;
		break;
	case 48:

		strcpy(cardF1, " 9 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " CLUBS  ");
		strcpy(cardF4, " 9 9 ");
		strcpy(cardF5, "  9  ");
		strcpy(cardF6, " 9 9 ");


		numf1 = 9;
		colorf = 4;
		break;
	case 49:

		strcpy(cardF1, "10 ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " CLUBS  ");
		strcpy(cardF4, "10 10");
		strcpy(cardF5, " 10  ");
		strcpy(cardF6, "10 10");


		numf1 = 10;
		colorf = 4;
		break;
	case 50:

		strcpy(cardF1, " J ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " CLUBS  ");
		strcpy(cardF4, "JJ JJ");
		strcpy(cardF5, "  J  ");
		strcpy(cardF6, "JJ JJ");


		numf1 = 11;
		colorf = 4;
		break;
	case 51:

		strcpy(cardF1, " Q ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " CLUBS  ");
		strcpy(cardF4, "QQ QQ");
		strcpy(cardF5, "  Q  ");
		strcpy(cardF6, "QQ QQ");


		numf1 = 12;
		colorf = 4;
		break;
	case 52:

		strcpy(cardF1, " K ");
		strcpy(cardF2, "OF");
		strcpy(cardF3, " CLUBS  ");
		strcpy(cardF4, "KK KK");
		strcpy(cardF5, "  K  ");
		strcpy(cardF6, "KK KK");


		numf1 = 13;
		colorf = 4;
		break;

	}


}

void firstCardOfOpponent(int theRandNumber7, char cardG1[], char cardG2[], char cardG3[], char cardG4[], char cardG5[], char cardG6[]) {
	// 1=hearts, 2=diamonds, 3=spades, 4=clubs
	int numg1 = 0, numg2 = 0, colorg = 0;
	switch (theRandNumber7) {
	case 1:

		strcpy(cardG1, "ACE");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " HEARTS ");
		strcpy(cardG4, "AA AA");
		strcpy(cardG5, " AAA ");
		strcpy(cardG6, "  A  ");

		numg1 = 11;
		numg2 = 1;
		colorg = 1;

		break;
	case 2:

		strcpy(cardG1, " 2 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " HEARTS ");
		strcpy(cardG4, "22 22");
		strcpy(cardG5, " 222 ");
		strcpy(cardG6, "  2  ");


		numg1 = 2;
		colorg = 1;
		break;
	case 3:

		strcpy(cardG1, " 3 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " HEARTS ");
		strcpy(cardG4, "33 33");
		strcpy(cardG5, " 333 ");
		strcpy(cardG6, "  3  ");


		numg1 = 3;
		colorg = 1;
		break;
	case 4:

		strcpy(cardG1, " 4 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " HEARTS ");
		strcpy(cardG4, "44 44");
		strcpy(cardG5, " 444 ");
		strcpy(cardG6, "  4  ");


		numg1 = 4;
		colorg = 1;
		break;
	case 5:

		strcpy(cardG1, " 5 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " HEARTS ");
		strcpy(cardG4, "55 55");
		strcpy(cardG5, " 555 ");
		strcpy(cardG6, "  5  ");


		numg1 = 5;
		colorg = 1;
		break;
	case 6:

		strcpy(cardG1, " 6 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " HEARTS ");
		strcpy(cardG4, "66 66");
		strcpy(cardG5, " 666 ");
		strcpy(cardG6, "  6  ");


		numg1 = 6;
		colorg = 1;
		break;
	case 7:

		strcpy(cardG1, " 7 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " HEARTS ");
		strcpy(cardG4, "77 77");
		strcpy(cardG5, " 777 ");
		strcpy(cardG6, "  7  ");


		numg1 = 7;
		colorg = 1;
		break;
	case 8:

		strcpy(cardG1, " 8 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " HEARTS ");
		strcpy(cardG4, "88 88");
		strcpy(cardG5, " 888 ");
		strcpy(cardG6, "  8  ");


		numg1 = 8;
		colorg = 1;
		break;
	case 9:

		strcpy(cardG1, " 9 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " HEARTS ");
		strcpy(cardG4, "99 99");
		strcpy(cardG5, " 999 ");
		strcpy(cardG6, "  9  ");


		numg1 = 9;
		colorg = 1;
		break;
	case 10:

		strcpy(cardG1, "10 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " HEARTS ");
		strcpy(cardG4, "10 10");
		strcpy(cardG5, " 010 ");
		strcpy(cardG6, " 10  ");


		numg1 = 10;
		colorg = 1;
		break;
	case 11:

		strcpy(cardG1, " J ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " HEARTS ");
		strcpy(cardG4, "JJ JJ");
		strcpy(cardG5, " JJJ ");
		strcpy(cardG6, "  J  ");


		numg1 = 11;
		colorg = 1;
		break;
	case 12:

		strcpy(cardG1, " Q ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " HEARTS ");
		strcpy(cardG4, "QQ QQ");
		strcpy(cardG5, " QQQ ");
		strcpy(cardG6, "  Q  ");


		numg1 = 12;
		colorg = 1;
		break;
	case 13:

		strcpy(cardG1, " K ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " HEARTS ");
		strcpy(cardG4, "KK KK");
		strcpy(cardG5, " KKK ");
		strcpy(cardG6, "  K  ");


		numg1 = 13;
		colorg = 1;
		break;
	case 14:

		strcpy(cardG1, "ACE");
		strcpy(cardG2, "OF");
		strcpy(cardG3, "DIAMONDS");
		strcpy(cardG4, "  A  ");
		strcpy(cardG5, " AAA ");
		strcpy(cardG6, "  A  ");


		numg1 = 1;
		numg2 = 11;
		colorg = 2;
		break;
	case 15:

		strcpy(cardG1, " 2 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, "DIAMONDS");
		strcpy(cardG4, "  2  ");
		strcpy(cardG5, " 222 ");
		strcpy(cardG6, "  2  ");


		numg1 = 2;
		colorg = 2;
		break;
	case 16:

		strcpy(cardG1, " 3 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, "DIAMONDS");
		strcpy(cardG4, "  3  ");
		strcpy(cardG5, " 333 ");
		strcpy(cardG6, "  3  ");


		numg1 = 3;
		colorg = 2;
		break;
	case 17:

		strcpy(cardG1, " 4 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, "DIAMONDS");
		strcpy(cardG4, "  4  ");
		strcpy(cardG5, " 444 ");
		strcpy(cardG6, "  4  ");


		numg1 = 4;
		colorg = 2;
		break;
	case 18:

		strcpy(cardG1, " 5 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, "DIAMONDS");
		strcpy(cardG4, "  5  ");
		strcpy(cardG5, " 555 ");
		strcpy(cardG6, "  5  ");


		numg1 = 5;
		colorg = 2;
		break;
	case 19:

		strcpy(cardG1, " 6 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, "DIAMONDS");
		strcpy(cardG4, "  6  ");
		strcpy(cardG5, " 666 ");
		strcpy(cardG6, "  6  ");


		numg1 = 6;
		colorg = 2;
		break;
	case 20:

		strcpy(cardG1, " 7 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, "DIAMONDS");
		strcpy(cardG4, "  7  ");
		strcpy(cardG5, " 777 ");
		strcpy(cardG6, "  7  ");


		numg1 = 7;
		colorg = 2;
		break;
	case 21:

		strcpy(cardG1, " 8 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, "DIAMONDS");
		strcpy(cardG4, "  8  ");
		strcpy(cardG5, " 888 ");
		strcpy(cardG6, "  8  ");


		numg1 = 8;
		colorg = 2;
		break;
	case 22:

		strcpy(cardG1, " 9 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, "DIAMONDS");
		strcpy(cardG4, "  9  ");
		strcpy(cardG5, " 999 ");
		strcpy(cardG6, "  9  ");


		numg1 = 9;
		colorg = 2;
		break;
	case 23:

		strcpy(cardG1, "10 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, "DIAMONDS");
		strcpy(cardG4, " 10  ");
		strcpy(cardG5, "1010 ");
		strcpy(cardG6, " 10  ");


		numg1 = 10;
		colorg = 2;
		break;
	case 24:

		strcpy(cardG1, " J ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, "DIAMONDS");
		strcpy(cardG4, "  J  ");
		strcpy(cardG5, " JJJ ");
		strcpy(cardG6, "  J  ");


		numg1 = 11;
		colorg = 2;
		break;
	case 25:

		strcpy(cardG1, " Q ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, "DIAMONDS");
		strcpy(cardG4, "  Q  ");
		strcpy(cardG5, " QQQ ");
		strcpy(cardG6, "  Q  ");


		numg1 = 12;
		colorg = 2;
		break;
	case 26:

		strcpy(cardG1, " K ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, "DIAMONDS");
		strcpy(cardG4, "  K  ");
		strcpy(cardG5, " KKK ");
		strcpy(cardG6, "  K  ");



		numg1 = 13;
		colorg = 2;
		break;
	case 27:

		strcpy(cardG1, "ACE");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " SPADES ");
		strcpy(cardG4, "  A  ");
		strcpy(cardG5, "AA AA");
		strcpy(cardG6, "  A  ");


		numg1 = 1;
		numg2 = 11;
		colorg = 3;
		break;
	case 28:

		strcpy(cardG1, " 2 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " SPADES ");
		strcpy(cardG4, "  2  ");
		strcpy(cardG5, "22 22");
		strcpy(cardG6, "  2  ");


		numg1 = 2;
		colorg = 3;
		break;
	case 29:

		strcpy(cardG1, " 3 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " SPADES ");
		strcpy(cardG4, "  3  ");
		strcpy(cardG5, "33 33");
		strcpy(cardG6, "  3  ");


		numg1 = 3;
		colorg = 3;
		break;
	case 30:

		strcpy(cardG1, " 4 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " SPADES ");
		strcpy(cardG4, "  4  ");
		strcpy(cardG5, "44 44");
		strcpy(cardG6, "  4  ");


		numg1 = 4;
		colorg = 3;
		break;
	case 31:

		strcpy(cardG1, " 5 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " SPADES ");
		strcpy(cardG4, "  5  ");
		strcpy(cardG5, "55 55");
		strcpy(cardG6, "  5  ");


		numg1 = 5;
		colorg = 3;
		break;
	case 32:

		strcpy(cardG1, " 6 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " SPADES ");
		strcpy(cardG4, "  6  ");
		strcpy(cardG5, "66 66");
		strcpy(cardG6, "  6  ");


		numg1 = 6;
		colorg = 3;
		break;
	case 33:

		strcpy(cardG1, " 7 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " SPADES ");
		strcpy(cardG4, "  7  ");
		strcpy(cardG5, "77 77");
		strcpy(cardG6, "  7  ");


		numg1 = 7;
		colorg = 3;
		break;
	case 34:

		strcpy(cardG1, " 8 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " SPADES ");
		strcpy(cardG4, "  8  ");
		strcpy(cardG5, "88 88");
		strcpy(cardG6, "  8  ");


		numg1 = 8;
		colorg = 3;
		break;
	case 35:

		strcpy(cardG1, " 9 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " SPADES ");
		strcpy(cardG4, "  9  ");
		strcpy(cardG5, "99 99");
		strcpy(cardG6, "  9  ");


		numg1 = 9;
		colorg = 3;
		break;
	case 36:

		strcpy(cardG1, "10 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " SPADES ");
		strcpy(cardG4, " 10  ");
		strcpy(cardG5, "10 10");
		strcpy(cardG6, " 10  ");


		numg1 = 10;
		colorg = 3;
		break;
	case 37:

		strcpy(cardG1, " J ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " SPADES ");
		strcpy(cardG4, "  J  ");
		strcpy(cardG5, "JJ JJ");
		strcpy(cardG6, "  J  ");


		numg1 = 11;
		colorg = 3;
		break;
	case 38:

		strcpy(cardG1, " Q ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " SPADES ");
		strcpy(cardG4, "  Q  ");
		strcpy(cardG5, "QQ QQ");
		strcpy(cardG6, "  Q  ");


		numg1 = 12;
		colorg = 3;
		break;
	case 39:

		strcpy(cardG1, " K ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " SPADES ");
		strcpy(cardG4, "  K  ");
		strcpy(cardG5, "KK KK");
		strcpy(cardG6, "  K  ");


		numg1 = 13;
		colorg = 3;
		break;
	case 40:

		strcpy(cardG1, "ACE");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " CLUBS  ");
		strcpy(cardG4, " A A ");
		strcpy(cardG5, "  A  ");
		strcpy(cardG6, " A A ");


		numg1 = 1;
		numg2 = 11;
		colorg = 4;
		break;
	case 41:

		strcpy(cardG1, " 2 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " CLUBS  ");
		strcpy(cardG4, " 2 2 ");
		strcpy(cardG5, "  2  ");
		strcpy(cardG6, " 2 2 ");


		numg1 = 2;
		colorg = 4;
		break;
	case 42:

		strcpy(cardG1, " 3 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " CLUBS  ");
		strcpy(cardG4, " 3 3 ");
		strcpy(cardG5, "  3  ");
		strcpy(cardG6, " 3 3 ");


		numg1 = 3;
		colorg = 4;
		break;
	case 43:

		strcpy(cardG1, " 4 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " CLUBS  ");
		strcpy(cardG4, " 4 4 ");
		strcpy(cardG5, "  4  ");
		strcpy(cardG6, " 4 4 ");


		numg1 = 4;
		colorg = 4;
		break;
	case 44:

		strcpy(cardG1, " 5 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " CLUBS  ");
		strcpy(cardG4, " 5 5 ");
		strcpy(cardG5, "  5  ");
		strcpy(cardG6, " 5 5 ");


		numg1 = 5;
		colorg = 4;
		break;
	case 45:

		strcpy(cardG1, " 6 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " CLUBS  ");
		strcpy(cardG4, " 6 6 ");
		strcpy(cardG5, "  6  ");
		strcpy(cardG6, " 6 6 ");


		numg1 = 6;
		colorg = 4;
		break;
	case 46:

		strcpy(cardG1, " 7 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " CLUBS  ");
		strcpy(cardG4, " 7 7 ");
		strcpy(cardG5, "  7  ");
		strcpy(cardG6, " 7 7 ");


		numg1 = 7;
		colorg = 4;
		break;
	case 47:

		strcpy(cardG1, " 8 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " CLUBS  ");
		strcpy(cardG4, " 8 8 ");
		strcpy(cardG5, "  8  ");
		strcpy(cardG6, " 8 8 ");


		numg1 = 8;
		colorg = 4;
		break;
	case 48:

		strcpy(cardG1, " 9 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " CLUBS  ");
		strcpy(cardG4, " 9 9 ");
		strcpy(cardG5, "  9  ");
		strcpy(cardG6, " 9 9 ");


		numg1 = 9;
		colorg = 4;
		break;
	case 49:

		strcpy(cardG1, "10 ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " CLUBS  ");
		strcpy(cardG4, "10 10");
		strcpy(cardG5, " 10  ");
		strcpy(cardG6, "10 10");


		numg1 = 10;
		colorg = 4;
		break;
	case 50:

		strcpy(cardG1, " J ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " CLUBS  ");
		strcpy(cardG4, "JJ JJ");
		strcpy(cardG5, "  J  ");
		strcpy(cardG6, "JJ JJ");


		numg1 = 11;
		colorg = 4;
		break;
	case 51:

		strcpy(cardG1, " Q ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " CLUBS  ");
		strcpy(cardG4, "QQ QQ");
		strcpy(cardG5, "  Q  ");
		strcpy(cardG6, "QQ QQ");


		numg1 = 12;
		colorg = 4;
		break;
	case 52:

		strcpy(cardG1, " K ");
		strcpy(cardG2, "OF");
		strcpy(cardG3, " CLUBS  ");
		strcpy(cardG4, "KK KK");
		strcpy(cardG5, "  K  ");
		strcpy(cardG6, "KK KK");


		numg1 = 13;
		colorg = 4;
		break;

	}

}

void secondCardOfOpponent(int theRandNumber8, char cardH1[], char cardH2[], char cardH3[], char cardH4[], char cardH5[], char cardH6[]) {
	// 1=hearts, 2=diamonds, 3=spades, 4=clubs
	int numh1 = 0, numh2 = 0, colorh = 0;
	switch (theRandNumber8) {
	case 1:

		strcpy(cardH1, "ACE");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " HEARTS ");
		strcpy(cardH4, "AA AA");
		strcpy(cardH5, " AAA ");
		strcpy(cardH6, "  A  ");

		numh1 = 11;
		numh2 = 1;
		colorh = 1;

		break;
	case 2:

		strcpy(cardH1, " 2 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " HEARTS ");
		strcpy(cardH4, "22 22");
		strcpy(cardH5, " 222 ");
		strcpy(cardH6, "  2  ");


		numh1 = 2;
		colorh = 1;
		break;
	case 3:

		strcpy(cardH1, " 3 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " HEARTS ");
		strcpy(cardH4, "33 33");
		strcpy(cardH5, " 333 ");
		strcpy(cardH6, "  3  ");


		numh1 = 3;
		colorh = 1;
		break;
	case 4:

		strcpy(cardH1, " 4 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " HEARTS ");
		strcpy(cardH4, "44 44");
		strcpy(cardH5, " 444 ");
		strcpy(cardH6, "  4  ");


		numh1 = 4;
		colorh = 1;
		break;
	case 5:

		strcpy(cardH1, " 5 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " HEARTS ");
		strcpy(cardH4, "55 55");
		strcpy(cardH5, " 555 ");
		strcpy(cardH6, "  5  ");


		numh1 = 5;
		colorh = 1;
		break;
	case 6:

		strcpy(cardH1, " 6 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " HEARTS ");
		strcpy(cardH4, "66 66");
		strcpy(cardH5, " 666 ");
		strcpy(cardH6, "  6  ");


		numh1 = 6;
		colorh = 1;
		break;
	case 7:

		strcpy(cardH1, " 7 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " HEARTS ");
		strcpy(cardH4, "77 77");
		strcpy(cardH5, " 777 ");
		strcpy(cardH6, "  7  ");


		numh1 = 7;
		colorh = 1;
		break;
	case 8:

		strcpy(cardH1, " 8 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " HEARTS ");
		strcpy(cardH4, "88 88");
		strcpy(cardH5, " 888 ");
		strcpy(cardH6, "  8  ");


		numh1 = 8;
		colorh = 1;
		break;
	case 9:

		strcpy(cardH1, " 9 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " HEARTS ");
		strcpy(cardH4, "99 99");
		strcpy(cardH5, " 999 ");
		strcpy(cardH6, "  9  ");


		numh1 = 9;
		colorh = 1;
		break;
	case 10:

		strcpy(cardH1, "10 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " HEARTS ");
		strcpy(cardH4, "10 10");
		strcpy(cardH5, " 010 ");
		strcpy(cardH6, " 10  ");


		numh1 = 10;
		colorh = 1;
		break;
	case 11:

		strcpy(cardH1, " J ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " HEARTS ");
		strcpy(cardH4, "JJ JJ");
		strcpy(cardH5, " JJJ ");
		strcpy(cardH6, "  J  ");


		numh1 = 11;
		colorh = 1;
		break;
	case 12:

		strcpy(cardH1, " Q ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " HEARTS ");
		strcpy(cardH4, "QQ QQ");
		strcpy(cardH5, " QQQ ");
		strcpy(cardH6, "  Q  ");


		numh1 = 12;
		colorh = 1;
		break;
	case 13:

		strcpy(cardH1, " K ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " HEARTS ");
		strcpy(cardH4, "KK KK");
		strcpy(cardH5, " KKK ");
		strcpy(cardH6, "  K  ");


		numh1 = 13;
		colorh = 1;
		break;
	case 14:

		strcpy(cardH1, "ACE");
		strcpy(cardH2, "OF");
		strcpy(cardH3, "DIAMONDS");
		strcpy(cardH4, "  A  ");
		strcpy(cardH5, " AAA ");
		strcpy(cardH6, "  A  ");


		numh1 = 1;
		numh2 = 11;
		colorh = 2;
		break;
	case 15:

		strcpy(cardH1, " 2 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, "DIAMONDS");
		strcpy(cardH4, "  2  ");
		strcpy(cardH5, " 222 ");
		strcpy(cardH6, "  2  ");


		numh1 = 2;
		colorh = 2;
		break;
	case 16:

		strcpy(cardH1, " 3 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, "DIAMONDS");
		strcpy(cardH4, "  3  ");
		strcpy(cardH5, " 333 ");
		strcpy(cardH6, "  3  ");


		numh1 = 3;
		colorh = 2;
		break;
	case 17:

		strcpy(cardH1, " 4 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, "DIAMONDS");
		strcpy(cardH4, "  4  ");
		strcpy(cardH5, " 444 ");
		strcpy(cardH6, "  4  ");


		numh1 = 4;
		colorh = 2;
		break;
	case 18:

		strcpy(cardH1, " 5 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, "DIAMONDS");
		strcpy(cardH4, "  5  ");
		strcpy(cardH5, " 555 ");
		strcpy(cardH6, "  5  ");


		numh1 = 5;
		colorh = 2;
		break;
	case 19:

		strcpy(cardH1, " 6 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, "DIAMONDS");
		strcpy(cardH4, "  6  ");
		strcpy(cardH5, " 666 ");
		strcpy(cardH6, "  6  ");


		numh1 = 6;
		colorh = 2;
		break;
	case 20:

		strcpy(cardH1, " 7 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, "DIAMONDS");
		strcpy(cardH4, "  7  ");
		strcpy(cardH5, " 777 ");
		strcpy(cardH6, "  7  ");


		numh1 = 7;
		colorh = 2;
		break;
	case 21:

		strcpy(cardH1, " 8 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, "DIAMONDS");
		strcpy(cardH4, "  8  ");
		strcpy(cardH5, " 888 ");
		strcpy(cardH6, "  8  ");


		numh1 = 8;
		colorh = 2;
		break;
	case 22:

		strcpy(cardH1, " 9 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, "DIAMONDS");
		strcpy(cardH4, "  9  ");
		strcpy(cardH5, " 999 ");
		strcpy(cardH6, "  9  ");


		numh1 = 9;
		colorh = 2;
		break;
	case 23:

		strcpy(cardH1, "10 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, "DIAMONDS");
		strcpy(cardH4, " 10  ");
		strcpy(cardH5, "1010 ");
		strcpy(cardH6, " 10  ");


		numh1 = 10;
		colorh = 2;
		break;
	case 24:

		strcpy(cardH1, " J ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, "DIAMONDS");
		strcpy(cardH4, "  J  ");
		strcpy(cardH5, " JJJ ");
		strcpy(cardH6, "  J  ");


		numh1 = 11;
		colorh = 2;
		break;
	case 25:

		strcpy(cardH1, " Q ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, "DIAMONDS");
		strcpy(cardH4, "  Q  ");
		strcpy(cardH5, " QQQ ");
		strcpy(cardH6, "  Q  ");


		numh1 = 12;
		colorh = 2;
		break;
	case 26:

		strcpy(cardH1, " K ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, "DIAMONDS");
		strcpy(cardH4, "  K  ");
		strcpy(cardH5, " KKK ");
		strcpy(cardH6, "  K  ");


		numh1 = 13;
		colorh = 2;
		break;
	case 27:

		strcpy(cardH1, "ACE");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " SPADES ");
		strcpy(cardH4, "  A  ");
		strcpy(cardH5, "AA AA");
		strcpy(cardH6, "  A  ");


		numh1 = 1;
		numh2 = 11;
		colorh = 3;
		break;
	case 28:

		strcpy(cardH1, " 2 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " SPADES ");
		strcpy(cardH4, "  2  ");
		strcpy(cardH5, "22 22");
		strcpy(cardH6, "  2  ");


		numh1 = 2;
		colorh = 3;
		break;
	case 29:

		strcpy(cardH1, " 3 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " SPADES ");
		strcpy(cardH4, "  3  ");
		strcpy(cardH5, "33 33");
		strcpy(cardH6, "  3  ");


		numh1 = 3;
		colorh = 3;
		break;
	case 30:

		strcpy(cardH1, " 4 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " SPADES ");
		strcpy(cardH4, "  4  ");
		strcpy(cardH5, "44 44");
		strcpy(cardH6, "  4  ");


		numh1 = 4;
		colorh = 3;
		break;
	case 31:

		strcpy(cardH1, " 5 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " SPADES ");
		strcpy(cardH4, "  5  ");
		strcpy(cardH5, "55 55");
		strcpy(cardH6, "  5  ");


		numh1 = 5;
		colorh = 3;
		break;
	case 32:

		strcpy(cardH1, " 6 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " SPADES ");
		strcpy(cardH4, "  6  ");
		strcpy(cardH5, "66 66");
		strcpy(cardH6, "  6  ");


		numh1 = 6;
		colorh = 3;
		break;
	case 33:

		strcpy(cardH1, " 7 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " SPADES ");
		strcpy(cardH4, "  7  ");
		strcpy(cardH5, "77 77");
		strcpy(cardH6, "  7  ");


		numh1 = 7;
		colorh = 3;
		break;
	case 34:

		strcpy(cardH1, " 8 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " SPADES ");
		strcpy(cardH4, "  8  ");
		strcpy(cardH5, "88 88");
		strcpy(cardH6, "  8  ");


		numh1 = 8;
		colorh = 3;
		break;
	case 35:

		strcpy(cardH1, " 9 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " SPADES ");
		strcpy(cardH4, "  9  ");
		strcpy(cardH5, "99 99");
		strcpy(cardH6, "  9  ");


		numh1 = 9;
		colorh = 3;
		break;
	case 36:

		strcpy(cardH1, "10 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " SPADES ");
		strcpy(cardH4, " 10  ");
		strcpy(cardH5, "10 10");
		strcpy(cardH6, " 10  ");


		numh1 = 10;
		colorh = 3;
		break;
	case 37:

		strcpy(cardH1, " J ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " SPADES ");
		strcpy(cardH4, "  J  ");
		strcpy(cardH5, "JJ JJ");
		strcpy(cardH6, "  J  ");


		numh1 = 11;
		colorh = 3;
		break;
	case 38:

		strcpy(cardH1, " Q ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " SPADES ");
		strcpy(cardH4, "  Q  ");
		strcpy(cardH5, "QQ QQ");
		strcpy(cardH6, "  Q  ");


		numh1 = 12;
		colorh = 3;
		break;
	case 39:

		strcpy(cardH1, " K ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " SPADES ");
		strcpy(cardH4, "  K  ");
		strcpy(cardH5, "KK KK");
		strcpy(cardH6, "  K  ");


		numh1 = 13;
		colorh = 3;
		break;
	case 40:

		strcpy(cardH1, "ACE");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " CLUBS  ");
		strcpy(cardH4, " A A ");
		strcpy(cardH5, "  A  ");
		strcpy(cardH6, " A A ");


		numh1 = 1;
		numh2 = 11;
		colorh = 4;
		break;
	case 41:

		strcpy(cardH1, " 2 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " CLUBS  ");
		strcpy(cardH4, " 2 2 ");
		strcpy(cardH5, "  2  ");
		strcpy(cardH6, " 2 2 ");


		numh1 = 2;
		colorh = 4;
		break;
	case 42:

		strcpy(cardH1, " 3 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " CLUBS  ");
		strcpy(cardH4, " 3 3 ");
		strcpy(cardH5, "  3  ");
		strcpy(cardH6, " 3 3 ");


		numh1 = 3;
		colorh = 4;
		break;
	case 43:

		strcpy(cardH1, " 4 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " CLUBS  ");
		strcpy(cardH4, " 4 4 ");
		strcpy(cardH5, "  4  ");
		strcpy(cardH6, " 4 4 ");


		numh1 = 4;
		colorh = 4;
		break;
	case 44:

		strcpy(cardH1, " 5 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " CLUBS  ");
		strcpy(cardH4, " 5 5 ");
		strcpy(cardH5, "  5  ");
		strcpy(cardH6, " 5 5 ");


		numh1 = 5;
		colorh = 4;
		break;
	case 45:

		strcpy(cardH1, " 6 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " CLUBS  ");
		strcpy(cardH4, " 6 6 ");
		strcpy(cardH5, "  6  ");
		strcpy(cardH6, " 6 6 ");


		numh1 = 6;
		colorh = 4;
		break;
	case 46:

		strcpy(cardH1, " 7 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " CLUBS  ");
		strcpy(cardH4, " 7 7 ");
		strcpy(cardH5, "  7  ");
		strcpy(cardH6, " 7 7 ");


		numh1 = 7;
		colorh = 4;
		break;
	case 47:

		strcpy(cardH1, " 8 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " CLUBS  ");
		strcpy(cardH4, " 8 8 ");
		strcpy(cardH5, "  8  ");
		strcpy(cardH6, " 8 8 ");


		numh1 = 8;
		colorh = 4;
		break;
	case 48:

		strcpy(cardH1, " 9 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " CLUBS  ");
		strcpy(cardH4, " 9 9 ");
		strcpy(cardH5, "  9  ");
		strcpy(cardH6, " 9 9 ");


		numh1 = 9;
		colorh = 4;
		break;
	case 49:

		strcpy(cardH1, "10 ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " CLUBS  ");
		strcpy(cardH4, "10 10");
		strcpy(cardH5, " 10  ");
		strcpy(cardH6, "10 10");


		numh1 = 10;
		colorh = 4;
		break;
	case 50:

		strcpy(cardH1, " J ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " CLUBS  ");
		strcpy(cardH4, "JJ JJ");
		strcpy(cardH5, "  J  ");
		strcpy(cardH6, "JJ JJ");


		numh1 = 11;
		colorh = 4;
		break;
	case 51:

		strcpy(cardH1, " Q ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " CLUBS  ");
		strcpy(cardH4, "QQ QQ");
		strcpy(cardH5, "  Q  ");
		strcpy(cardH6, "QQ QQ");


		numh1 = 12;
		colorh = 4;
		break;
	case 52:

		strcpy(cardH1, " K ");
		strcpy(cardH2, "OF");
		strcpy(cardH3, " CLUBS  ");
		strcpy(cardH4, "KK KK");
		strcpy(cardH5, "  K  ");
		strcpy(cardH6, "KK KK");


		numh1 = 13;
		colorh = 4;
		break;

	}

}

void firstValuesOfPlayer(int theRandNumber, float numa1, float numa2, float colora) {
	// 1=hearts, 2=diamonds, 3=spades, 4=clubs

	switch (theRandNumber) {
	case 1:

		numa1 = 11;
		numa2 = 1;
		colora = 1;

		break;
	case 2:


		numa1 = 2;
		colora = 1;
		break;
	case 3:


		numa1 = 3;
		colora = 1;
		break;
	case 4:

		numa1 = 4;
		colora = 1;
		break;
	case 5:

		numa1 = 5;
		colora = 1;
		break;
	case 6:


		numa1 = 6;
		colora = 1;
		break;
	case 7:


		numa1 = 7;
		colora = 1;
		break;
	case 8:

		numa1 = 8;
		colora = 1;
		break;
	case 9:


		numa1 = 9;
		colora = 1;
		break;
	case 10:


		numa1 = 10;
		colora = 1;
		break;
	case 11:


		numa1 = 10.1;
		colora = 1;
		break;
	case 12:

		numa1 = 10.2;
		colora = 1;
		break;
	case 13:

		numa1 = 10.3;
		colora = 1;
		break;
	case 14:

		numa1 = 11;
		numa2 = 1;
		colora = 2;
		break;
	case 15:

		numa1 = 2;
		colora = 2;
		break;
	case 16:

		numa1 = 3;
		colora = 2;
		break;
	case 17:

		numa1 = 4;
		colora = 2;
		break;
	case 18:

		numa1 = 5;
		colora = 2;
		break;
	case 19:

		numa1 = 6;
		colora = 2;
		break;
	case 20:

		numa1 = 7;
		colora = 2;
		break;
	case 21:

		numa1 = 8;
		colora = 2;
		break;
	case 22:

		numa1 = 9;
		colora = 2;
		break;
	case 23:

		numa1 = 10;
		colora = 2;
		break;
	case 24:

		numa1 = 10.1;
		colora = 2;
		break;
	case 25:

		numa1 = 10.2;
		colora = 2;
		break;
	case 26:

		numa1 = 10.3;
		colora = 2;
		break;
	case 27:

		numa1 = 11;
		numa2 = 1;
		colora = 3;
		break;
	case 28:

		numa1 = 2;
		colora = 3;
		break;
	case 29:

		numa1 = 3;
		colora = 3;
		break;
	case 30:

		numa1 = 4;
		colora = 3;
		break;
	case 31:

		numa1 = 5;
		colora = 3;
		break;
	case 32:

		numa1 = 6;
		colora = 3;
		break;
	case 33:

		numa1 = 7;
		colora = 3;
		break;
	case 34:

		numa1 = 8;
		colora = 3;
		break;
	case 35:

		numa1 = 9;
		colora = 3;
		break;
	case 36:

		numa1 = 10;
		colora = 3;
		break;
	case 37:

		numa1 = 10.1;
		colora = 3;
		break;
	case 38:

		numa1 = 10.2;
		colora = 3;
		break;
	case 39:

		numa1 = 10.3;
		colora = 3;
		break;
	case 40:

		numa1 = 11;
		numa2 = 1;
		colora = 4;
		break;
	case 41:

		numa1 = 2;
		colora = 4;
		break;
	case 42:

		numa1 = 3;
		colora = 4;
		break;
	case 43:

		numa1 = 4;
		colora = 4;
		break;
	case 44:

		numa1 = 5;
		colora = 4;
		break;
	case 45:

		numa1 = 6;
		colora = 4;
		break;
	case 46:

		numa1 = 7;
		colora = 4;
		break;
	case 47:

		numa1 = 8;
		colora = 4;
		break;
	case 48:

		numa1 = 9;
		colora = 4;
		break;
	case 49:

		numa1 = 10;
		colora = 4;
		break;
	case 50:

		numa1 = 10.1;
		colora = 4;
		break;
	case 51:

		numa1 = 10.2;
		colora = 4;
		break;
	case 52:

		numa1 = 10.3;
		colora = 4;
		break;

	}


}

void secondValueOfPlayer(int theRandNumber2, float numb1, float numb2, float colorb) {

	// 1=hearts, 2=diamonds, 3=spades, 4=clubs

	switch (theRandNumber2) {
	case 1:

		numb1 = 11;
		numb2 = 1;
		colorb = 1;

		break;
	case 2:

		numb1 = 2;
		colorb = 1;
		break;
	case 3:

		numb1 = 3;
		colorb = 1;
		break;
	case 4:

		numb1 = 4;
		colorb = 1;
		break;
	case 5:

		numb1 = 5;
		colorb = 1;
		break;
	case 6:

		numb1 = 6;
		colorb = 1;
		break;
	case 7:

		numb1 = 7;
		colorb = 1;
		break;
	case 8:

		numb1 = 8;
		colorb = 1;
		break;
	case 9:

		numb1 = 9;
		colorb = 1;
		break;
	case 10:

		numb1 = 10;
		colorb = 1;
		break;
	case 11:

		numb1 = 10.1;
		colorb = 1;
		break;
	case 12:

		numb1 = 10.2;
		colorb = 1;
		break;
	case 13:

		numb1 = 10.3;
		colorb = 1;
		break;
	case 14:

		numb1 = 11;
		numb2 = 1;
		colorb = 2;
		break;
	case 15:

		numb1 = 2;
		colorb = 2;
		break;
	case 16:

		numb1 = 3;
		colorb = 2;
		break;
	case 17:

		numb1 = 4;
		colorb = 2;
		break;
	case 18:

		numb1 = 5;
		colorb = 2;
		break;
	case 19:

		numb1 = 6;
		colorb = 2;
		break;
	case 20:

		numb1 = 7;
		colorb = 2;
		break;
	case 21:

		numb1 = 8;
		colorb = 2;
		break;
	case 22:

		numb1 = 9;
		colorb = 2;
		break;
	case 23:

		numb1 = 10;
		colorb = 2;
		break;
	case 24:

		numb1 = 10.1;
		colorb = 2;
		break;
	case 25:

		numb1 = 10.2;
		colorb = 2;
		break;
	case 26:

		numb1 = 10.3;
		colorb = 2;
		break;
	case 27:

		numb1 = 11;
		numb2 = 1;
		colorb = 3;
		break;
	case 28:

		numb1 = 2;
		colorb = 3;
		break;
	case 29:

		numb1 = 3;
		colorb = 3;
		break;
	case 30:

		numb1 = 4;
		colorb = 3;
		break;
	case 31:

		numb1 = 5;
		colorb = 3;
		break;
	case 32:

		numb1 = 6;
		colorb = 3;
		break;
	case 33:

		numb1 = 7;
		colorb = 3;
		break;
	case 34:

		numb1 = 8;
		colorb = 3;
		break;
	case 35:

		numb1 = 9;
		colorb = 3;
		break;
	case 36:

		numb1 = 10;
		colorb = 3;
		break;
	case 37:

		numb1 = 10.1;
		colorb = 3;
		break;
	case 38:

		numb1 = 10.2;
		colorb = 3;
		break;
	case 39:

		numb1 = 10.3;
		colorb = 3;
		break;
	case 40:

		numb1 = 11;
		numb2 = 1;
		colorb = 4;
		break;
	case 41:

		numb1 = 2;
		colorb = 4;
		break;
	case 42:

		numb1 = 3;
		colorb = 4;
		break;
	case 43:

		numb1 = 4;
		colorb = 4;
		break;
	case 44:

		numb1 = 5;
		colorb = 4;
		break;
	case 45:

		numb1 = 6;
		colorb = 4;
		break;
	case 46:

		numb1 = 7;
		colorb = 4;
		break;
	case 47:

		numb1 = 8;
		colorb = 4;
		break;
	case 48:

		numb1 = 9;
		colorb = 4;
		break;
	case 49:

		numb1 = 10;
		colorb = 4;
		break;
	case 50:

		numb1 = 10.1;
		colorb = 4;
		break;
	case 51:

		numb1 = 10.2;
		colorb = 4;
		break;
	case 52:

		numb1 = 10.3;
		colorb = 4;
		break;

	}

}

void firstValueOnTable(int theRandNumber3, float numc1, float numc2, float colorc) {

	; // 1=hearts, 2=diamonds, 3=spades, 4=clubs

	switch (theRandNumber3) {
	case 1:

		numc1 = 11;
		numc2 = 1;
		colorc = 1;

		break;
	case 2:

		numc1 = 2;
		colorc = 1;
		break;
	case 3:

		numc1 = 3;
		colorc = 1;
		break;
	case 4:

		numc1 = 4;
		colorc = 1;
		break;
	case 5:

		numc1 = 5;
		colorc = 1;
		break;
	case 6:

		numc1 = 6;
		colorc = 1;
		break;
	case 7:

		numc1 = 7;
		colorc = 1;
		break;
	case 8:

		numc1 = 8;
		colorc = 1;
		break;
	case 9:

		numc1 = 9;
		colorc = 1;
		break;
	case 10:

		numc1 = 10;
		colorc = 1;
		break;
	case 11:

		numc1 = 10.1;
		colorc = 1;
		break;
	case 12:

		numc1 = 10.2;
		colorc = 1;
		break;
	case 13:

		numc1 = 10.3;
		colorc = 1;
		break;
	case 14:

		numc1 = 11;
		numc2 = 1;
		colorc = 2;
		break;
	case 15:

		numc1 = 2;
		colorc = 2;
		break;
	case 16:

		numc1 = 3;
		colorc = 2;
		break;
	case 17:

		numc1 = 4;
		colorc = 2;
		break;
	case 18:

		numc1 = 5;
		colorc = 2;
		break;
	case 19:

		numc1 = 6;
		colorc = 2;
		break;
	case 20:

		numc1 = 7;
		colorc = 2;
		break;
	case 21:

		numc1 = 8;
		colorc = 2;
		break;
	case 22:

		numc1 = 9;
		colorc = 2;
		break;
	case 23:

		numc1 = 10;
		colorc = 2;
		break;
	case 24:

		numc1 = 10.1;
		colorc = 2;
		break;
	case 25:

		numc1 = 10.2;
		colorc = 2;
		break;
	case 26:

		numc1 = 10.3;
		colorc = 2;
		break;
	case 27:

		numc1 = 11;
		numc2 = 1;
		colorc = 3;
		break;
	case 28:

		numc1 = 2;
		colorc = 3;
		break;
	case 29:

		numc1 = 3;
		colorc = 3;
		break;
	case 30:

		numc1 = 4;
		colorc = 3;
		break;
	case 31:

		numc1 = 5;
		colorc = 3;
		break;
	case 32:

		numc1 = 6;
		colorc = 3;
		break;
	case 33:

		numc1 = 7;
		colorc = 3;
		break;
	case 34:

		numc1 = 8;
		colorc = 3;
		break;
	case 35:

		numc1 = 9;
		colorc = 3;
		break;
	case 36:

		numc1 = 10;
		colorc = 3;
		break;
	case 37:

		numc1 = 10.1;
		colorc = 3;
		break;
	case 38:

		numc1 = 10.2;
		colorc = 3;
		break;
	case 39:

		numc1 = 10.3;
		colorc = 3;
		break;
	case 40:

		numc1 = 11;
		numc2 = 1;
		colorc = 4;
		break;
	case 41:

		numc1 = 2;
		colorc = 4;
		break;
	case 42:

		numc1 = 3;
		colorc = 4;
		break;
	case 43:

		numc1 = 4;
		colorc = 4;
		break;
	case 44:

		numc1 = 5;
		colorc = 4;
		break;
	case 45:

		numc1 = 6;
		colorc = 4;
		break;
	case 46:

		numc1 = 7;
		colorc = 4;
		break;
	case 47:

		numc1 = 8;
		colorc = 4;
		break;
	case 48:

		numc1 = 9;
		colorc = 4;
		break;
	case 49:

		numc1 = 10;
		colorc = 4;
		break;
	case 50:

		numc1 = 10.1;
		colorc = 4;
		break;
	case 51:

		numc1 = 10.2;
		colorc = 4;
		break;
	case 52:

		numc1 = 10.3;
		colorc = 4;
		break;

	}

}

void secondValueOnTable(int theRandNumber4, float numd1, float numd2, float colord) {
	// 1=hearts, 2=diamonds, 3=spades, 4=clubs

	switch (theRandNumber4) {
	case 1:

		numd1 = 11;
		numd2 = 1;
		colord = 1;

		break;
	case 2:

		numd1 = 2;
		colord = 1;
		break;
	case 3:

		numd1 = 3;
		colord = 1;
		break;
	case 4:

		numd1 = 4;
		colord = 1;
		break;
	case 5:

		numd1 = 5;
		colord = 1;
		break;
	case 6:

		numd1 = 6;
		colord = 1;
		break;
	case 7:

		numd1 = 7;
		colord = 1;
		break;
	case 8:
		numd1 = 8;
		colord = 1;
		break;
	case 9:

		numd1 = 9;
		colord = 1;
		break;
	case 10:

		numd1 = 10;
		colord = 1;
		break;
	case 11:

		numd1 = 10.1;
		colord = 1;
		break;
	case 12:

		numd1 = 10.2;
		colord = 1;
		break;
	case 13:

		numd1 = 10.3;
		colord = 1;
		break;
	case 14:

		numd1 = 11;
		numd2 = 1;
		colord = 2;
		break;
	case 15:

		numd1 = 2;
		colord = 2;
		break;
	case 16:

		numd1 = 3;
		colord = 2;
		break;
	case 17:

		numd1 = 4;
		colord = 2;
		break;
	case 18:

		numd1 = 5;
		colord = 2;
		break;
	case 19:

		numd1 = 6;
		colord = 2;
		break;
	case 20:

		numd1 = 7;
		colord = 2;
		break;
	case 21:

		numd1 = 8;
		colord = 2;
		break;
	case 22:

		numd1 = 9;
		colord = 2;
		break;
	case 23:

		numd1 = 10;
		colord = 2;
		break;
	case 24:

		numd1 = 10.1;
		colord = 2;
		break;
	case 25:

		numd1 = 10.2;
		colord = 2;
		break;
	case 26:

		numd1 = 10.3;
		colord = 2;
		break;
	case 27:

		numd1 = 11;
		numd2 = 1;
		colord = 3;
		break;
	case 28:

		numd1 = 2;
		colord = 3;
		break;
	case 29:

		numd1 = 3;
		colord = 3;
		break;
	case 30:

		numd1 = 4;
		colord = 3;
		break;
	case 31:

		numd1 = 5;
		colord = 3;
		break;
	case 32:

		numd1 = 6;
		colord = 3;
		break;
	case 33:

		numd1 = 7;
		colord = 3;
		break;
	case 34:

		numd1 = 8;
		colord = 3;
		break;
	case 35:

		numd1 = 9;
		colord = 3;
		break;
	case 36:

		numd1 = 10;
		colord = 3;
		break;
	case 37:

		numd1 = 10.1;
		colord = 3;
		break;
	case 38:

		numd1 = 10.2;
		colord = 3;
		break;
	case 39:

		numd1 = 10.3;
		colord = 3;
		break;
	case 40:

		numd1 = 11;
		numd2 = 1;
		colord = 4;
		break;
	case 41:

		numd1 = 2;
		colord = 4;
		break;
	case 42:

		numd1 = 3;
		colord = 4;
		break;
	case 43:

		numd1 = 4;
		colord = 4;
		break;
	case 44:

		numd1 = 5;
		colord = 4;
		break;
	case 45:

		numd1 = 6;
		colord = 4;
		break;
	case 46:

		numd1 = 7;
		colord = 4;
		break;
	case 47:

		numd1 = 8;
		colord = 4;
		break;
	case 48:

		numd1 = 9;
		colord = 4;
		break;
	case 49:

		numd1 = 10;
		colord = 4;
		break;
	case 50:

		numd1 = 10.1;
		colord = 4;
		break;
	case 51:

		numd1 = 10.2;
		colord = 4;
		break;
	case 52:

		numd1 = 10.3;
		colord = 4;
		break;

	}

}

void thirdValueOnTable(int theRandNumber5, float nume1, float nume2, float colore) {

	// 1=hearts, 2=diamonds, 3=spades, 4=clubs

	switch (theRandNumber5) {
	case 1:

		nume1 = 11;
		nume2 = 1;
		colore = 1;

		break;
	case 2:

		nume1 = 2;
		colore = 1;
		break;
	case 3:

		nume1 = 3;
		colore = 1;
		break;
	case 4:

		nume1 = 4;
		colore = 1;
		break;
	case 5:

		nume1 = 5;
		colore = 1;
		break;
	case 6:

		nume1 = 6;
		colore = 1;
		break;
	case 7:

		nume1 = 7;
		colore = 1;
		break;
	case 8:

		nume1 = 8;
		colore = 1;
		break;
	case 9:

		nume1 = 9;
		colore = 1;
		break;
	case 10:

		nume1 = 10;
		colore = 1;
		break;
	case 11:

		nume1 = 10.1;
		colore = 1;
		break;
	case 12:

		nume1 = 10.2;
		colore = 1;
		break;
	case 13:

		nume1 = 10.3;
		colore = 1;
		break;
	case 14:

		nume1 = 11;
		nume2 = 1;
		colore = 2;
		break;
	case 15:

		nume1 = 2;
		colore = 2;
		break;
	case 16:

		nume1 = 3;
		colore = 2;
		break;
	case 17:

		nume1 = 4;
		colore = 2;
		break;
	case 18:

		nume1 = 5;
		colore = 2;
		break;
	case 19:

		nume1 = 6;
		colore = 2;
		break;
	case 20:

		nume1 = 7;
		colore = 2;
		break;
	case 21:

		nume1 = 8;
		colore = 2;
		break;
	case 22:

		nume1 = 9;
		colore = 2;
		break;
	case 23:

		nume1 = 10;
		colore = 2;
		break;
	case 24:

		nume1 = 10.1;
		colore = 2;
		break;
	case 25:

		nume1 = 10.2;
		colore = 2;
		break;
	case 26:

		nume1 = 10.3;
		colore = 2;
		break;
	case 27:

		nume1 = 11;
		nume2 = 1;
		colore = 3;
		break;
	case 28:

		nume1 = 2;
		colore = 3;
		break;
	case 29:

		nume1 = 3;
		colore = 3;
		break;
	case 30:

		nume1 = 4;
		colore = 3;
		break;
	case 31:

		nume1 = 5;
		colore = 3;
		break;
	case 32:

		nume1 = 6;
		colore = 3;
		break;
	case 33:

		nume1 = 7;
		colore = 3;
		break;
	case 34:

		nume1 = 8;
		colore = 3;
		break;
	case 35:

		nume1 = 9;
		colore = 3;
		break;
	case 36:

		nume1 = 10;
		colore = 3;
		break;
	case 37:

		nume1 = 10.1;
		colore = 3;
		break;
	case 38:

		nume1 = 10.2;
		colore = 3;
		break;
	case 39:

		nume1 = 10.3;
		colore = 3;
		break;
	case 40:

		nume1 = 11;
		nume2 = 1;
		colore = 4;
		break;
	case 41:

		nume1 = 2;
		colore = 4;
		break;
	case 42:

		nume1 = 3;
		colore = 4;
		break;
	case 43:

		nume1 = 4;
		colore = 4;
		break;
	case 44:

		nume1 = 5;
		colore = 4;
		break;
	case 45:

		nume1 = 6;
		colore = 4;
		break;
	case 46:

		nume1 = 7;
		colore = 4;
		break;
	case 47:

		nume1 = 8;
		colore = 4;
		break;
	case 48:

		nume1 = 9;
		colore = 4;
		break;
	case 49:

		nume1 = 10;
		colore = 4;
		break;
	case 50:

		nume1 = 10.1;
		colore = 4;
		break;
	case 51:

		nume1 = 10.2;
		colore = 4;
		break;
	case 52:

		nume1 = 10.3;
		colore = 4;
		break;

	}


}

void fourthValueOnTable(int theRandNumber6, float numf1, float numf2, float colorf) {

	// 1=hearts, 2=diamonds, 3=spades, 4=clubs

	switch (theRandNumber6) {
	case 1:

		numf1 = 11;
		numf2 = 1;
		colorf = 1;

		break;
	case 2:

		numf1 = 2;
		colorf = 1;
		break;
	case 3:

		numf1 = 3;
		colorf = 1;
		break;
	case 4:

		numf1 = 4;
		colorf = 1;
		break;
	case 5:

		numf1 = 5;
		colorf = 1;
		break;
	case 6:

		numf1 = 6;
		colorf = 1;
		break;
	case 7:

		numf1 = 7;
		colorf = 1;
		break;
	case 8:

		numf1 = 8;
		colorf = 1;
		break;
	case 9:

		numf1 = 9;
		colorf = 1;
		break;
	case 10:

		numf1 = 10;
		colorf = 1;
		break;
	case 11:

		numf1 = 10.1;
		colorf = 1;
		break;
	case 12:

		numf1 = 10.2;
		colorf = 1;
		break;
	case 13:

		numf1 = 10.3;
		colorf = 1;
		break;
	case 14:

		numf1 = 11;
		numf2 = 1;
		colorf = 2;
		break;
	case 15:

		numf1 = 2;
		colorf = 2;
		break;
	case 16:

		numf1 = 3;
		colorf = 2;
		break;
	case 17:

		numf1 = 4;
		colorf = 2;
		break;
	case 18:

		numf1 = 5;
		colorf = 2;
		break;
	case 19:

		numf1 = 6;
		colorf = 2;
		break;
	case 20:

		numf1 = 7;
		colorf = 2;
		break;
	case 21:

		numf1 = 8;
		colorf = 2;
		break;
	case 22:

		numf1 = 9;
		colorf = 2;
		break;
	case 23:

		numf1 = 10;
		colorf = 2;
		break;
	case 24:

		numf1 = 10.1;
		colorf = 2;
		break;
	case 25:

		numf1 = 10.2;
		colorf = 2;
		break;
	case 26:

		numf1 = 10.3;
		colorf = 2;
		break;
	case 27:

		numf1 = 11;
		numf2 = 1;
		colorf = 3;
		break;
	case 28:

		numf1 = 2;
		colorf = 3;
		break;
	case 29:

		numf1 = 3;
		colorf = 3;
		break;
	case 30:

		numf1 = 4;
		colorf = 3;
		break;
	case 31:

		numf1 = 5;
		colorf = 3;
		break;
	case 32:

		numf1 = 6;
		colorf = 3;
		break;
	case 33:

		numf1 = 7;
		colorf = 3;
		break;
	case 34:

		numf1 = 8;
		colorf = 3;
		break;
	case 35:

		numf1 = 9;
		colorf = 3;
		break;
	case 36:

		numf1 = 10;
		colorf = 3;
		break;
	case 37:

		numf1 = 10.1;
		colorf = 3;
		break;
	case 38:

		numf1 = 10.2;
		colorf = 3;
		break;
	case 39:

		numf1 = 10.3;
		colorf = 3;
		break;
	case 40:

		numf1 = 11;
		numf2 = 1;
		colorf = 4;
		break;
	case 41:

		numf1 = 2;
		colorf = 4;
		break;
	case 42:

		numf1 = 3;
		colorf = 4;
		break;
	case 43:

		numf1 = 4;
		colorf = 4;
		break;
	case 44:

		numf1 = 5;
		colorf = 4;
		break;
	case 45:

		numf1 = 6;
		colorf = 4;
		break;
	case 46:

		numf1 = 7;
		colorf = 4;
		break;
	case 47:

		numf1 = 8;
		colorf = 4;
		break;
	case 48:

		numf1 = 9;
		colorf = 4;
		break;
	case 49:

		numf1 = 10;
		colorf = 4;
		break;
	case 50:

		numf1 = 10.1;
		colorf = 4;
		break;
	case 51:

		numf1 = 10.2;
		colorf = 4;
		break;
	case 52:

		numf1 = 10.3;
		colorf = 4;
		break;

	}


}

void firstValueOfOpponent(int theRandNumber7, float numg1, float numg2, float colorg) {
	// 1=hearts, 2=diamonds, 3=spades, 4=clubs

	switch (theRandNumber7) {
	case 1:

		numg1 = 11;
		numg2 = 1;
		colorg = 1;

		break;
	case 2:

		numg1 = 2;
		colorg = 1;
		break;
	case 3:

		numg1 = 3;
		colorg = 1;
		break;
	case 4:

		numg1 = 4;
		colorg = 1;
		break;
	case 5:

		numg1 = 5;
		colorg = 1;
		break;
	case 6:

		numg1 = 6;
		colorg = 1;
		break;
	case 7:

		numg1 = 7;
		colorg = 1;
		break;
	case 8:

		numg1 = 8;
		colorg = 1;
		break;
	case 9:

		numg1 = 9;
		colorg = 1;
		break;
	case 10:

		numg1 = 10;
		colorg = 1;
		break;
	case 11:

		numg1 = 10.1;
		colorg = 1;
		break;
	case 12:

		numg1 = 10.2;
		colorg = 1;
		break;
	case 13:

		numg1 = 10.3;
		colorg = 1;
		break;
	case 14:

		numg1 = 11;
		numg2 = 1;
		colorg = 2;
		break;
	case 15:

		numg1 = 2;
		colorg = 2;
		break;
	case 16:

		numg1 = 3;
		colorg = 2;
		break;
	case 17:

		numg1 = 4;
		colorg = 2;
		break;
	case 18:

		numg1 = 5;
		colorg = 2;
		break;
	case 19:

		numg1 = 6;
		colorg = 2;
		break;
	case 20:

		numg1 = 7;
		colorg = 2;
		break;
	case 21:

		numg1 = 8;
		colorg = 2;
		break;
	case 22:

		numg1 = 9;
		colorg = 2;
		break;
	case 23:

		numg1 = 10;
		colorg = 2;
		break;
	case 24:

		numg1 = 10.1;
		colorg = 2;
		break;
	case 25:

		numg1 = 10.2;
		colorg = 2;
		break;
	case 26:

		numg1 = 10.3;
		colorg = 2;
		break;
	case 27:

		numg1 = 11;
		numg2 = 1;
		colorg = 3;
		break;
	case 28:

		numg1 = 2;
		colorg = 3;
		break;
	case 29:

		numg1 = 3;
		colorg = 3;
		break;
	case 30:

		numg1 = 4;
		colorg = 3;
		break;
	case 31:

		numg1 = 5;
		colorg = 3;
		break;
	case 32:

		numg1 = 6;
		colorg = 3;
		break;
	case 33:

		numg1 = 7;
		colorg = 3;
		break;
	case 34:

		numg1 = 8;
		colorg = 3;
		break;
	case 35:

		numg1 = 9;
		colorg = 3;
		break;
	case 36:

		numg1 = 10;
		colorg = 3;
		break;
	case 37:

		numg1 = 10.1;
		colorg = 3;
		break;
	case 38:

		numg1 = 10.2;
		colorg = 3;
		break;
	case 39:

		numg1 = 10.3;
		colorg = 3;
		break;
	case 40:

		numg1 = 11;
		numg2 = 1;
		colorg = 4;
		break;
	case 41:

		numg1 = 2;
		colorg = 4;
		break;
	case 42:

		numg1 = 3;
		colorg = 4;
		break;
	case 43:

		numg1 = 4;
		colorg = 4;
		break;
	case 44:

		numg1 = 5;
		colorg = 4;
		break;
	case 45:

		numg1 = 6;
		colorg = 4;
		break;
	case 46:

		numg1 = 7;
		colorg = 4;
		break;
	case 47:

		numg1 = 8;
		colorg = 4;
		break;
	case 48:

		numg1 = 9;
		colorg = 4;
		break;
	case 49:

		numg1 = 10;
		colorg = 4;
		break;
	case 50:

		numg1 = 10.1;
		colorg = 4;
		break;
	case 51:

		numg1 = 10.2;
		colorg = 4;
		break;
	case 52:

		numg1 = 10.3;
		colorg = 4;
		break;

	}

}

void secondValueOfOpponent(int theRandNumber8, float numh1, float numh2, float colorh) {
	// 1=hearts, 2=diamonds, 3=spades, 4=clubs

	switch (theRandNumber8) {
	case 1:

		numh1 = 11;
		numh2 = 1;
		colorh = 1;

		break;
	case 2:

		numh1 = 2;
		colorh = 1;
		break;
	case 3:

		numh1 = 3;
		colorh = 1;
		break;
	case 4:

		numh1 = 4;
		colorh = 1;
		break;
	case 5:

		numh1 = 5;
		colorh = 1;
		break;
	case 6:

		numh1 = 6;
		colorh = 1;
		break;
	case 7:

		numh1 = 7;
		colorh = 1;
		break;
	case 8:

		numh1 = 8;
		colorh = 1;
		break;
	case 9:

		numh1 = 9;
		colorh = 1;
		break;
	case 10:

		numh1 = 10;
		colorh = 1;
		break;
	case 11:

		numh1 = 10.1;
		colorh = 1;
		break;
	case 12:

		numh1 = 10.2;
		colorh = 1;
		break;
	case 13:

		numh1 = 10.3;
		colorh = 1;
		break;
	case 14:

		numh1 = 11;
		numh2 = 1;
		colorh = 2;
		break;
	case 15:

		numh1 = 2;
		colorh = 2;
		break;
	case 16:

		numh1 = 3;
		colorh = 2;
		break;
	case 17:

		numh1 = 4;
		colorh = 2;
		break;
	case 18:

		numh1 = 5;
		colorh = 2;
		break;
	case 19:

		numh1 = 6;
		colorh = 2;
		break;
	case 20:

		numh1 = 7;
		colorh = 2;
		break;
	case 21:

		numh1 = 8;
		colorh = 2;
		break;
	case 22:

		numh1 = 9;
		colorh = 2;
		break;
	case 23:

		numh1 = 10;
		colorh = 2;
		break;
	case 24:

		numh1 = 10.1;
		colorh = 2;
		break;
	case 25:

		numh1 = 10.2;
		colorh = 2;
		break;
	case 26:

		numh1 = 10.3;
		colorh = 2;
		break;
	case 27:

		numh1 = 11;
		numh2 = 1;
		colorh = 3;
		break;
	case 28:

		numh1 = 2;
		colorh = 3;
		break;
	case 29:

		numh1 = 3;
		colorh = 3;
		break;
	case 30:

		numh1 = 4;
		colorh = 3;
		break;
	case 31:

		numh1 = 5;
		colorh = 3;
		break;
	case 32:

		numh1 = 6;
		colorh = 3;
		break;
	case 33:

		numh1 = 7;
		colorh = 3;
		break;
	case 34:

		numh1 = 8;
		colorh = 3;
		break;
	case 35:

		numh1 = 9;
		colorh = 3;
		break;
	case 36:

		numh1 = 10;
		colorh = 3;
		break;
	case 37:

		numh1 = 10.1;
		colorh = 3;
		break;
	case 38:

		numh1 = 10.2;
		colorh = 3;
		break;
	case 39:

		numh1 = 10.3;
		colorh = 3;
		break;
	case 40:

		numh1 = 11;
		numh2 = 1;
		colorh = 4;
		break;
	case 41:

		numh1 = 2;
		colorh = 4;
		break;
	case 42:

		numh1 = 3;
		colorh = 4;
		break;
	case 43:

		numh1 = 4;
		colorh = 4;
		break;
	case 44:

		numh1 = 5;
		colorh = 4;
		break;
	case 45:

		numh1 = 6;
		colorh = 4;
		break;
	case 46:

		numh1 = 7;
		colorh = 4;
		break;
	case 47:

		numh1 = 8;
		colorh = 4;
		break;
	case 48:

		numh1 = 9;
		colorh = 4;
		break;
	case 49:

		numh1 = 10;
		colorh = 4;
		break;
	case 50:

		numh1 = 10.1;
		colorh = 4;
		break;
	case 51:

		numh1 = 10.2;
		colorh = 4;
		break;
	case 52:

		numh1 = 10.3;
		colorh = 4;
		break;

	}

}

void winningSystem(int userMoney, int betAmount, int betcount, float numa1, float numa2, float colora, float numb1, float numb2, float colorb, float numc1, float numc2, float colorc, float numd1, float numd2, float colord, float nume1, float nume2, float colore, float numf1, float numf2, float colorf, float numg1, float numg2, float colorg, float numh1, float numh2, float colorh) {
	int pointsPlayer = 0, pointsOpponent = 0;
	float highCard[6] = { 0 };
	int count = 10, c = 0, temp = 0, i = 0;
	// GAME RULES


	////// PAIRS ///////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (numa1 == numb1 || numa1 == numc1 || numa1 == numd1 || numa1 == nume1 || numa1 == numf1) { // PAIRS FOR FIRST CARD player
		pointsPlayer = pointsPlayer + 5;
	}
	if (numb1 == numc1 || numb1 == numd1 || numb1 == nume1 || numb1 == numf1) { // PAIRS FOR SECOND CARD PLAYER
		pointsPlayer = pointsPlayer + 5;
	}
	if (numg1 == numh1 || numg1 == numc1 || numg1 == numd1 || numg1 == nume1 || numg1 == numf1) { // PAIRS FOR FIRST CARD opponent
		pointsOpponent = pointsOpponent + 5;
	}
	if (numh1 == numc1 || numh1 == numd1 || numh1 == nume1 || numh1 == numf1) { // PAIRS FOR second CARD opponent
		pointsOpponent = pointsOpponent + 5;
	}

	// three of a kind/////////////////////////////////////////////////////////////////////////////////////////////////
	if (numa1 == numb1 && numa1 == numc1 || numa1 == numb1&&numa1 == numd1 || numa1 == numb1&&numa1 == nume1 || numa1 == numb1&&numa1 == numf1 || numa1 == numc1&&numa1 == numd1 || numa1 == numc1&&numa1 == nume1 || numa1 == numc1&&numa1 == numf1 || numa1 == numd1&&numa1 == nume1 || numa1 == numd1&&numa1 == numf1 || numa1 == nume1&&numa1 == numf1) {
		pointsPlayer = pointsPlayer + 15;
	}
	if (numb1 == numc1&&numb1 == numd1 || numb1 == numc1&&numb1 == nume1 || numb1 == numc1&&numb1 == numf1 || numb1 == numd1&&numb1 == nume1 || numb1 == numd1&&numb1 == numf1 || numb1 == nume1&&numb1 == numf1) {
		pointsPlayer = pointsPlayer + 15;
	}
	if (numg1 == numh1 && numg1 == numc1 || numg1 == numh1&&numg1 == numd1 || numg1 == numh1&&numg1 == nume1 || numg1 == numh1&&numg1 == numf1 || numg1 == numc1&&numg1 == numd1 || numg1 == numc1&&numg1 == nume1 || numg1 == numc1&&numg1 == numf1 || numg1 == numd1&&numg1 == nume1 || numg1 == numd1&&numg1 == numf1 || numg1 == nume1&&numg1 == numf1) {
		pointsOpponent = pointsOpponent + 15;
	}
	if (numh1 == numc1&&numh1 == numd1 || numh1 == numc1&&numh1 == nume1 || numh1 == numc1&&numh1 == numf1 || numh1 == numd1&&numh1 == nume1 || numh1 == numd1&&numh1 == numf1 || numh1 == nume1&&numh1 == numf1) {
		pointsOpponent = pointsOpponent + 15;
	}

	// straight /////////player//////////////////////////////////////////////////////////////////////////////////
	highCard[0] = numa1;
	highCard[1] = numb1;
	highCard[2] = numc1;
	highCard[3] = numd1;
	highCard[4] = nume1;
	highCard[5] = numf1;
	for (i = 0; i <= count; i++) {
		for (c = i; c <= i - count - 1; c++) {
			if (highCard[c] > highCard[c + 1]) {
				temp = highCard[c];
				highCard[c] = highCard[c + 1];
				highCard[c + 1] = temp;
			}
		}//End For 2
	}//End For

	if (highCard[0] + 1 == highCard[1] && highCard[1] + 1 == highCard[2] && highCard[2] + 1 == highCard[3] && highCard[3] + 1 == highCard[4] || highCard[1] + 1 == highCard[2] && highCard[2] + 1 == highCard[3] && highCard[3] + 1 == highCard[4] && highCard[4] + 1 == highCard[5])
		pointsPlayer = pointsPlayer + 25;

	// straight /////////opponent////////////////////////////////////////////////////////////////////////////////
	highCard[0] = numg1;
	highCard[1] = numh1;
	highCard[2] = numc1;
	highCard[3] = numd1;
	highCard[4] = nume1;
	highCard[5] = numf1;
	for (i = 0; i <= count; i++) {
		for (c = i; c <= i - count - 1; c++) {
			if (highCard[c] > highCard[c + 1]) {
				temp = highCard[c];
				highCard[c] = highCard[c + 1];
				highCard[c + 1] = temp;
			}
		}//End For 2
	}//End For

	if (highCard[0] + 1 == highCard[1] && highCard[1] + 1 == highCard[2] && highCard[2] + 1 == highCard[3] && highCard[3] + 1 == highCard[4] || highCard[1] + 1 == highCard[2] && highCard[2] + 1 == highCard[3] && highCard[3] + 1 == highCard[4] && highCard[4] + 1 == highCard[5])
		pointsOpponent = pointsOpponent + 25;


	//////////////FLUSH////////////////////////////////////////////////////////////////////////////////////////////////////////
	// PLAYER//
	if (colora == colorb&&colora == colorc&&colora == colord&&colora == colore || colora == colorb&&colora == colord&&colora == colore&&colora == colorf || colora == colorb&&colora == colorc&&colora == colore&&colora == colorf || colora == colorb&&colora == colorc&&colora == colord&&colora == colorf || colora == colorc&&colora == colord&&colora == colore&&colora == colorf)
		pointsPlayer = pointsPlayer + 35;
	if (colorb == colorc&&colorb == colord&&colorb == colore&&colorb == colorf)
		pointsPlayer = pointsPlayer + 35;
	// OPPONENT //
	if (colorg == colorh&&colorg == colorc&&colorg == colord&&colorg == colore || colorg == colorh&&colorg == colord&&colorg == colore&&colorg == colorf || colorg == colorh&&colorg == colorc&&colorg == colore&&colorg == colorf || colorg == colorh&&colorg == colorc&&colorg == colord&&colorg == colorf || colorg == colorc&&colorg == colord&&colorg == colore&&colorg == colorf)
		pointsOpponent = pointsOpponent + 35;
	if (colorh == colorc&&colorh == colord&&colorh == colore&&colorh == colorf)
		pointsOpponent = pointsOpponent + 35;

	////////// FOUR OF A KIND ////////////////////////////////////////////////////////////
	// PLAYER //
	if (numa1 == numb1&&numa1 == numc1&&numa1 == numd1 || numa1 == numb1&&numa1 == numc1&&numa1 == nume1 || numa1 == numb1&&numa1 == numc1&&numa1 == numf1 || numa1 == numb1&&numa1 == numd1&&numa1 == nume1 || numa1 == numb1&&numa1 == numd1&&numa1 == numf1 || numa1 == numb1&&numa1 == nume1&&numa1 == numf1 || numa1 == numc1&&numa1 == numd1&&numa1 == nume1 || numa1 == numc1&&numa1 == nume1&&numa1 == numf1 || numa1 == numc1&&numa1 == numd1&&numa1 == numf1 || numa1 == numd1&&numa1 == nume1&&numa1 == numf1)
		pointsPlayer = pointsPlayer + 75;
	if (numb1 == numc1&&numb1 == numd1&&numb1 == nume1 || numb1 == numc1&&numb1 == nume1&&numb1 == numf1 || numb1 == numc1&&numb1 == numd1&&numb1 == numf1 || numb1 == numd1&&numb1 == nume1&&numb1 == numf1)
		pointsPlayer = pointsPlayer + 75;
	// OPPONENT //
	if (numg1 == numh1&&numg1 == numc1&&numg1 == numd1 || numg1 == numh1&&numg1 == numc1&&numg1 == nume1 || numg1 == numh1&&numg1 == numc1&&numg1 == numf1 || numg1 == numh1&&numg1 == numh1&&numg1 == nume1 || numg1 == numh1&&numg1 == numd1&&numg1 == numf1 || numg1 == numh1&&numg1 == nume1&&numg1 == numf1 || numg1 == numc1&&numg1 == numd1&&numg1 == nume1 || numg1 == numc1&&numg1 == nume1&&numg1 == numf1 || numg1 == numc1&&numg1 == numd1&&numg1 == numf1 || numg1 == numd1&&numg1 == nume1&&numg1 == numf1)
		pointsOpponent = pointsOpponent + 75;
	if (numh1 == numc1&&numh1 == numd1&&numh1 == nume1 || numh1 == numc1&&numh1 == nume1&&numh1 == numf1 || numh1 == numc1&&numh1 == numd1&&numh1 == numf1 || numh1 == numd1&&numh1 == nume1&&numh1 == numf1)
		pointsOpponent = pointsOpponent + 75;


	//////////////////// HIGH CARD //////////////////////////////////////////////////////
	if (pointsPlayer == pointsOpponent) { //high card

		highCard[0] = numa1;
		highCard[1] = numb1;
		highCard[2] = numg1;
		highCard[3] = numh1;
		highCard[4] = 0;
		highCard[5] = 0;
		for (i = 0; i <= count; i++) {
			for (c = i; c <= i - count - 1; c++) {
				if (highCard[c] < highCard[c + 1]) {
					temp = highCard[c];
					highCard[c] = highCard[c + 1];
					highCard[c + 1] = temp;
				}
			}//End For 2
		}//End For
		if (highCard[0] == numa1)
			pointsPlayer++;
		if (highCard[0] == numb1)
			pointsPlayer++;
		if (highCard[0] == numg1)
			pointsOpponent++;
		if (highCard[0] == numg1)
			pointsOpponent++;
	}
	CLS;

	if (pointsPlayer > pointsOpponent) {
		userMoney = userMoney + (betcount * 2);
		printf("\n\n\t <CONGRATULATIONS PLAYER 1> \n\t         <YOU WON>        \n\n");
		printf("\n\n\t <NOW YOU HAVE %i DOLLARS> \n\n", userMoney);

	}
	else {
		printf("\n\n\t <I AM SORRY PLAYER 1> \n\t     <YOU LOOSE>     \n\n");
		printf("\n\n\t <NOW YOU HAVE %i DOLLARS> \n\n", userMoney);
	}
	betcount = 0;

	PAUSE;
}

char endGame() {
	char result;
	CLS;
	printf("<DO YOU WANT TO PLAY AGAIN (Y/N) ?>\n");
	scanf("%c", &result);
	result = toupper(result);
	return result;
}

/////////// END OF CASINO ////////////////////////////////////////////////// 