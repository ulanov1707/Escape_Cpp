// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateTrap.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ARotateTrap::ARotateTrap()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//AutoPossesPlayer = EAutoRecieveInput::Player0;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Comp"));
	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Our Camera"));
	OurVisibleActor = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Our Mesh"));
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.f, 0.0f, 0.0f));
	OurVisibleActor->SetupAttachment(RootComponent);
	RotationSpeed = 100.f;
}

// Called when the game starts or when spawned
void ARotateTrap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotateTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Handle movement based on our "MoveX" and "MoveY" axes
	{
		if (!CurrentVelocity.IsZero())
		{
			
			FRotator NewRotation = OurVisibleActor->GetComponentRotation() + (CurrentVelocity * DeltaTime);
			//dont set RelativeRotation (it will mixedup and cause some shit roatations)
			OurVisibleActor->SetWorldRotation(NewRotation);
		}
	}

	
}

// Called to bind functionality to input
void ARotateTrap::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("RotatePawnX", this, &ARotateTrap::Rotate_XAxis);
	InputComponent->BindAxis("RotatePawnY", this, &ARotateTrap::Rotate_YAxis);

}



void ARotateTrap::Rotate_XAxis(float AxisValue)
{
	// Move at 100 units per second forward or backward
	CurrentVelocity.Pitch= FMath::Clamp(AxisValue, -1.0f, 1.0f) * RotationSpeed;
}

void ARotateTrap::Rotate_YAxis(float AxisValue)
{
	// Move at 100 units per second right or left
	CurrentVelocity.Roll = FMath::Clamp(AxisValue, -1.0f, 1.0f) * RotationSpeed;
}