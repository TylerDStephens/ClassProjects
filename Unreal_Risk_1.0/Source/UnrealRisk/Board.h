// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Space.h"
#include "Enums.h"
#include "Structs.h"
#include <limits>
#include "Board.generated.h"

UCLASS()
class UNREALRISK_API ABoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	
	//array of spaces for Africa
	UPROPERTY(EditAnywhere)
		TArray<ASpace*> afSpaces;

	//array of spaces for Asia
	UPROPERTY(EditAnywhere)
		TArray<ASpace*> asSpaces;

	//array of spaces for Austrailia
	UPROPERTY(EditAnywhere)
		TArray<ASpace*> auSpaces;

	//array of spaces for Europe
	UPROPERTY(EditAnywhere)
		TArray<ASpace*> euSpaces;

	//array of spaces for North America
	UPROPERTY(EditAnywhere)
		TArray<ASpace*> naSpaces;

	//array of spaces for South America
	UPROPERTY(EditAnywhere)
		TArray<ASpace*> saSpaces;

	//recursive helper function for GetBordersConnectedToSpace()
	UFUNCTION(BlueprintCallable)
		void GBCSHelper(TArray<ASpace*>& arry, ASpace* space);

	//returns all array of boarder spaces that this space is able to transfer to. Used in GetTransferPair()
	UFUNCTION(BlueprintCallable)
		TArray<ASpace*> GetBordersConnectedToSpace(ASpace* space);

	//finds and returns lowest amount of troops in a space located on a border owned by the current player
	UFUNCTION(BlueprintCallable)
		int GetLowestBorderValue(EPlayers currentPlayer);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Calculates and returns reinforcements for the given player
	UFUNCTION(BlueprintCallable)
		int CalculateReinforcements(int player);

	//Checks if the given player has been knocked out when they lose a territory
	UFUNCTION(BlueprintCallable)
		bool CheckForKnockout(EPlayers losingPlayer);

	//checks if there are spaces owned by SWISS, indicating that the Begining phase has not ended yet
	UFUNCTION(BlueprintCallable)
		bool CheckForUnclaimed();

	//checks if a single player owns every space, indicating a win state
	UFUNCTION(BlueprintCallable)
		bool CheckForWinner();

	//Easy AI space selection for the space to attack from, will attack if troops are equal to a connection's troops, 
	//that is owned by another player
	UFUNCTION(BlueprintCallable)
		ASpace* EasyAttackAiSelectAttackSpace(EPlayers currentPlayer);

	//Easy AI space selection for the space to attack
	UFUNCTION(BlueprintCallable)
		ASpace* EasyAttackAiSelectDeffendSpace(ASpace* attackSpace);

	//Easy AI beging phase space selection. Selects a random space owned by SWISS
	UFUNCTION(BlueprintCallable)
		FSpaceLocation EasyBeginAiSelectSpace();

	//Easy AI reinforcement phase space selection. Selects a boarder space who's troops equal GetLowestBorderValue()
	UFUNCTION(BlueprintCallable)
		FSpaceLocation EasyReinfAiSelectSpace(EPlayers currentPlayer);

	//Returns the space on the board determined by continent enum and space int
	UFUNCTION(BlueprintCallable)
		ASpace* GetSpace(EConinents cont, int space);

	//Ai function to select spaces to transfer troops to and from
	UFUNCTION(BlueprintCallable)
		FSpacePair GetTransferPair(EPlayers currentPlayer);

	//Hard AI space selection for the space to attack from, will attack if troops are greater than all of it's connection's troops, 
	//that are owned by another player
	UFUNCTION(BlueprintCallable)
		ASpace* HardAttackAiSelectAttackSpace(EPlayers currentPlayer);

	//Hard AI space selection for the space to attack
	UFUNCTION(BlueprintCallable)
		ASpace* HardAttackAiSelectDeffendSpace(ASpace* attackSpace);

	//Hard AI beging phase space selection. Tries to find an available space connected to spaces the current player already owns. 
	//if not possible returns EasyBeginAiSelectSpace()
	UFUNCTION(BlueprintCallable)
		ASpace* HardBeginAiSelectSpace(EPlayers currentPlayer);

	//Ai check to see if their are any extra troops that are not on the border for the given player, 
	//if true then the ai knows to start the transfer process
	UFUNCTION(BlueprintCallable)
		bool SearchForNonBorderExtraTroops(EPlayers currentPlayer);

	//turns off eventBool for every space
	UFUNCTION(BlueprintCallable)
		void TurnOffBoardEvents();
	
	//turns on eventBool for every space the user owns that lies on their border
	UFUNCTION(BlueprintCallable)
		void TurnOnBorderEvents();

	//turns on eventBool for every space the user owns
	UFUNCTION(BlueprintCallable)
		void TurnOnPlayerSpaceEvents();

	//turns on eventBool for every space the user owns that has more than one troops
	UFUNCTION(BlueprintCallable)
		void TurnOnPlayerTransferEvents();

	//turns off eventBool for every space who's ownr is SWISS
	UFUNCTION(BlueprintCallable)
		void TurnOnUnclaimedEvents();
};
