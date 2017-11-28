#ifndef HERO_H
#define HERO_H

#include "Global.h"
#include "Util.h"
#include "Creature.h"
#include "Monster.h"


struct shStoryFlag 
{ 
    char *mName;
    int mValue; 
    shStoryFlag () {}
    shStoryFlag (char *name, int value) 
    { 
        mName = strdup (name);
        mValue = value; 
    }
};


class shHero : public shCreature
{
    friend struct shInterface;

    int mXP;
    int mScore;
    int mBusy;
    shVector <shStoryFlag *> mStoryFlags;
    
 public:
    shVector <shCreature *> mPets;

    void saveState (int fd);
    void loadState (int fd);

    int isHero () { return 1; }

    void init (char *name, shProfession *profession);

    char *the (char *buff, int buflen);
    char *an (char *buff, int buflen);
    char *your (char *buff, int buflen);
    char *getDescription (char *buff, int len);

    int numHands () { return mIlk->mNumHands; }

    int die (shCauseOfDeath how, char *killer = NULL);
    int die (shCauseOfDeath how, shCreature *killer);
    void deathMessage (char *buf, int len, 
                       shCauseOfDeath how, char *killer = NULL);
    void tallyScore ();
    void tomb (char *message);
    void logGame (char *message);

    int addObjectToInventory (shObject *obj, int quiet = 0);

    int wield (shObject *obj, int quiet = 0);
    int unwield (shObject *obj, int quiet = 0);
        
    void earnXP (int challenge);
    void earnScore (int points);
    void gainAbility ();

    void newLocation ();
    void lookAtFloor (int menuok = 0);
    int getStoryFlag (char *name) { 
        int i;
        for (i = 0; i < mStoryFlags.count (); i++) {
            if (0 == strcmp (name, mStoryFlags.get (i) -> mName)) {
                return mStoryFlags.get (i) -> mValue;
            }
        }
        return 0;
    }

    void setStoryFlag (char *name, int value) {
        int i;
        for (i = 0; i < mStoryFlags.count (); i++) {
            if (0 == strcmp (name, mStoryFlags.get (i) -> mName)) {
                mStoryFlags.get (i) -> mValue = value;
                return;
            }
        }
        mStoryFlags.add (new shStoryFlag (name, value));
    }

    void resetStoryFlag (char *name) {
        setStoryFlag (name, 0);
    }

    shObject *quickPickItem (shObjectVector *v, char *action, 
                             int flags, int *count = NULL);

    int interrupt ();  /* returns 0 if hero was busy */

    int instantUpkeep ();

    void doGodMode ();

    int tryToTranslate (shCreature *c);

    void enterShop ();    
    void leaveShop ();
    void pickedUpItem (shObject *obj);
    void usedUpItem (shObject *obj, int cnt, const char *action);
    void maybeSellItem (shObject *obj);
    void payShopkeeper ();

    void checkForFollowers (shMapLevel *level, int sx, int sy);
    int displace (shCreature *c);
    int doMove (shDirection dir);
    void drop (shObject *obj);
    int kick (shDirection dir);
    void reorganizeInventory ();
    void listInventory ();
    void feel (int x, int y, int force = 0);
    void spotStuff ();

    void editSkills (int points);

    void quaffFromVat (shFeature *vat);

    shMutantPower getMutantPower (shMutantPower power = kNoMutantPower,
                                  int silent = 0);

    int useMutantPower ();

    /* fighting functions; see Fight.cpp */
    int meleeAttack (shObject *weapon, shDirection dir);

    void upkeep ();
    void takeTurn ();
};

int quaffGainAbility (shObject *can);

#endif




