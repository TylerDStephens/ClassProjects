USE Project4;
SELECT *
FROM EmployeeData FULL OUTER JOIN Department
ON( EmployeeData.Department = Department.DepartmentName)
WHERE 
	EmployeeData.Department = 'Production';