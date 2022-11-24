// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EffectParametersBase.h"
#include "EffectsModule.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EffectsFunctions.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMEPROTOTYPEUE_API UEffectsFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	static AEffectsModule* GetEffectsModule(UWorld* World);
public:
	UFUNCTION(BlueprintCallable)
	static void PlayEffect(UWorld* World, FEffectParametersBase Parameters, ACGPCharacterBase* Target);

	//TEMP solution for localization. Will be changed
	UFUNCTION(BlueprintPure)
	static FString GetLocalizedString(UWorld* World, FEffectParametersBase Parameters);
};
