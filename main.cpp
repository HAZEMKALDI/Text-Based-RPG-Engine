#include <iostream>
using namespace std;

class Player {

    int energy_PLayer=55;
    int health_Player=100;
    int Attack_Player=30;
    int levelplayer=1;
    public:
    Player(){};
    ~Player(){};
    int retlevel() {
        return levelplayer;
    }
    void retinfoPlayer() {
        cout << "The Energy Player:" << energy_PLayer <<endl;
        cout << "The Health Player:" << health_Player <<endl;
        cout<<endl;
    }
  void  UseSkill() {
        switch (levelplayer) {
            case 1:if (energy_PLayer>=15) {
                energy_PLayer -=15;break;
            }else {
                cout <<" The Energy Low!!"<<endl;break;
            }


            case 2:if (energy_PLayer>=20) {
                energy_PLayer -=20;break;
            }else {
                cout <<" The Energy Low!!"<<endl;break;
            }
            case 3:if (energy_PLayer>=25) {
                energy_PLayer -=25;break;
            }else {
                cout <<" The Energy Low!!"<<endl;break;
            }
            case 4:if (energy_PLayer>=30) {
                energy_PLayer -=30;break;
            }else {
                cout <<" The Energy Low!!"<<endl;break;
            }
            case 5:if (energy_PLayer>=35) {
                energy_PLayer -=35;break;
            }else {
                cout <<" The Energy Low!!"<<endl;break;
            }
        }

    }
    bool damagePlayer(int damage) {
      if (health_Player <=damage) {
          return false;
      }
      if (health_Player > damage) {
          health_Player =health_Player-damage;
      cout <<"He received valuable damage :"<<damage<<endl;
          return true;
      }

  }
    void Level_progress() {
     levelplayer++;
        switch (levelplayer) {
            case 1:health_Player=120;energy_PLayer=90;Attack_Player=35;break;
            case 2:health_Player=155;energy_PLayer=90;Attack_Player=40;break;
            case 3:health_Player=160;energy_PLayer=95;Attack_Player=45;break;
            case 4:health_Player=160;energy_PLayer=120;Attack_Player=50;break;
            case 5:health_Player=220;energy_PLayer=125;Attack_Player=60;break;
        }

  }
    int retAttack() {
        return Attack_Player;
    }
    void skip() {
        health_Player +=5;
        energy_PLayer+=15;
    }
};
class Enemies  {
    int Health_Goblin=120;
    int Attack_Goblin=25;
    int Health_Skelton=170;
    int Attack_Skelton=30;
    int Health_Zombie=180;
    int Attack_Zombie=35;
    int Health_stonegiant=400;
    int Attack_stonegiant=10;
    int Health_Dragon=300;
    int Attack_Dragon=39;
public:
    Enemies(){};
    ~Enemies(){};
    int healthenenemies=Health_Goblin;

    int Attack=Attack_Goblin;
    bool setEnemies(Player &PL) {
        switch (PL.retlevel()) {
            case 1:healthenenemies=Health_Goblin;Attack=Attack_Goblin;return false;break;
            case 2:healthenenemies=Health_Skelton;Attack=Attack_Skelton;return false;break;
            case 3:healthenenemies=Health_Zombie;Attack=Attack_Zombie;return false;break;
            case 4:healthenenemies=Health_stonegiant;Attack=Attack_stonegiant;return false;break;
            case 5:healthenenemies=Health_Dragon;Attack=Attack_Dragon;return false;break;
                case 6:cout <<"You Win!!"<<endl;return true;break;
        }
    }
    void retinfoEnemies(Player &PL) {
int level=PL.retlevel();
        switch (level) {
            case 1: cout <<"Name The Enemies is "<< "Goblin"<<endl;break;
            case 2: cout <<"Name The Enemies is "<<"Skelton"<<endl;break;
            case 3: cout <<"Name The Enemies is "<< "Zombie"<<endl;break;
            case 4: cout <<"Name The Enemies is "<< "stone giant"<<endl;break;
            case 5: cout <<"Name The Enemies is "<< "Dragon"<<endl;break;
        }


        cout << "The Health Enemies: " << healthenenemies <<endl;
        cout <<"The Attack Enemies: "<<Attack<<endl;
        cout<<endl;

    }
    bool AttackPlayer(Player &PL) {
    return  PL.damagePlayer(Attack);
    }

    bool damageEnemies(Player &PL) {
PL.UseSkill();
        if (healthenenemies<=PL.retAttack()) {
            cout<<"You Kill the Enemies"<<endl;
            return true;
        }
        if (healthenenemies > PL.retAttack()) {
            healthenenemies -=PL.retAttack();
            return false;
        }

    }

};
int main() {
     int input;
    cout <<" 1- Start the game "<<endl;
    cout<<endl;
    cout <<" 2- Exit"<<endl;
    cout<<endl;
    cout <<" Enter Your choice :";
    cin>>input;
    int savech=input;
    Player player;
        Enemies enemies;
while (true) {

    if (savech == 1) {

        player.retinfoPlayer();
        enemies.retinfoEnemies(player);
        cout<<"1- Attack" <<endl;
        cout << "2- Skip(+15 point Energy and +5 point Health)" <<endl;
        cout <<" Enter Your choice :";
        cin>>input;
        if (input == 1) {
            if (enemies.damageEnemies(player)) {
                player.Level_progress();
                if (!enemies.setEnemies(player)) {
                    continue;
                }else {

                    break;
                }

            }else {
                enemies.retinfoEnemies(player);
            }
        }else if (input == 2) {
            player.skip();

        }else {
            cout<<"Try again"<<endl;
            continue;
        }

        if (!enemies.AttackPlayer(player)) {
            cout << "Game Over"<<endl;
            break;
        }
    }else {
        break;
    }
}
    return 0;
}