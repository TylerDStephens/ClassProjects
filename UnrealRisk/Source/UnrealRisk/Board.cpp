// Fill out your copyright notice in the Description page of Project Settings.

#include "Board.h"
#include <limits>

// Sets default values
ABoard::ABoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABoard::TurnOffBoardEvents() 
{
	for (ASpace* space : naSpaces)
	{
		space->EventOff();
	}
	for (ASpace* space : saSpaces)
	{
		space->EventOff();
	}
	for (ASpace* space : afSpaces)
	{
		space->EventOff();
	}
	for (ASpace* space : euSpaces)
	{
		space->EventOff();
	}
	for (ASpace* space : asSpaces)
	{
		space->EventOff();
	}
	for (ASpace* space : auSpaces)
	{
		space->EventOff();
	}
}

void ABoard::TurnOnUnclaimedEvents()
{
	for (ASpace* space : naSpaces)
	{	
		if (space->GetOwnr() == EPlayers::SWISS)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() == EPlayers::SWISS)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() == EPlayers::SWISS)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() == EPlayers::SWISS)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() == EPlayers::SWISS)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() == EPlayers::SWISS)
		{
			space->EventOn();
		}
	}
}

bool ABoard::CheckForKnockout(EPlayers losingPlayer)
{

	for (ASpace* space : naSpaces)
	{
		if (space->GetOwnr() == losingPlayer)
		{
			return false;
		}
	}
	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() == losingPlayer)
		{
			return false;
		}
	}
	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() == losingPlayer)
		{
			return false;
		}
	}
	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() == losingPlayer)
		{
			return false;
		}
	}
	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() == losingPlayer)
		{
			return false;
		}
	}
	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() == losingPlayer)
		{
			return false;
		}
	}

	return true;
}

bool ABoard::CheckForUnclaimed()
{
	for (ASpace* space : naSpaces)
	{
		if (space->GetOwnr() == EPlayers::SWISS)
		{
			return true;
		}
	}
	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() == EPlayers::SWISS)
		{
			return true;
		}
	}
	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() == EPlayers::SWISS)
		{
			return true;
		}
	}
	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() == EPlayers::SWISS)
		{
			return true;
		}
	}
	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() == EPlayers::SWISS)
		{
			return true;
		}
	}
	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() == EPlayers::SWISS)
		{
			return true;
		}
	}

	return false;
}

bool ABoard::CheckForWinner()
{
	EPlayers seed = auSpaces[0]->GetOwnr();

	for (ASpace* space : naSpaces)
	{
		if (space->GetOwnr() != seed)
		{
			return false;
		}
	}
	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() != seed)
		{
			return false;
		}
	}
	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() != seed)
		{
			return false;
		}
	}
	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() != seed)
		{
			return false;
		}
	}
	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() != seed)
		{
			return false;
		}
	}
	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() != seed)
		{
			return false;
		}
	}
	return true;
}

