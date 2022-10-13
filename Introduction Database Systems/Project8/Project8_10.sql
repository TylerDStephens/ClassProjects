Select EmployeeName
From HotelEmployee
natural join HR_Department
Where
	HoursWorked > 40;