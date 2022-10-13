Select RoomType
From ROOMS
NATURAL JOIN Prices
Where 
	PriceOfRoom > 140;