#include "defintion.h" 

int roll_dice(void) {
	return rand() % 6 + 1;
}
int one_value_calc (int values[], int size) {
	int one_value = 0;
	for (int i = 0; i < size; i++) {
		if (values[i] == 1) {
			one_value = one_value + 1;
		}
	}
	return one_value;
}
int two_value_calc(int values[], int size) {
	int two_value = 0;
	for (int i = 0; i < size; i++) {
		if (values[i] == 2) {
			two_value = two_value + 1;
		}
	}
	return two_value;
}
int three_value_calc(int values[], int size) {
	int three_value = 0;
	for (int i = 0; i < size; i++) {
		if (values[i] == 3) {
			three_value = three_value + 1;
		}
	}
	return three_value;
}
int four_value_calc(int values[], int size) {
	int four_value = 0;
	for (int i = 0; i < size; i++) {
		if (values[i] == 4) {
			four_value = four_value + 1;
		}
	}
	return four_value;
}
int five_value_calc(int values[], int size) {
	int five_value = 0;
	for (int i = 0; i < size; i++) {
		if (values[i] == 5) {
			five_value = five_value + 1;
		}
	}
	return five_value;
}
int six_value_calc(int values[], int size) {
	int six_value = 0;
	for (int i = 0; i < size; i++) {
		if (values[i] == 6) {
			six_value = six_value + 1;
		}
	}
	return six_value;
}
int computepoints_1(int values[], int comb_option, int size, int *one_value) {
	*one_value = 0;
	int points = 0;
	for (int i = 0; i < size; i++) {
		if (values[i] == comb_option) {
			*one_value = *one_value + 1;
		}
	}
	points = *one_value * comb_option;
	return points;
}
int computepoints_2(int values[], int comb_option, int size, int *two_value) {
	*two_value = 0;
	int points = 0;
	for (int i = 0; i < size; i++) {
		if (values[i] == comb_option) {
			*two_value = *two_value + 1;
		}
	}
	points = *two_value * comb_option;
	return points;
}
int computepoints_3(int values[], int comb_option, int size, int *three_value) {
	*three_value = 0;
	int points = 0;
	for (int i = 0; i < size; i++) {
		if (values[i] == comb_option) {
			*three_value = *three_value + 1;
		}
	}
	points = *three_value * comb_option;
	return points;
}
int computepoints_4(int values[], int comb_option, int size, int *four_value) {
	*four_value = 0;
	int points = 0;
	for (int i = 0; i < size; i++) {
		if (values[i] == comb_option) {
			*four_value = *four_value + 1;
		}
	}
	points = *four_value * comb_option;
	return points;
}
int computepoints_5(int values[], int comb_option, int size, int *five_value) {
	*five_value = 0;
	int points = 0;
	for (int i = 0; i < size; i++) {
		if (values[i] == comb_option) {
			*five_value = *five_value + 1;
		}
	}
	points = *five_value * comb_option;
	return points;
}
int computepoints_6(int values[], int comb_option, int size, int *six_value) {
	*six_value = 0;
	int points = 0;
	for (int i = 0; i < size; i++) {
		if (values[i] == comb_option) {
			*six_value = *six_value + 1;
		}
	}
	points = *six_value * comb_option;
	return points;
}
void reroll_dice(int arr[]) {
	int dice_number;
	printf("enter the dice you want to change\n");
	scanf("%d", &dice_number);
	switch (dice_number) {
	case 1:
		arr[0] = roll_dice();
		break;
	case 2:
		arr[1] = roll_dice();
		break;
	case 3:
		arr[2] = roll_dice();
		break;
	case 4:
		arr[3] = roll_dice();
		break;
	case 5:
		arr[4] = roll_dice();
		break;
	}
}
int array_sort(int values[], int size) {
	int passes = 0;
	for (; passes < size; passes++) {
		for (int i = 0; i < size; i++) {
			if (values[i] > values[i + 1]) {
				int temp = 0;
				temp = values[i];
				values[i] = values[i + 1];
				values[i + 1] = temp;
			}
		}
	}
}
void clear_function() {
	system("cls");
}