FSpaceLocation ABoard::EasyBeginAiSelectSpace()
{
	FSpaceLocation selection;
	srand(time(0));
	int randNum = (rand() % 6);

	if (randNum == 0)
	{
		selection.cont = EConinents::NAMER;
	}
	else if (randNum == 1)
	{
		selection.cont = EConinents::SAMER;
	}
	else if (randNum == 2)
	{
		selection.cont = EConinents::AFRICA;
	}
	else if (randNum == 3)
	{
		selection.cont = EConinents::EUROPE;
	}
	else if (randNum == 4)
	{
		selection.cont = EConinents::ASIA;
	}
	else
	{
		selection.cont = EConinents::AUSTR;
	}

	switch (randNum)
	{
	case 0: //North America 0-9
		randNum = (rand() % 9);
		selection.space = randNum;
		break;
	case 1: // South America 0-4
		randNum = (rand() % 4);
		selection.space = randNum;
		break;
	case 2: // Africa 0-6
		randNum = (rand() % 6);
		selection.space = randNum;
		break;
	case 3: //Europe 0-7
		randNum = (rand() % 7);
		selection.space = randNum;
		break;
	case 4: //Asia 0-12
		randNum = (rand() % 12);
		selection.space = randNum;
		break;
	case 5: //Australia 0-4
		randNum = (rand() % 4);
		selection.space = randNum;
		break;

	}

	if (GetSpace(selection.cont, selection.space)->GetOwnr() == EPlayers::SWISS)
	{
		return selection;
	}

	while (GetSpace(selection.cont, selection.space)->GetOwnr() != EPlayers::SWISS)
	{
		selection.space++;

		switch (selection.cont)
		{
		case EConinents::NAMER: //North America 0-9
			if (selection.space >= 9)
			{
				selection.space = 0;
				selection.cont = EConinents::SAMER;
			}
			break;
		case EConinents::SAMER: // South America 0-4
			if (selection.space >= 4)
			{
				selection.space = 0;
				selection.cont = EConinents::AFRICA;
			}
			break;
		case EConinents::AFRICA: // Africa 0-6
			if (selection.space >= 6)
			{
				selection.space = 0;
				selection.cont = EConinents::EUROPE;
			}
			break;
		case EConinents::EUROPE: //Europe 0-7
			if (selection.space >= 7)
			{
				selection.space = 0;
				selection.cont = EConinents::ASIA;
			}
			break;
		case EConinents::ASIA: //Asia 0-12
			if (selection.space >= 12)
			{
				selection.space = 0;
				selection.cont = EConinents::AUSTR;
			}
			break;
		case EConinents::AUSTR: //Australia 0-4
			if (selection.space >= 4)
			{
				selection.space = 0;
				selection.cont = EConinents::NAMER;
			}
			break;
		}
	}
	return selection;
}

ASpace* ABoard::HardBeginAiSelectSpace(EPlayers currentPlayer)
{
	for (ASpace* space : naSpaces)
	{
		if (space->GetOwnr() == currentPlayer)
		{
			for (auto connection : space->GetConnections()) {
				if (connection->GetOwnr() == EPlayers::SWISS)
				{
					return connection;
				}
			}
		}
	}
	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() == currentPlayer)
		{
			for (auto connection : space->GetConnections()) {
				if (connection->GetOwnr() == EPlayers::SWISS)
				{
					return connection;
				}
			}
		}
	}
	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() == currentPlayer)
		{
			for (auto connection : space->GetConnections()) {
				if (connection->GetOwnr() == EPlayers::SWISS)
				{
					return connection;
				}
			}
		}
	}
	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() == currentPlayer)
		{
			for (auto connection : space->GetConnections()) {
				if (connection->GetOwnr() == EPlayers::SWISS)
				{
					return connection;
				}
			}
		}
	}
	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() == currentPlayer)
		{
			for (auto connection : space->GetConnections()) {
				if (connection->GetOwnr() == EPlayers::SWISS)
				{
					return connection;
				}
			}
		}
	}
	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() == currentPlayer)
		{
			for (auto connection : space->GetConnections()) {
				if (connection->GetOwnr() == EPlayers::SWISS)
				{
					return connection;
				}
			}
		}
	}

	FSpaceLocation value;
	value = EasyBeginAiSelectSpace();
	return GetSpace(value.cont, value.space);
}

