// Fill out your copyright notice in the Description page of Project Settings.


#include "CardsModule.h"

#include "CardGamePrototypeUE/Effects/EffectsDeserializer.h"
#include "Common/ReflectionFunctions.h"

TArray<FEffectParametersBase> ACardsModule::LoadEffects(FCardDataRow DataRow) {
	auto Reader = TJsonReaderFactory<>::Create(DataRow.JsonString);
	TSharedPtr<FJsonObject> ArrayContainer = MakeShareable(new FJsonObject);
	if (!FJsonSerializer::Deserialize(Reader, ArrayContainer))
	{
		return TArray<FEffectParametersBase>();
	}

	auto JsonValues = ArrayContainer->GetArrayField("Values");
	TArray<FEffectParametersBase> EffectParameters;
	for (TSharedPtr<FJsonValue, ESPMode::ThreadSafe> JsonValue : JsonValues)
	{
		auto EffectJson = JsonValue->AsObject();
		auto StructClass = UReflectionFunctions::GetUStructByName(EffectJson->GetStringField("ClassName"));
		if (StructClass == nullptr)
		{
			continue;
		}

		auto Parameters = EffectsDeserializer::Deserialize(EffectJson.ToSharedRef());
		EffectParameters.Add(Parameters);
	}

	return EffectParameters;
}

void ACardsModule::BeginPlay() {
	Super::BeginPlay();

	TArray<FName> RowNames = CardsTable->GetRowNames();
	for (auto RowName : RowNames)
	{
		auto Row = CardsTable->FindRow<FCardDataRow>(RowName, "");
		CardsNames.Add(RowName.ToString());
		CardsEffects.Add(RowName.ToString(), LoadEffects(*Row));
	}
}

TArray<FEffectParametersBase> ACardsModule::GetEffects(UCardDBEntry* CardDBEntry) {
	if (CardDBEntry == nullptr)
	{
		return TArray<FEffectParametersBase>();
	}
	const auto BulletName = CardDBEntry->GetName();
	if (!CardsEffects.Contains(BulletName))
	{
		return TArray<FEffectParametersBase>();
	}
	return CardsEffects[BulletName];
}
