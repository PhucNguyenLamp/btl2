///main.h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

///TODO: knight2.h
bool checkprime(int n){
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}
bool checkpythagoras(int number){
    if (number<100) return false; // hp max 999
    int a = pow(number/100,2);
    int b = pow(number/10%10,2);
    int c = pow(number%10,2);
    if (a==b+c || b==a+c || c==a+b) return true;
    return false;
}

enum ItemType {/* TODO: */ ANTIDODE = 0, PHOENIXDOWNI, PHOENIXDOWNII, PHOENIXDOWNIII, PHOENIXDOWNIV };
class BaseItem;
class Events;
class BaseBag {
public:
    virtual bool insertFirst(BaseItem * item);
    virtual BaseItem * get(ItemType itemType);
    virtual string toString() const;
};

class BaseOpponent{
    
};

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
    int phoenixdownI;
    BaseBag * bag; // tui doi, 5.6
    KnightType knightType; // loai hiep si
public:
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
    void updatehp(int hp){
        this->hp = hp;
    }
    int getid() const{
        return id;
    };
    int gethp() const{
        return hp;
    };
    int getmaxhp() const{
        return maxhp;
    };
    int getlevel() const{
        return level;
    };
    int getgil() const{
        return gil;
    };
    int getantidote() const{
        return antidote;
    };
    int getphoenixdownI() const{
        return phoenixdownI;
    };
    KnightType getknightType() const{
        return knightType;
    };
    virtual void fight(BaseOpponent * opponent); //them cho ngựa 🐴🦄
    ~BaseKnight();
};
//dinh nghia lai fight cho dong nay
class PaladinKnight : public BaseKnight {
    public:
    PaladinKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
        this->id = id;
        this->maxhp = maxhp;
        this->hp = maxhp;
        this->level = level;
        this->gil = gil;
        this->antidote = antidote;
        bag = new BaseBag;
        this->knightType = PALADIN;
    }
    void fight(BaseOpponent * opponent);
};
class LancelotKnight : public BaseKnight {
        public:
        LancelotKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
        this->id = id;
        this->maxhp = maxhp;
        this->hp = maxhp;
        this->level = level;
        this->gil = gil;
        this->antidote = antidote;
        bag = new BaseBag;
        this->knightType = LANCELOT;
        }
};
class DragonKnight : public BaseKnight {
        public:
        DragonKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
        this->id = id;
        this->maxhp = maxhp;
        this->hp = maxhp;
        this->level = level;
        this->gil = gil;
        this->antidote = antidote;
        bag = new BaseBag;  
        this->knightType = DRAGON;
    }
};
class NormalKnight : public BaseKnight {
        public:
        NormalKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
        this->id = id;
        this->maxhp = maxhp;
        this->hp = maxhp;
        this->level = level;
        this->gil = gil;
        this->antidote = antidote;
        bag = new BaseBag;
        this->knightType = NORMAL;
        }
};


