// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CGPCharacterBase.h"
#include "CharactersModule.h"
#include "CardGamePrototypeUE/Common/Side.h"
#include "UObject/Object.h"
#include "CGPCharactersFunctions.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMEPROTOTYPEUE_API UCGPCharactersFunctions : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static ACharactersModule* GetCharactersModule(UWorld* World);
	
	UFUNCTION(BlueprintPure)
	static ACGPCharacterBase* GetCharacterBySide(UWorld* World, TEnumAsByte<ESide> Side);
};
