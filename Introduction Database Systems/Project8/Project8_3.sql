SELECT COUNT(Vaccancy), RoomStatus 
FROM ROOMS
GROUP BY RoomStaus
HAVING COUNT(Vaccancy) > 1;