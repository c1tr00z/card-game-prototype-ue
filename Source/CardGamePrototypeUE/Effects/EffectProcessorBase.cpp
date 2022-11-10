// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectProcessorBase.h"


// Sets default values
AEffectProcessorBase::AEffectProcessorBase() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

UStruct* AEffectProcessorBase::GetParametersUStruct() {
	return FEffectParametersBase::StaticStruct();
}

// Called when the game starts or when spawned
void AEffectProcessorBase::BeginPlay() {
	Super::BeginPlay();
	
}

void AEffectProcessorBase::PlayEffect(FEffectParametersBase Parameters, ACGPCharacterBase* Target) {
	
}

