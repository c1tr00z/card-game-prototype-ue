// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectsModule.h"

#include "Common/ReflectionFunctions.h"

void AEffectsModule::BeginPlay() {
	Super::BeginPlay();

	TArray<UClass*> ProcessorsClasses = UReflectionFunctions::GetSubclassesOf(AEffectProcessorBase::StaticClass(), false);

	for (auto ProcessorsClass : ProcessorsClasses)
	{
		auto EffectProcessor = Cast<AEffectProcessorBase>(GetWorld()->SpawnActor(ProcessorsClass));
		if (EffectProcessor == nullptr)
		{
			continue;
		}
		EffectProcessors.Add(EffectProcessor);
	}
}

AEffectProcessorBase* AEffectsModule::GetProcessor(FEffectParametersBase Parameters) const {
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
