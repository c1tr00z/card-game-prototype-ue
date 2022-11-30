// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardDBEntry.h"
#include "CardsModule.h"
#include "UObject/Object.h"
#include "CardFunctions.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMEPROTOTYPEUE_API UCardFunctions : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static ACardsModule* GetCardsModule(UWorld* World);
	
	UFUNCTION(BlueprintCallable)
	static void PlayCard(UWorld* World, UCardDBEntry* CardDBEntry, TEnumAsByte<ESide> CurrentSide);
};
