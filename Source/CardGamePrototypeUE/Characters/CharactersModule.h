// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharactersModuleSettings.h"
#include "Modules/AssistLibModule.h"
#include "UObject/Object.h"
#include "CharactersModule.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMEPROTOTYPEUE_API ACharactersModule : public AAssistLibModule {
	GENERATED_BODY()

private:
	UCharactersModuleSettings* Settings;

	TMap<TEnumAsByte<ESide>, ACGPCharacterBase*> CharactersBySide;

public:

	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintPure)
	UCharactersModuleSettings* GetSettings();

	UFUNCTION(BlueprintPure)
	ACGPCharacterBase* GetCharacterBySide(TEnumAsByte<ESide> Side);

	UFUNCTION(BlueprintPure)
	ACGPCharacterBase* GetOpponent(TEnumAsByte<ESide> Side);
};
