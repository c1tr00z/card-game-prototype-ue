// Fill out your copyright notice in the Description page of Project Settings.


#include "CardsAgentPlayer.h"

int UCardsAgentPlayer::GetEnergy() const {
	return Energy;
}

bool UCardsAgentPlayer::Pay(UCardDBEntry* card) {
	if (Energy < card->EnergyPrice) {
		return false;
	}

	Energy - card->EnergyPrice;
	return true;
}
