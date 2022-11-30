// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardsAgentBase.h"
#include "CardsAgentPlayer.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class CARDGAMEPROTOTYPEUE_API UCardsAgentPlayer : public UCardsAgentBase {
	GENERATED_BODY()

private:
	int Energy;

public:
	UFUNCTION(BlueprintPure)
	int GetEnergy() const;

	virtual bool Pay(UCardDBEntry* card) override;
};
