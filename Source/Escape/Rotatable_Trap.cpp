// Fill out your copyright notice in the Description page of Project Settings.


#include "Rotatable_Trap.h"
#include"Components/StaticMeshComponent.h"

// Sets default values
ARotatable_Trap::ARotatable_Trap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	RootComponent = Mesh;

}

// Called when the game starts or when spawned
void ARotatable_Trap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatable_Trap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FQuat QuatRotation = FRotator(PitchSpeed, YawSpeed, RollSpeed).Quaternion();
	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);

}

