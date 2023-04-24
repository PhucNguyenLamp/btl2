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
    int phoenixdownI;
    BaseBag * bag; // tui doi, 5.6
    KnightType knightType; // loai hiep si

public:
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
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
    virtual bool fight(BaseOpponent * opponent);
};
//dinh nghia lai fight cho dong nay
class PaladinKnight : public BaseKnight {
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
};
class LancelotKnight : public BaseKnight {
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
    int **knightNo;
    string line;
    int numberofKnights;
    int paladinshield=0, lancelotspear=0, GuinevereHair=0,ExcaliburSword=0;
    BaseKnight **knightarray = new BaseKnight*[numberofKnights];
public: 
    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights();
    //danh nhau
    bool fight(BaseOpponent * opponent){
        // if (hiep si con lai dead) return false;
        // else return true;
        return true; //cho no dep
    };
    bool adventure (Events * events);
    int count() const{
        return 2; //them dai vao cho het loi
    };
    BaseKnight * lastKnight() const{
        // if (ko con hiep si) return nullptr;
        // else return hiep si cuoi cung;
        return nullptr; //cho no dep
    };
    
    bool hasPaladinShield() const{
        if (paladinshield>0) return true;
        else return false;
    };
    bool hasLancelotSpear() const{
        if (lancelotspear>0) return true;
        else return false;
    };
    
    bool hasGuinevereHair() const{
        if (GuinevereHair>0) return true;
        else return false;
    };
    bool hasExcaliburSword() const{
        if (ExcaliburSword>0) return true;
        else return false;
    };

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
}
/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
ArmyKnights::ArmyKnights(const string & file_armyknights) {
        ifstream army(file_armyknights);
        getline(army,line);
        numberofKnights = stoi(line);
        // tao mang knights
        
        for (int i=0; i< numberofKnights;i++){
            knightarray[i] = new BaseKnight();
            cin >> knightarray[i]->maxhp >> knightarray[i]->level >> knightarray[i]->phoenixdownI >> knightarray[i]->gil >>knightarray[i]->antidote;
            knightarray[i]->hp = knightarray[i]->maxhp;
        }
    };
ArmyKnights::~ArmyKnights() {
        for (int i=0; i< numberofKnights;i++){
            delete knightarray[i];
        }
        delete [] knightarray;
    };
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