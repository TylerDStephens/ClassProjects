USE Project4;
SELECT *
FROM EmployeeData INNER JOIN Department
ON( EmployeeData.Department = Department.DepartmentName)
WHERE 
	EmployeeData.Department != 'Production';

