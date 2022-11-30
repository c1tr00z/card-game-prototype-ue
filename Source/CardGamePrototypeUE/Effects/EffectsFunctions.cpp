// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectsFunctions.h"

#include "Modules/ModulesFunctions.h"

AEffectsModule* UEffectsFunctions::GetEffectsModule(UWorld* World) {
	return Cast<AEffectsModule>(UModulesFunctions::GetModuleByWorldAndUClass(World, AEffectsModule::StaticClass()));
}

void UEffectsFunctions::PlayEffect(UWorld* World, FEffectParametersBase Parameters, ACGPCharacterBase* Target) {
	auto Module = GetEffectsModule(World);

	if (Module == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No effects module was found"));
		return;
	}

	Module->PlayEffectParameters(Parameters, Target);
}

FString UEffectsFunctions::GetLocalizedString(UWorld* World, FEffectParametersBase Parameters) {
	auto Module = GetEffectsModule(World);
	
	if (Module == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("[Localization] No effects module was found"));
		return FString("");
	}

	return Module->GetLocalizedString(Parameters);
}

int UEffectsFunctions::GetPositiveNegativeIndex(UWorld* World, FEffectParametersBase Parameters) {
	auto Module = GetEffectsModule(World);
	
	if (Module == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No effects module was found"));
		return 0;
	}

	return Module->GetPositiveNegativeIndex(Parameters);
}

FEffectParametersBase UEffectsFunctions::DeserializeFromJson(UWorld* World, TSharedRef<FJsonObject> JsonObject) {
	auto Module = GetEffectsModule(World);
	
	if (Module == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No effects module was found"));
		return FEffectParametersBase();
	}

	auto Processor = Module->GetProcessorByParametersStructName(JsonObject->GetStringField("ClassName"));
	return Processor->Deserialize(JsonObject);
}
