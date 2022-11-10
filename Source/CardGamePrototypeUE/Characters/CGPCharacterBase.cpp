// Fill out your copyright notice in the Description page of Project Settings.


#include "CGPCharacterBase.h"


// Sets default values
ACGPCharacterBase::ACGPCharacterBase() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Life = CreateDefaultSubobject<ULifeComponent>("Life");
}

// Called when the game starts or when spawned
void ACGPCharacterBase::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void ACGPCharacterBase::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACGPCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

ULifeComponent* ACGPCharacterBase::GetLife() {
	return Life;
}

