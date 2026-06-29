#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class Tools {
public:
    string ToolName;
    double Damage;
    string Type;
    int number = 1;
    vector<Tools> tools;

    Tools(string name, string type, double damage) {
        this->ToolName = name;
        this->Damage = damage;
        this->Type = type;
    }
    Tools() {}
    Tools(string name, string type) {
        this->ToolName = name;
        this->Type = type;
    }
    ~Tools() {};

    void ToolsGame() {
        Tools tool1("Spear", "Attack", 1.3);
        tools.push_back(tool1);
        Tools tool2("sword", "Attack", 1);
        tools.push_back(tool2);
        Tools tool3("shield", "Defense");
        tools.push_back(tool3);
        Tools tool4("Soul dose", "Dosages");
        tools.push_back(tool4);
        Tools tool5("Energy dose", "Dosages");
        tools.push_back(tool5);
    }

    Tools retnewtools(string Name) {
        if (Name == "shield") return tools[2];
        if (Name == "Spear") return tools[0];
        if (Name == "sword") return tools[1];
        if (Name == "Energy dose") return tools[4];
        if (Name == "Soul dose") return tools[3];
        return Tools();
    }
};

class Player {
    vector<Tools> toolsPlayer;
    double energy_PLayer = 75;
    double health_Player = 180;
    double Attack_Player = 30;
    Tools tools;
    int levelplayer = 1;

public:
    void useSouldose() {
        health_Player += 40;
        remtool("Soul dose");
    }
    void useEnergydose() {
        energy_PLayer += 30;
        remtool("Energy dose");
    }
    void remtool(string Name) {
        for (size_t i = 0; i < toolsPlayer.size(); i++) {
            if (toolsPlayer[i].ToolName == Name) {
                toolsPlayer.erase(toolsPlayer.begin() + i);
                break;
            }
        }
    }
    Player() {
        tools.ToolsGame();
        toolsPlayer.push_back(tools.retnewtools("sword"));
    }
    ~Player() {};

    string ChoisePlayer() {
        int input;
        int number = 0;
        cout << YELLOW << "--- Inventory ---" << RESET << endl;

        for (size_t i = 0; i < toolsPlayer.size(); i++) {
            cout << YELLOW << "[ " << i + 1 << "- " << toolsPlayer[i].ToolName << " ] ";
            number++;
        }
        cout << RESET << endl << endl;
        cout << "Enter Your choice :";
        cin >> input;

        if (input > number || input <= 0) {
            cout << RED << "Try again" << RESET << endl;
            return ChoisePlayer();
        } else {
            return toolsPlayer[input - 1].ToolName;
        }
    }

    int retlevel() { return levelplayer; }

    void retinfoPlayer() {
        cout << BLUE << "The Energy Player:" << energy_PLayer << RESET << endl;
        cout << RED << "The Health Player:" << health_Player << RESET << endl;
        cout << endl;
    }

    bool UseSkill(string name) {
        double requiredEnergy = 0;
        if (levelplayer == 1) requiredEnergy = 15;
        else if (levelplayer == 2) requiredEnergy = 20;
        else if (levelplayer == 3) requiredEnergy = 25;
        else if (levelplayer == 4) requiredEnergy = 30;
        else if (levelplayer == 5) requiredEnergy = 35;

        if (name == "Spear") {
            requiredEnergy *= 1.15;
        }

        if (energy_PLayer >= requiredEnergy) {
            energy_PLayer -= requiredEnergy;
            return true;
        } else {
            cout << GREEN << " The Energy Low!!" << RESET << endl;
            skip();
            return false;
        }
    }

    void skip() {
        switch (levelplayer) {
            case 1: health_Player += 10; energy_PLayer += 25; break;
            case 2: health_Player += 15; energy_PLayer += 30; break;
            case 3: health_Player += 20; energy_PLayer += 35; break;
            case 4: health_Player += 25; energy_PLayer += 40; break;
            case 5: health_Player += 40; energy_PLayer += 60; break;
        }
    }

    bool damagePlayer(double damage) {
        if (health_Player <= damage) {
            health_Player = 0;
            return false;
        } else {
            health_Player -= damage;
            cout << YELLOW << "He received valuable damage :" << damage << RESET << endl;
            return true;
        }
    }

