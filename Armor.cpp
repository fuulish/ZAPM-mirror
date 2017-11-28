#include "Global.h"
#include "Util.h"
#include "Object.h"
#include "Interface.h"

shVector <shObjectIlk *> ArmorIlks;

shArmorIlk *shHelmet;
shArmorIlk *shJumpsuit;
shArmorIlk *shBodyArmor;
shArmorIlk *shGoggles;
shArmorIlk *shBelt;


void
initializeArmor ()
{
    int n = 0;

    shHelmet = 
    new shArmorIlk ("helmet", "helmet", "helmet", kGray, NULL, kSteel,
                    kIdentified | kEnhanceable, 400, kTiny, 20, 10, 0,
                    0, kNoEnergy, 0, 0, 0, 0, 0);

    new shArmorIlk ("stormtrooper helmet", "helmet", "plastic helmet", 
                    kWhite, 
                    shHelmet, kPlastic,
                    kIdentified | kEnhanceable, 2000, kTiny, 20, 10, -1,
                    1, kNoEnergy, 0, 2000, 5, 50, 25);
    
    new shArmorIlk ("space helmet", "helmet", "sealed helmet",
                    kWhite, shHelmet, kSteel,
                    kIdentified | kEnhanceable, 1000, kTiny, 20, 10, -1,
                    1, kNoEnergy, 20, 2000, 5, 100, 25);

    new shArmorIlk ("football helmet", "helmet", "padded helmet", 
                    kRed, shHelmet, kSteel,
                    kEnhanceable, 400, kTiny, 20, 10, 0,
                    1, kNoEnergy, 0, 1500, 5, 25, 3);

    new shArmorIlk ("psionic helmet", "helmet", "ornate helmet", 
                    kRed, shHelmet, kSteel,
                    kEnhanceable, 400, kTiny, 20, 10, 4,
                    1, kNoEnergy, 0, 1500, 5, 25, 5);

    shArmorIlk *brainshield = 
    new shArmorIlk ("brain shield", "hat", "tinfoil hat", 
                    kRed, shHelmet, kSteel,
                    kEnhanceable, 400, kTiny, 20, 10, -20,
                    0, kNoEnergy, 0, 1500, 5, 25, 5);
    brainshield->mInUseIntrinsics |= kReflection;
    brainshield->mInUseIntrinsics |= kBrainShielded;

    shGoggles = 
    new shArmorIlk ("goggles", "goggles", "goggles", kGray, NULL, kSteel,
                    kIdentified, 400, kTiny, 20, 10, 0, 
                    0, kNoEnergy, 0, 0, 0, 0, 0);

    new shArmorIlk ("pair of sunglasses", "pair of goggles", 
                    "pair of goggles",
                    kYellow, shGoggles, kPlastic,
                    0, 50, kTiny, 5, 1, 0,
                    0, kBlinding, 100, 500, 0, 50, 10);

    shArmorIlk *pss =
    new shArmorIlk ("pair of peril-sensitive sunglasses", "pair of goggles", 
                    "pair of goggles",
                    kYellow, shGoggles, kPlastic,
                    kUsuallyBuggy, 50, kTiny, 5, 1, 0,
                    0, kBlinding, 100, 500, 0, 50, 10);
    pss->mInUseIntrinsics |= kPerilSensing;

    shArmorIlk *blindfold =
    new shArmorIlk ("blindfold", "blindfold", "blindfold",
                    kBrightBlue, shGoggles, kCloth,
                    0, 50, kTiny, 20, 5, 0, 
                    0, kBlinding, 100, 500, 0, 50, 10);
    blindfold->mInUseIntrinsics |= kBlind;

    shArmorIlk *xraygoggles =
    new shArmorIlk ("pair of x-ray goggles", "pair of goggles", 
                    "pair of goggles",
                    kRed, shGoggles, kCloth,
                    0, 50, kTiny, 20, 5, 0,
                    0, kBlinding, 100, 500, 0, 100, 5);
    xraygoggles->mInUseIntrinsics |= kXRayVision;

    new shArmorIlk ("pair of targetter goggles", "pair of goggles", 
                    "pair of goggles",
                    kRed, shGoggles, kCloth,
                    0, 50, kTiny, 20, 5, 0,
                    0, kBlinding, 100, 500, 0, 100, 5);
    /* grants +2 attack and +2 damage bonus to ranged weapons - see Fight.cpp */

    shBelt = 
    new shArmorIlk ("belt", "belt", "belt", kGray, NULL, kSteel,
                    kIdentified, 400, kTiny, 20, 10, 0, 
                    0, kNoEnergy, 0, 0, 0, 0, 0);

    shArmorIlk *shieldbelt =
    new shArmorIlk ("shield belt", "belt", BeltData[n].mDesc,
                    BeltData[n].mColor, shBelt, kSteel,
                    0, 100, kTiny, 5, 1, 0,
                    0, kNoEnergy, 0, 500, 0, 300, 10);
    n++;
    shieldbelt->mInUseIntrinsics |= kShielded;
/*
    shArmorIlk *antigravbelt =
    new shArmorIlk ("jetpack", "belt", BeltData[n].mDesc,
                    BeltData[n].mColor, shBelt, kSteel,
                    kUsuallyBuggy, 100, kTiny, 5, 1, 0,
                    0, kNoEnergy, 0, 500, 0, 300, 10);
    n++;
    antigravbelt->mInUseIntrinsics |= kFlying;
*/  

    n = 0;

    shJumpsuit = 
    new shArmorIlk ("jumpsuit", "jumpsuit", "plaid jumpsuit",
                    kGreen, NULL, kCloth,
                    kEnhanceable, 400, kMedium, 20, 10, 0,
                    1, kNoEnergy, 0, 5000, 0, 0, 0);

    new shArmorIlk ("ordinary jumpsuit", "jumpsuit", JumpsuitData[n].mDesc,
                    JumpsuitData[n].mColor, shJumpsuit, kCloth,
                    kEnhanceable, 400, kMedium, 20, 10, 0,
                    1, kNoEnergy, 0, 5000, 0, 25, 100);
    n++;

    
    new shArmorIlk ("radiation suit", "jumpsuit", JumpsuitData[n].mDesc, 
                    JumpsuitData[n].mColor, shJumpsuit, kCloth,
                    kEnhanceable, 400, kMedium, 20, 10, 0,
                    1, kRadiological, 100, 5000, 0, 100, 40);
    n++;

    new shArmorIlk ("janitor uniform", "jumpsuit", JumpsuitData[n].mDesc,
                    JumpsuitData[n].mColor, shJumpsuit, kCloth,
                    kEnhanceable, 400, kMedium, 20, 10, 0,
                    1, kNoEnergy, 0, 5000, 0, 25, 10);
    n++;

    /* The chameleon suit grants 20% concealment, currently handled
       kludgily in shObject::applyConferredResistances */
    new shArmorIlk ("chameleon suit", "jumpsuit", JumpsuitData[n].mDesc,
                    JumpsuitData[n].mColor, shJumpsuit, kCloth,
                    kEnhanceable, 400, kMedium, 20, 10, 0,
                    1, kNoEnergy, 0, 5000, 0, 500, 5);
    n++;


    shBodyArmor = 
    new shArmorIlk ("armor", "armor", "armor",
                    kBlack, NULL, kCloth,
                    kEnhanceable, 400, kMedium, 20, 10, 0,
                    0, kNoEnergy, 0, 5000, 0, 0, 0);

    shArmorIlk *reflecsuit =
    new shArmorIlk ("suit of reflec armor", "suit of armor",
                    "suit of shiny armor",
                    kBrightCyan, shBodyArmor, kCloth,
                    kEnhanceable, 400, kMedium, 20, 10, 0,
                    1, kLaser, 4, 5000, 0, 100, 80);
    reflecsuit->mInUseIntrinsics |= kReflection;

    new shArmorIlk ("football uniform", "uniform", "padded uniform", 
                    kRed, shBodyArmor, kCloth,
                    kEnhanceable, 5000, kMedium, 20, 10, 0,
                    3, kNoEnergy, 0, 7500, 30, 100, 3);

    new shArmorIlk ("flak jacket", "uniform", "padded uniform", 
                    kYellow, shBodyArmor, kCloth,
                    kIdentified | kEnhanceable, 2500, kMedium, 20, 10, -1,
                    3, kNoEnergy, 0, 5000, 0, 75, 75);

    new shArmorIlk ("stormtrooper suit", "suit of armor", 
                    "suit of plastic armor",
                    kWhite, shBodyArmor, kPlastic,
                    kIdentified | kEnhanceable, 10000, kMedium, 20, 10, -2,
                    4, kNoEnergy, 0, 7500, 10, 400, 25);

    new shArmorIlk ("suit of power armor", "suit of armor", 
                    "suit of mechanical armor", 
                    kYellow, shBodyArmor, kPlasteel,
                    kIdentified | kEnhanceable | kPowered, 
                    15000, kMedium, 25, 15, -2,
                    7, kNoEnergy, 0, 10000, 0, 1500, 10);
    
    new shArmorIlk ("space suit", "space suit", "space suit", 
                    kWhite, shBodyArmor, kSteel, 
                    kIdentified | kEnhanceable | kPowered, 
                    18000, kMedium, 20, 10, -2,
                    4, kNoEnergy, 0, 10000, 100, 800, 25);

/* TODO: dreadnaught armor :-)*/    
}

