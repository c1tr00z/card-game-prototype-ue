// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EffectParametersBase.h"
#include "CardGamePrototypeUE/Characters/CGPCharacterBase.h"
#include "EffectProcessorBase.generated.h"

UCLASS(Abstract)
class CARDGAMEPROTOTYPEUE_API UEffectProcessorBase : public UObject {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UEffectProcessorBase();

	UFUNCTION(BlueprintCallable)
	virtual UStruct* GetParametersUStruct();

public:
	UFUNCTION(BlueprintCallable)
	virtual void PlayEffect(FEffectParametersBase Parameters, ACGPCharacterBase* Target);
};