    void Level_progress() {
        levelplayer++;
        switch (levelplayer) {
            case 2: health_Player = 230; energy_PLayer = 100; Attack_Player = 40; cout << "You Win Soul Dose ,Description : increases 40 life points" << endl; toolsPlayer.push_back(tools.retnewtools("Soul dose")); break;
            case 3: health_Player = 260; energy_PLayer = 110; Attack_Player = 50; cout << "You Win shield ,Description : Reduces damage received by 50%" << endl; toolsPlayer.push_back(tools.retnewtools("shield")); break;
            case 4: health_Player = 300; energy_PLayer = 130; Attack_Player = 55; cout << "You Win Spear ,Description : Your damage increases by 30%" << endl; toolsPlayer.push_back(tools.retnewtools("Spear")); break;
            case 5: health_Player = 350; energy_PLayer = 150; Attack_Player = 65; cout << "You Win Energy Dose ,Description : increases 30 Energy points" << endl; toolsPlayer.push_back(tools.retnewtools("Energy dose")); break;
        }
    }

    int retAttack() { return Attack_Player; }
};

class Enemies {
    vector<Enemies> object;
public:
    double healthenenemies;
    double Attack;
    double energyEnemies;
    string NameEnemies;

    Enemies() {}
    Enemies(double HL, double ATT, double ene, string Name) {
        this->healthenenemies = HL;
        this->Attack = ATT;
        this->NameEnemies = Name;
        this->energyEnemies = ene;
    }
    ~Enemies() {};

    void StartGame() {
        object.push_back(Enemies(120, 25, 100, "Goblin"));
        object.push_back(Enemies(170, 30, 120, "Skelton"));
        object.push_back(Enemies(180, 35, 140, "Zombie"));
        object.push_back(Enemies(400, 10, 170, "stone giant"));
        object.push_back(Enemies(300, 39, 220, "Dragon"));
    }

    void Poison(Enemies &en, Player &PL) {
        double skill = 10;
        en.Attack *= 1.2;
        en.healthenenemies *= 1.1;
        if (PL.retlevel() == 1) skill = 10 * 1.2;
        else if (PL.retlevel() == 2) skill = 20 * 1.2;
        else if (PL.retlevel() == 3) skill = 30 * 1.2;
        else if (PL.retlevel() == 4) skill = 20 * 1.2;
        else if (PL.retlevel() == 5) skill = 35 * 1.2;
        UseSkillEnemies(en, skill);
    }

    void Fire(Enemies &en, Player &PL) {
        double skill = 10;
        en.Attack *= 1.25;
        en.healthenenemies *= 1.05;
        if (PL.retlevel() == 1) skill = 10 * 1.05;
        else if (PL.retlevel() == 2) skill = 20 * 1.05;
        else if (PL.retlevel() == 3) skill = 30 * 1.05;
        else if (PL.retlevel() == 4) skill = 20 * 1.05;
        else if (PL.retlevel() == 5) skill = 35 * 1.05;
        UseSkillEnemies(en, skill);
    }

    void Frost(Enemies &en, Player &PL) {
        double skill = 10;
        en.Attack *= 1.1;
        en.healthenenemies *= 1.25;
        if (PL.retlevel() == 1) skill = 10;
        else if (PL.retlevel() == 2) skill = 20;
        else if (PL.retlevel() == 3) skill = 30;
        else if (PL.retlevel() == 4) skill = 20;
        else if (PL.retlevel() == 5) skill = 35;
        UseSkillEnemies(en, skill);
    }

    void UseSkillEnemies(Enemies &en, double skill) {
        en.energyEnemies -= skill;
    }

    Enemies setEnemies(Player &PL) {
        int lvl = PL.retlevel() - 1;
        if (lvl >= 0 && lvl < 5) return object[lvl];
        return object[0];
    }

    void randomAttackEnemies(Enemies &en, Player &PL) {
        int random = (rand() % 3) + 1;
        double minEnergy = 10;
        if (en.NameEnemies == "Skelton") minEnergy = 20;
        else if (en.NameEnemies == "Zombie") minEnergy = 30;
        else if (en.NameEnemies == "stone giant") minEnergy = 20;
        else if (en.NameEnemies == "Dragon") minEnergy = 35;

        if (en.energyEnemies >= minEnergy * 1.2) {
            if (random == 1) { Poison(en, PL); cout << GREEN << "Enemies use Poison" << RESET << endl; }
            else if (random == 2) { Fire(en, PL); cout << RED << "Enemies use Fire" << RESET << endl; }
            else { Frost(en, PL); cout << BLUE << "Enemies use Frost" << RESET << endl; }
        } else if (en.energyEnemies >= minEnergy) {
            Frost(en, PL); cout << BLUE << "Enemies use Frost" << RESET << endl;
        } else {
            cout << en.NameEnemies << " has low energy! Uses Basic Attack!" << endl;
        }
    }

