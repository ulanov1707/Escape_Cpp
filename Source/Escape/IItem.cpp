// Fill out your copyright notice in the Description page of Project Settings.


#include "IItem.h"
#include"Components/SphereComponent.h"
#include"Components/StaticMeshComponent.h"
#include"Particles/ParticleSystemComponent.h"
#include"Kismet/GameplayStatics.h"
#include"Engine/World.h"
#include"Sound/SoundCue.h"

// Sets default values
AIItem::AIItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionVolume = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionVolume"));
	RootComponent = CollisionVolume;



	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());

	IdleParticlesComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("IdleParticlesComponent"));
	IdleParticlesComponent->SetupAttachment(GetRootComponent());

	bRotate = false;
	RotationRate = 45.f;


}

// Called when the game starts or when spawned
void AIItem::BeginPlay()
{
	Super::BeginPlay();

	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &AIItem::OverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &AIItem::OverlapEnd);
	
}

// Called every frame
void AIItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bRotate)
	{
		FRotator Rotation = GetActorRotation();
		Rotation.Yaw += DeltaTime * RotationRate;
		SetActorRotation(Rotation);
	}

}
void AIItem::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Super::On Overlap begin"));
	if (OverlapParticle)
	{
		//when u ovelap coin/bomb it will spawn a new Particle
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OverlapParticle/*Particel that will be spawned*/, GetActorLocation(), FRotator(0.f), true);
	}

	if (OverlapSound)
	{
		UGameplayStatics::PlaySound2D(this, OverlapSound);
	}

}

void AIItem::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Super::On Overlap end"));
}

