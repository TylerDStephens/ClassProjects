// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Space.h"
#include "Structs.h"
#include "AttackHandler.generated.h"

UCLASS()
class UNREALRISK_API AAttackHandler : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAttackHandler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	//Space to attack from
	UPROPERTY(EditAnywhere)
		ASpace* attacker;

	//Space to attack
	UPROPERTY(EditAnywhere)
		ASpace* defender;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Simulates battle based on parameters and returns the results to be displayed
	UFUNCTION(BlueprintCallable)
		FBattleReport Battle(int aRoll, int dRoll);

	//sets attacker and defender to NULL
	UFUNCTION(BlueprintCallable)
		void ClearSelections();

	//getter for attacker
	UFUNCTION(BlueprintCallable)
		ASpace* GetSelection1();

	//getter for defender
	UFUNCTION(BlueprintCallable)
		ASpace* GetSelection2();

	//Test for if attacker is NULL
	UFUNCTION(BlueprintCallable)
		bool ifFromSelected();

	//setter for attacker
	UFUNCTION(BlueprintCallable)
		void setSelection1(ASpace* space);

	//setter for defender
	UFUNCTION(BlueprintCallable)
		void setSelection2(ASpace* space);
};

