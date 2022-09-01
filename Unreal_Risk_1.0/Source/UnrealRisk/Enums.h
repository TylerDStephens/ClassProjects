#pragma once

#include "CoreMinimal.h"
#include "Enums.generated.h"

//AI difficulties, SWISS for USER and inactive AI
UENUM(BlueprintType)
enum class EDifficulties : uint8
{
	EASY,	//0
	HARD,	//1
	SWISS,	//2
};

//Colors, SWISS for inactive AI
UENUM(BlueprintType)
enum class EColors : uint8
{
	PINK,		//0
	RED,		//1
	ORANGE,		//2
	YELLOW,		//3
	GREEN,		//4
	LIGHT_BLUE,	//5
	BLUE,		//6
	VIOLET,		//7
	SWISS,		//8
};

//Player ID's, SWISS for inactive AI
UENUM(BlueprintType)
enum class EPlayers : uint8
{
	USER,		//0
	AI_ONE,		//1
	AI_TWO,		//2
	AI_THREE,	//3
	AI_FOUR,	//4
	AI_FIVE,	//5
	SWISS,		//6
};

//Phases
UENUM(BlueprintType)
enum class EPhases : uint8
{
	BEGIN,		//0:Begining
	REINF,		//1:Troop Reinforcement
	ATTACK,		//2:Attack
	TRANS,		//3:Troop Transfer
};

//continents
UENUM(BlueprintType)
enum class EConinents : uint8
{
	NAMER,		//0:North America
	SAMER,		//1:South America
	AFRICA,		//2:Africa
	EUROPE,		//3:Europe
	ASIA,		//4:Asia
	AUSTR,		//5:Austrailia
};


//North America Spaces
UENUM(BlueprintType)
enum class ENA_Spaces : uint8
{
	ALASKA,		//0:Alaska
	NWTER,		//1:Northwest Territory
	ALBER,		//2:Alberta
	ONTAR,		//3:Ontario
	QUEBEC,		//4:Quebec
	GRLAND,		//5:Greenland
	WESTUS,		//6:Western US
	EASTUS,		//7:Eastern US
	CENAMR,		//8:Central America
};

//South America Spaces
UENUM(BlueprintType)
enum class ESA_Spaces : uint8
{
	VENEZ,		//0:Venezuela
	BRAZIL,		//1:Brazil
	PERU,		//2:Peru
	ARGENT,		//3:Argentina
};

//Africa Spaces
UENUM(BlueprintType)
enum class EAF_Spaces : uint8
{
	NORTHA,		//0:North Africa
	SOUTHA,		//1:South Africa
	EASTA,		//2:East Africa
	EGYPT,		//3:Egypt
	CONGO,		//4:Congo
	MADAGA,		//5:Madagascar
};

//Europe Spaces
UENUM(BlueprintType)
enum class EEU_Spaces : uint8
{
	ICELAN,		//0:Iceland
	BRIT,		//1:Great Britain
	SCANDA,		//2:Scandinavia
	UKRAN,		//3:Ukraine
	NORTEU,		//4:Northern Europe
	SOUTEU,		//5:Southern Europe
	WESTEU,		//6:Western Europe
};

//Asia Spaces
UENUM(BlueprintType)
enum class EAS_Spaces : uint8	
{
	MEAST,		//0:Middle East
	AFGHAN,		//1:Afghanistan
	INDIA,		//2:India
	SIAM,		//3:Siam
	CHINA,		//4:China
	URAL,		//5:Ural
	SIBER,		//6:Siberia
	YAKU,		//7:Yakutsk
	IRKU,		//8:Irkutsk
	MONGO,		//9:Mongolia
	KAMCHA,		//10:Kamchatka
	JAPAN,		//11:Japan
};

//Austrailia Spaces
UENUM(BlueprintType)
enum class EAU_Spaces : uint8
{
	INDO,		//0:Indonesia
	NEWGUI,		//1:New Guinea
	WESTAU,		//2:Western Austrailia
	EASTAU,		//3:Eastern Austrailia
};