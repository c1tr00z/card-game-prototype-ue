// Fill out your copyright notice in the Description page of Project Settings.


#include "CardsHandPanel.h"

#include "Components/CanvasPanelSlot.h"
#include "Widgets/SCanvas.h"

void UCardsHandPanel::RefreshHandLayout(TArray<UPanelSlot*> AllSlots) {
	auto SlotsAmount = AllSlots.Num();
	//cards.Count / 2 * _spacing - _spacing * ((cards.Count + 1) % 2) / 2;
	auto StartAngle = DefaultAngleOffset + SlotsAmount / 2 * AngleStep - AngleStep * ((SlotsAmount + 1) % 2) / 2;
	FVector2D LastPosition;
	for (int SlotIndex = 0; SlotIndex < SlotsAmount; SlotIndex++) {
		auto Slot = AllSlots[SlotIndex];
		const auto CanvasSlot = Cast<UCanvasPanelSlot>(Slot);
		if (!IsValid(CanvasSlot)) {
			continue;
		}
		CanvasSlot->SetAnchors(FAnchors(0.5f, 1));
		CanvasSlot->SetAlignment(FVector2D(0.5, 1));
		auto Angle = StartAngle - AngleStep * SlotIndex;
		auto AngleRad = FMath::DegreesToRadians(Angle);
		auto Position = FVector2D(Radius * FMath::Cos(AngleRad), Radius * FMath::Sin(AngleRad)) + Offset;
		CanvasSlot->SetPosition(Position);
		LastPosition = Position;
		auto Widget = CanvasSlot->Content;
		auto WidgetTransform = Widget->RenderTransform;
		WidgetTransform.Angle = Angle - DefaultAngleOffset;
		Widget->SetRenderTransform(WidgetTransform);
	}
}

void UCardsHandPanel::OnSlotAdded(UPanelSlot* InSlot) {
	auto AllSlots = GetSlots();
	if (!AllSlots.Contains(InSlot)) {
		AllSlots.Add(InSlot);
	}
	RefreshHandLayout(AllSlots);
	Super::OnSlotAdded(InSlot);
}

void UCardsHandPanel::OnSlotRemoved(UPanelSlot* InSlot) {
	auto AllSlots = GetSlots();
	if (AllSlots.Contains(InSlot)) {
		AllSlots.Remove(InSlot);
	}
	RefreshHandLayout(AllSlots);
	Super::OnSlotRemoved(InSlot);
}

void UCardsHandPanel::OnWidgetRebuilt() {
	RefreshHandLayout(GetSlots());
	Super::OnWidgetRebuilt();
}
