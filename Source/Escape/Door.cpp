// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include"Components/BoxComponent.h"
#include"Components/StaticMeshComponent.h"
#include"MainCharacter.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TriggerBox;

	//QueryOnly allows to overlap 
	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	
	TriggerBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
//	Ignores all other objects exept "Pawn",Pawn can ovelap

	TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(GetRootComponent());



	
	


}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	//All the job related with loction better to initialize in "BeginPlay" rather than in Constructor 
	//in constructor it works wrong

	//Location in the world
	InitialDoorLocation = Door->GetComponentLocation();//dont initialie in Constuctor

	FinalDoorLocation = InitialDoorLocation;//dont initialie in Constuctor
	FinalDoorLocation.Z += FinalDoor_Z_Component;






	//when something is starts  overlaping(passing through) with Trigger Box event  calles OnOverlapBegin function.	
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ADoor::OnOverlapBegin);
	//when something is stops overlaping with Trigger Box event  calles OnOverlapEnd function
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ADoor::OnOverlapEnd);

	
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

void  ADoor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//if something overlaps with a door it Raises the door
	RaiseDoor();
	
}

void ADoor::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//if something stops overlaping with a door it Lowers the door
	LowerDoor();
	
}

