// Fill out your copyright notice in the Description page of Project Settings.


#include "Space.h"
#include <vector>

// Sets default values
ASpace::ASpace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ownr = EPlayers::SWISS;
	troops = 1;
	eventBool = true;
	pauseBool = true;
	visited = false;

}

// Called when the game starts or when spawned
void ASpace::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpace::ClaimSpace(EPlayers newOwner)
{
	ownr = newOwner;
}

EPlayers ASpace::GetOwnr()
{
	return ownr;
}

int ASpace::GetTroops()
{
	return troops;
}

AActor* ASpace::GetMarker()
{
	return marker;
}

void ASpace::EventOff() 
{
	eventBool = false;
}

void ASpace::EventOn()
{
	eventBool = true;
}

bool ASpace::GetEventBool()
{
	return eventBool;
}

void ASpace::PauseOff()
{
	pauseBool = false;
}

void ASpace::PauseOn()
{
	pauseBool = true;
}

bool ASpace::GetPauseBool()
{
	return pauseBool;
}

TArray<ASpace*> ASpace::GetConnections()
{
	return connections;
}

void ASpace::IncrementTroops()
{
	troops++;
}

void ASpace::DecrementTroops()
{
	troops--;
}

bool ASpace::IsBorder(EPlayers player)
{
	for (ASpace* space : connections) 
	{
		if (this->GetOwnr() == player && this->GetOwnr() != space->GetOwnr())
		{
			return true;
		}
	}
	return false;
}

void ASpace::TurnOnGlobalConnectionEvents()
{
	this->EventOn();

	for (auto node : connections)
	{
		if (node->GetOwnr() == this->GetOwnr() &&
			node->GetEventBool() == false)
		{
			node->TurnOnGlobalConnectionEvents();
		}
	}

}

void ASpace::TurnOnBattleEvents()
{
	this->EventOn();

	for (auto node : connections)
	{
		if (node->GetOwnr() != this->GetOwnr())
		{
			node->EventOn();
		}
	}
}

void ASpace::EnableVisited()
{
	visited = true;
}

bool ASpace::GetVisited()
{
	return visited;
}

void ASpace::DisableVisited()
{
	visited = false;
}