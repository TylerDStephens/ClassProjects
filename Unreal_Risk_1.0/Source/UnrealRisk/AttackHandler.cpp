// Fill out your copyright notice in the Description page of Project Settings.

#include "AttackHandler.h"
#include <algorithm>
#include <vector>

// Sets default values
AAttackHandler::AAttackHandler()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAttackHandler::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AAttackHandler::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

FBattleReport AAttackHandler::Battle(int aRoll, int dRoll)
{
    //Attacker Roll array
    std::srand(std::time(0));
    std::vector<int> attackerArray(aRoll, 0);
    for (int i = 0; i < aRoll; i++) {
        attackerArray[i] = std::rand() % 6 + 1;
    }
    //Defender Roll array
    std::vector<int> defenderArray(dRoll, 0);
    for (int j = 0; j < dRoll; j++) {
        defenderArray[j] = std::rand() % 6 + 1;
    }
    std::sort(attackerArray.begin(), attackerArray.end());
    std::sort(defenderArray.begin(), defenderArray.end());
    int temp = 0;
    if (aRoll > dRoll) {
        temp = dRoll;
    }
    else
        temp = aRoll;
    FBattleReport report;
    report.ACasualties = 0;
    report.DCasualties = 0;
    for (int k = temp-1; k >= 0; k--) {
        if (attackerArray[k] > defenderArray[k]) 
        {
            defender->DecrementTroops();
            report.DCasualties++;
        }
        else
        {
            attacker->DecrementTroops();
            report.ACasualties++;
        }
    }
    return report;
}

void AAttackHandler::setSelection1(ASpace* space)
{
    attacker = space;
}

void AAttackHandler::setSelection2(ASpace* space)
{
    defender = space;
}


ASpace* AAttackHandler::GetSelection1()
{
    return attacker;
}

ASpace* AAttackHandler::GetSelection2()
{
    return defender;
}

bool AAttackHandler::ifFromSelected()
{
    if (attacker == NULL)
    {
        return false;
    }

    return true;
}

void AAttackHandler::ClearSelections()
{
    attacker = NULL;
    defender = NULL;
}


