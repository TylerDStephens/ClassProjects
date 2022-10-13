Select EmployeeName
From HotelEmployee
FULL OUTER JOIN HR_Department
ON(HotelEmployee.EmployeeID = HR_Department.EmployeeID)
Where
	HoursWorked > 40;