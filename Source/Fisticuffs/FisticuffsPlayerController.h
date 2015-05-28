// Copyright Brandon Ly and Kevin Luc.

#pragma once

#include "GameFramework/PlayerController.h"
#include "FisticuffsPlayerController.generated.h"

/**
 * C++ Class for our Fisticuffs game player controller.
 */
UCLASS()
class FISTICUFFS_API AFisticuffsPlayerController : public APlayerController
{
public:

	GENERATED_BODY()

	// Constructor
	AFisticuffsPlayerController(const FObjectInitializer& ObjectInitializer);

	// Event Begin Play
	virtual void BeginPlay() override;

	// Event Tick
	virtual void Tick(float DeltaSeconds) override;

	// Other Functions
	UFUNCTION(BlueprintCallable, Category = "C++ Functions")
	void ChangeHMDSPSetting();
	
};
