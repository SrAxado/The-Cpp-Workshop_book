#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

// The health value below which the character will try regain health by consuming an (recovery) item
#define HEALTH_THRESHOLD 20

// Defines the Attack class
class Attack {
  public:
    // Defines an Attack
    Attack(const string name, const int attackStat) : m_name(name), m_attackStat(attackStat) {}

    string getName() const { return m_name; }

    int getAttackStrength() const { return m_attackStat; }
    void setAttackStrength(const int attackStat) { m_attackStat = attackStat; }


  private:
    string m_name;
    int m_attackStat;
};

// Defines the Item class -- the items are all health gainers
class Item {
  public:
    // Item's constructor
    Item(const string name, const int healStat) : m_name(name), m_healStat(healStat) {}

    string getName() const { return m_name; }

    int getHealValue() const { return m_healStat; }
    void setHealValue(int const healStat) { m_healStat = healStat; }

  private:
    string m_name;
    int m_healStat;
};

// Defines the Character class
class Character {
  public:
    // Character's constructor
    Character(const string name, int strengthMultiplier, int defenseMultiplier, 
      vector<Attack*>& attacks, vector<Item*>& items)
      : m_name(name), m_strength(strengthMultiplier), m_defense(defenseMultiplier),
        m_attacks(attacks), m_items(items) {
          m_life = 100;
        }

    // Performs an attack with a random attack from the attack vector's list to a specific character
    void doAttack(Character* character) {
      Attack* attack = getRandomAttack();
      cout << "== " << m_name << " attacks " << character->getName() << " with '" << attack->getName() << "'" << endl;
      character->doDefense(attack);
    }

    // The character gets attacked with a specific
    /// TODO: by knowing the caracteristics of the attack, one can implement special defenses/potions to counteract the attack
    void doDefense(const Attack* attack) {
      // If the attack is weaker then the defense, it will just weaken the defense
      if (attack->getAttackStrength() <= m_defense) {
        m_defense -= attack->getAttackStrength();
        cout << m_name << " [" << m_life << "]: Ah! Ah! Ah! You barely made me a scratch" << endl;
      
        // If the attack is stronger then the defense,
        // Set the defense to 0 and inflict the rest of the attack to the character's life
      } else {
        // If the character's life is below the HEALTH_THRESHOLD value, recover it a bit by using an item
        if ((m_life <= HEALTH_THRESHOLD) && (m_items.size() > 0)) {
          useItem();
        }

        m_life = m_life - (attack->getAttackStrength() - m_defense);
        m_defense = 0;  // The character's defense shields were depleted
        if (m_life > 0) {
          cout << m_name << " [" << m_life << "]: Is that all you have!?" << endl;
        
          // The character died
        } else {
          cout << m_name << ": Arrrgghhhhh!" << endl;
        }
      }
    }

    // Recover the character's health by using a random item from the item's vector list
    void useItem() {
      Item* item = getRandomItem();
      cout << m_name << " used " << item->getName() << " and recovers " << item->getHealValue() << " points of health" << endl;
      m_life += item->getHealValue();
      m_items.erase(find(m_items.begin(), m_items.end(), item));  // Removes the used item from the vector's list
    }

    // ~Character() {
    //   // delete[] m_name;
    // }


    string getName() const { return m_name; }
    int getLife() const { return m_life; }
    int getStrength() const { return m_strength; }
    int getDefense() const { return m_defense; }

    void revive() { m_life = 100; }
    void setStrength(const int value) { m_strength = value; }
    void setAttack(Attack& attack) { m_attacks.push_back(&attack); }
    void setItem(Item& item) { m_items.push_back(&item); }

    // Prints all the character's information
    void printInfo() {
      cout << "NAME: " << m_name << endl;
      cout << "LIFE ==> " << m_life
        << "\t|\tSTRENGTH: " << m_strength  
        << "\t|\tDEFENSE: " << m_defense << endl
        << "- - -- ---  ATTACKS  --- -- - -\t\t- - ---  ITEMS  --- - -  " << endl;
      for (int i = 0; i < int(m_attacks.size()); ++i) {
        cout << "   " << m_attacks[i]->getName() << "  ==>  " << m_attacks[i]->getAttackStrength() << "\t\t\t   ";
        if (i < int(m_items.size())) {
         cout << m_items[i]->getName() << "  ==>  " << m_items[i]->getHealValue();
        }
        cout << endl;
      }
      cout << endl;
    }

    private:
    string m_name;
    int m_life;
    int m_strength = 0;
    int m_defense = 0;
    vector<Attack*> m_attacks;
    vector<Item*> m_items;

    // Gets a random attack from the attack's vector list
    Attack* getRandomAttack() {
      return (m_attacks.size() > 1 ?  m_attacks[(rand() % m_attacks.size())] : m_attacks[0]);
    }

    // Gets a random item from the item's vector list
    Item* getRandomItem() {
      return (m_items.size() > 1 ? m_items[(rand() % m_items.size())] : m_items[0]);
    }
};

// Defines a battle class -- the battle class gathers the information of all the intervenients
// and performs the battle, determining its winner
class Battle {
  public:
    // Battle constructor gets the opponents vector list, resets their life to the fullest and prints their information
    // Battle(string name, Character* opponents[], int numOpponents) : m_name(name) {
    Battle(string name, vector<Character*>& opponents) {
      // int numOpponents = sizeof(opponents) / sizeof(opponents[0]);
      // int numOpponents = *(&opponents + 1) - opponents;

      m_opponents = opponents;

      // Revive all opponents to their best shape
      for (auto& opponent : m_opponents) {
        opponent->revive();
      }

      cout << "    -------  BATTLE " << name << "  -------" << endl;

      // After the battle defined, before the battle, prints the information regarding their intervenients
      printBattleOpponents();
    }


