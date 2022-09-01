// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnHandler.h"

// Sets default values
ATurnHandler::ATurnHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	srand(time(0));
	firstPlayer = (rand() % 6);
	currentPlayer = firstPlayer;
	currentPhase = EPhases::BEGIN;
	currentReinfTroops = 0;

	for (int i = 0; i < 6; i++)
	{
		reinforcements[i] = 3;
	}

}

// Called when the game starts or when spawned
void ATurnHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurnHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ATurnHandler::GetFirstPlayer()
{
	return firstPlayer;
}

EPlayers ATurnHandler::GetCurrentPlayer()
{
	EPlayers value = static_cast<EPlayers>(currentPlayer);
	return value;
}

EColors ATurnHandler::GetCurrentPlayerColor()
{
	return colors[currentPlayer];
}

EPhases ATurnHandler::GetCurrentPhase() 
{
	return currentPhase;
}

void ATurnHandler::IncrementTurn()
{
	
	currentPlayer++;
	if (currentPlayer >= 6)
	{
		currentPlayer = 0;
	}
	while (players[currentPlayer] == EPlayers::SWISS) 
	{
		currentPlayer++;
		if (currentPlayer >= 6)
		{
			currentPlayer = 0;
		}
	}

	if (currentPhase == EPhases::TRANS)
	{
		currentPhase = EPhases::REINF;
	}
	
}

void ATurnHandler::IncrementPhase()
{
	if (currentPhase == EPhases::BEGIN)
	{
		currentPhase = EPhases::REINF;
	}
	else if (currentPhase == EPhases::REINF)
	{
		currentPhase = EPhases::ATTACK;
	}
	else if (currentPhase == EPhases::ATTACK)
	{
		currentPhase = EPhases::TRANS;
	}
}

void ATurnHandler::Knockout(EPlayers player)
{
	players[(int)player] = EPlayers::SWISS;
}

void ATurnHandler::SetMembers(TArray<FString> nameArray, TArray<FString> colorArray, TArray<FString> diffArray)
{
	for (int i = 0; i < 6; i++)
	{
		names.Add(nameArray[i]);
	}

	players.Add(EPlayers::USER);
	players.Add(EPlayers::AI_ONE);
	if (nameArray[2] != "SWISS") 
	{
		players.Add(EPlayers::AI_TWO);
	}
	else
	{
		players.Add(EPlayers::SWISS);
	}

	if (nameArray[3] != "SWISS")
	{
		players.Add(EPlayers::AI_THREE);
	}
	else
	{
		players.Add(EPlayers::SWISS);
	}

	if (nameArray[4] != "SWISS")
	{
		players.Add(EPlayers::AI_FOUR);
	}
	else
	{
		players.Add(EPlayers::SWISS);
	}

	if (nameArray[5] != "SWISS")
	{
		players.Add(EPlayers::AI_FIVE);
	}
	else
	{
		players.Add(EPlayers::SWISS);
	}
	
	for (int i = 0; i < 6; i++) 
	{
		if (colorArray[i] == "Pink")
		{
			colors.Add(EColors::PINK);
		}
		else if (colorArray[i] == "Red")
		{
			colors.Add(EColors::RED);
		}
		else if (colorArray[i] == "Orange")
		{
			colors.Add(EColors::ORANGE);
		}
		else if (colorArray[i] == "Yellow")
		{
			colors.Add(EColors::YELLOW);
		}
		else if (colorArray[i] == "Green")
		{
			colors.Add(EColors::GREEN);
		}
		else if (colorArray[i] == "Light Blue")
		{
			colors.Add(EColors::LIGHT_BLUE);
		}
		else if (colorArray[i] == "Blue")
		{
			colors.Add(EColors::BLUE);
		}
		else if (colorArray[i] == "Violet")
		{
			colors.Add(EColors::VIOLET);
		}
		else 
		{
			colors.Add(EColors::SWISS);
		}
	}

	for (int i = 0; i < 6; i++) 
	{
		if (diffArray[i] == "Easy")
		{
			difficulties[i] = EDifficulties::EASY;
		}
		else if (diffArray[i] == "Hard")
		{
			difficulties[i] = EDifficulties::HARD;
		}
		else
		{
			difficulties[i] = EDifficulties::SWISS;
		}
	}
}

void ATurnHandler::SetCurrentPlayer(int first)
{
	currentPlayer = first;
}

void ATurnHandler::SetCurrentReinfTroops(int value)
{
	currentReinfTroops = value;
}

int ATurnHandler::GetCurrentReinfTroops()
{
	return currentReinfTroops;
}

EDifficulties ATurnHandler::GetDifficulty(int player)
{
	return difficulties[player];
}

void ATurnHandler::DecCurrentReinfTroops()
{
	currentReinfTroops--;
}

TArray<EPlayers> ATurnHandler::GetPlayers()
{
	return players;
}

TArray<FString> ATurnHandler::GetNames()
{
	return names;
}

TArray<EColors> ATurnHandler::GetColors()
{
	return colors;
}

void ATurnHandler::SetReinforcments(int player, int value)
{
	reinforcements[player] = value;
}

int ATurnHandler::GetReinforcments(int player)
{
	return reinforcements[player];
}