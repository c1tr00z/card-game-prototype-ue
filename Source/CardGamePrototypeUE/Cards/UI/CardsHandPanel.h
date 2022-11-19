// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "Components/PanelWidget.h"
#include "CardsHandPanel.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMEPROTOTYPEUE_API UCardsHandPanel : public UCanvasPanel
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Radius;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float AngleStep;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DefaultAngleOffset = 90;

private:
	void RefreshHandLayout(TArray<UPanelSlot*> AllSlots);
	
public:
	virtual void OnSlotAdded(UPanelSlot* InSlot) override;

	virtual void OnSlotRemoved(UPanelSlot* InSlot) override;
};
