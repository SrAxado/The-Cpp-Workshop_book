#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Attack {
  public:
    Attack(const string name, const int attackStat) : m_name(name), m_attackStat(attackStat) {}

    Attack(const Attack& attack) 
      : m_name(attack.m_name), m_attackStat(attack.m_attackStat) {}
    
    Attack& operator=(const Attack& rhs) {
      if (this != &rhs) {
        m_attackStat = rhs.m_attackStat;
        m_name = rhs.m_name;
      }
      return *this;
    }

    ~Attack() {}

    string getName() const { return m_name; }
    int getAttackStat() const { return m_attackStat; }
    void setAttackStat(const int attackStat) { m_attackStat = attackStat; }

  private:
    string m_name;
    int m_attackStat;
};

class Item {
  public:
    Item(const string name, const int healStat) : m_name(name), m_healStat(healStat) {}

    Item(const Item& item) : m_name(item.m_name), m_healStat(item.m_healStat) {}

    Item& operator=(const Item& rhs) {
      if (this != &rhs) {
        m_name = rhs.m_name;
        m_healStat = rhs.m_healStat;
      }
      return *this;
    }

    ~Item() {}

    string getName() const { return m_name; }
    int getHealStat() const { return m_healStat; }
    void setHealStat(int const healStat) { m_healStat = healStat; }

  private:
    string m_name;
    int m_healStat;
};

class Character {
  public:
    Character(const char* name, int strengthMultiplier, int defenseMultiplier, vector<Attack> attacks, vector<Item> items)
      : m_strengthMultiplier(strengthMultiplier), m_defenseMultiplier(defenseMultiplier),
        m_attacks(attacks), m_items(items) {
      m_life = 100;
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);

      // for (int i = 0; i < attacks.size(); ++i) {
      //   // cout << attacks[i].getName() << " " << attacks[i].getAttackStat() << endl;
      //   m_attacks.push_back(attacks[i]);
      //   m_strengthMultiplier += attacks[i].getAttackStat();
      // };
      // for (int i = 0; i < items.size(); ++i) {
      //   // cout << items[i].getName() << " " << items[i].getHealStat() << endl;
      //   m_items.push_back(items[i]);
      //   m_defenseMultiplier += items[i].getHealStat() * 3;
      // }
      printInfo();
    };

    Character(const Character& character) 
      : m_strengthMultiplier(character.m_strengthMultiplier),
        m_defenseMultiplier(character.m_defenseMultiplier),
        m_attacks(character.m_attacks), m_items(character.m_items) {
          m_life = 100;
          m_name = new char[strlen(character.m_name) + 3];
          strcpy(m_name, character.m_name);
          strcpy(&m_name[strlen(character.m_name)], "_X");
    }

    Character& operator=(const Character& rhs) {
      if (this != &rhs) {
        m_life = 100;
        m_name = new char[strlen(rhs.m_name) + 3];
        strcpy(m_name, rhs.m_name);
        strcpy(&m_name[strlen(rhs.m_name)], "_X");
        m_strengthMultiplier = rhs.m_strengthMultiplier;
        m_defenseMultiplier = rhs.m_defenseMultiplier;
        m_attacks = rhs.m_attacks;
        m_items = rhs.m_items;
      }
      return *this;
    }

    void AttackEnemy(Attack& attack, Character& character) {
      cout << "== " << m_name << " attacks with '" << attack.getName() << "' --> " << character.getName() << endl;
    }

    void Defend() {}

    void UseItem() {}

    ~Character() {
      // delete[] m_name;
    }


    string getName() const { return m_name; }
    int getAttack() const { return m_strengthMultiplier; }
    int getDefense() const { return m_defenseMultiplier; }

    void setAttack(const int value) { m_strengthMultiplier = value; }

    void printInfo() {
      cout << "NAME: " << m_name << endl;
      cout << "LIFE ==> " << m_life << endl
        << "STRENGTH: " << m_strengthMultiplier  
        << "\tDEFENSE: " << m_defenseMultiplier << endl
        << "- - -- ---  ATTACKS  --- -- - -\t- - ---  ITEMS  --- - -  " << endl;
      for (int i = 0; i < m_attacks.size(); ++i) {
        cout << "   " << m_attacks[i].getName() << "  ==>  " << m_attacks[i].getAttackStat() << "\t\t   ";
        if (i < m_items.size()) {
         cout << m_items[i].getName() << "  ==>  " << m_items[i].getHealStat();
        }
        cout << endl;
      }
      cout << endl;
    }

  private:
    int m_life;
    char* m_name;
    int m_strengthMultiplier = 0;
    int m_defenseMultiplier = 0;
    vector<Attack> m_attacks;
    vector<Item> m_items;
};

