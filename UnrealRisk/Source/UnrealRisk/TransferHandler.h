// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Space.h"
#include "TransferHandler.generated.h"

UCLASS()
class UNREALRISK_API ATransferHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATransferHandler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	//Space to transfer troops from
	UPROPERTY(EditAnywhere)
		ASpace* selectionFrom;

	//Space to transfer troops to
	UPROPERTY(EditAnywhere)
		ASpace* selectionTo;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//sets selectionFrom and selectionTo to NULL
	UFUNCTION(BlueprintCallable)
		void ClearSelections();

	//getter for selectionFrom
	UFUNCTION(BlueprintCallable)
		ASpace* GetSelection1();

	//getter for selectionTo
	UFUNCTION(BlueprintCallable)
		ASpace* GetSelection2();

	//Test for if selectionFrom is NULL
	UFUNCTION(BlueprintCallable)
		bool ifFromSelected();

	//setter for selectionFrom
	UFUNCTION(BlueprintCallable)
		void setSelection1(ASpace* space);

	//setter for selectionTo
	UFUNCTION(BlueprintCallable)
		void setSelection2(ASpace* space);

	//decrements troops of sectionFrom and increments troops of selectionTo the number of times equal to value
	UFUNCTION(BlueprintCallable)
		void Transfer(int value);

};
