// Copyright Brandon Ly and Kevin Luc.

#include "Fisticuffs.h"
#include "FisticuffsPlayerController.h"
#include "FisticuffsPlayerCameraManager.h"

// Constructor
AFisticuffsPlayerController::AFisticuffsPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PlayerCameraManagerClass = AFisticuffsPlayerCameraManager::StaticClass();
}

void AFisticuffsPlayerController::BeginPlay()
{

}

void AFisticuffsPlayerController::Tick(float DeltaSeconds)
{
	if (WasInputKeyJustPressed(EKeys::E))
		ChangeHMDSPSetting();
}

void AFisticuffsPlayerController::ChangeHMDSPSetting()
{
	//GEngine->DeferredCommands.Add(TEXT("hmd sp 50"));
	GetWorld()->Exec(GetWorld(), TEXT("hmd sp 50"));
}
