#include "PlayerController.h"
#include "GameplayStatics.h"

#include "reboot.h"

void APlayerController::ServerChangeName(FString& S)
{
	static auto ServerChangeNameFn = FindObject<UFunction>("/Script/Engine.PlayerController.ServerChangeName");
	this->ProcessEvent(ServerChangeNameFn, &S);
}

UCheatManager*& APlayerController::SpawnCheatManager(UClass* CheatManagerClass)
{
	GetCheatManager() = UGameplayStatics::SpawnObject<UCheatManager>(CheatManagerClass, this, true);
	return GetCheatManager();
}

FRotator APlayerController::GetControlRotation()
{
	static auto fn = FindObject<UFunction>(L"/Script/Engine.Controller.GetControlRotation");
	FRotator rot;
	this->ProcessEvent(fn, &rot);
	return rot;
}

void APlayerController::ServerRestartPlayer()
{
	static auto fn = FindObject<UFunction>(L"/Script/Engine.PlayerController.ServerRestartPlayer");
	this->ProcessEvent(fn);
}

UClass* APlayerController::StaticClass()
{
	static auto Class = FindObject<UClass>(L"/Script/Engine.PlayerController");
	return Class;
}