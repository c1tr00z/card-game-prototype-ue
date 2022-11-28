// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardDBEntry.h"
#include "DeckData.h"
#include "CardGamePrototypeUE/Common/Side.h"
#include "UObject/Object.h"
#include "CardsAgentBase.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMEPROTOTYPEUE_API UCardsAgentBase : public UObject {
	GENERATED_BODY()

private:
	TEnumAsByte<ESide> MySide;

	UDeckData* MyDeck;
	
public:

	UFUNCTION(BlueprintPure)
	TEnumAsByte<ESide> GetSide() const;

	UFUNCTION(BlueprintPure)
	UDeckData* GetDeck() const;

	UFUNCTION(BlueprintCallable)
	void Init(TEnumAsByte<ESide> side, UDeckData* Deck);

	UFUNCTION(BlueprintCallable)
	virtual bool Pay(UCardDBEntry* card);

	UFUNCTION(BlueprintCallable)
	virtual void Play(UCardDBEntry* card);
};
