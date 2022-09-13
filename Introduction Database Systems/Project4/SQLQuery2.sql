USE Project4;
SELECT Department.DepartmentName, EmployeeData.FirstName, EmployeeData.OfficePhone
FROM EmployeeData FULL OUTER JOIN Department
ON(EmployeeData.Department = Department.DepartmentName)
--GROUP BY EmployeeData.Department
--ORDER BY EmployeeData.FirstName;