#include <stdio.h>

struct player {
    char name[50];
    int runs;
};

int main() {
    int i,n, total_runs = 0;
    
    printf("Enter the number of players: ");
    scanf("%d", &n);
    
    struct player team[n];
    
    for (i = 0; i < n; i++) {
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", team[i].name);
        
        printf("Enter the runs scored by player %d: ", i+1);
        scanf("%d", &team[i].runs);
        
        total_runs += team[i].runs;
    }
    
    printf("\nBatting Information\n");
    for (i = 0; i < n; i++) {
        printf("Player %d: %s\n", i+1, team[i].name);
        printf("Runs scored: %d\n", team[i].runs);
        printf("\n");
    }
    
    printf("Total runs scored by the team: %d", total_runs);
    
    return 0;
}

