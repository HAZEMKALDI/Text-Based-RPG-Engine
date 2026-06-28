#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
 class Tools {
 public:
    string ToolName;
    double Damage;
    string Type;
    int number=1;
    vector<Tools> tools;

    Tools(string name,string type ,double damage) {
        this->ToolName=name;
        this->Damage=damage;
        this->Type=type;

    }
     Tools(){}
    Tools(string name,string type) {
        this->ToolName=name;
        this->Type=type;
    }
    ~Tools(){};
    void ToolsGame() {
        Tools tool1("Spear","Attack",1.3);
        tools.push_back(tool1);
        Tools tool2("sword","Attack",1);
        tools.push_back(tool2);
        Tools tool3("shield","Defense");
        tools.push_back(tool3);
        Tools tool4("Soul dose","Dosages");
        tools.push_back(tool4);
        Tools tool5("Energy dose","Dosages");
        tools.push_back(tool5);
    }
Tools retnewtools(string Name) {
        if (Name=="shield") {
            return tools[2];
        }else if (Name=="Spear") {
            return tools[0];
        }else if (Name=="sword") {
            return tools[1];
        }else if (Name=="Energy dose") {
            return tools[4];
        }else if (Name=="Soul dose") {
            return tools[3];
        }else {
            return Tools();
        }
    }

};
class Player {
vector<Tools> toolsPlayer;
    double energy_PLayer=75;
    double health_Player=180;
    double Attack_Player=30;
    Tools tools;

