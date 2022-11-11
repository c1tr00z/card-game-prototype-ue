// Fill out your copyright notice in the Description page of Project Settings.


#include "CardsModule.h"

#include "CardGamePrototypeUE/Effects/EffectsDeserializer.h"
#include "Common/ReflectionFunctions.h"
#include "DB/DBFunctions.h"

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
			UE_LOG(LogTemp, Error, TEXT("No struct with name : %s"), *EffectJson->GetStringField("ClassName"));
			continue;
		}

		auto Parameters = EffectsDeserializer::Deserialize(EffectJson.ToSharedRef());
		EffectParameters.Add(Parameters);
	}

	return EffectParameters;
}

UCardsModuleSettings* ACardsModule::GetSettings() {
	if (Settings == nullptr) {
		Settings = UDBFunctions::GetByClass<UCardsModuleSettings>(GetWorld());
	}

	return Settings;
}

UDataTable* ACardsModule::GetCardsTable() {
	if (!IsValid(GetSettings())) {
		return nullptr;
	}

	return GetSettings()->CardsTable;
}

void ACardsModule::BeginPlay() {
	Super::BeginPlay();

	const auto CardsTable = GetCardsTable();
	if (CardsTable == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("NO CARDS TABLE ASSIGNED"));
		return;
	}
	TArray<FName> RowNames = CardsTable->GetRowNames();
	UE_LOG(LogTemp, Warning, TEXT("Rows : %d"), CardsTable->GetRowNames().Num());
	for (auto RowName : RowNames)
	{
		auto Row = CardsTable->FindRow<FCardDataRow>(RowName, "");
		UE_LOG(LogTemp, Warning, TEXT("%s :: Json: %s"), *RowName.ToString(), *Row->JsonString);
		CardsNames.Add(RowName.ToString());
		CardsEffects.Add(RowName.ToString(), LoadEffects(*Row));
		UE_LOG(LogTemp, Warning, TEXT("%s ::: %d"), *RowName.ToString(), LoadEffects(*Row).Num());
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