FSpaceLocation ABoard::EasyReinfAiSelectSpace(EPlayers currentPlayer)
{
	FSpaceLocation selection;
	int i = 0;
	for (ASpace* space : naSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer) && space->GetTroops() == this->GetLowestBorderValue(currentPlayer))
		{
			selection.cont = EConinents::NAMER;
			selection.space = i;
			return selection;
		}
		i++;
	}
	i = 0;
	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer) && space->GetTroops() == this->GetLowestBorderValue(currentPlayer))
		{
			selection.cont = EConinents::SAMER;
			selection.space = i;
			return selection;
		}
		i++;
	}
	i = 0;
	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer) && space->GetTroops() == this->GetLowestBorderValue(currentPlayer))
		{
			selection.cont = EConinents::AFRICA;
			selection.space = i;
			return selection;
		}
		i++;
	}
	i = 0;
	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer) && space->GetTroops() == this->GetLowestBorderValue(currentPlayer))
		{
			selection.cont = EConinents::EUROPE;
			selection.space = i;
			return selection;
		}
		i++;
	}
	i = 0;
	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer) && space->GetTroops() == this->GetLowestBorderValue(currentPlayer))
		{
			selection.cont = EConinents::ASIA;
			selection.space = i;
			return selection;
		}
		i++;
	}
	i = 0;
	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer) && space->GetTroops() == this->GetLowestBorderValue(currentPlayer))
		{
			selection.cont = EConinents::AUSTR;
			selection.space = i;
			return selection;
		}
		i++;
	}

	return selection;
}

ASpace* ABoard::EasyAttackAiSelectAttackSpace(EPlayers currentPlayer)
{
	for (ASpace* space : naSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer))
		{
			for (auto connect : space->GetConnections())
			{
				if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() >= connect->GetTroops() && space->GetTroops() != 1)
				{
					return space;
				}
			}
		}
	}

	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer))
		{
			for (auto connect : space->GetConnections())
			{
				if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() >= connect->GetTroops() && space->GetTroops() != 1)
				{
					return space;
				}
			}
		}
	}

	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer))
		{
			for (auto connect : space->GetConnections())
			{
				if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() >= connect->GetTroops() && space->GetTroops() != 1)
				{
					return space;
				}
			}
		}
	}

	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer))
		{
			for (auto connect : space->GetConnections())
			{
				if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() >= connect->GetTroops() && space->GetTroops() != 1)
				{
					return space;
				}
			}
		}
	}

	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer))
		{
			for (auto connect : space->GetConnections())
			{
				if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() >= connect->GetTroops() && space->GetTroops() != 1)
				{
					return space;
				}
			}
		}
	}

	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer))
		{
			for (auto connect : space->GetConnections())
			{
				if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() >= connect->GetTroops() && space->GetTroops() != 1)
				{
					return space;
				}
			}
		}
	}

	return NULL;
}

ASpace* ABoard::EasyAttackAiSelectDeffendSpace(ASpace* attackSpace)
{
	for (auto connect : attackSpace->GetConnections())
	{
		if (attackSpace->GetOwnr() != connect->GetOwnr() && attackSpace->GetTroops() >= connect->GetTroops())
		{
			return connect;
		}
	}

	return NULL;
}

void ABoard::GBCSHelper(TArray<ASpace*>& borders, ASpace* space)
{
	space->EnableVisited();
	bool temp = false;
	for (auto connection : space->GetConnections())
	{
		if(space->GetOwnr() != connection->GetOwnr())
		{
			temp = true;
		}
	}
	if(temp)
	{
		borders.Add(space);
	}
	for (auto connection : space->GetConnections())
	{
		if (!connection->GetVisited()) {
			GBCSHelper(borders, connection);
		}
	}
}

TArray<ASpace*> ABoard::GetBordersConnectedToSpace(ASpace* space)
{
	TArray<ASpace*> borders;
	space->EnableVisited();
	for (auto connection : space->GetConnections()) 
	{
		GBCSHelper(borders, connection);
	}

	return borders;
}

int ABoard::GetLowestBorderValue(EPlayers currentPlayer)
{
	int value = std::numeric_limits<int>::max();
	for (ASpace* space : naSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer) && space->GetTroops() < value)
		{
			value = space->GetTroops();
		}

	}
	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer) && space->GetTroops() < value)
		{
			value = space->GetTroops();
		}

	}
	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer) && space->GetTroops() < value)
		{
			value = space->GetTroops();
		}

	}
	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer) && space->GetTroops() < value)
		{
			value = space->GetTroops();
		}

	}
	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer) && space->GetTroops() < value)
		{
			value = space->GetTroops();
		}

	}
	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer) && space->GetTroops() < value)
		{
			value = space->GetTroops();
		}

	}
	return value;
}