    int levelplayer=1;
    public:
    void useSouldose() {
        health_Player +=40;
        remtool("Soul dose");
    }
    void useEnergydose() {
        energy_PLayer +=30;
        remtool("Energy dose");
    }
    void remtool(string Name) {
        for (int i = 0; i < toolsPlayer.size(); i++) {
            if (toolsPlayer[i].ToolName == Name) {
                toolsPlayer.erase(toolsPlayer.begin() + i);
                break;
            }
        }
    }
    Player() {
        tools.ToolsGame();

        toolsPlayer.push_back(tools.retnewtools("sword"));
    };
    ~Player(){};
    string ChoisePlayer() {
        int input;
        int number=0;
        cout << "--- Inventory ---" << endl;

        // ليتفقد كم أداة موجودة فعلياً بالحقيبة ويطبعها
        for (int i = 0; i < toolsPlayer.size(); i++) {
            cout << "[ " << i + 1 << "- " << toolsPlayer[i].ToolName << " ] ";
            number++;
        }

        cout  << endl;
        cout<<"Enter Your choice :";
        cin >> input;
        if (input >number) {
            cout<<"Try again"<<endl;
            ChoisePlayer();
        }else {
           switch (input) {
               case 1:return toolsPlayer[0].ToolName;break;
               case 2:return toolsPlayer[1].ToolName;break;
               case 3:return toolsPlayer[2].ToolName;break;
                   case 4:return toolsPlayer[3].ToolName;break;
                   case 5:return toolsPlayer[4].ToolName;break;
           }
        }

    }
    int retlevel() {
        return levelplayer;
    }
    void retinfoPlayer() {
        cout << "The Energy Player:" << energy_PLayer <<endl;
        cout << "The Health Player:" << health_Player <<endl;
        cout<<endl;
    }
  void  UseSkill(string name) {
        switch (levelplayer) {
            case 1:if (energy_PLayer>=15 || name=="sword") {
                energy_PLayer -=15;break;
            }else if (energy_PLayer>=15 || name=="Spear"){
                energy_PLayer -=15*1.15;break;
            }else {
                cout <<" The Energy Low!!"<<endl;break;
            }


            case 2:if (energy_PLayer>=20|| name=="sword") {
                energy_PLayer -=20;break;
            }else if (energy_PLayer>=20 || name=="Spear") {
                energy_PLayer -=20*1.15;break;
            }else {
                cout <<" The Energy Low!!"<<endl;break;
            }
            case 3:if (energy_PLayer>=25|| name=="sword") {
                energy_PLayer -=25;break;
            }else if (energy_PLayer>=25 || name=="Spear") {
                energy_PLayer -=25*1.15;break;
            }else {
                cout <<" The Energy Low!!"<<endl;break;
            }
            case 4:if (energy_PLayer>=30|| name=="sword") {
                energy_PLayer -=30;break;
            }else if (energy_PLayer>=30 || name=="Spear") {
                energy_PLayer -=30*1.15;break;
            }else {
                cout <<" The Energy Low!!"<<endl;break;
            }
            case 5:if (energy_PLayer>=35|| name=="sword") {
                energy_PLayer -=35;break;
            }else if (energy_PLayer>=35 || name=="Spear") {
                energy_PLayer -=35*1.15;break;
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

            case 2:health_Player=200;energy_PLayer=100;Attack_Player=40;cout<<"You Win Soul Dose ,"<<"Description : increases 40 life points"<<endl;toolsPlayer.push_back(tools.retnewtools("Soul dose"));break;
            case 3:health_Player=250;energy_PLayer=110;Attack_Player=50;cout<<"You Win shield ,"<<"Description : Reduces damage received by 50%, except for poison attack, which reduces it by 30%"<<endl;toolsPlayer.push_back(tools.retnewtools("shield"));break;
            case 4:health_Player=300;energy_PLayer=130;Attack_Player=55;cout<<"You Win Spear ,"<<"Description : Your damage increases by 30% and your energy consumption increases by 15%"<<endl;toolsPlayer.push_back(tools.retnewtools("Spear"));break;
            case 5:health_Player=350;energy_PLayer=150;Attack_Player=65;cout<<"You Win Energy Dose ,"<<"Description : increases 30 Energy points"<<endl;toolsPlayer.push_back(tools.retnewtools("Energy dose"));break;
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
    double healthenenemies;
    double Attack;
    double energyEnemies;
    string NameEnemies;
    Enemies(){}
    Enemies(double HL,double ATT,double ene,string Name) {
      this->healthenenemies=HL;
        this->Attack=ATT;
        this->NameEnemies=Name;
        this->energyEnemies=ene;

    };
    ~Enemies(){};
    // صنع الاعداء
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
// هجوم خاص يستخدم السم
void Poison(Enemies &en,Player &PL) {
        double skill;
    en.Attack = en.Attack*1.2;
        en.healthenenemies=en.healthenenemies*1.1;
        switch (PL.retlevel()) {
            case 1:skill=10*1.2;UseSkillEnemies(en,skill);break;
                case 2:skill=20*1.2;UseSkillEnemies(en,skill);break;
                case 3:skill=30*1.2;UseSkillEnemies(en,skill);break;
            case 4:skill=20*1.2;UseSkillEnemies(en,skill);break;
            case 5:skill=35*1.2;UseSkillEnemies(en,skill);break;
        }

}
// هجوم خاص يستخدم النار
    void Fire(Enemies &en, Player &PL) {
        double skill;
        en.Attack = en.Attack*1.25;
        en.healthenenemies=en.healthenenemies*1.05;
        switch (PL.retlevel()) {
            case 1:skill=10*1.05;UseSkillEnemies(en,skill);break;
            case 2:skill=20*1.05;UseSkillEnemies(en,skill);break;
            case 3:skill=30*1.05;UseSkillEnemies(en,skill);break;
            case 4:skill=20*1.05;UseSkillEnemies(en,skill);break;
            case 5:skill=35*1.05;UseSkillEnemies(en,skill);break;
        }

    };
// هجوم خاص يستخدم الجليد
    void Frost(Enemies &en,Player &PL) {
        double skill;
        en.Attack = en.Attack*1.1;
        en.healthenenemies=en.healthenenemies*1.25;
        switch (PL.retlevel()) {
            case 1:skill=10;UseSkillEnemies(en,skill);break;
            case 2:skill=20;UseSkillEnemies(en,skill);break;
            case 3:skill=30;UseSkillEnemies(en,skill);break;
            case 4:skill=20;UseSkillEnemies(en,skill);break;
            case 5:skill=35;UseSkillEnemies(en,skill);break;
        }

    }
// استهلاك طاقة للهجوم
    void UseSkillEnemies(Enemies &en,double skill) {
        en.energyEnemies=en.energyEnemies-skill;
    }
// اعادة ضبط العدو حسب الجولة
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
// ذكاء خاص للعدو يجعله يستخدم هجوم عشوائي حسب طاقته
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
// طباعة معلومات العدو الاصلية
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
// هجوم على الاعب
    bool AttackPlayer(Enemies &enem,Player &PL,int choise) {
        randomAttackEnemies(enem,PL);
        if (choise == 1) {
             return  PL.damagePlayer(enem.Attack);
        }else {
            int level=PL.retlevel();
            double Att;
            switch (level) {
                case 1:
                    Att=enem.Attack/25;
                    if (Att>1.05) {
                        double NewAttack=enem.Attack-(enem.Attack*0.3);
                       return  PL.damagePlayer(NewAttack);
                    }else {
                        return PL.damagePlayer(enem.Attack/2);
                    }
                    break;
                case 2:
                    Att=enem.Attack/30;
                    if (Att>1.05) {
                        double NewAttack=enem.Attack-(enem.Attack*0.3);
                        return  PL.damagePlayer(NewAttack);
                    }else {
                        return PL.damagePlayer(enem.Attack/2);
                    }
                    break;
                case 3:
                    Att=enem.Attack/35;
                    if (Att>1.05) {
                        double NewAttack=enem.Attack-(enem.Attack*0.3);
                        return  PL.damagePlayer(NewAttack);
                    }else {
                        return PL.damagePlayer(enem.Attack/2);
                    }
                    break;
                case 4:
                    Att=enem.Attack/10;
                    if (Att>1.05) {
                        double NewAttack=enem.Attack-(enem.Attack*0.3);
                        return  PL.damagePlayer(NewAttack);
                    }else {
                        return PL.damagePlayer(enem.Attack/2);
                    }
                    break;
                case 5:
                    Att=enem.Attack/39;
                    if (Att>1.05) {
                        double NewAttack=enem.Attack-(enem.Attack*0.3);
                        return  PL.damagePlayer(NewAttack);
                    }else {
                        return PL.damagePlayer(enem.Attack/2);
                    }
                    break;
            }
        }


    }
// طباعة معلومات العدو خلال الجولة
    void retinfonow() {
        cout<<endl;
        cout<<"The Name Enemies :"<<NameEnemies<<endl;
        cout<<"The Health Enemies :"<<healthenenemies<<endl;
        cout<<"The Energy Enemies :"<<energyEnemies<<endl;
        cout<<"The Attack Enemies :"<<Attack<<endl;
        cout<<endl;
    }
// تعرض العدو للضرر
    bool damageEnemies(Player &PL,string Name) {
PL.UseSkill( Name);
        if (Name=="Spear") {
            if (healthenenemies<=(PL.retAttack()*1.3)) {
            cout<<"You Kill the Enemies"<<endl;
            return true;
        }else if (healthenenemies > (PL.retAttack()*1.3)) {
            healthenenemies -=PL.retAttack();
            return false;
        }
        }else {
            if (healthenenemies<=PL.retAttack()) {
                cout<<"You Kill the Enemies"<<endl;
                return true;
            }else if (healthenenemies > PL.retAttack()) {
                healthenenemies -=PL.retAttack();
                return false;
            }
        }


    }
// تعيد ضبط هجوم العدو اثناء الجولة
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
    Enemies enemies;
enemies.StartGame();
     enemies = enemies.setEnemies(player);

    int input;
    cout << " 1- Start the game " << endl;
    cout << endl;
    cout << " 2- Exit" << endl;
    cout << endl;
    cout << " Enter Your choice :";
    cin >> input;
    cout << endl;
    int savech = input;

    while (true) {
        if (savech == 1) {
            // فحص إذا فاز اللاعب باللعبة (تخطى ليفل 5)
            if (player.retlevel() > 5) {
                cout << " CONGRATULATIONS! You defeated the Dragon and won the game! 🎉" << endl;
                break;
            }

            player.retinfoPlayer();
            enemies.retinfonow();
            string tool = player.ChoisePlayer();

            if (tool == "sword") {
                if (!enemies.damageEnemies(player, tool)) {
                    enemies.retinfonow();
                    player.retinfoPlayer();
                    if (enemies.AttackPlayer(enemies, player, 1)) {
                        enemies.setinraond(enemies, player);
                        continue;
                    } else {
                        cout << "Game Over! You were defeated by the enemy." << endl;
                        break;
                    }
                } else {
                    player.Level_progress();
                    enemies = enemies.setEnemies(player);
                    continue;
                }
            }
            else if (tool == "Spear") {
                if (!enemies.damageEnemies(player, tool)) {
                    enemies.retinfonow();
                    player.retinfoPlayer();
                    if (enemies.AttackPlayer(enemies, player, 1)) {
                        enemies.setinraond(enemies, player);
                        continue;
                    } else {
                        cout << "Game Over! You were defeated by the enemy." << endl;
                        break;
                    }
                } else {
                    player.Level_progress();
                    enemies = enemies.setEnemies(player);
                    continue;
                }
            }
            else if (tool == "shield") {
                if (enemies.AttackPlayer(enemies, player, 2)) {
                    player.skip();
                    enemies.retinfonow();
                    player.retinfoPlayer();
                } else {
                    cout << "Game Over! You were defeated by the enemy." << endl;
                    break;
                }
            }
            else if (tool == "Soul dose") {
                player.useSouldose();
                if (enemies.AttackPlayer(enemies, player, 1)) {
                    enemies.retinfonow();
                    player.retinfoPlayer();
                } else {
                    cout << "Game Over! You were defeated by the enemy." << endl;
                    break;
                }
            }
            else { // Energy dose
                player.useEnergydose();
                if (enemies.AttackPlayer(enemies, player, 1)) {
                    enemies.retinfonow();
                    player.retinfoPlayer();
                } else {
                    cout << "Game Over! You were defeated by the enemy." << endl;
                    break;
                }
            }

            // 🌟 شبكة أمان: تصفير هجوم الوحش بعد نهاية أي دور لم يمت فيه الوحش أو اللاعب
            enemies.setinraond(enemies, player);
            cout << "------------------------------------------" << endl;

        } else {
            cout << "Exiting the game... Goodbye!" << endl;
            break;
        }
    }
    return 0;
}