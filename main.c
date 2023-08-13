
#include "defintion.h"
int main(void)
{

	// Initialize the variables
	int option = 0, dice1 = 0, dice2 = 0, dice3 = 0, dice4 = 0, dice5 = 0, x = 0, size = 5, counter = 0, one_value = 0, points = 0, comb_option = 0, two_value = 0, three_value = 0, four_value = 0, five_value = 0, six_value = 0, turn = 0, round = 0, player1_points = 0, player2_points = 0, uppersecp1 = 0, uppersecp2 = 0, lowersecp2 = 0, lowersecp1 = 0, reroll = 0;
	char answer = 'a';
	int values[100];
	// Use this variable to loop through the program till the user enters the exit option
	int proceed = 1;

	// setup the library for random number generator
	srand((unsigned int)time(NULL)); // call only once PERIOD

	// The program will keep showing the menu items until the player selects the option-4 (Exit the game)
	while (proceed == 1) {
		printf("\n choose an option between 1 and 3\n");
		printf("option 1: diplay rules\n");
		printf("option 2: play game\n");
		printf("option 3: exit game\n");
		scanf("%d", &option);
		clear_function();

		// Decide the actions based on the option selected
		switch (option) // option has to be 1 - 3
		{
		case 1:
			printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. The lower section contains a number of poker like combinations.\nlower section: three of a kind: sum of all five faces on the dice\nfour of a kind: sum of all five faces on the dice\na sequence of four dice: 30 points\na sequence of five dice: 40 points\nfive dice with same values: 50 points\nchance: sum of all five dices\n");
			break;
		case 2:
			// Initialize the variables every time the user plays the game
			counter = 0;
			turn = 0;
			round = 0;
			uppersecp1 = 0;
			uppersecp2 = 0;
			lowersecp1 = 0;
			lowersecp2 = 0;
			player1_points = 0; // total player-1 points
			player2_points = 0; // total player-2 points

			// Play for 14 rounds
			while (round < 14) {
				turn = 0;

				// Each round is of 2 turns
				while (turn < 2) {

					// Start playing till the user changes combination or reaches 3 time dice rolls
					do {
						// Start with rolling the 5 dices
						dice1 = roll_dice();
						values[0] = dice1;
						dice2 = roll_dice();
						values[1] = dice2;
						dice3 = roll_dice();
						values[2] = dice3;
						dice4 = roll_dice();
						values[3] = dice4;
						dice5 = roll_dice();
						values[4] = dice5;

						for (int i = 0; i < size; i++) {
							printf("\n%d", values[i]);
						}
						printf("\n Do you want to keep the combination?\n");
						scanf(" %c", &answer);

						// If the user wants to change the dice rolls values, get the dices that need to be changed
						while (answer == 'n') {
							printf("\nhow many dice do you want to reroll?\n");
							scanf("%d", &reroll);
							for (int i = 0; i < reroll; i++) {
								reroll_dice(values);
							}
							for (int i = 0; i < size; i++) {
								printf("\n%d",values[i]);
							}
							counter = counter + 1;
							// if the count is 3, then no more chance to change the combination
							if (counter == 3) {
								printf("\n\nThat was your final combination. No more change combination possible\n");
								answer = 'y';
							}
							else {
								printf("\n Do you want to keep the combination?\n");
								scanf(" %c", &answer);
							}
						}
					} while (answer != 'y');

					// Ask the user 
					printf("\n what choice / combination would you like to choose from 1-13\n");
					printf(" 1. Sum of 1's\n2. Sum of 2's\n3. Sum of 3's\n4. Sum of 4's\n5. Sum of 5's\n6. Sum of 6's\n7. Three-of-a-kind\n8. Four-of-a-kind\n9. Full house\n10. Small straight\n11. Large straight\n12. Yahtzee\n13. Chance\n");
					scanf("%d", &comb_option);
					switch (comb_option) {
						// For each option, get the count of repeated values and compute the points
					case 1:
						one_value = 0;
						points = computepoints_1(values, comb_option, size, &one_value);
						break;
					case 2:
						two_value = 0;
						points = computepoints_2(values, comb_option, size, &two_value);
						break;
					case 3:
						three_value = 0;
						points = computepoints_3(values, comb_option, size, &three_value);
						break;
					case 4:
						four_value = 0;
						points = computepoints_4(values, comb_option, size, &four_value);
						break;
					case 5:
						five_value = 0;
						points = computepoints_5(values, comb_option, size, &five_value);
						break;
					case 6:
						six_value = 0;
						points = computepoints_6(values, comb_option, size, &six_value);
						break;
					case 7:
						if (one_value_calc(values, size) == 3 || two_value_calc(values,size) == 3 || three_value_calc(values, size) == 3 || four_value_calc(values, size) == 3 || five_value_calc(values, size) == 3 || six_value_calc(values, size) == 3) {
							points = values[0] + values[1] + values[2] + values[3] + values[4];
						}
						break;
					case 8:
						if (one_value_calc(values, size) == 4 || two_value_calc(values, size) == 4 || three_value_calc(values, size) == 4 || four_value_calc(values, size) == 4 || five_value_calc(values, size) == 4 || six_value_calc(values, size) == 4) {
							points = values[0] + values[1] + values[2] + values[3] + values[4];
						}
						break;
					case 9:
						if ((one_value_calc(values, size) == 3 || two_value_calc(values, size) == 3 || three_value_calc(values, size) == 3 || four_value_calc(values, size) == 3 || five_value_calc(values, size) == 3 || six_value_calc(values, size) == 3) && (one_value_calc(values, size) == 2 || two_value_calc(values, size) == 2 || three_value_calc(values, size) == 2 || four_value_calc(values, size) == 2 || five_value_calc(values, size) == 2 || six_value_calc(values, size) == 2)) {
							points = 25;
						}
						break;
					case 10:
						array_sort(values, size);
						if (values[0] + 1 == values[1] && values[1] + 1 == values[2] && values[2] + 1 == values[3] || values[1] + 1 == values[2] && values[2] + 1 == values[3] && values[3] + 1 == values[4]) {
							points = 30;
						}
						break;
					case 11:
						array_sort(values, size);
						if (values[0] + 1 == values[1] && values[1] + 1 == values[2] && values[2] + 1 == values[3] && values[3] + 1 == values[4]) {
							points = 40;
						}
						break;
					case 12:
						if (one_value_calc(values, size) == 5 || two_value_calc(values, size) == 5 || three_value_calc(values, size) == 5 || four_value_calc(values, size) == 5 || five_value_calc(values, size) == 5 || six_value_calc(values, size) == 4) {
							points = 50;
						}
						break;
					case 13:
						points = values[0] + values[1] + values[2] + values[3] + values[4];
						break;
					}

					// compute the upper and lower points
					if (comb_option >= 1 && comb_option <= 6 && turn == 0) {
						uppersecp1 = uppersecp1 + points;
					}
					if (comb_option >= 1 && comb_option <= 6 && turn == 1) {
						uppersecp2 = uppersecp2 + points;
					}
					if (comb_option >= 7 && comb_option <= 13 && turn == 0) {
						lowersecp1 = lowersecp1 + points;
					}
					if (comb_option >= 7 && comb_option <= 13 && turn == 1) {
						lowersecp2 = lowersecp2 + points;
					}
					player1_points = lowersecp1 + uppersecp1;
					player2_points = lowersecp2 + uppersecp2;
					printf("\nplayer 1 points is %d\n", player1_points);
					printf("\nplayer 2 points is %d\n", player2_points);
					turn = turn + 1;
					
					if (turn < 3) {
						printf("\n player %d turn\n", turn + 1);
					}
				} // End of Turn Loop


				printf("\n round %d is over\n", round + 1);
				round = round + 1;
			} // end of round loop

			// Add bonus points
			if (uppersecp1 >= 63) {
				player1_points = lowersecp1 + uppersecp1 + 35;
			}
			else {
				player1_points = uppersecp1 + lowersecp1;
			}


			if (uppersecp2 >= 63) {
				player2_points = lowersecp2 + uppersecp2 + 35;
			}
			else {
				player2_points = lowersecp2 + uppersecp2;
			}

			// Determine the winner
			if (player1_points > player2_points) {
				printf("\n Hurray! - Player 1 wins! \n");
			}
			else {
				printf("\n Hurray! - Player 2 wins! \n");
			}
			break;

		case 3: // exit the program. Player need to enter "3" to exit the program
			proceed = 0;
			printf("goodbye\n");
			break;

		default:  // If player types in any option other than 1,2,3 keep looping in the game to get the valid option
			proceed = 1;
		} // end of switch case for the playing options
	} // end of while loop for the gaming options

	return 0;
}