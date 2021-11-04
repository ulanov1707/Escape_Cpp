// Fill out your copyright notice in the Description page of Project Settings.


#include "Spike_Trap.h"
#include"Components/BoxComponent.h"
#include"Components/StaticMeshComponent.h"
#include"MainCharacter.h"

// Sets default values
ASpike_Trap::ASpike_Trap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	Spike = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Spike"));
	Platform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));

	RootComponent = Platform;
	Spike->SetupAttachment(GetRootComponent());
	TriggerBox->SetupAttachment(GetRootComponent());





	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	TriggerBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	//	Ignores all other objects exept "Pawn",Pawn can ovelap

	TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

}

// Called when the game starts or when spawned
void ASpike_Trap::BeginPlay()
{
	Super::BeginPlay();

	InitialSikeLocation = Spike->GetComponentLocation();


	//when something is starts  overlaping(passing through) with Trigger Box event  calles OnOverlapBegin function.	
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ASpike_Trap::OnOverlapBegin);
	//when something is stops overlaping with Trigger Box event  calles OnOverlapEnd function
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ASpike_Trap::OnOverlapEnd);
	
}

// Called every frame
void ASpike_Trap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpike_Trap::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	RaiseSpike();

	
		
	
}
void ASpike_Trap::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) 
{
	LowerSpike();
}