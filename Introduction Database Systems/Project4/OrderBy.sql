Use Project4;
SELECT *
FROM EmployeeData INNER JOIN Department
 ON(EmployeeData.Department = Department.DepartmentName)
ORDER BY EmployeeData.Department;