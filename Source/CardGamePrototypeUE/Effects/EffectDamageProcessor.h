// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EffectProcessorBase.h"
#include "EffectDamageProcessor.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CARDGAMEPROTOTYPEUE_API AUEffectDamageProcessor : public AEffectProcessorBase {
	GENERATED_BODY()
	
public:
	virtual UStruct* GetParametersUStruct() override;

	virtual void PlayEffect(FEffectParametersBase Parameters, ACGPCharacterBase* Target) override;
};
