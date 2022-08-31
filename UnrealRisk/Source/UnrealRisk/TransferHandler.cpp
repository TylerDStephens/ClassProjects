// Fill out your copyright notice in the Description page of Project Settings.


#include "TransferHandler.h"

// Sets default values
ATransferHandler::ATransferHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATransferHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATransferHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATransferHandler::Transfer(int value)
{
    for (int i = 0; i < value; i++)
    {
        selectionFrom->DecrementTroops();
        selectionTo->IncrementTroops();
    }
}

void ATransferHandler::setSelection1(ASpace* space)
{
    selectionFrom = space;
}

void ATransferHandler::setSelection2(ASpace* space)
{
    selectionTo = space;
}


ASpace* ATransferHandler::GetSelection1()
{
    return selectionFrom;
}

ASpace* ATransferHandler::GetSelection2()
{
    return selectionTo;
}

bool ATransferHandler::ifFromSelected()
{
    if (selectionFrom == NULL)
    {
        return false;
    }

    return true;
}

void ATransferHandler::ClearSelections()
{
    selectionFrom = NULL;
    selectionTo = NULL;
}