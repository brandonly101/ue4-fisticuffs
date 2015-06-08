// Copyright Brandon Ly and Kevin Luc.

#include "Fisticuffs.h"
#include "FisticuffsGameMode.h"

////////////////////////////////////////////////////////////////
// Constructor
AFisticuffsGameMode::AFisticuffsGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	PlayState(EFisticuffsPlayState::EMainMenu),
	StatBaseDamageSP(0.15), StateBaseDamageEnemySP(0.15), StatStaminaPunchDegenSP(0.01), StatStaminaPunchDegenEnemySP(0.01),
	StatDiscombobDegenSP(0.035), StatDiscombobDegenEnemySP(0.035), StatStaminaRegenSP(0.005), StatStaminaRegenEnemySP(0.005),
	StatBaseDamageMP(0.15), StatStaminaPunchDegenMP(0.01), StatDiscombobDegenMP(0.035), StatStaminaRegenMP(0.005),
	LevelTriggerState(true)
{}

////////////////////////////////////////////////////////////////
// Event Begin Play
void AFisticuffsGameMode::BeginPlay()
{
	// Call parent BeginPlay() in case there are things in it.
	Super::BeginPlay();

	// Make it singleplayer for now...
	SetCurrentState(EFisticuffsPlayState::EMainMenu);
}

////////////////////////////////////////////////////////////////
// Event Tick
void AFisticuffsGameMode::Tick(float DeltaSeconds)
{
	// Call parent Tick() in case there are things in it.
	Super::Tick(DeltaSeconds);
}

////////////////////////////////////////////////////////////////
// Game Play State Changer
void AFisticuffsGameMode::SetCurrentState(EFisticuffsPlayState StateNew)
{
	PlayState = StateNew;
	LevelTriggerState = true;
	HandleChangeState(StateNew);
}

////////////////////////////////////////////////////////////////
// Game Play State Change Handler (this function is private)
void AFisticuffsGameMode::HandleChangeState(EFisticuffsPlayState StateNew)
{
	if (StateNew == EFisticuffsPlayState::EMainMenu)
	{
		// In Main Menu
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Main Menu State");
	}
	else if (StateNew == EFisticuffsPlayState::EMatchStartSP)
	{
		// Match Started
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Match Started SP State");
	}
	else if (StateNew == EFisticuffsPlayState::EMatchOver)
	{
		// Match is Over
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Match Over State");
	}
	else
	{
		// Match Unknown
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Unknown State");
	}
}
