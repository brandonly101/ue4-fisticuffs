// Copyright Brandon Ly and Kevin Luc.

#pragma once

#include "GameFramework/HUD.h"
#include "FisticuffsHUD.generated.h"

/**
 * 
 */
UCLASS()
class FISTICUFFS_API AFisticuffsHUD : public AHUD
{
	GENERATED_BODY()

	// Variable for storing the font
	UPROPERTY()
	UFont* FisticuffsHUDFont;
	
	// Primary draw call for the HUD - this is where modifications to it will go!
};
