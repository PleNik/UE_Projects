// Fill out your copyright notice in the Description page of Project Settings.

#include "CppBaseActor.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();

	float X = FMath::FRandRange(200.0f, 1000.0f);
	float Y = FMath::FRandRange(200.0f, 1000.0f);
    float Z = 0.0f;

	InitialLocation = FVector(X, Y, Z);
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
}

FVector ACppBaseActor::SinMovment()
{ 
	FVector SetActorLocation;
	SetActorLocation[0] = InitialLocation[0];
	SetActorLocation[1] = InitialLocation[1];
    SetActorLocation[2] = Amplitude * FMath::Sin(Frequency * GetLastRenderTime()) + InitialLocation[2];

	return SetActorLocation;
}