shArmorIlk::shArmorIlk (char *name, 
                        char *vaguename,
                        char *appearance, 
                        shColor color,
                        shArmorIlk *parent,
                        shMaterialType material,
                        int flags,
                        int weight,
                        shThingSize size,
                        int hardness, 
                        int hp, 
                        int psimod,
                        int bonus,
                        shEnergyType specialtype, 
                        int specialbonus,
                        int equipspeed,
                        int speedpenalty,
                        int cost,
                        int prob)
{
    int i;
    for (i = 0; i < kMaxEnergyType; i++) {
        mResistances[i] = 0;
    }
    ArmorIlks.add (this);
    mType = kArmor;
    mParent = parent;
    mName = name;
    mVagueName = vaguename;
    mAppearance = appearance;
    mGlyph.mChar = ObjectGlyphs[mType].mChar | ColorMap[color];
    mCost = cost;
    mMaterial = material;
    mFlags = flags;// | kEnhanceable;
    mProbability = prob;
    mWeight = weight;
    mSize = size;
    mHardness = hardness;
    mHP = hp;
    mPsiModifier = psimod;
    mArmorBonus = bonus;
    if (kNoEnergy != specialtype) {
        mResistances[specialtype] = specialbonus;
    }
    mEquipSpeed = equipspeed;
    mSpeedPenalty = speedpenalty;
}
    
    






