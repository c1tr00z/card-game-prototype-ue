// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardDataRow.h"
#include "CardDBEntry.h"
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
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* CardsTable;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TArray<FString> CardsNames;

	TMap<FString, TArray<FEffectParametersBase>> CardsEffects;

private:
	TArray<FEffectParametersBase> LoadEffects(FCardDataRow DataRow);

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	TArray<FEffectParametersBase> GetEffects(UCardDBEntry* CardDBEntry);
};
