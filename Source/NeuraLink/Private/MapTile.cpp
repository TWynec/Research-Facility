// Fill out your copyright notice in the Description page of Project Settings.


#include "MapTile.h"

// Sets default values
AMapTile::AMapTile()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	StaticMeshComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMapTile::BeginPlay()
{
	Super::BeginPlay();
	
}
