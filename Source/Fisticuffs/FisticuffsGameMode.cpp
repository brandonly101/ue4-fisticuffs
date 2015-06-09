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
        UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->SetActorTickEnabled(false);
    }
	else if (StateNew == EFisticuffsPlayState::EMatchStartSP)
	{
		// Match Started SP
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Match Started SP State");
        UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->SetActorTickEnabled(true);
    }
    else if (StateNew == EFisticuffsPlayState::EMatchStartMP)
    {
        // Match Started MP
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Match Started MP State");
    }
	else if (StateNew == EFisticuffsPlayState::EMatchOverWin)
	{
		// Match Over Win
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Match Over Win State");
	}
    else if (StateNew == EFisticuffsPlayState::EMatchOverLoseSP)
    {
        // Match Over Lose SP
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Match Over Lose SP State");
    }
    else if (StateNew == EFisticuffsPlayState::EMatchOverLoseMP)
    {
        // Match Over Lose MP
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Match Over Lose MP State");
    }
	else
	{
		// Unknown State
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Unknown State");
	}
}
