// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "AIController.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* pc = Cast<APlayerController>(GetController());
	//uint64 test1 = GetController()->GetClass()->HasAnyClassFlags()
	EClassCastFlags flag1 = GetController()->GetClass()->ClassCastFlags;
	EClassCastFlags flagAI = AAIController::StaticClass()->ClassCastFlags;
	EClassCastFlags flag2 = TCastFlags<APlayerController>::Value;

	/*int64 i = 45646541651312;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%lld"), i));*/
	//if (flag1 == flag2)
	//{
	UE_LOG(LogTemp, Warning, TEXT("flag1 = %llu, flag2 = %llu, flagAI = %llu"), flag1, flag2, flagAI);
	//}

	FName test(TEXT("you eruui"));
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

