#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int Deck[][13]);
void play(int Deck[][13], const char *num[], const char *mark[], int people);

int main(void)
{
	const char *marks[4] = {"Diamond", "Heart", "Spade", "Clover"};

	const char *num[13] =
	{ "2", "3", "4", "5",
	"6", "7", "8", "9",
	"10", "J", "Q", "K", "A" };

	int deck[4][13] = { 0 };
	int people;

	srand((unsigned)time(NULL));

	shuffle(deck);
	printf("플레이할 사람 수 : ");
	scanf("%d", &people);

	if (people < 7)
		play(deck, num, marks, people);
	else
		printf("사람이 너무 많습니다. 게임을 종료합니다. \n");

	return (0);

}

void shuffle(int Deck[][13])
{
	int row;
	int column;
	int card;

	for (card = 1; card <= 52; card++) 
	{

		do 
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (Deck[row][column] != 0);

		Deck[row][column] = card;
	}
}

void play(int Deck[][13], const char *num[], const char *mark[], int people) 
{
	int card;
	int row;
	int column;
	int i=1;
	int j=1;

	for (card = 1; card <= 7 * people; card++) 
	{
		for (row = 0; row <= 3; row++) 
		{
			for (column = 0; column <= 12; column++) 
			{
				if (Deck[row][column] == card) 
				{
					for (j = 1; j <= people; j++)
					{
						if (card == 1 + (7 * (j-1)))
						{
							printf("\n Player %d's Card \n", j);
							i = 1;
						}
					}
					printf("\n Card %1d: %s %s \n", i, mark[row], num[column]);
					i++;
				}
			}
		}
	}
	printf("\n");
}