ASpace* ABoard::GetSpace(EConinents cont, int space)
{
	if (cont == EConinents::NAMER)
	{
		return naSpaces[space];
	}
	else if(cont == EConinents::SAMER)
	{
		return saSpaces[space];
	}
	else if (cont == EConinents::AFRICA)
	{
		return afSpaces[space];
	}
	else if (cont == EConinents::EUROPE)
	{
		return euSpaces[space];
	}
	else if (cont == EConinents::ASIA)
	{
		return asSpaces[space];
	}
	else 
	{
		return auSpaces[space];
	}
}

FSpacePair ABoard::GetTransferPair(EPlayers currentPlayer)
{
	FSpacePair pair;
	int tempInt = std::numeric_limits<int>::max();
	TArray<ASpace*> connectedBorders;
	for (ASpace* space : naSpaces)
	{
		if (space->GetOwnr() == currentPlayer && !space->IsBorder(currentPlayer) && space->GetTroops() > 1)
		{
			//get all borders connected to tempSpace and get lowest value of troops
			for (auto border : GetBordersConnectedToSpace(space))
			{
				if (border->GetTroops() < tempInt)
				{
					tempInt = border->GetTroops();
				}
			}
			//find border with lowest troops
			for (auto border : GetBordersConnectedToSpace(space))
			{
				if (border->GetTroops() == tempInt)
				{
					pair.SelectionOne = space;
					pair.SelectionTwo = border;
					return pair;
				}
			}
		}
	}
	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() == currentPlayer && !space->IsBorder(currentPlayer) && space->GetTroops() > 1)
		{
			//get all borders connected to tempSpace and get lowest value of troops
			for (auto border : GetBordersConnectedToSpace(space))
			{
				if (border->GetTroops() < tempInt)
				{
					tempInt = border->GetTroops();
				}
			}
			//find border with lowest troops
			for (auto border : GetBordersConnectedToSpace(space))
			{
				if (border->GetTroops() == tempInt)
				{
					pair.SelectionOne = space;
					pair.SelectionTwo = border;
					return pair;
				}
			}
		}
	}
	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() == currentPlayer && !space->IsBorder(currentPlayer) && space->GetTroops() > 1)
		{
			//get all borders connected to tempSpace and get lowest value of troops
			for (auto border : GetBordersConnectedToSpace(space))
			{
				if (border->GetTroops() < tempInt)
				{
					tempInt = border->GetTroops();
				}
			}
			//find border with lowest troops
			for (auto border : GetBordersConnectedToSpace(space))
			{
				if (border->GetTroops() == tempInt)
				{
					pair.SelectionOne = space;
					pair.SelectionTwo = border;
					return pair;
				}
			}
		}
	}
	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() == currentPlayer && !space->IsBorder(currentPlayer) && space->GetTroops() > 1)
		{
			//get all borders connected to tempSpace and get lowest value of troops
			for (auto border : GetBordersConnectedToSpace(space))
			{
				if (border->GetTroops() < tempInt)
				{
					tempInt = border->GetTroops();
				}
			}
			//find border with lowest troops
			for (auto border : GetBordersConnectedToSpace(space))
			{
				if (border->GetTroops() == tempInt)
				{
					pair.SelectionOne = space;
					pair.SelectionTwo = border;
					return pair;
				}
			}
		}
	}
	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() == currentPlayer && !space->IsBorder(currentPlayer) && space->GetTroops() > 1)
		{
			//get all borders connected to tempSpace and get lowest value of troops
			for (auto border : GetBordersConnectedToSpace(space))
			{
				if (border->GetTroops() < tempInt)
				{
					tempInt = border->GetTroops();
				}
			}
			//find border with lowest troops
			for (auto border : GetBordersConnectedToSpace(space))
			{
				if (border->GetTroops() == tempInt)
				{
					pair.SelectionOne = space;
					pair.SelectionTwo = border;
					return pair;
				}
			}
		}
	}
	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() == currentPlayer && !space->IsBorder(currentPlayer) && space->GetTroops() > 1)
		{
			//get all borders connected to tempSpace and get lowest value of troops
			for (auto border : GetBordersConnectedToSpace(space))
			{
				if (border->GetTroops() < tempInt)
				{
					tempInt = border->GetTroops();
				}
			}
			//find border with lowest troops
			for (auto border : GetBordersConnectedToSpace(space))
			{
				if (border->GetTroops() == tempInt)
				{
					pair.SelectionOne = space;
					pair.SelectionTwo = border;
					return pair;
				}
			}
		}
	}
	pair.SelectionOne = NULL;
	pair.SelectionTwo = NULL;
	return pair;
}

