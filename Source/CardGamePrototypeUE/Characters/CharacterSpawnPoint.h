// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardGamePrototypeUE/Common/Side.h"
#include "GameFramework/Actor.h"
#include "CharacterSpawnPoint.generated.h"

UCLASS()
class CARDGAMEPROTOTYPEUE_API ACharacterSpawnPoint : public AActor {
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<ESide> Side;
};
