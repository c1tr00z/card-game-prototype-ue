// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CGPCharacterBase.h"
#include "CardGamePrototypeUE/Common/Side.h"
#include "DB/DBEntry.h"
#include "CharactersModuleSettings.generated.h"

USTRUCT(BlueprintType)
struct FCharactersSettings {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<ACGPCharacterBase> CharacterClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<ESide> Side;
};

/**
 * 
 */
UCLASS()
class CARDGAMEPROTOTYPEUE_API UCharactersModuleSettings : public UDBEntry {
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FCharactersSettings> CharactersSettings;
};