shObject *
createArmor (char *desc,
             int count, int bugginess, int enhancement, int charges)
{
    shArmorIlk *ilk;
    shObject *armor;
    
    ilk = (shArmorIlk *) (NULL == desc ? pickAnIlk (&ArmorIlks) 
                                        : findAnIlk (&ArmorIlks, desc));
    if (NULL == ilk) return NULL;

    armor = new shObject ();
    armor->mIlk = ilk;
    armor->mCount = 1;
    armor->mHP = ilk->mHP;
    
    if (-2 == bugginess) {
        int tmp = RNG (8);
        bugginess = (1 == tmp) ? 1 : (0 == tmp) ? -1 : 0;
        if (kUsuallyBuggy & ilk->mFlags && RNG (9)) {
            bugginess = -1;
        }
    }
    armor->setBugginess (bugginess);

    if (!armor->isEnhanceable ()) {
        armor->mEnhancement = 0;
    } else if (-22 != enhancement) {
        armor->mEnhancement = enhancement;
    } else if (armor->isOptimized ()) {
        armor->mEnhancement = (RNG (5) * RNG (5) + 4) / 5;

        /* +5  1/36  55
           +4  2/36  54 45 
           +3  5/36  35 34 44 43 53
           +2  7/36  23 24 25 33 32 42 52
           +1 10/36  11 12 13 14 15 22 21 31 41 51
           +0 11/36  0* *0
         */
    } else if (armor->isBuggy ()) {
        armor->mEnhancement = RNG (5) * RNG (5) / -5;
    } else { /* debugged */
        armor->mEnhancement = RNG (6) ? RNG (5) * RNG (5) / 5 
                                      : RNG (5) * RNG (5) / -5;
    }

    if (kNoEnergy == armor->vulnerability ()) {
        armor->setFooproofKnown ();
    }

    return armor;
}



