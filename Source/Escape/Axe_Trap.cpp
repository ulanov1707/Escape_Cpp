// Fill out your copyright notice in the Description page of Project Settings.


#include "Axe_Trap.h"
#include"Components/StaticMeshComponent.h"
#include"MainCharacter.h"

// Sets default values
AAxe_Trap::AAxe_Trap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	PrimaryActorTick.bCanEverTick = true;
	
	Axe_Top = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Axe_Top"));
	RootComponent = Axe_Top;

	Axe = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Axe"));
	Axe->SetupAttachment(GetRootComponent());




	//BeginPlay Activates it
	bRotateYAxis = false;


	
	InitialYRotation = FRotator(0.f, 0.f, 0.f);

	//speed of rotation
	RotationRate = 5.f;


}

// Called when the game starts or when spawned
void AAxe_Trap::BeginPlay()
{
	Super::BeginPlay();

	//activates a  rotatition
	bRotateYAxis = true;

}

// Called every frame
void AAxe_Trap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	if (bRotateYAxis) 
	{

		if (InitialYRotation.Pitch == -90 || InitialYRotation.Pitch == 90)//rotates in range of 90 and -90 degrees
		{
			SwapRotationRate(RotationRate);
		}

		InitialYRotation.Pitch += RotationRate;


		//If you are using a SetRelativeRotatiton , Component(Axe) must have a parent(Any Scene Component) in our case "Axe_Top" 
		//to Rotate relative to Parent . Otherwise it will work wierd
		Axe->SetRelativeRotation(InitialYRotation);
	}

}


void AAxe_Trap::SwapRotationRate(float& Rate) {
	
	//If Rate is Negative makes it positive and if Rate is Positive makes it Negative 
	Rate *= -1;

}
