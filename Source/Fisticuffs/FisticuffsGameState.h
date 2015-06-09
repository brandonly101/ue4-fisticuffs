// Copyright Brandon Ly and Kevin Luc 2015

#pragma once

#include "GameFramework/GameState.h"
#include "FisticuffsGameMode.h"
#include "FisticuffsPlayerState.h"
#include "FisticuffsGameState.generated.h"

/**
 * 
 */

UCLASS()
class FISTICUFFS_API AFisticuffsGameState : public AGameState
{
	GENERATED_BODY()

public:
	// Constructor
	AFisticuffsGameState(const FObjectInitializer& ObjectInitializer);

	// Begin Play
	virtual void BeginPlay() override;

	// Tick
	virtual void Tick(float DeltaSeconds) override;

private:
	AFisticuffsGameMode* GameMode;
	bool PlayerWin;
};
