// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealRiskPlayerController.h"

void AUnrealRiskPlayerController::BeginPlay()
{
    Super::BeginPlay();
    SetInputMode(FInputModeGameAndUI());
}
