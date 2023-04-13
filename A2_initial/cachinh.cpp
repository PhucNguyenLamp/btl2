//main.h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;
//knight2.h
enum ItemType {/* TODO: */};

class BaseItem;
class Events;

class BaseBag {
public:
    virtual bool insertFirst(BaseItem * item);
    virtual BaseItem * get(ItemType itemType);
    virtual string toString() const;
};

class BaseOpponent;

enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };
class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    BaseBag * bag;
    KnightType knightType;

public:
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
};

class Paladin : public BaseKnight {
    public:
    Paladin (int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
        this->id = id;
        this->maxhp = maxhp;
        this->level = level;
        this->gil = gil;
        this->antidote = antidote;
        this->bag = nullptr;
        this->knightType = PALADIN;
    }
};

class Lancelot : public BaseKnight {
    public:
    Lancelot (int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
        this->id = id;
        this->maxhp = maxhp;
        this->level = level;
        this->gil = gil;
        this->antidote = antidote;
        this->bag = nullptr;
        this->knightType = LANCELOT;
    }
};

class Dragon : public BaseKnight {
    public:
    Dragon (int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
        this->id = id;
        this->maxhp = maxhp;
        this->level = level;
        this->gil = gil;
        this->antidote = antidote;
        this->bag = nullptr;
        this->knightType = DRAGON;
    }
};

class Normal : public BaseKnight {
    public:
    Normal (int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
        this->id = id;
        this->maxhp = maxhp;
        this->level = level;
        this->gil = gil;
        this->antidote = antidote;
        this->bag = nullptr;
        this->knightType = NORMAL;
    }
};

class ArmyKnights {
public:
    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent * opponent);
    bool adventure (Events * events);
    int count() const;
    BaseKnight * lastKnight() const;

    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;

    void printInfo() const;
    void printResult(bool win) const;
};

class BaseItem {
public:
    virtual bool canUse ( BaseKnight * knight ) = 0;
    virtual void use ( BaseKnight * knight ) = 0;
};

class Events {
public:
    Events ( const string & file_events );
    ~Events();
    int count(string file_events) const{
        ifstream count;
        count.open(file_events);
        int line1;
        cin >> line1;
        return line1;
    };
    int get(int i, string file_events) const{
        ifstream get;
        get.open(file_events);
        string line2;
        getline(get, line2);getline(get, line2);
        stringstream ss(line2);
        for (int j=0; j<i; j++){
            ss >> i;
        }
        return i;
    };
};

class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;

public:
    KnightAdventure();
    ~KnightAdventure(); // TODO:

    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
};

//knight2.cpp

/* * * BEGIN implementation of class BaseBag * * */

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}

/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}

/* * * END implementation of class KnightAdventure * * */

//main.cpp

int main(int argc, char ** argv) {
    string file_armyknights, file_events;
    if (argc == 1) {
        file_armyknights = "tc1_armyknights"; // hard-code
        file_events = "tc1_events";
    }
    else if (argc == 3) {
        file_armyknights = argv[1];
        file_events = argv[2];
    }
    else {
        cout << "Error number of arguments" << endl;
        exit(1);
    }
    
    // BEBGIN
    KnightAdventure * knightAdventure = new KnightAdventure();
    knightAdventure->loadArmyKnights(file_armyknights);
    knightAdventure->loadEvents(file_events);
    knightAdventure->run();

    delete knightAdventure;

    return 0;
}
