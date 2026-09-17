#include <stdio.h>

int main() {
    // ---------------- TEAM A ROSTER (6 PLAYERS) ----------------
    char teamA_setter[30];
    char teamA_spiker1[30], teamA_spiker2[30];
    char teamA_blocker1[30], teamA_blocker2[30];
    char teamA_libero[30];

    // ---------------- TEAM B ROSTER (6 PLAYERS) ----------------
    char teamB_setter[30];
    char teamB_spiker1[30], teamB_spiker2[30];
    char teamB_blocker1[30], teamB_blocker2[30];
    char teamB_libero[30];

    // Stats Variables
    int teamA_sets = 0, teamB_sets = 0;
    int teamA_pts, teamB_pts;

    // Specific Position Stats
    int spikerA1_kills, spikerA2_kills;
    int spikerB1_kills, spikerB2_kills;

    int blockerA1_blocks, blockerA2_blocks;
    int blockerB1_blocks, blockerB2_blocks;

    int total_teamA_blocks, total_teamB_blocks;
    int total_teamA_attacks, total_teamB_attacks;

    printf("===================================================\n");
    printf("     FULL 6v6 VOLLEYBALL MATCH & POSITION SYSTEM   \n");
    printf("===================================================\n");

    // STEP 1: INPUT ALL 6 PLAYERS OF TEAM A
    printf("\n--- ENTER TEAM A ROSTER (6 PLAYERS) ---\n");
    printf("1. Setter Name            : "); scanf(" %[^\n]", teamA_setter);
    printf("2. Outside Hitter 1 (Spiker): "); scanf(" %[^\n]", teamA_spiker1);
    printf("3. Outside Hitter 2 (Spiker): "); scanf(" %[^\n]", teamA_spiker2);
    printf("4. Middle Blocker 1       : "); scanf(" %[^\n]", teamA_blocker1);
    printf("5. Middle Blocker 2       : "); scanf(" %[^\n]", teamA_blocker2);
    printf("6. Libero (Defender)      : "); scanf(" %[^\n]", teamA_libero);

    // STEP 2: INPUT ALL 6 PLAYERS OF TEAM B
    printf("\n--- ENTER TEAM B ROSTER (6 PLAYERS) ---\n");
    printf("1. Setter Name            : "); scanf(" %[^\n]", teamB_setter);
    printf("2. Outside Hitter 1 (Spiker): "); scanf(" %[^\n]", teamB_spiker1);
    printf("3. Outside Hitter 2 (Spiker): "); scanf(" %[^\n]", teamB_spiker2);
    printf("4. Middle Blocker 1       : "); scanf(" %[^\n]", teamB_blocker1);
    printf("5. Middle Blocker 2       : "); scanf(" %[^\n]", teamB_blocker2);
    printf("6. Libero (Defender)      : "); scanf(" %[^\n]", teamB_libero);

    // STEP 3: MATCH SCORE INPUT
    printf("\n--- ENTER MATCH SCORE (SET 1) ---\n");
    printf("Points Scored by Team A: "); scanf("%d", &teamA_pts);
    printf("Points Scored by Team B: "); scanf("%d", &teamB_pts);

    if (teamA_pts >= 25 && (teamA_pts - teamB_pts) >= 2) {
        teamA_sets++;
    } else if (teamB_pts >= 25 && (teamB_pts - teamA_pts) >= 2) {
        teamB_sets++;
    }

    // STEP 4: POSITION SPECIFIC STATS INPUT
    printf("\n--- ENTER ATTACK KILLS (Spikers) ---\n");
    printf("[%s - Team A Spiker 1] Kills: ", teamA_spiker1); scanf("%d", &spikerA1_kills);
    printf("[%s - Team A Spiker 2] Kills: ", teamA_spiker2); scanf("%d", &spikerA2_kills);
    printf("[%s - Team B Spiker 1] Kills: ", teamB_spiker1); scanf("%d", &spikerB1_kills);
    printf("[%s - Team B Spiker 2] Kills: ", teamB_spiker2); scanf("%d", &spikerB2_kills);

    printf("\n--- ENTER STUFF BLOCKS (Middle Blockers) ---\n");
    printf("[%s - Team A Blocker 1] Blocks: ", teamA_blocker1); scanf("%d", &blockerA1_blocks);
    printf("[%s - Team A Blocker 2] Blocks: ", teamA_blocker2); scanf("%d", &blockerA2_blocks);
    printf("[%s - Team B Blocker 1] Blocks: ", teamB_blocker1); scanf("%d", &blockerB1_blocks);
    printf("[%s - Team B Blocker 2] Blocks: ", teamB_blocker2); scanf("%d", &blockerB2_blocks);

    // Cumulative Calculations
    total_teamA_attacks = spikerA1_kills + spikerA2_kills;
    total_teamB_attacks = spikerB1_kills + spikerB2_kills;

    total_teamA_blocks = blockerA1_blocks + blockerA2_blocks;
    total_teamB_blocks = blockerB1_blocks + blockerB2_blocks;

    // ------------------- FINAL MATCH REPORT -------------------
    printf("\n===================================================\n");
    printf("             OFFICIAL MATCH REPORT & STATS         \n");
    printf("===================================================\n");

    // Match Winner Output
    if (teamA_sets > teamB_sets) {
        printf("MATCH WINNER      : *** TEAM A WON THE MATCH ***\n");
    } else if (teamB_sets > teamA_sets) {
        printf("MATCH WINNER      : *** TEAM B WON THE MATCH ***\n");
    } else {
        printf("MATCH WINNER      : MATCH TIED / INCOMPLETE\n");
    }

    printf("---------------------------------------------------\n");
    printf("TEAM TOTALS:\n");
    printf("Team A Total Attack Kills: %d | Total Blocks: %d\n", total_teamA_attacks, total_teamA_blocks);
    printf("Team B Total Attack Kills: %d | Total Blocks: %d\n", total_teamB_attacks, total_teamB_blocks);
    printf("---------------------------------------------------\n");

    // Best Blocker Logic (Middle Blockers Mein Se)
    printf("BEST MIDDLE BLOCKER  : ");
    if (blockerA1_blocks >= blockerA2_blocks && blockerA1_blocks >= blockerB1_blocks && blockerA1_blocks >= blockerB2_blocks) {
        printf("%s (Team A) with %d Blocks!\n", teamA_blocker1, blockerA1_blocks);
    } else if (blockerA2_blocks >= blockerB1_blocks && blockerA2_blocks >= blockerB2_blocks) {
        printf("%s (Team A) with %d Blocks!\n", teamA_blocker2, blockerA2_blocks);
    } else if (blockerB1_blocks >= blockerB2_blocks) {
        printf("%s (Team B) with %d Blocks!\n", teamB_blocker1, blockerB1_blocks);
    } else {
        printf("%s (Team B) with %d Blocks!\n", teamB_blocker2, blockerB2_blocks);
    }

    // Best Spiker Logic (Attackers Mein Se)
    printf("BEST ATTACKER / SPIKER : ");
    if (spikerA1_kills >= spikerA2_kills && spikerA1_kills >= spikerB1_kills && spikerA1_kills >= spikerB2_kills) {
        printf("%s (Team A) with %d Attack Kills!\n", teamA_spiker1, spikerA1_kills);
    } else if (spikerA2_kills >= spikerB1_kills && spikerA2_kills >= spikerB2_kills) {
        printf("%s (Team A) with %d Attack Kills!\n", teamA_spiker2, spikerA2_kills);
    } else if (spikerB1_kills >= spikerB2_kills) {
        printf("%s (Team B) with %d Attack Kills!\n", teamB_spiker1, spikerB1_kills);
    } else {
        printf("%s (Team B) with %d Attack Kills!\n", teamB_spiker2, spikerB2_kills);
    }

    printf("===================================================\n");

    return 0;
}