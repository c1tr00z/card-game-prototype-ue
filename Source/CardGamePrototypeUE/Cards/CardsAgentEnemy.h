// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardsAgentBase.h"
#include "UObject/Object.h"
#include "CardsAgentEnemy.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMEPROTOTYPEUE_API UCardsAgentEnemy : public UCardsAgentBase {
	GENERATED_BODY()

private:
	UCardDBEntry* NextAction;

public:
	UFUNCTION(BlueprintPure)
	UCardDBEntry* GetNextAction() const;

	UFUNCTION(BlueprintCallable)
	void PlayNextAction();
	
	virtual void Play(UCardDBEntry* card) override;
};
