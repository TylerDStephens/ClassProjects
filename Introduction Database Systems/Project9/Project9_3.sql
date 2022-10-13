SELECT COUNT(Vaccancy), RoomStatus 
FROM ROOMS
GROUP BY RoomStatus
HAVING COUNT(Vaccancy) > 1;