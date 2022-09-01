// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enums.h"
#include "Structs.h"
#include "Space.generated.h"

UCLASS()
class UNREALRISK_API ASpace : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpace();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	//array of spaces representing the spaces connected to this space
	UPROPERTY(EditAnywhere)
		TArray<ASpace*> connections;

	//bool to gate mouse events while game is running
	UPROPERTY(EditAnywhere)
		bool eventBool;

	//actor to contain visual lable and troops value objects to be placed above the space's static mesh
	UPROPERTY(EditAnywhere)
		AActor* marker;

	//Enum to represent the player who owns this space
	UPROPERTY(EditAnywhere)
		EPlayers ownr;

	//bool to gate mouse events while game is paused
	UPROPERTY(EditAnywhere)
		bool pauseBool;
	
	//int representing the amount of troops this space contains
	UPROPERTY(EditAnywhere)
		int troops;

	//bool for ai transfer algorithm in board.cpp
	UPROPERTY(EditAnywhere)
		bool visited;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//sets ownr to the given enum
	UFUNCTION(BlueprintCallable)
		void ClaimSpace(EPlayers newOwner);

	//decrements troops by 1
	UFUNCTION(BlueprintCallable)
		void DecrementTroops();

	//sets visited to false;
	UFUNCTION(BlueprintCallable)
		void DisableVisited();

	//sets visited to true;
	UFUNCTION(BlueprintCallable)
		void EnableVisited();

	//sets eventBool to false;
	UFUNCTION(BlueprintCallable)
		void EventOff();

	//sets eventBool to true;
	UFUNCTION(BlueprintCallable)
		void EventOn();

	//getter for connections array
	UFUNCTION(BlueprintCallable)
		TArray<ASpace*> GetConnections();

	//getter for eventBool
	UFUNCTION(BlueprintCallable)
		bool GetEventBool();

	//getter for the marker object
	UFUNCTION(BlueprintCallable)
		AActor* GetMarker();

	//getter for ownr
	UFUNCTION(BlueprintCallable)
		EPlayers GetOwnr();

	//getter for pauseBool
	UFUNCTION(BlueprintCallable)
		bool GetPauseBool();

	//getter for troops
	UFUNCTION(BlueprintCallable)
		int GetTroops();

	//getter for visited
	UFUNCTION(BlueprintCallable)
		bool GetVisited();

	//increments troops
	UFUNCTION(BlueprintCallable)
		void IncrementTroops();

	//returns wiether or not one the space's connections belongs to another player other than this space's ownr
	UFUNCTION(BlueprintCallable)
		bool IsBorder(EPlayers player);

	//sets pauseBool to false
	UFUNCTION(BlueprintCallable)
		void PauseOff();

	//sets pauseBool to true
	UFUNCTION(BlueprintCallable)
		void PauseOn();

	//turns on eventBool for this space's connections that belong to another player other than this space's ownr, for attacking
	UFUNCTION(BlueprintCallable)
		void TurnOnBattleEvents();

	//turns on eventBool for every space this space is directly and indirectly connected to that is owned by this space's ownr, 
	//and that does not cross a space owned by another player otehr that this space's ownr. for transfering
	UFUNCTION(BlueprintCallable)
		void TurnOnGlobalConnectionEvents();
};
