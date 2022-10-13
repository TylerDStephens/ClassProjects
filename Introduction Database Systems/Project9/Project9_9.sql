Select *
From HotelEmployee
FULL OUTER JOIN HR_Department
ON(HotelEmployee.EmployeeID = HR_Department.EmployeeID)
WHERE
     EmployeeSalary > 80000;