// Fill out your copyright notice in the Description page of Project Settings.


#include "LifeComponent.h"


// Sets default values for this component's properties
ULifeComponent::ULifeComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULifeComponent::BeginPlay() {
	Super::BeginPlay();

	// ...
	
}

void ULifeComponent::OnDamaged(bool IsDied) {
	
}

void ULifeComponent::OnDied() {
	
}


// Called every frame
void ULifeComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                   FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int ULifeComponent::GetCurrentHP() const {
	return FMath::Max(0, MaxHP - DamageValue);
}

bool ULifeComponent::IsAlive() const {
	return GetCurrentHP() > 0;
}

void ULifeComponent::Damage(int Value) {
	DamageValue += Value;
	auto isAlive = IsAlive();
	OnDamaged(!isAlive);
	if (!IsAlive()) {
		OnDied();
	}
}

