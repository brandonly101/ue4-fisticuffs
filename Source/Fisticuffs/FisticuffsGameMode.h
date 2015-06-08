// Copyright Brandon Ly and Kevin Luc.

#pragma once

#include "GameFramework/GameMode.h"
#include "FisticuffsGameMode.generated.h"

#define MAX_DISCOMBOB 1.0
#define MIN_DISCOMBOB 0.0
#define MAX_STAMINA 1.0
#define MIN_STAMINA 0.0

// Fisticuffs Play States
UENUM(BlueprintType)
enum class EFisticuffsPlayState : uint8
{
	EMainMenu UMETA(DisplayName = "MainMenu"),
	EMatchStartSP UMETA(DisplayName = "MatchStart"),
	EMatchStartMP UMETA(DisplayName = "MatchStartMultiplayer"),
	EMatchOver UMETA(DisplayName = "MatchOver"),
	EUnknown UMETA(DisplayName = "Unknown"),
};

UCLASS()
class FISTICUFFS_API AFisticuffsGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	// Constructor
	AFisticuffsGameMode(const FObjectInitializer& ObjectInitializer);

	// Event Begin Play
	virtual void BeginPlay() override;

	// Event Tick
	virtual void Tick(float DeltaSecond) override;

	// Game Play State Variable - Current State
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FisticuffsGameStatistics")
	EFisticuffsPlayState PlayState;

	//
	// Gameplay Statistics
	//
	// Single Player
	//
	// Base Damage and Stamina per punch
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FisticuffsGameStatistics")
	float StatBaseDamageSP;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FisticuffsGameStatistics")
	float StateBaseDamageEnemySP;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FisticuffsGameStatistics")
	float StatStaminaPunchDegenSP;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FisticuffsGameStatistics")
	float StatStaminaPunchDegenEnemySP;
	// Fighter Stabilization Rates (Discombob degen and Stamina regen)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FisticuffsGameStatistics")
	float StatDiscombobDegenSP;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FisticuffsGameStatistics")
	float StatDiscombobDegenEnemySP;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FisticuffsGameStatistics")
	float StatStaminaRegenSP;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FisticuffsGameStatistics")
	float StatStaminaRegenEnemySP;
	
	//
	// Multiplayer
	//
	// Base Damage and Stamina per punch
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FisticuffsGameStatistics")
	float StatBaseDamageMP;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FisticuffsGameStatistics")
	float StatStaminaPunchDegenMP;
	// Fighter Stabilization Rates (Discombob degen and Stamina regen)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FisticuffsGameStatistics")
	float StatDiscombobDegenMP;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "FisticuffsGameStatistics")
	float StatStaminaRegenMP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayState")
	bool LevelTriggerState;

	//
	// State Changer
	//
	UFUNCTION(BlueprintCallable, Category = "PlayState")
	void SetCurrentState(EFisticuffsPlayState StateNew);

private:	
	// Upon call of "SetCurrentState", handle the change in states
	void HandleChangeState(EFisticuffsPlayState StateNew);

};