class Battle {
  public:
    Battle(string name, Character* opponents[], int numOpponents) : m_name(name) {
      // int numOpponents = sizeof(opponents) / sizeof(opponents[0]);
      // int numOpponents = *(&opponents + 1) - opponents;

      

      cout << "    -------  BATTLE " << name << "  -------" << endl
        << "  " << opponents[0]->getName();
      m_opponents.push_back(opponents[0]);
      for (int i = 1; i < numOpponents; ++i) {
        // opponents++;
        cout << "\tvs.\t" << opponents[i]->getName();
        m_opponents.push_back(opponents[i]);
      }
      cout << endl;


    }

    ~Battle() {}

    void printBattleResult() {
      int numOpponents = m_opponents.size();
      
      int winnerID = 0;

      for (int i = 0; i < numOpponents; ++i) {
        battleGround.push_back({i, m_opponents[i].getDefense()});
        // battleGround[i] = m_opponents[i].getDefense();
      }

      // while (continueBattle()) {
      while (battleGround.size() > 1) {
        for (int attacker = 0; attacker < battleGround.size(); ++attacker) {
          for (int defender = 0; defender < battleGround.size(); ++defender) {
            if (attacker != defender) {
              battleGround[defender].second -= battleGround[attacker].second;
              if (battleGround[defender].second <= 0) {
                battleGround.erase(battleGround.begin() + defender);
                  // find(battleGround.begin(), battleGround.end(), battleGround[defender]));
              }
            }
          }
        }
      }


      cout << endl << "    ================================================" << endl
           << "\t\t" << m_opponents[battleGround[0].first].getName() << " WON!!!" << endl
           << "    ================================================" << endl << endl;
      
    }

  private:
    string m_name;
    vector<Character*> m_opponents;
    vector<pair<int, int>> battleGround;

    // bool continueBattle() { 
    //   // return any_of(m_opponents[0], m_opponents[m_opponents.size()], [](int opponent) { opponent > 0; });
    //   return any_of(battleGround[0], battleGround[battleGround.size()], [](pair<int, int> opponent) { opponent.second > 0; });
    // }

    // int getRoundWinner(int* battleGround, const int numOpponents) {
    //   for (int i = 0; i < numOpponents; ++i) {

    //   }
    // } 
};

int main() {
  // Attack attack1("Punch", 33);
  // Attack attack2("Kick", 38);
  // Attack attack3("Shout", 17);
  // Attack attack4("Sword To The Face", 29);
  // Attack attack5("Flame Breath", 50);

  vector<Attack> attacks {
    Attack("Punch", 33), Attack("Kick", 38), Attack("Shout", 17),
    Attack("Sword To The Face", 29), Attack("Flame Breath", 50)
  };

  // Item item1("Aspirin", 27);
  // Item item2("Bagaço", 50);
  // Item item3("Bandage", 30);
  // Item item4("Old Grog", 21);
  // Item item5("Scale Oil", 20);
  // Item item6("Breath of Life", 55);

  vector<Item> items {
    Item("Aspirin", 27), Item("Bagaço", 50), Item("Old Grog", 21),
    Item("Scale Oil", 20), Item("Breath of Life", 55)
  };

  // Attack attacks[] {attack1,attack2};
  // vector<Attack> attacks {attack1, attack2, attack4};
  // vector<Item> items {item1, item2};
  Character knight("Sir Collin", 15, 10,
    {attacks[0], attacks[1], attacks[3]}, {items[0], items[1]});
    // {attack1, attack2, attack4}, {item1, item2});
  // knight.printInfo();

  // Character knight2 = knight;

  // attacks[0] = attack3;
  // items[1] = item3;
  Character mage("Brown Bear", 25, 4,
    {attacks[1], attacks[2], attacks[4]}, {items[0], items[2]});
    // {attack2, attack3, attack5}, {item0, item2});
  // mage.printInfo();

  // attacks[0] = attack1;
  // items[0] = item2;
  // items[1] = item2;
  Character superman("Superman", 20, 20,
    {attacks[0], attacks[1], attacks[4]}, {items[1], items[1]});
    // {attack1, attack2, attack5}, {item2, item2});
  // superman.printInfo();

  Character* opponents[] {&knight, &mage, &superman};  // lighter version
  Battle battle1("Multiverse Stand", opponents, 3);

  // Character opponents[] {knight, mage, superman}; // creates a copy of the characteres
  // delete[] opponents;
  // Character* opponents[] {&knight, &mage, &superman};
  opponents[0] = &knight;
  opponents[1] = &mage;
  opponents[2] = &superman;
  Battle battle2("Trafalgar Square", opponents[0], 3);
  // Battle battle2("Trafalgar Square", opponents, 3);
  // battle1.printBattleResult();

  return 0;
}