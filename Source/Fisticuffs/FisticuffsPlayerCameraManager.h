// Copyright Brandon Ly and Kevin Luc.

#pragma once

#include "Camera/PlayerCameraManager.h"
#include "FisticuffsPlayerCameraManager.generated.h"

/**
 * 
 */
UCLASS()
class FISTICUFFS_API AFisticuffsPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()

	// Constructor
	AFisticuffsPlayerCameraManager(const FObjectInitializer& ObjectInitializer);

	// Variables for tracking the actor to be targeted
	AActor* TargetActor;
	
	// Create custom BeginPlay() function! Weeeeee
	virtual void BeginPlay() override;
	
	// Custom Tick() function
	virtual void Tick(float DeltaSeconds) override;
	
};
