// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DB/DBEntry.h"
#include "Engine/DataTable.h"
#include "UObject/Object.h"
#include "CardsModuleSettings.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMEPROTOTYPEUE_API UCardsModuleSettings : public UDBEntry {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* CardsTable;
};
