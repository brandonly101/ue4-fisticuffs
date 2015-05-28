// Copyright Brandon Ly and Kevin Luc.

#pragma once

#include "GameFramework/GameMode.h"
#include "FisticuffsGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FISTICUFFS_API AFisticuffsGameMode : public AGameMode
{
	GENERATED_BODY()
	
	// Constructor
	AFisticuffsGameMode(const FObjectInitializer& ObjectInitializer);

	// Event Begin Play
	virtual void BeginPlay() override;

	// Event Tick
	virtual void Tick(float DeltaSecond) override;
	
};
