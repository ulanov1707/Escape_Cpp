// Fill out your copyright notice in the Description page of Project Settings.


#include "Exxplosive.h"
#include "MainCharacter.h"

AExxplosive::AExxplosive()
{
    Damage = 15.f;
}

void AExxplosive::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    //here we are calling   OverlapBegin() of a  parent class
    Super::OverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

    UE_LOG(LogTemp, Warning, TEXT("EXplosive::On Overlap begin"));

    //OtherActor contains info about other actor that overlaped with "Explosive"
    if (OtherActor)
    {
        //Cast converts "OtherActor" data type to "AMainCharacter" 
        //Convertin into MainCharacter cuz we want change Health of MainCharacter when it overlaps with the Bomb
        AMainCharacter* Main = Cast<AMainCharacter>(OtherActor);

        //if Cast cannot convert into a needed data type then in returns NULL ,that why we are checking wether it is NOT NULL
        if (Main)
        {
           // Main->DecreaseHealth(Damage);
            //destroys an  item(disappieares from screen)
            Destroy();
        }
    }

}
void AExxplosive::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    //here we are calling   OverlapEnd() of a  parent class
    Super::OverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

    UE_LOG(LogTemp, Warning, TEXT("Explosive::On Overlap end"));
}


