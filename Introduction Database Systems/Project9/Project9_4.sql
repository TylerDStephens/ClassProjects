Select *
From ROOMS
FULL OUTER JOIN Guest
ON(ROOMS.idGuest = Guest.idGuest);