// Fill out your copyright notice in the Description page of Project Settings.


#include "CharactersModule.h"

#include "CharacterSpawnPoint.h"
#include "EngineUtils.h"
#include "DB/DBFunctions.h"

void ACharactersModule::BeginPlay() {
	Super::BeginPlay();

	TMap<TEnumAsByte<ESide>, FTransform> SpawnPoints;
	for (TActorIterator<ACharacterSpawnPoint> PointsIterator = TActorIterator<ACharacterSpawnPoint>(GetWorld(),
		ACharacterSpawnPoint::StaticClass()); PointsIterator; ++PointsIterator) {

		auto SpawnPoint = *PointsIterator;
		SpawnPoints.Add(SpawnPoint->Side, SpawnPoint->GetActorTransform());
	}
	
	for (auto CharacterSettings : GetSettings()->CharactersSettings) {
		auto CharacterTransform = SpawnPoints[CharacterSettings.Side];
		FActorSpawnParameters SpawnParameters;
		auto Character = Cast<ACGPCharacterBase>(GetWorld()->SpawnActor(CharacterSettings.CharacterClass, &CharacterTransform, SpawnParameters));
		CharactersBySide.Add(CharacterSettings.Side, Character);
	}
}

UCharactersModuleSettings* ACharactersModule::GetSettings() {
	if (Settings == nullptr) {
		Settings = UDBFunctions::GetByClass<UCharactersModuleSettings>(GetWorld());
	}

	return Settings;
}

ACGPCharacterBase* ACharactersModule::GetCharacterBySide(TEnumAsByte<ESide> Side) {
	return CharactersBySide.Contains(Side) ? CharactersBySide[Side] : nullptr;
}

ACGPCharacterBase* ACharactersModule::GetOpponent(TEnumAsByte<ESide> Side) {
	auto OppositeSide = Side == ESide::Player ? ESide::Enemy : ESide::Player;
	return GetCharacterBySide(OppositeSide);
}
