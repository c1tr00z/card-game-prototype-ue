// Fill out your copyright notice in the Description page of Project Settings.


#include "CGPGameModeBattle.h"


void ACGPGameModeBattle::BeginTurn() {
}

void ACGPGameModeBattle::EndTurn() {
	
}

void ACGPGameModeBattle::BeginPlay() {
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TurnTimerHandle, this, &ACGPGameModeBattle::BeginTurn, 1.0f, false, 3.0f);
}
