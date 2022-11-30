// Fill out your copyright notice in the Description page of Project Settings.


#include "CardsAgentBase.h"

#include "CardFunctions.h"

TEnumAsByte<ESide> UCardsAgentBase::GetSide() const {
	return MySide;
}

UDeckData* UCardsAgentBase::GetDeck() const {
	return MyDeck;
}

void UCardsAgentBase::Init(TEnumAsByte<ESide> side, UDeckData* Deck) {
	MySide = side;
}

bool UCardsAgentBase::Pay(UCardDBEntry* card) {
	return false;
}

void UCardsAgentBase::Play(UCardDBEntry* card) {
	if (!Pay(card)) {
		return;
	}

	UCardFunctions::PlayCard(GetWorld(), card, GetSide());
}
