#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Player {

    double energy_PLayer=75;
    double health_Player=180;
    double Attack_Player=30;
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
    bool damagePlayer(double damage) {
      if (health_Player <=damage) {
          return false;
      }else
      if (health_Player > damage) {
          health_Player =health_Player-damage;
      cout <<"He received valuable damage :"<<damage<<endl;
          return true;
      }

  }
    void Level_progress() {
     levelplayer++;
        switch (levelplayer) {

            case 2:health_Player=200;energy_PLayer=100;Attack_Player=40;break;
            case 3:health_Player=250;energy_PLayer=110;Attack_Player=50;break;
            case 4:health_Player=300;energy_PLayer=130;Attack_Player=55;break;
            case 5:health_Player=350;energy_PLayer=150;Attack_Player=65;break;
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
    vector<Enemies> object;


public:
    Enemies(){}
    Enemies(double HL,double ATT,double ene,string Name) {
      this->healthenenemies=HL;
        this->Attack=ATT;
        this->NameEnemies=Name;
        this->energyEnemies=ene;

    };
    ~Enemies(){};
    void StartGame() {
        Enemies EN1(120,25,100,"Goblin");
        object.push_back(EN1);
        Enemies EN2(170,30,120,"Skelton");
        object.push_back(EN2);
        Enemies EN3(180,35,140,"Zombie");
        object.push_back(EN3);
        Enemies EN4(400,10,170,"stone giant");
        object.push_back(EN4);
        Enemies EN5(300,39,220,"Dragon");
        object.push_back(EN5);

    }

Enemies Poison(Enemies &en,Player &PL) {
        double skill;
    en.Attack = en.Attack*1.2;
        en.healthenenemies=en.healthenenemies*1.1;
        switch (PL.retlevel()) {
            case 1:skill=10*1.2;UseSkill(en,skill);break;
                case 2:skill=20*1.2;UseSkill(en,skill);break;
                case 3:skill=30*1.2;UseSkill(en,skill);break;
            case 4:skill=20*1.2;UseSkill(en,skill);break;
            case 5:skill=35*1.2;UseSkill(en,skill);break;
        }
        return en;
}
    Enemies Fire(Enemies &en,Player &PL) {
        double skill;
        en.Attack = en.Attack*1.25;
        en.healthenenemies=en.healthenenemies*1.05;
        switch (PL.retlevel()) {
            case 1:skill=10*1.05;UseSkill(en,skill);break;
            case 2:skill=20*1.05;UseSkill(en,skill);break;
            case 3:skill=30*1.05;UseSkill(en,skill);break;
            case 4:skill=20*1.05;UseSkill(en,skill);break;
            case 5:skill=35*1.05;UseSkill(en,skill);break;
        }
        return en;
    }
    Enemies Frost(Enemies &en,Player &PL) {
        double skill;
        en.Attack = en.Attack*1.1;
        en.healthenenemies=en.healthenenemies*1.25;
        switch (PL.retlevel()) {
            case 1:skill=10;UseSkill(en,skill);break;
            case 2:skill=20;UseSkill(en,skill);break;
            case 3:skill=30;UseSkill(en,skill);break;
            case 4:skill=20;UseSkill(en,skill);break;
            case 5:skill=35;UseSkill(en,skill);break;
        }
        return en;
    }
    double healthenenemies;
    double Attack;
    double energyEnemies;
    string NameEnemies;
    void UseSkill(Enemies &en,double skill) {
        en.energyEnemies=en.energyEnemies-skill;
    }
    Enemies setEnemies(Player &PL) {
        switch (PL.retlevel()) {
            case 1: return object[0];
            case 2: return object[1];
            case 3: return object[2];
            case 4: return object[3];
            case 5: return object[4];
            default: return object[0];
        }
    }
   void randomAttackEnemies(Enemies &en, Player &PL) {
    int random = (rand() % 3) + 1;

    if (en.NameEnemies == "Goblin") {
        if (en.energyEnemies >= 12) {
            if (random == 1) {
                Poison(en, PL);
                cout << "Enemies use Poison" << endl;
            } else if (random == 2) {
                Fire(en, PL);
                cout << "Enemies use Fire" << endl;
            } else { // الاحتمال 3
                Frost(en, PL);
                cout << "Enemies use Frost" << endl;
            }
        } else if (en.energyEnemies >= 10.5) {
            if (random == 1 || random == 2) { // إذا كان 1 أو 2 يضرب نار (أو المهارة المتاحة) لكي لا يهرب
                Fire(en, PL);
                cout << "Enemies use Fire" << endl;
            } else { // الاحتمال 3
                Frost(en, PL);
                cout << "Enemies use Frost" << endl;
            }
        } else if (en.energyEnemies >= 10) { // يملك طاقة فقط للـ Frost
            Frost(en, PL);
            cout << "Enemies use Frost" << endl;
        } else {
            // شبكة الأمان: إذا كانت الطاقة أقل من 10، يضرب هجوم عادي ولا يقف متفرجاً
            PL.damagePlayer(en.Attack);
            cout << "Goblin has low energy! Uses Basic Attack!" << endl;
        }
    }

    if (en.NameEnemies == "Skelton") {
        if (en.energyEnemies >= 24) {
            if (random == 1) {
                Poison(en, PL);
                cout << "Enemies use Poison" << endl;
            } else if (random == 2) {
                Fire(en, PL);
                cout << "Enemies use Fire" << endl;
            } else {
                Frost(en, PL);
                cout << "Enemies use Frost" << endl;
            }
        } else if (en.energyEnemies >= 21) {
            if (random == 1 || random == 2) {
                Fire(en, PL);
                cout << "Enemies use Fire" << endl;
            } else {
                Frost(en, PL);
                cout << "Enemies use Frost" << endl;
            }
        } else if (en.energyEnemies >= 20) {
            Frost(en, PL);
            cout << "Enemies use Frost" << endl;
        } else {
            PL.damagePlayer(en.Attack);
            cout << "Skelton has low energy! Uses Basic Attack!" << endl;
        }
    }

    if (en.NameEnemies == "Zombie") {
        if (en.energyEnemies >= 36) {
            if (random == 1) {
                Poison(en, PL);
                cout << "Enemies use Poison" << endl;
            } else if (random == 2) {
                Fire(en, PL);
                cout << "Enemies use Fire" << endl;
            } else {
                Frost(en, PL);
                cout << "Enemies use Frost" << endl;
            }
        } else if (en.energyEnemies >= 31.5) {
            if (random == 1 || random == 2) {
                Fire(en, PL);
                cout << "Enemies use Fire" << endl;
            } else {
                Frost(en, PL);
                cout << "Enemies use Frost" << endl;
            }
        } else if (en.energyEnemies >= 30) {
            Frost(en, PL);
            cout << "Enemies use Frost" << endl;
        } else {
            PL.damagePlayer(en.Attack);
            cout << "Zombie has low energy! Uses Basic Attack!" << endl;
        }
    }

    if (en.NameEnemies == "stone giant") {
        if (en.energyEnemies >= 24) {
            if (random == 1) {
                Poison(en, PL);
                cout << "Enemies use Poison" << endl;
            } else if (random == 2) {
                Fire(en, PL);
                cout << "Enemies use Fire" << endl;
            } else {
                Frost(en, PL);
                cout << "Enemies use Frost" << endl;
            }
        } else if (en.energyEnemies >= 21) {
            if (random == 1 || random == 2) {
                Fire(en, PL);
                cout << "Enemies use Fire" << endl;
            } else {
                Frost(en, PL);
                cout << "Enemies use Frost" << endl;
            }
        } else if (en.energyEnemies >= 20) {
            Frost(en, PL);
            cout << "Enemies use Frost" << endl;
        } else {
            PL.damagePlayer(en.Attack);
            cout << "Stone Giant has low energy! Uses Basic Attack!" << endl;
        }
    }

    if (en.NameEnemies == "Dragon") {
        if (en.energyEnemies >= 42) {
            if (random == 1) {
                Poison(en, PL);
                cout << "Enemies use Poison" << endl;
            } else if (random == 2) {
                Fire(en, PL);
                cout << "Enemies use Fire" << endl;
            } else {
                Frost(en, PL);
                cout << "Enemies use Frost" << endl;
            }
        } else if (en.energyEnemies >= 36.75) {
            if (random == 1 || random == 2) {
                Fire(en, PL);
                cout << "Enemies use Fire" << endl;
            } else {
                Frost(en, PL);
                cout << "Enemies use Frost" << endl;
            }
        } else if (en.energyEnemies >= 35) {
            Frost(en, PL);
            cout << "Enemies use Frost" << endl;
        } else {
            PL.damagePlayer(en.Attack);
            cout << "Dragon has low energy! Uses Basic Attack!" << endl;
        }
    }
}
    void retinfoEnemies(Player &PL) {
int level=PL.retlevel();
        switch (level) {
            case 1: cout << object[0].NameEnemies <<endl;cout<<object[0].healthenenemies<<endl;cout<<object[0].Attack<<endl;cout<<object[0].energyEnemies<<endl;break;
            case 2: cout << object[1].NameEnemies <<endl;cout<<object[1].healthenenemies<<endl;cout<<object[1].Attack<<endl;cout<<object[1].energyEnemies<<endl;break;
            case 3: cout << object[2].NameEnemies <<endl;cout<<object[2].healthenenemies<<endl;cout<<object[2].Attack<<endl;cout<<object[2].energyEnemies<<endl;break;
            case 4: cout << object[3].NameEnemies <<endl;cout<<object[3].healthenenemies<<endl;cout<<object[3].Attack<<endl;cout<<object[3].energyEnemies<<endl;break;
            case 5: cout << object[4].NameEnemies <<endl;cout<<object[4].healthenenemies<<endl;cout<<object[4].Attack<<endl;cout<<object[4].energyEnemies<<endl;break;
        }

    }
    bool AttackPlayer(Enemies &enem,Player &PL) {
        randomAttackEnemies(enem,PL);
    return  PL.damagePlayer(enem.Attack);

    }
    void retinfonow() {
        cout<<endl;
        cout<<"The Name Enemies :"<<NameEnemies<<endl;
        cout<<"The Health Enemies :"<<healthenenemies<<endl;
        cout<<"The Energy Enemies :"<<energyEnemies<<endl;
        cout<<"The Attack Enemies :"<<Attack<<endl;
        cout<<endl;
    }

    bool damageEnemies(Player &PL) {
PL.UseSkill();
        if (healthenenemies<=PL.retAttack()) {
            cout<<"You Kill the Enemies"<<endl;
            return true;
        }else if (healthenenemies > PL.retAttack()) {
            healthenenemies -=PL.retAttack();
            return false;
        }

    }
    void setinraond(Enemies &en,Player &PL) {
        switch (PL.retlevel()) {
            case 1:en.Attack=object[0].Attack;break;
            case 2:en.Attack=object[1].Attack;break;
            case 3:en.Attack=object[2].Attack;break;
            case 4:en.Attack=object[3].Attack;break;
            case 5:en.Attack=object[4].Attack;break;
        }
    }

};
int main() {
    Player player;
    Enemies enem;
    enem.StartGame();
    Enemies enemies=enem.setEnemies(player);

     int input;
    cout <<" 1- Start the game "<<endl;
    cout<<endl;
    cout <<" 2- Exit"<<endl;
    cout<<endl;
    cout <<" Enter Your choice :";
    cin>>input;
    cout<<endl;
    int savech=input;

while (true) {

    if (savech == 1) {

        player.retinfoPlayer();
        enemies.retinfonow();
        cout<<"1- Attack" <<endl;
        cout << "2- Skip(+15 point Energy and +5 point Health)" <<endl;
        cout <<" Enter Your choice :";
        cin>>input;
        cout<<endl;
        if (input == 1) {
            if (enemies.damageEnemies(player)) {
                player.Level_progress();
enemies=enem.setEnemies(player);
                continue;;
            }else {
                enemies.retinfonow();
            }
        }else if (input == 2) {
            player.skip();

        }else {
            cout<<"Try again"<<endl;
            continue;
        }

        if (enemies.AttackPlayer(enemies,player)) {
           enem.setinraond(enemies,player);
        }else {
            cout << "Game Over"<<endl;
            break;
        }
    }else {
        break;
    }
}
    return 0;
}