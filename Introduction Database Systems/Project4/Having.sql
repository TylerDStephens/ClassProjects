USE Project4;
SELECT COUNT(Supervisor), Department 
FROM EmployeeData
GROUP BY Department
HAVING COUNT(Supervisor) > 3;
