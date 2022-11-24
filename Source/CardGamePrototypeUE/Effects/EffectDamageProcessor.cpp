// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectDamageProcessor.h"

#include "EffectDamageParameters.h"

UStruct* UEffectDamageProcessor::GetParametersUStruct() {
	return FEffectDamageParameters::StaticStruct();
}

void UEffectDamageProcessor::PlayEffect(FEffectParametersBase Parameters, ACGPCharacterBase* Target) {
	if (Parameters.StaticStruct() != GetParametersUStruct()) {
		return;
	}

	const auto PreCasted = static_cast<FEffectDamageParameters*>(&Parameters);
	const auto MyParameters = *PreCasted;

	Target->GetLife()->Damage(MyParameters.DamageValue);
}

FString UEffectDamageProcessor::GetLocalizedString(FEffectParametersBase Parameters) {
	if (Parameters.StaticStruct() != GetParametersUStruct()) {
		return FString("");
	}

	const auto PreCasted = static_cast<FEffectDamageParameters*>(&Parameters);
	FStringFormatOrderedArguments args;
	args.Add(FStringFormatArg(PreCasted->DamageValue));
	return FString::Format(TEXT("Deal {0} damage"), args);
}
