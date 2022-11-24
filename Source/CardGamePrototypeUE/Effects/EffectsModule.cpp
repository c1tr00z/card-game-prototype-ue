// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectsModule.h"

#include "Common/ReflectionFunctions.h"

void AEffectsModule::BeginPlay() {
	Super::BeginPlay();

	TArray<UClass*> ProcessorsClasses = UReflectionFunctions::GetSubclassesOf(UEffectProcessorBase::StaticClass(), false);

	for (auto ProcessorsClass : ProcessorsClasses)
	{
		UEffectProcessorBase* EffectProcessor = NewObject<UEffectProcessorBase>(GetTransientPackage(), ProcessorsClass);
		if (EffectProcessor == nullptr)
		{
			continue;
		}
		UE_LOG(LogTemp, Warning, TEXT("Effect Processor [%s] Initialized"), *EffectProcessor->GetName());
		EffectProcessors.Add(EffectProcessor);
	}
}

UEffectProcessorBase* AEffectsModule::GetProcessor(FEffectParametersBase Parameters) const {
	for (auto EffectProcessor : EffectProcessors)
	{
		if (EffectProcessor->GetParametersUStruct() == Parameters.StaticStruct())
		{
			return EffectProcessor;
		}
	}

	UE_LOG(LogTemp, Error, TEXT("[EFFECTS MODULE] No effect processor defined for %s"), *Parameters.StaticStruct()->GetName());
	return nullptr;
}

void AEffectsModule::PlayEffectParameters(FEffectParametersBase Parameters, ACGPCharacterBase* Target) const {
	auto Processor = GetProcessor(Parameters);
	if (Processor == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No processor was found for %s"), *Parameters.StaticStruct()->GetName());
		return;
	}
	Processor->PlayEffect(Parameters, Target);
}

FString AEffectsModule::GetLocalizedString(FEffectParametersBase Parameters) const {
	auto Processor = GetProcessor(Parameters);
	if (Processor == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("[Localization] No processor was found for %s"), *Parameters.StaticStruct()->GetName());
		return FString("");
	}

	return Processor->GetLocalizedString(Parameters);
}