ASpace* ABoard::HardAttackAiSelectAttackSpace(EPlayers currentPlayer)
{
	bool test = true;
	for (ASpace* space : naSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer))
		{	
			test = true;
			for (auto connect : space->GetConnections())
			{
				if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() <= connect->GetTroops())
				{
					test = false;
				}
			}
			if (test) 
			{
				for (auto connect : space->GetConnections())
				{
					if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() > connect->GetTroops() && space->GetTroops() != 1)
					{
						return space;
					}
				}
			}
		}
	}

	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer))
		{
			test = true;
			for (auto connect : space->GetConnections())
			{
				if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() <= connect->GetTroops())
				{
					test = false;
				}
			}
			if (test)
			{
				for (auto connect : space->GetConnections())
				{
					if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() > connect->GetTroops() && space->GetTroops() != 1)
					{
						return space;
					}
				}
			}
		}
	}

	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer))
		{
			test = true;
			for (auto connect : space->GetConnections())
			{
				if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() <= connect->GetTroops())
				{
					test = false;
				}
			}
			if (test)
			{
				for (auto connect : space->GetConnections())
				{
					if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() > connect->GetTroops() && space->GetTroops() != 1)
					{
						return space;
					}
				}
			}
		}
	}

	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer))
		{
			test = true;
			for (auto connect : space->GetConnections())
			{
				if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() <= connect->GetTroops())
				{
					test = false;
				}
			}
			if (test)
			{
				for (auto connect : space->GetConnections())
				{
					if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() > connect->GetTroops() && space->GetTroops() != 1)
					{
						return space;
					}
				}
			}
		}
	}

	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer))
		{
			test = true;
			for (auto connect : space->GetConnections())
			{
				if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() <= connect->GetTroops())
				{
					test = false;
				}
			}
			if (test)
			{
				for (auto connect : space->GetConnections())
				{
					if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() > connect->GetTroops() && space->GetTroops() != 1)
					{
						return space;
					}
				}
			}
		}
	}

	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() == currentPlayer && space->IsBorder(currentPlayer))
		{
			test = true;
			for (auto connect : space->GetConnections())
			{
				if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() <= connect->GetTroops())
				{
					test = false;
				}
			}
			if (test)
			{
				for (auto connect : space->GetConnections())
				{
					if (space->GetOwnr() != connect->GetOwnr() && space->GetTroops() > connect->GetTroops() && space->GetTroops() != 1)
					{
						return space;
					}
				}
			}
		}
	}

	return NULL;
}

ASpace* ABoard::HardAttackAiSelectDeffendSpace(ASpace* attackSpace)
{
	for (auto connect : attackSpace->GetConnections())
	{
		if (attackSpace->GetOwnr() != connect->GetOwnr() && attackSpace->GetTroops() > connect->GetTroops())
		{
			return connect;
		}
	}

	return NULL;
}

