// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectProcessorBase.h"


// Sets default values
UEffectProcessorBase::UEffectProcessorBase() {
}

UStruct* UEffectProcessorBase::GetParametersUStruct() {
	return FEffectParametersBase::StaticStruct();
}

void UEffectProcessorBase::PlayEffect(FEffectParametersBase Parameters, ACGPCharacterBase* Target) {
	
}

FString UEffectProcessorBase::GetLocalizedString(FEffectParametersBase Parameters) {
	return FString("");
}

int UEffectProcessorBase::GetPositiveNegativeIndex() {
	return 0;
}

FEffectParametersBase UEffectProcessorBase::Deserialize(TSharedRef<FJsonObject> JsonObject) {
	return FEffectParametersBase();
}

