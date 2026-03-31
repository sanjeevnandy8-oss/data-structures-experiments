#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player {
    char name[50];
    char team[50];
    float battingAverage;
    struct Player *next;
} Player;

Player *createPlayer(char name[], char team[], float battingAverage);
void addPlayer(Player **head, char name[], char team[], float battingAverage);
void displayPlayersWithAverage(Player *head, float minAverage);
void freePlayerList(Player *head);

int main() {
    Player *players = NULL;
    int n;

    printf("Enter number of players: ");
    scanf("%d", &n);

    char name[50], team[50];
    float battingAverage;

    for (int i = 0; i < n; i++) {
        printf("\nPlayer %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", name);
        printf("Team: ");
        scanf(" %[^\n]", team);
        printf("Batting average: ");
        scanf("%f", &battingAverage);

        addPlayer(&players, name, team, battingAverage);
    }

    printf("\nPlayers with batting average >= 50:\n");
    displayPlayersWithAverage(players, 50.0f);

    freePlayerList(players);
    return 0;
}

Player *createPlayer(char name[], char team[], float battingAverage) {
    Player *newPlayer = (Player *)malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    strcpy(newPlayer->team, team);
    newPlayer->battingAverage = battingAverage;
    newPlayer->next = NULL;
    return newPlayer;
}

void addPlayer(Player **head, char name[], char team[], float battingAverage) {
    Player *newPlayer = createPlayer(name, team, battingAverage);

    if (*head == NULL) {
        *head = newPlayer;
    } else {
        Player *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newPlayer;
    }
}

void displayPlayersWithAverage(Player *head, float minAverage) {
    int found = 0;

    while (head != NULL) {
        if (head->battingAverage >= minAverage) {
            printf("\nName: %s\n", head->name);
            printf("Team: %s\n", head->team);
            printf("Batting Average: %.2f\n", head->battingAverage);
            found = 1;
        }
        head = head->next;
    }

    if (!found)
        printf("No players found with batting average >= %.2f\n", minAverage);
}

void freePlayerList(Player *head) {
    while (head != NULL) {
        Player *temp = head;
        head = head->next;
        free(temp);
    }
}