    // Prints a horizontal list of all the opponents of the battle
    void printBattleOpponents() const {
      for (auto& opponent : m_opponents) {
        cout << opponent->getName() << " [" << opponent->getLife() << "]";
        if (opponent != m_opponents[m_opponents.size() - 1]) {
          cout << "\tvs.\t";
        }
      }
      cout << endl << endl;
    }

    // Prints the battle history
    void printBattle() {
      int numRound = 1;
      // While there isn't a winner go for another round of attacks
      while (m_opponents.size() > 1) {
        // Each opponent has a round to attack for the order of entrance
        // Change these cycles to iterators
        for (auto itAttacker = m_opponents.begin();  itAttacker < m_opponents.end(); ++itAttacker) {
          // vector<Character*>::iterator attackerIt = m_opponents.begin();
          for (auto itDefender = m_opponents.begin(); itDefender != m_opponents.end(); ++itDefender) {
            if (itAttacker != itDefender) {
              (*itAttacker)->doAttack(*itDefender);
              if ((*itDefender)->getLife() <= 0) {
                cout << "--------->>> " << (*itDefender)->getName() << " died!" << endl;
                m_opponents.erase(itDefender);
                if (itAttacker > itDefender) {
                 --itAttacker; // Adjusts the attacker iterator position
                }
                --itDefender; // So that the attacker can continue its round of attacks
              }
            }
          }
          cout << endl;
        }
        
        // Prints the found winner
        if (m_opponents.size() == 1) {
          cout << endl << "     =======================================" << endl
            << "\t\t" << m_opponents[0]->getName() << " WON!!!" << endl
            << "    =========================================" << endl << endl; 
          break;
        
        // Prints the next round of attacks opponents horixontal list
        } else {
          cout << "    ---------------------  " << ++numRound << "  ------------------------" << endl << endl; 
          printBattleOpponents();
        }
      }
    }

  private:
    string m_name;
    vector<Character*> m_opponents;
    // vector<pair<int, int>> battleGround;
};


int main() {

  vector<Attack*> attacks {
    new Attack("Punch", 33), new Attack("Kick", 38), new Attack("Shout", 17),
    new Attack("Sword To The Face", 29), new Attack("Flame Breath", 50)
  };

  vector<Item*> items {
    new Item("Aspirin", 27), new Item("Bagaço", 50), new Item("Old Grog", 21),
    new Item("Scale Oil", 20), new Item("Breath of Life", 55)
  };

  vector<Attack*> charactAttacks = {attacks[0], attacks[1], attacks[3]};
  vector<Item*> charactItems = {items[0], items[1]};
  
  Character knight("Sir Collin", 15, 10, charactAttacks, charactItems);
  //   {&attacks[0], &attacks[1], &attacks[3]}, {items[0], items[1]});
    // {attack1, attack2, attack4}, {item1, item2});
  // knight.printInfo();

  // vector<Attack*> boboAttacks = {attacks[0], attacks[1], attacks[3]};
  // vector<Item*> boboItems = {items[0], items[1]};

  charactAttacks.clear();
  charactItems.clear();
  charactAttacks = {attacks[0], attacks[1], attacks[3]};
  charactItems = {items[0], items[1]};
  Character bobo("Bobo da Corte", 15, 27, charactAttacks, charactItems);

  // bobo.printInfo();

  // boboItems.clear();

  // Character bobo({&attacks[0], &attacks[1], &attacks[3]});
  // Character knight2 = knight;

  // attacks[0] = attack3;
  // items[1] = item3;

  charactAttacks.clear();
  charactItems.clear();
  charactAttacks = {attacks[1], attacks[2], attacks[4]};
  charactItems = {items[0], items[2]};
  Character mage("Brown Bear", 25, 4, charactAttacks, charactItems);
  //   {attacks[1], attacks[2], attacks[4]}, {items[0], items[2]});
    // {attack2, attack3, attack5}, {item0, item2});
  // mage.printInfo();

  // attacks[0] = attack1;
  // items[0] = item2;
  // items[1] = item2;

  charactAttacks.clear();
  charactItems.clear();
  charactAttacks = {attacks[0], attacks[1], attacks[4]};
  charactItems = {items[1], items[2]};
  Character superman("Superman", 20, 20, charactAttacks, charactItems);
  //   {attacks[0], attacks[1], attacks[4]}, {items[1], items[1]});
    // {attack1, attack2, attack5}, {item2, item2});
  // superman.printInfo();

  charactAttacks.clear();
  charactItems.clear();
  
  knight.printInfo();
  mage.printInfo();
  bobo.printInfo();
  superman.printInfo();

  vector<Character*> opponents = {&knight, &mage, &superman};
  Battle battle1("Multiverse Stand", opponents);

  // battle1.printBattleOpponents();
  battle1.printBattle();
  
/*
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
*/
  opponents.clear();
  opponents = {&knight, &bobo, &mage, &superman};
  Battle battle2("Trafalgar Square", opponents);
  battle2.printBattle();

  return 0;
}