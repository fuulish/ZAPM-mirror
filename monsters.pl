#!/usr/bin/perl -W

# script to generate MonsterIlk constructors from datafile
# input: monsters.dat
# output: Monsters.inc

open (MF, "<", "monsters.dat");

print "/*****************************************************************\n";
print " *      This file is AUTOMATICALLY GENERATED by monsters.pl      *\n";
print " *      DO NOT EDIT IT BY HAND!                                  *\n";
print " *****************************************************************/\n";

while ($_ = <MF>) {
    next if /\#/;

    $atktype = 0;
    $atkeffect = "Single";
    $range = 0;

    if (/^\+/) {
	/^\+\s+(\S.+)/;
	print "cur->addEquipment(\"$1\");\n";
    } elsif (/^\!/) {
	/^\!\s+(\S+)\s+(\d+)/;
	print "cur->addResistance(k$1, $2);\n";
    } elsif (/^\@/) {
	/^\@\s+(\S+)/;
	print "cur->addIntrinsic(k$1);\n";
    } elsif (/^\~/) {
	/^\~\s+(\S+)/;
	print "cur->addMutantPower(k$1);\n";
    } elsif (/^\*/) {
	($ignore, $atktype, $entype, $damage, 
	 $prob, $rcov, $secen, $secdmg) = split;
	$atkeffect = "Beam";
	$range = 6;
	$ignore++;
    } elsif (/^\s/) {
	($atktype, $entype, $damage, $prob, $rcov, $secen, $secdmg) = split;
    } else {
    	($name, $sym, $color, $type, $rarity, $numapp, $size, $hd, $lvl,
	 $str, $con, $agi, $dex, $int, $wis, $cha, 
	 $speed, $numhands, $ac, $strategy, $peaceful,
	 $atktype, $entype, $damage, $prob, $rcov, $secen, $secdmg)
	    = split;

	next if $name eq "";
    
	$name =~ s/_/ /g;

	if ($numapp =~ /(\d+)d(\d+)/) {
	    ($nad, $nads) = ($1, $2);
	} else {
	    $nad = $numapp;
	    $nads = 1;
	}
	
	print "cur = new shMonsterIlk (\"$name\", k$type, NULL, k$size, $hd, $lvl, ";
	print "$str, $con, $agi, $dex, $int, $wis, $cha, $speed, $numhands, $ac, ";
	print "$nad, $nads, shMonster::k$strategy, $peaceful, $rarity, ";
	print "'$sym', k$color);\n";
    }

    if ($atktype) {
	if ($damage =~ /(\d+)d(\d+)/)  {
	    ($nad, $nads) = ($1, $2);
	} else {
	    $nad = $numapp;
	    $nads = 1;
	}

	if ($range) {
	    print "cur->addRangedAttack (shAttack::k$atktype, shAttack::k$atkeffect, k$entype, $nad, $nads, $rcov, $range, $prob";
	} else {
	    print "cur->addAttack (shAttack::k$atktype, k$entype, $nad, $nads, $rcov, $prob";
	}
	if ($secen) {
	    if ($secdmg =~ /(\d+)d(\d+)/) {
		($nad, $nads) = ($1, $2);
	    } else {
		$nad = $secdmg;
		$nads = 1;
	    }
	    print ", k$secen, $nad, $nads";
	}

	print ");\n";

    }
}
