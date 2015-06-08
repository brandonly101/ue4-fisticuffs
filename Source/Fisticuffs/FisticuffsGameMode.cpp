// Copyright Brandon Ly and Kevin Luc.

#include "Fisticuffs.h"
#include "FisticuffsGameMode.h"

////////////////////////////////////////////////////////////////
// Constructor
AFisticuffsGameMode::AFisticuffsGameMode(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    // Game Play State Variable - Current State
    EFisticuffsPlayState PlayState = EFisticuffsPlayState::EMainMenu;

    //
    // Gameplay Statistics
    //
    // Single Player
    //
    // Base Damage and Stamina per punch
    float StatBaseDamageSP = 0.15;
    float StateBaseDamageEnemySP = 0.15;
    float StatStaminaPunchDegenSP = 0.01;
    float StatStaminaPunchDegenEnemySP = 0.01;
    // Fighter Stabilization Rates (Discombob degen and Stamina regen)
    float StatDiscombobDegenSP = 0.035;
    float StatDiscombobDegenEnemySP = 0.035;
    float StatStaminaRegenSP = 0.005;
    float StatStaminaRegenEnemySP = 0.005;

    //
    // Multiplayer
    //
    // Base Damage and Stamina per punch
    float StatBaseDamageMP = 0.15;
    float StatStaminaPunchDegenMP = 0.01;
    // Fighter Stabilization Rates (Discombob degen and Stamina regen)
    float StatDiscombobDegenMP = 0.035;
    float StatStaminaRegenMP = 0.005;
}

////////////////////////////////////////////////////////////////
// Event Begin Play
void AFisticuffsGameMode::BeginPlay()
{
	// Call parent BeginPlay() in case there are things in it.
	Super::BeginPlay();

	// Make it singleplayer for now...
	SetCurrentState(EFisticuffsPlayState::EMatchStartedSP);
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
	else if (StateNew == EFisticuffsPlayState::EMatchStartedSP)
	{
		// Match Started
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Match Started State");
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
