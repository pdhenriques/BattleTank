// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController not possesing a Tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController possesing: %s"), *ControlledTank->GetName())
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController can't find the player"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController found player: %s"), *PlayerTank->GetName())
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	ATank* Player = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Player)
	{
		return Player;
	}
	else
	{
		return nullptr;
	}
}


