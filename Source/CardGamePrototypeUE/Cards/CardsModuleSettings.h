// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardsAgentBase.h"
#include "CardGamePrototypeUE/Common/Side.h"
#include "DB/DBEntry.h"
#include "Engine/DataTable.h"
#include "CardsModuleSettings.generated.h"

USTRUCT(BlueprintType)
struct FCardAgentSettings {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UCardsAgentBase> AgentClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<ESide> Side;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDeckData* Deck;
};

/**
 * 
 */
UCLASS()
class CARDGAMEPROTOTYPEUE_API UCardsModuleSettings : public UDBEntry {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* CardsTable;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FCardAgentSettings> AgentsSettings;
};
