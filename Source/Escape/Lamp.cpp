// Fill out your copyright notice in the Description page of Project Settings.


#include "Lamp.h"
#include"Components/StaticMeshComponent.h"
#include"Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"
#include"Materials/MaterialInstance.h"
#include "Components/PointLightComponent.h"

// Sets default values
ALamp::ALamp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Trigger = CreateDefaultSubobject<USphereComponent>(TEXT("Trigger"));
	RootComponent = Trigger;

	Trigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	Trigger->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	//	Ignores all other objects exept "Pawn",Pawn can ovelap

	Trigger->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Trigger->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);


	Lamp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lamp"));
	Lamp->SetupAttachment(GetRootComponent());
	
	

	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	Light->SetupAttachment(GetRootComponent());
	Light->Intensity = 10000.f;
	
	

	

	//Lamp_Material = CreateDefaultSubobject<UMaterialInstance>(TEXT("Lamp Material"));

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("Engine/BasicShapes/Cube"));

	//static ConstructorHelpers::FObjectFinder<UMaterial> Light(TEXT("/Game/Blueprints/Lamp/M_Light_Ins"));

	//if(Mesh.Succeeded())
	//{
		//Lamp->SetStaticMesh(Mesh.Object);
		//Lamp->SetMaterial(0, Light.Object);
	//}

	

}

// Called when the game starts or when spawned
void ALamp::BeginPlay()
{
	Super::BeginPlay();





	
}

// Called every frame
void ALamp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

