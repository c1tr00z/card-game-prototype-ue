// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EffectProcessorBase.h"
#include "Modules/AssistLibModule.h"
#include "EffectsModule.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CARDGAMEPROTOTYPEUE_API AEffectsModule : public AAssistLibModule
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TArray<UEffectProcessorBase*> EffectProcessors;

protected:
	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable)
	UEffectProcessorBase* GetProcessor(FEffectParametersBase Parameters) const;

	UFUNCTION(BlueprintCallable)
	void PlayEffectParameters(FEffectParametersBase Parameters, ACGPCharacterBase* Target) const;

	//TEMP solution for localization. Will be changed
	UFUNCTION(BlueprintPure)
	FString GetLocalizedString(FEffectParametersBase Parameters) const;

	int GetPositiveNegativeIndex(FEffectParametersBase Parameters) const;
};
