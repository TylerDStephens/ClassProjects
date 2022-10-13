Select RoomType
From ROOMS
FUlL OUTER JOIN Prices
ON(ROOMS.idRoom = Prices.idRoom) 
WHERE	PriceOfRoom > 140;