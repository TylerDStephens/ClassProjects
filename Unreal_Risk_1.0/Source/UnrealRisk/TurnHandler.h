// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enums.h"
#include "TurnHandler.generated.h"

UCLASS()
class UNREALRISK_API ATurnHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurnHandler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	//array of enums to represent player colors
	UPROPERTY(EditAnywhere)
		TArray<EColors> colors;

	//enum that represents the current phase of gameplay
	UPROPERTY(EditAnywhere)
		EPhases currentPhase;

	//int that represents the current player who's turn it currently is
	UPROPERTY(EditAnywhere)
		int currentPlayer;

	//int that represents the current player's troops for the reinforcment phase
	UPROPERTY(EditAnywhere)
		int currentReinfTroops;

	//array that represents the difficulties for Ai, [0] = SWISS for the user
	UPROPERTY(EditAnywhere)
		EDifficulties difficulties[6];

	//int that represents the player who goe first
	UPROPERTY(EditAnywhere)
		int firstPlayer;

	//array of strings to be displayed in the HUD
	UPROPERTY(EditAnywhere)
		TArray<FString> names;

	//array of Enums to represent players in the game, for SWISS turns are skipped
	UPROPERTY(EditAnywhere)
		TArray<EPlayers> players;

	//array of ints to keep track of each players reinforcements, to be calculated everytime a space is claimed
	UPROPERTY(EditAnywhere)
		int reinforcements[6];

	//Function for setting parameters set in main menu map, stored in game instance
	UFUNCTION(BlueprintCallable)
	void SetMembers(TArray<FString> nameArray, TArray<FString> colorArray, TArray<FString> diffArray);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Decrements currentReinfTroops
	UFUNCTION(BlueprintCallable)
		void DecCurrentReinfTroops();

	//getter to return colors array
	UFUNCTION(BlueprintCallable)
		TArray<EColors> GetColors();

	//getter for currentPhase
	UFUNCTION(BlueprintCallable)
		EPhases GetCurrentPhase();

	//getter for currentPlayer
	UFUNCTION(BlueprintCallable)
		EPlayers GetCurrentPlayer();

	//getter for the current Player's color
	UFUNCTION(BlueprintCallable)
		EColors GetCurrentPlayerColor();

	//getter for currentReinfTroops
	UFUNCTION(BlueprintCallable)
		int GetCurrentReinfTroops();

	//getter for a given player's difficulty
	UFUNCTION(BlueprintCallable)
		EDifficulties GetDifficulty(int player);

	//getter for firstPlayer
	UFUNCTION(BlueprintCallable)
		int GetFirstPlayer();

	//getter to return names array
	UFUNCTION(BlueprintCallable)
		TArray<FString> GetNames();

	//getter to return players array
	UFUNCTION(BlueprintCallable)
		TArray<EPlayers> GetPlayers();

	//getter for a given player's reinforcments
	UFUNCTION(BlueprintCallable)
		int GetReinforcments(int player);

	//increments phases not handled by IncrementTurn()
	UFUNCTION(BlueprintCallable)
		void IncrementPhase();

	//increments the current turn by incremnting the currentplayer, skipping SWISS players.
	//if it is not the begining phase, sets currentPhase to reinforcment phase.
	UFUNCTION(BlueprintCallable)
		void IncrementTurn();

	//sets the given player, represented by EPlayer, to SWISS
	UFUNCTION(BlueprintCallable)
		void Knockout(EPlayers player);

	//setter for currentPlayer
	UFUNCTION(BlueprintCallable)
		void SetCurrentPlayer(int first);

	//setter for currentReinfTroops
	UFUNCTION(BlueprintCallable)
		void SetCurrentReinfTroops(int value);

	//setter for a given player's reinforcments
	UFUNCTION(BlueprintCallable)
		void SetReinforcments(int player, int value);

};