class ArmyKnights {
private:
    int knightnum;
    BaseKnight **knightarray;
    bool shield=false, spear=false, hair=false, sword=false;
public:
// mong la dc 
    void UpdateTreasure (int &event){
        if (event==95) shield = true;
        else if (event==96) spear = true;
        else if (event==97) hair = true;
        else if (event==98&&spear==true&&hair==true&&shield==true) sword = true;
    }
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

class Antidote : public BaseItem {
    bool canUse ( BaseKnight * knight ){
       // if (poison) return true;
        // return false; 
    }
    void use ( BaseKnight * knight ){
        // antidode--;
    }
};
class PhoenixDownI : public BaseItem {
    bool canUse ( BaseKnight * knight ){
        if (knight->gethp()<=0) return true;
        // return false; 
    }
    void use ( BaseKnight * knight ){
        knight->updatehp(knight->getmaxhp());
        // phoenixdownI--;
        
    }
};
class PhoenixDownII : public BaseItem {
    bool canUse ( BaseKnight * knight ){
        if (knight->gethp()<knight->getmaxhp()/4) return true;
        return false; 
    }
    void use ( BaseKnight * knight ){
        knight->updatehp(knight->getmaxhp());
        // phoenixdownII--;
        
    }
};
class PhoenixDownIII : public BaseItem {
    bool canUse ( BaseKnight * knight ){
        if (knight->gethp()<knight->getmaxhp()/3) return true;
        return false; 
    }
    void use ( BaseKnight * knight ){
        if (knight->gethp()<=0) knight->updatehp(knight->getmaxhp()/3);
        else knight->updatehp(knight->gethp() + knight->getmaxhp()/4);
        // phoenixdownIII--;
    }
};
class PhoenixDownIV : public BaseItem {
    bool canUse ( BaseKnight * knight ){
        if (knight->gethp()<knight->getmaxhp()/2) return true;
        return false; 
    }
    void use ( BaseKnight * knight ){
        if (knight->gethp()<=0) knight->updatehp(knight->getmaxhp()/2);
        else knight->updatehp(knight->gethp() + knight->getmaxhp()/5);
        // phoenixdownIV--;
    }
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
        return arr[i]; //dem tu 0
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
        arr = nullptr;
    };
};

class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;

public:
    KnightAdventure();
    ~KnightAdventure(){
        delete armyKnights;
        delete events;
    }; // TODO:

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
BaseKnight * BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
    BaseKnight *knightType = new BaseKnight;
    if (checkprime(maxhp)) knightType = new PaladinKnight(id, maxhp, level, gil, antidote, phoenixdownI);
    else if (maxhp = 888) knightType = new LancelotKnight(id, maxhp, level, gil, antidote, phoenixdownI);
    else if (checkpythagoras(maxhp)) knightType = new DragonKnight(id, maxhp, level, gil, antidote, phoenixdownI);
    else knightType = new NormalKnight(id, maxhp, level, gil, antidote, phoenixdownI);
}
BaseKnight::~BaseKnight() {
    delete bag;
    bag = nullptr;
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
ArmyKnights::ArmyKnights(const string & file_armyknights) {
    ifstream ifs(file_armyknights);
    ifs >> knightnum;
    knightarray = new BaseKnight*[knightnum];
    int id, maxhp, level, gil, antidote, phoenixdownI;
    for (int i=0; i< knightnum; i++){
        ifs >> id >> maxhp >> level >> gil >> antidote >> phoenixdownI;
        knightarray[i] = BaseKnight::create(id, maxhp, level, gil, antidote, phoenixdownI);
    }
}
ArmyKnights::~ArmyKnights(){
    for (int i=0; i< knightnum; i++){
        delete knightarray[i];
    }
    delete[] knightarray;
    knightarray = nullptr;
}
bool ArmyKnights::fight(BaseOpponent * opponent){
    // doi lam sau
}
bool ArmyKnights::adventure(Events * events){
    int eventNum;
    for (int i=0; i< events->count(); i++){
        eventNum = events->get(i);
    // fight(eventNum);
    // use item();
    printInfo();
    }
    if (knightnum<=0) return false; else return true;
}
int ArmyKnights::count() const{
     return knightnum; // neu chet thi -1
}
BaseKnight * ArmyKnights::lastKnight() const{
    if (knightnum<=0) return nullptr; else return knightarray[knightnum-1];
}
bool ArmyKnights::hasExcaliburSword() const{
    return sword;
}
bool ArmyKnights::hasGuinevereHair() const{
    return hair;
}
bool ArmyKnights::hasLancelotSpear() const{
    return spear;
}
bool ArmyKnights::hasPaladinShield() const{
    return shield;
}
/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}
void KnightAdventure::loadArmyKnights(const string & file_armyknights) {
    armyKnights = new ArmyKnights(file_armyknights);
};
void KnightAdventure::loadEvents(const string & file_events) {
    events = new Events(file_events);
};
void KnightAdventure::run() {
    
};
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