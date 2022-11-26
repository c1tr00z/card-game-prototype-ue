// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardDataRow.h"
#include "CardDBEntry.h"
#include "CardsModuleSettings.h"
#include "CardGamePrototypeUE/Characters/CGPCharacterBase.h"
#include "CardGamePrototypeUE/Effects/EffectParametersBase.h"
#include "Engine/DataTable.h"
#include "Modules/AssistLibModule.h"
#include "CardsModule.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CARDGAMEPROTOTYPEUE_API ACardsModule : public AAssistLibModule
{
	GENERATED_BODY()

private:
	UCardsModuleSettings* Settings;
	
public:

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TArray<FString> CardsNames;

	TMap<FString, TArray<FEffectParametersBase>> CardsEffects;

private:
	
	TArray<FEffectParametersBase> LoadEffects(FCardDataRow DataRow);

	UCardsModuleSettings* GetSettings();

	UDataTable* GetCardsTable();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	TArray<FEffectParametersBase> GetEffects(UCardDBEntry* CardDBEntry);

	UFUNCTION(BlueprintPure)
	int GetPositiveNegativeIndex(UCardDBEntry* CardDBEntry);

	UFUNCTION(BlueprintCallable)
	void PlayCard(UCardDBEntry* CardDBEntry, ACGPCharacterBase* Target);
};
