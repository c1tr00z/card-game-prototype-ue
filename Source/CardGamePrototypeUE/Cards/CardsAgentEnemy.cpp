// Fill out your copyright notice in the Description page of Project Settings.


#include "CardsAgentEnemy.h"

#include "CardFunctions.h"

UCardDBEntry* UCardsAgentEnemy::GetNextAction() const {
	return NextAction;
}

void UCardsAgentEnemy::PlayNextAction() {
	if (NextAction == nullptr) {
		return;
	}
	UCardFunctions::PlayCard(GetWorld(), NextAction, GetSide());
	NextAction = nullptr;
}

void UCardsAgentEnemy::Play(UCardDBEntry* card) {
	NextAction = card;
}
