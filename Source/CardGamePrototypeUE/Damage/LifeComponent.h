// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LifeComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CARDGAMEPROTOTYPEUE_API ULifeComponent : public UActorComponent {
	GENERATED_BODY()

private: 
	int MaxHP;
	int DamageValue;

	int Armor;
	
public:
	// Sets default values for this component's properties
	ULifeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	void OnDamaged(bool IsDied);
	
	void OnDied();
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure)
	int GetCurrentHP() const;

	UFUNCTION(BlueprintPure)
	bool IsAlive() const;

	UFUNCTION(BlueprintCallable)
	void Damage(int Value);

	UFUNCTION(BlueprintCallable)
	void Heal(int Value);

	UFUNCTION(BlueprintCallable)
	void AddArmor(int Value);
};
