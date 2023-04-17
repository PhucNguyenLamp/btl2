///main.h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

///TODO: knight2.h
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
    //nghich
protected:
    int id; // dinh danh
    int hp;
    int maxhp;
    int level;
    int gil; // tien
    int antidote;
    BaseBag * bag; // tui doi, 5.6
    KnightType knightType; // loai hiep si

public:
        static bool checkprime(int n){
            if (n < 2) return false;
            for (int i = 2; i <= sqrt(n); i++){
                if (n % i == 0) return false;
            }
            return true;
        }
        static bool checkpythagoras(int number){
            if (number<100) return false; // hp co lon hon 1000 dc ko?
            int a = pow(number/100,2);
            int b = pow(number/10%10,2);
            int c = pow(number%10,2);
            if (a==b+c || b==a+c || c==a+b) return true;
            return false;
        }
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
        BaseKnight *knight = new BaseKnight();
        knight->id = id;
        knight->hp = maxhp;
        knight->maxhp = maxhp;
        knight->level = level;
        knight->gil = gil;
        knight->antidote = antidote;
        knight->bag = new BaseBag();
        knight->knightType = NORMAL;
        if (checkprime(maxhp)){knight->knightType = PALADIN;}
        else if (maxhp == 888){knight->knightType = LANCELOT;}
        else if (checkpythagoras(maxhp)) {knight->knightType = DRAGON;}
        else knight->knightType = NORMAL;
        return knight;

    }; // static nen ko can khai obj de call
    
    string toString() const;
};
//dinh nghia lai fight cho dong nay
class PaladinKnight : public BaseKnight {

};
class LancelotKnight : public BaseKnight {

};
class DragonKnight : public BaseKnight {

};
class NormalKnight : public BaseKnight {

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
private:
    int eventsNum;
    int *arr = new int[eventsNum];
public:
    int count() const {
        return eventsNum;
    };
    int get(int i) const {
        return arr[i];
    };
    //todo cua tui hihi
    Events(const string & file_events){
        ifstream ifs(file_events);
        ifs >> eventsNum;
        for(int i = 0; i < eventsNum; i++){
            ifs >> arr[i];
        }
    };
    ~Events(){
        delete[] arr;
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


///TODO: knight2.cpp
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

///main.cpp
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