// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DB/DBEntry.h"
#include "CardDBEntry.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CARDGAMEPROTOTYPEUE_API UCardDBEntry : public UDBEntry {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int EnergyPrice;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture* Illustration;

};
