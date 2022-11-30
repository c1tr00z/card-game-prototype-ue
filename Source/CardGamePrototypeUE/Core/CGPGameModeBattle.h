// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CGPGameModeBase.h"
#include "UObject/Object.h"
#include "CGPGameModeBattle.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMEPROTOTYPEUE_API ACGPGameModeBattle : public ACGPGameModeBase {
	GENERATED_BODY()

private:
	FTimerHandle TurnTimerHandle;

private:
	void BeginTurn();

	void EndTurn();

protected:
	virtual void BeginPlay() override;
};
