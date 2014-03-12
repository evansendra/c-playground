#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define PLAYERS 3

struct PlayerInfo
{
    int skill_level;
    string name;
};

PlayerInfo upgrade_skills(PlayerInfo player);

int main(void)
{
    srand( time ( NULL ) );

    PlayerInfo players[PLAYERS];
    for(int i = 0; i < PLAYERS; i++)
    {
        cout << "Please enter the name for player " << i << ":" << endl;
        cin >> players[i].name;
        cout << "Please enter the skill level for " << players[i].name << endl;
        cin >> players[i].skill_level;
    }

    cout << endl << endl << "## PLAYING ##" << endl << endl;
    int rand_num = rand() % (PLAYERS - 0);
    players[rand_num] = upgrade_skills(players[rand_num]);

    for(int i = 0; i < PLAYERS; i++)
    {
        cout << players[i].name << " is at skill level " << players[i].skill_level
            << endl;
    }
}

PlayerInfo upgrade_skills(PlayerInfo player)
{
    player.skill_level += 100;
    return player;
}
