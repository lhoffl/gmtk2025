// Copyright Epic Games, Inc. All Rights Reserved.


#include "Gmtk2025PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Gmtk2025CameraManager.h"

AGmtk2025PlayerController::AGmtk2025PlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AGmtk2025CameraManager::StaticClass();
}

void AGmtk2025PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