    bool AttackPlayer(Enemies &enem, Player &PL, int choise) {
        randomAttackEnemies(enem, PL);
        double ENEMIESATTCK = enem.Attack;
        if (choise == 1) {
            return PL.damagePlayer(ENEMIESATTCK);
        } else {
            return PL.damagePlayer(ENEMIESATTCK * 0.5); // تبسيط لدرع الحماية
        }
    }

    void retinfonow() {
        cout << endl << "The Name Enemies :" << NameEnemies << endl;
        cout << RED << "The Health Enemies :" << healthenenemies << RESET << endl;
        cout << BLUE << "The Energy Enemies :" << energyEnemies << RESET << endl;
        cout << GREEN << "The Attack Enemies :" << Attack << RESET << endl << endl;
    }

    bool damageEnemies(Player &PL, string Name) {
        bool ret = PL.UseSkill(Name);
        if (!ret) return false; // إذا لم تنجح المهارة بسبب نقص الطاقة، لا ينقص دم العدو

        double actualDamage = PL.retAttack();
        if (Name == "Spear") actualDamage *= 1.3;

        if (healthenenemies <= actualDamage) {
            cout << "You Kill the Enemies" << endl;
            healthenenemies = 0;
            return true;
        } else {
            healthenenemies -= actualDamage;
            return false;
        }
    }

    void setinraond(Enemies &en, Player &PL) {
        int lvl = PL.retlevel() - 1;
        if (lvl >= 0 && lvl < 5) en.Attack = object[lvl].Attack;
    }
};

int main() {
    srand(time(0));
    Player player;
    Enemies enemies;
    enemies.StartGame();
    enemies = enemies.setEnemies(player);

    int input;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "|                               1-[Start Game]                                   |" << endl;
    cout << "|                               2-[   Exit   ]                                   |" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << " Enter Your choice :";
    cin >> input;

    if (input != 1) {
        cout << BLUE << "Exiting the game... Goodbye!" << RESET << endl;
        return 0;
    }

    while (true) {
        if (player.retlevel() > 5) {
            cout << YELLOW << "CONGRATULATIONS! You won the game!" << RESET << endl;
            break;
        }

        player.retinfoPlayer();
        enemies.retinfonow();
        string tool = player.ChoisePlayer();

        if (tool == "sword" || tool == "Spear") {
            double oldHealth = enemies.healthenenemies;
            bool killed = enemies.damageEnemies(player, tool);

            // تحقق إذا فشلت الضربة بسبب نقص طاقة اللاعب اصلاً
            if (enemies.healthenenemies == oldHealth && !killed) {
                // اللاعب تخطى جعبته وزادت طاقته عبر دالة skip() تلقائياً داخل UseSkill
                // هنا العدو سيهاجم اللاعب لأن اللاعب لم يضربه
                if (!enemies.AttackPlayer(enemies, player, 1)) {
                    cout << GREEN << "Game Over! You were defeated." << RESET << endl;
                    break;
                }
                continue;
            }

            if (!killed) {
                if (!enemies.AttackPlayer(enemies, player, 1)) {
                    cout << GREEN << "Game Over! You were defeated." << RESET << endl;
                    break;
                }
            } else {
                player.Level_progress();
                enemies = enemies.setEnemies(player);
            }
        }
        else if (tool == "shield") {
            if (enemies.AttackPlayer(enemies, player, 2)) {
                player.skip();
            } else {
                cout << GREEN << "Game Over! You were defeated." << RESET << endl;
                break;
            }
        }
        else if (tool == "Soul dose") {
            player.useSouldose();
            if (!enemies.AttackPlayer(enemies, player, 1)) {
                cout << GREEN << "Game Over! You were defeated." << RESET << endl;
                break;
            }
        }
        else if (tool == "Energy dose") {
            player.useEnergydose();
            if (!enemies.AttackPlayer(enemies, player, 1)) {
                cout << GREEN << "Game Over! You were defeated." << RESET << endl;
                break;
            }
        }

        enemies.setinraond(enemies, player);
        cout << endl;
    }
    return 0;
}
