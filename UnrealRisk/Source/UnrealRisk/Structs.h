#pragma once
#pragma once

#include "CoreMinimal.h"
#include "Enums.h"
#include "Structs.generated.h"

class ASpace;

//Struct that contains info to be passed to Board.GetSpace()
USTRUCT(Blueprintable)
struct FSpaceLocation
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EConinents cont;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int space;
};

//Struct that contains 2 pointers to spaces, for ai selections
USTRUCT(Blueprintable)
struct FSpacePair
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class ASpace* SelectionOne;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class ASpace* SelectionTwo;
};

//Struct that contains casualty numbers to be returned by AttackHandler.Battle()
USTRUCT(Blueprintable)
struct FBattleReport
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int ACasualties;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int DCasualties;
};