bool ABoard::SearchForNonBorderExtraTroops(EPlayers currentPlayer)
{
	for (ASpace* space : naSpaces)
	{
		if (space->GetOwnr() == currentPlayer && !space->IsBorder(currentPlayer) && space->GetTroops() > 1)
		{
			return true;
		}
	}
	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() == currentPlayer && !space->IsBorder(currentPlayer) && space->GetTroops() > 1)
		{
			return true;
		}
	}
	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() == currentPlayer && !space->IsBorder(currentPlayer) && space->GetTroops() > 1)
		{
			return true;
		}
	}
	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() == currentPlayer && !space->IsBorder(currentPlayer) && space->GetTroops() > 1)
		{
			return true;
		}
	}
	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() == currentPlayer && !space->IsBorder(currentPlayer) && space->GetTroops() > 1)
		{
			return true;
		}
	}
	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() == currentPlayer && !space->IsBorder(currentPlayer) && space->GetTroops() > 1)
		{
			return true;
		}
	}
	return false;
}

void ABoard::TurnOnPlayerSpaceEvents()
{
	for (ASpace* space : naSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER)
		{
			space->EventOn();
		}
	}
}

void ABoard::TurnOnBorderEvents()
{
	for (ASpace* space : naSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER && space->IsBorder(EPlayers::USER) && space->GetTroops() > 1)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER && space->IsBorder(EPlayers::USER) && space->GetTroops() > 1)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER && space->IsBorder(EPlayers::USER) && space->GetTroops() > 1)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER && space->IsBorder(EPlayers::USER) && space->GetTroops() > 1)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER && space->IsBorder(EPlayers::USER) && space->GetTroops() > 1)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER && space->IsBorder(EPlayers::USER) && space->GetTroops() > 1)
		{
			space->EventOn();
		}
	}
}

int ABoard::CalculateReinforcements(int player)
{
	int value = 0;
	for (ASpace* space : naSpaces)
	{
		if (space->GetOwnr() == static_cast<EPlayers>(player))
		{
			value++;
		}
	}
	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() == static_cast<EPlayers>(player))
		{
			value++;
		}
	}
	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() == static_cast<EPlayers>(player))
		{
			value++;
		}
	}
	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() == static_cast<EPlayers>(player))
		{
			value++;
		}
	}
	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() == static_cast<EPlayers>(player))
		{
			value++;
		}
	}
	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() == static_cast<EPlayers>(player))
		{
			value++;
		}
	}
	
	value = value / 3;
	if (value < 3)
	{
		value = 3;
	}
	//if owns continent add to value
	bool testBool = true;
	for (ASpace* space : naSpaces)
	{
		if (space->GetOwnr() != static_cast<EPlayers>(player))
		{
			testBool = false;
		}
	}
	if (testBool == true)
	{
		value = value + 5;
	}

	testBool = true;
	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() != static_cast<EPlayers>(player))
		{
			testBool = false;
		}
	}
	if (testBool == true)
	{
		value = value + 2;
	}

	testBool = true;
	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() != static_cast<EPlayers>(player))
		{
			testBool = false;
		}
	}
	if (testBool == true)
	{
		value = value + 3;
	}

	testBool = true;
	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() != static_cast<EPlayers>(player))
		{
			testBool = false;
		}
	}
	if (testBool == true)
	{
		value = value + 5;
	}

	testBool = true;
	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() != static_cast<EPlayers>(player))
		{
			testBool = false;
		}
	}
	if (testBool == true)
	{
		value = value + 7;
	}

	testBool = true;
	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() != static_cast<EPlayers>(player))
		{
			testBool = false;
		}
	}
	if (testBool == true)
	{
		value = value + 2;
	}

	return value;
}

void ABoard::TurnOnPlayerTransferEvents()
{
	for (ASpace* space : naSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER && space->GetTroops() >= 2)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : saSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER && space->GetTroops() >= 2)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : afSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER && space->GetTroops() >= 2)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : euSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER && space->GetTroops() >= 2)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : asSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER && space->GetTroops() >= 2)
		{
			space->EventOn();
		}
	}
	for (ASpace* space : auSpaces)
	{
		if (space->GetOwnr() == EPlayers::USER && space->GetTroops() >= 2)
		{
			space->EventOn();
		}
	}
}