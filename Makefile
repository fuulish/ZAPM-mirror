# to build a multi-user version, make clean and then make zapm-multiuser
#

OBJS = Global.o Armor.o Artifact.o Attack.o BunkerRooms.o Canister.o	\
Cave.o Corpse.o Creature.o Doctor.o Droid.o Energy.o Event.o Fight.o	\
FloppyDisk.o Game.o God.o Help.o Hero.o Implant.o Interface.o		\
Inventory.o Mainframe.o Map.o Money.o Monster.o MonsterAI.o Mutant.o	\
Object.o ObjectParser.o Options.o Path.o Profession.o RabbitLevel.o	\
RayGun.o Render.o Room.o SaveLoad.o Sewer.o SewerPlant.o Shop.o		\
Skills.o Tombstone.o Tool.o Town.o TwistyRooms.o Util.o Vat.o Vision.o	\
Weapon.o main.o

ZAPMOWNER= appowner
GAMEDIR= "/usr/games"
DATADIR= "/usr/games/lib/zapmdir"

#ARCH = -arch i386 -arch ppc

LIBS= -lpanel -lcurses
INCLUDE=
LDFLAGS= -flat_namespace $(ARCH)
CXX = c++
#CXX= c++-4.0


CXXFLAGS=-Wall -Wno-char-subscripts -O -g $(INCLUDE) $(ARCH)

all: zapm-oneuser

install: zapm-multiuser
	mkdir -p $(GAMEDIR)
	cp zapm $(GAMEDIR)
	mkdir -p $(DATADIR)
	-chown $(ZAPMOWNER) $(DATADIR)
	-chown $(ZAPMOWNER) $(GAMEDIR)/zapm
	chmod 04755 $(GAMEDIR)/zapm
	chmod 04755 $(DATADIR)

zdebug: oneuser zapm
	mkdir -p build
	mkdir -p build/zapm
	mkdir -p build/zapm/user
	cp zapm build/zapm/

zapm-oneuser: oneuser zapm
	mkdir -p build
	mkdir -p build/zapm
	mkdir -p build/zapm/user
	cp zapm build/zapm/
	strip build/zapm/zapm
	cp docs/Guide.txt build/zapm
	tar czf zapm.tar.gz -C build zapm

zapm-multiuser: multiuser zapm

zapm-win32: win32/Release/zapm.exe
	mkdir -p win32/build/zapm/user
	cp win32/Release/zapm.exe win32/build/zapm/
	cp docs/Guide.txt win32/build/zapm
	rm -f zapm.zip
	cd win32/build && zip -r ../zapm.zip zapm 

zapm: $(OBJS)
	c++ -g -o zapm $(LDPATH) $(LDFLAGS) $(LIBS) $(OBJS)

debug: $(OBJS)
	c++ -g -o zapm $(LDPATH) $(LDFLAGS) $(LIBS) $(OBJS) $(DEBUGLIBS)

clean:
	rm -f zapm *.o config.h dbg.txt gmon.out

cleaner: clean
	rm -f *~ \#*\#

#$(OBJS) : config.h
Monster.o : MonsterData.h

multiuser :
	echo "/* this file is automatically generated!! */ " > config.h
	echo '#define DATADIR $(DATADIR)' >> config.h

oneuser :
	echo "/* this file is automatically generated!! */ " > config.h
	echo '#define DATADIR "user"' >> config.h

MonsterData.h : monsters.dat monsters.pl
	./monsters.pl > MonsterData.h
