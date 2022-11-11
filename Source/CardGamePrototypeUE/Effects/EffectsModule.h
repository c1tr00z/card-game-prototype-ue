// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EffectProcessorBase.h"
#include "Modules/AssistLibModule.h"
#include "EffectsModule.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMEPROTOTYPEUE_API AEffectsModule : public AAssistLibModule
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TArray<AEffectProcessorBase*> EffectProcessors;

public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	AEffectProcessorBase* GetProcessor(FEffectParametersBase Parameters) const;

	UFUNCTION(BlueprintCallable)
	void PlayEffectParameters(FEffectParametersBase Parameters, ACGPCharacterBase* Target) const;
};
