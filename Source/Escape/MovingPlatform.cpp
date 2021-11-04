// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include"TimerManager.h"
#include"Components/StaticMeshComponent.h"
#include"Components/BoxComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EndBox = CreateDefaultSubobject<UBoxComponent>(TEXT("EndBox"));
	RootComponent = EndBox;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//RootComponent = Mesh;
	Mesh->SetupAttachment(GetRootComponent());

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(Mesh);
	



	
	



	

	
	
	
	

	InterpSpeed = 3.f;
	InterpTime = 3.f;//1 sec
	bStartToFloat = false;




}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	


	StartPoint = Mesh->GetComponentLocation();

	EndPoint = EndBox->GetComponentLocation();
	
	

	//NOTE:Location of an EndPoint will be shown with respect to placed Blueprint(not world coordinates)
	//Since that we are getting StartPoint's Location because its represented with respect world and adding it to the
	//Endpoint to get EndPoint's location with respect to World
	
	//EndPoint += (StartPoint);

	//After a game  starts it will wait 1sec(InterpTime) and call function ToggleInterping() and makes bStartToFloat=true
	


	GetWorldTimerManager().SetTimer(InterpTimer, this, &AMovingPlatform::ToggleInterping, InterpTime);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = Mesh->GetComponentLocation();

	//Rotates a Static Mesh
	Mesh->AddLocalRotation(MeshRotation);


	


	if (bStartToFloat)
	{

	
		//VInterpTo-stands for Interpolation
		//Each frame VInterpTo will move from  StartPont to Endpoint smooothly and return his location at particular frame  
		FVector Interp = FMath::VInterpTo(CurrentLocation, EndPoint, DeltaTime, InterpSpeed);

		//will update this location each frame thus actually move  object visually and smoothly
		Mesh->SetWorldLocation(Interp);


		if (CurrentLocation == EndPoint)
		{
			
	
			//FVector Interpp = FMath::VInterpTo(EndPoint, CurrentLocation,  DeltaTime, InterpSpeed);
			//will swap the values of a Vector
			SwapVector(StartPoint, EndPoint);

			

		}

	}

}


void  AMovingPlatform::ToggleInterping()
{
	//if bInterping is true make it false , if false make it true
	bStartToFloat = !bStartToFloat;
	GetWorldTimerManager().ClearTimer(InterpTimer);
}

void  AMovingPlatform::SwapVector(FVector& VecOne, FVector& VecTwo) {
	
	FVector Temp = VecOne;
	VecOne = VecTwo;
	VecTwo = Temp;
	
}
