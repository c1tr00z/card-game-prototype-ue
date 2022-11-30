// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EffectProcessorBase.h"
#include "EffectDamageProcessor.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CARDGAMEPROTOTYPEUE_API UEffectDamageProcessor : public UEffectProcessorBase {
	GENERATED_BODY()
	
public:
	virtual UStruct* GetParametersUStruct() override;

	virtual void PlayEffect(FEffectParametersBase Parameters, ACGPCharacterBase* Target) override;

	virtual FString GetLocalizedString(FEffectParametersBase Parameters) override;

	virtual int GetPositiveNegativeIndex() override;

	virtual FEffectParametersBase Deserialize(TSharedRef<FJsonObject> JsonObject) override;
};
