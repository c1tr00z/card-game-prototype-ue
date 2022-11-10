// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardGamePrototypeUE/Damage/Damageable.h"
#include "CardGamePrototypeUE/Damage/LifeComponent.h"
#include "GameFramework/Character.h"
#include "CGPCharacterBase.generated.h"

UCLASS()
class CARDGAMEPROTOTYPEUE_API ACGPCharacterBase : public ACharacter, public IDamageable {
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACGPCharacterBase();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	ULifeComponent* Life;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual ULifeComponent* GetLife() override;
};
