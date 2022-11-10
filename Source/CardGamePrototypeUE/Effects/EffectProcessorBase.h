// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EffectParametersBase.h"
#include "CardGamePrototypeUE/Characters/CGPCharacterBase.h"
#include "GameFramework/Actor.h"
#include "EffectProcessorBase.generated.h"

UCLASS(Abstract)
class CARDGAMEPROTOTYPEUE_API AEffectProcessorBase : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEffectProcessorBase();

	UFUNCTION(BlueprintCallable)
	virtual UStruct* GetParametersUStruct();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	virtual void PlayEffect(FEffectParametersBase Parameters, ACGPCharacterBase* Target);
};
