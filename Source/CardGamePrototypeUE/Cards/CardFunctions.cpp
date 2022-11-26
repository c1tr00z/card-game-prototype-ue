// Fill out your copyright notice in the Description page of Project Settings.


#include "CardFunctions.h"

#include "CardGamePrototypeUE/Characters/CGPCharactersFunctions.h"
#include "Modules/ModulesFunctions.h"

ACardsModule* UCardFunctions::GetCardsModule(UWorld* World) {
	return UModulesFunctions::GetModule<ACardsModule>(World);
}

void UCardFunctions::PlayCard(UWorld* World, UCardDBEntry* CardDBEntry, TEnumAsByte<ESide> CurrentSide) {
	auto Module = GetCardsModule(World);

	if (Module == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("No Cards Module exists in current world"));
		return;
	}

	TEnumAsByte<ESide> TargetSide = CurrentSide;
	if (Module->GetPositiveNegativeIndex(CardDBEntry) < 0) {
		TargetSide = CurrentSide == ESide::Player ? ESide::Enemy : ESide::Player;
	}

	auto Target = UCGPCharactersFunctions::GetCharacterBySide(World, TargetSide);

	Module->PlayCard(CardDBEntry, Target);
}
