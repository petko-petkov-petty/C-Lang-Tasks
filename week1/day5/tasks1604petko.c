#include <stdio.h>
#include <stdint.h>

//task1
uint16_t getBroadcastId(uint16_t leaderID, uint8_t x)
{
    uint16_t mask = ~0;
    mask <<= x;

    return leaderID | (mask >> x);
}

//task3
int isInCluster(uint16_t leaderID, uint8_t x, uint16_t id)
{
    return (leaderID >> (sizeof(leaderID)*8 - x)) == (id >> (sizeof(leaderID)*8 - x));
}

//task4
int isFollower(uint16_t leaderID, uint8_t x, uint16_t id)
{
    if (isInCluster(leaderID, x, id))
        return (id != leaderID) && (id != getBroadcastId(leaderID, x));
    else
        return 0;
}

//task5
uint16_t getClusterSize(uint16_t leaderID, uint8_t x)
{
    return 1 << (sizeof(leaderID)*8 - x);
}

//task2
uint16_t getFollowersCount(uint16_t leaderID, uint8_t x)
{
    return getClusterSize(leaderID, x) - 2;
}

short isLeaderIdCorrect(uint16_t, uint8_t);
void printbin(uint16_t);

int main()
{
    const uint16_t LEADER_ID = 1024;
    const uint8_t X = 15;
    const uint16_t MACHINE_ID = 1025;

    if(isLeaderIdCorrect(LEADER_ID, X) && X < sizeof(LEADER_ID)*8)
    {
        //task1
        printf("TASK1 - getBroadcastId\n");          printbin(LEADER_ID);    printf("\n");   printbin(getBroadcastId(LEADER_ID, X));

        //task3
        printf("\n\nTASK3 - isInCluster\n");         printbin(LEADER_ID);    printf("\n");   printbin(MACHINE_ID);                      printf("\n%s", isInCluster(LEADER_ID, X, MACHINE_ID) ? "YES" : "NO");

        //task4
        printf("\n\nTASK4 - isFollower\n");          printbin(LEADER_ID);    printf("\n");   printbin(MACHINE_ID);                      printf("\n%s", isFollower(LEADER_ID, X, MACHINE_ID) ? "YES" : "NO");

        //task5
        printf("\n\nTASK5 - getClusterSize\n");      printbin(LEADER_ID);    printf("\n%d", getClusterSize(LEADER_ID, X));

        //task2
        printf("\n\nTASK2 - getFollowersCount\n");   printbin(LEADER_ID);    printf("\n%d\n", getFollowersCount(LEADER_ID, X));
    }
    else
        printf("Incorrect LEADER_ID or X\n");

    return 0;
}

short isLeaderIdCorrect(uint16_t leaderId, uint8_t x)
{
    uint16_t mask = 0;

    for(int i = 0; i < sizeof(leaderId)*8 - x; i++)
        mask |= 1 << i;

    return !(leaderId & mask);
}

void printbin(uint16_t number)
{
    uint16_t mask;

    for (mask = 0x8000; mask; mask = mask >> 1)
    printf("%d", !!(number & mask));

    return;
}