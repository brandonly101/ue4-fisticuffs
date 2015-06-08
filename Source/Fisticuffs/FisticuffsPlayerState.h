// Copyright Brandon Ly and Kevin Luc 2015

#pragma once

#include "GameFramework/PlayerState.h"
#include "FisticuffsGameMode.h"
#include "FisticuffsPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class FISTICUFFS_API AFisticuffsPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	// Constructor
	AFisticuffsPlayerState(const FObjectInitializer& ObjectInitializer);

	// Begin Play
	virtual void BeginPlay() override;

	// Tick
	virtual void Tick(float DeltaSeconds) override;

    // Current Statistics
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "FisticuffsGameStatistics")
	float FighterStatDiscombobCurrent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "FisticuffsGameStatistics")
	float FighterStatStaminaCurrent;
	
    // Accessor
    bool GetFighterDead() const;
    void SetFighterDead();

private:
    bool FighterDead;

};
