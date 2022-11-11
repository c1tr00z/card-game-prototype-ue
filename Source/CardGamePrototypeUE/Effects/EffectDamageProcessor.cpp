// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectDamageProcessor.h"

#include "EffectDamageParameters.h"

UStruct* AUEffectDamageProcessor::GetParametersUStruct() {
	return FEffectDamageParameters::StaticStruct();
}

void AUEffectDamageProcessor::PlayEffect(FEffectParametersBase Parameters, ACGPCharacterBase* Target) {
	if (Parameters.StaticStruct() != GetParametersUStruct()) {
		return;
	}

	const auto PreCasted = static_cast<FEffectDamageParameters*>(&Parameters);
	const auto MyParameters = *PreCasted;

	Target->GetLife()->Damage(MyParameters.DamageValue);
}


