// Fill out your copyright notice in the Description page of Project Settings.


#include "Elevator.h"
#include"Components/TimelineComponent.h"
#include"MainCharacter.h"
#include"Components/BoxComponent.h"
#include"Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"



// Sets default values
AElevator::AElevator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Door = CreateDefaultSubobject<UStaticMeshComponent>(FName("Door"));
	Elevator = CreateDefaultSubobject<UStaticMeshComponent>(FName("Elevator"));
	TriggerBox= CreateDefaultSubobject<UBoxComponent>(FName("Trigger"));
	Root = CreateDefaultSubobject<USceneComponent>(FName("Root"));


	RootComponent = Root;
	Elevator->SetupAttachment(GetRootComponent());
	Door->SetupAttachment(GetRootComponent());
	TriggerBox->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AElevator::BeginPlay()
{
	Super::BeginPlay();

	//when something is starts  overlaping(passing through) with Trigger Box event  calles OnOverlapBegin function.	
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AElevator::OnOverlapBegin);
	//when something is stops overlaping with Trigger Box event  calles OnOverlapEnd function
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AElevator::OnOverlapEnd);
	
	TriggerBox->SetHiddenInGame(false);
	
	
	
	
}

// Called every frame
void AElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	Timeline.TickTimeline(DeltaTime);

}



void AElevator::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Main = Cast<AMainCharacter>(OtherActor);
	if (Main) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap Started"));
		if (CurveFloat)//if CurveFloat assigned
		{
			UE_LOG(LogTemp, Warning, TEXT("Curve Assigned "));

			//Creating Delegate(connects timeline with function " TimelineUpdate"). FOnTimelineFloat so it takes float as parameter
			FOnTimelineFloat TProgress;
			//binds a  function to delegate (basically to access a "TimelineProgress" function we need to use "TProgress")
			TProgress.BindUFunction(this, FName("OpenDoor"));
			//same as above
			


			//Binds a curve with function.Take value from curve and pass value(alpha) 
			//the delegate TProgress which is actually our function "TimelineProgress"
			Timeline.AddInterpFloat(CurveFloat, TProgress);

			//when timeline finished calls "TFinished" which is deleagte to our OnTimelineFinised()
			//we dont need it for now , but you can call it if u need 
			//Timeline.SetTimelineFinishedFunc(TFinished);

			//looping of timeline
			Timeline.SetLooping(false);



			Timeline.PlayFromStart();

			//you can use this one as well
			//Timeline.Play();

		}
		
	}



}
void AElevator::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Main = Cast<AMainCharacter>(OtherActor);
	if (Main)
	{
		if (CurveFloat)//if CurveFloat assigned
		{
			UE_LOG(LogTemp, Warning, TEXT("OverlpEnded"));
			if (CurveFloat)//if CurveFloat assigned
			{
				UE_LOG(LogTemp, Warning, TEXT("Curve Assigned Ended"));

				//Creating Delegate(connects timeline with function " TimelineUpdate"). FOnTimelineFloat so it takes float as parameter
				FOnTimelineEvent TProgress;
				//binds a  function to delegate (basically to access a "TimelineProgress" function we need to use "TProgress")
				TProgress.BindUFunction(this, FName("CloseDoor"));
				//same as above



				Timeline.SetTimelineFinishedFunc(TProgress);

			

				


			}


		}
	}
}
void AElevator::OpenDoor(float value)
{

	UE_LOG(LogTemp, Warning, TEXT("Timeline Started"));
	FVector DoorStart;
	DoorStart = Door->GetComponentLocation();
	FVector DoorEnd = FVector(DoorStart.X, DoorStart.Y, DoorStart.Z + 2.f);
	
	FVector NewLoc = FMath::Lerp(DoorStart, DoorEnd, value);
	Door->SetWorldLocation(NewLoc);
}

void AElevator::CloseDoor(float value)
{
	UE_LOG(LogTemp, Warning, TEXT("Door Closed"));
	//Timeline.Reverse();
}