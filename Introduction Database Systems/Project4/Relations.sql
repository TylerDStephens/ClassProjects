USE Project4;
CREATE TABLE Department(DepartmentName varchar(255), BudgetCode varchar(255), 
			            OfficeNumber varchar(255), DepartmentPhone float);

CREATE TABLE EmployeeData( EmployeeNumber int, FirstName varchar(255), LastName varchar(255),
					   Department varchar(255), Position varchar(255), Supervisor int,
					   OfficePhone varchar(360), EmailAddress varchar(360));
CREATE TABLE Project( ProjectID int, ProjectName varchar(255), Department varchar(255),
					  MaxHours float, StartDate varchar(255), EndDate varchar(255));

CREATE TABLE Assignment( ProjectID int, EmployeeNumber int, HourWorked float);

INSERT INTO Department values( 'Administration', 'BC-100-10', 'BLDG01-210', 3602858100),
							 ( 'Legal', 'BC-200-10', 'BLDG01-220', 3602858200),
							 ( 'Human Resources', 'BC-300-10', 'BLDG01-230', 3602858300),
							 ( 'Finance', 'BC-400-10', 'BLDG01-110', 3602858400),
							 ( 'Accounting', 'BC-500-10', 'BLDG01-120', 3602858500),
							 ( 'Sales and Marketing', 'BC-600-10', 'BLDG01-250', 3602858600),
							 ( 'InfoSystems', 'BC-700-10', 'BLDG02-210', 3602858700),
							 ( 'Research and Development', 'BC-800-10', 'BLDG02-250', 3602858800),
							 ( 'Production', 'BC-900-10', 'BLDG02-110', 3602858900);

INSERT INTO EmployeeData values ( 1, 'Mary', 'Jacobs', 'Administration', 'CEO', 0, '360-285-8110', 'Mary.Jacobs@WP.com'),
                            ( 2, 'Rosalie', 'Jackson', 'Administration', 'Admin Assistant', 1, '360-285-8120', 'Rosalie.Jackson@WP.com'),
							( 3, 'Richard', 'Bandalone', 'Legal', 'Attorney', 1, '360-285-8210', 'Richard.Bandalone@WP.com'),
							( 4, 'George', 'Smith', 'Human Resources', 'HR3', 1, '360-285-8310', 'George.Smith@WP.com'),
							( 5, 'Alan', 'Adams', 'Human Resources', 'HR1', 4, '360-285-8320', 'Alan.Adams@WP.com'),
							( 6, 'Ken', 'Evans', 'Finance', 'CFO', 1, '360-285-8410', 'Ken.Evans@WP.com'),
							( 7, 'Mary', 'Abernathy', 'Finance', 'FA3', 6, '360-285-8420', 'Mary.Abernathy@WP.com'),
							( 8, 'Tom', 'Caruthers', 'Accounting', 'FA2', 6, '360-285-8430', 'Tom.Caruthers@WP.com'),
							( 9, 'Heather', 'Jones', 'Accounting', 'FA2', 6, '360-285-8440', 'Heather.Jones@WP.com'),
							( 10, 'Ken', 'Numoto', 'Sales and Marketing', 'SM3', 1, '360-285-8510', 'Ken.Numoto@WP.com'),
							( 11, 'Linda', 'Granger', 'Sales and Marketing', 'SM2', 10, '360-285-8520', 'Linda.Granger@WP.com'),
							( 12, 'James', 'Nestor', 'InfoSystems', 'CIO', 1, '360-285-8610', 'James.Nestor@WP.com'),
							( 13, 'Rick', 'Brown', 'InfoSystmes', 'IS2', 12, ' ', 'Rick.Brown@WP.com'),
							( 14, 'Mike', 'Nguyen', 'Research and Development', 'CTO', 1, '360-285-8710', 'Mike.Nguyen@WP.com'),
							( 15, 'Jason', 'Sleeman', 'Research and Development', 'RD3', 14, '360-285-8720', 'Jason.Sleeman@WP.com'),
							( 16, 'Mary', 'Smith', 'Production', 'OPS3', 1, '360-285-8810', 'Mary.Smith@WP.com'),
							( 17, 'Tom', 'Jackson', 'Production', 'OPS2', 16, '360-285-8820', 'Tom.Jackson@WP.com'),
							( 18, 'George', 'Jones', 'Production', 'OPS2', 17, '360-285-8830', 'George.Jones@WP.com'),
							( 19, 'Julia', 'Hayakawa', 'Production', 'OPS1', 17, ' ', 'Julia.Hayakawa@WP.com'),
							( 20, 'Sam', 'Stewart', 'Production', 'OPS1', 17, ' ', 'Sam.Stewart@WP.com');

INSERT INTO Project values( 1000, '2018 Q3 Prodcution Plan', 'Production', 100.00, '5/10/18', '6/15/18'),
                          ( 1100, '2018 Q3 Prodcution Plan', 'Sales and Marketing', 135.00, '5/10/18', '6/15/18'),
						  ( 1200, '2018 Q3 Prodcution Plan', 'Finance', 120.00, '7/05/18', '7/25/18'),
						  ( 1300, '2018 Q3 Prodcution Plan', 'Accounting', 145.00, '8/10/18', '10/15/18'),
						  ( 1400, '2018 Q4 Prodcution Plan', 'Production', 100.00, '8/10/18', '09/15/18'),
						  ( 1500, '2018 Q4 Prodcution Plan', 'Sales and Marketing', 135.00, '8/10/18', '09/15/18'),
						  ( 1600, '2018 Q4 Prodcution Plan', 'Finance', 140.00, '10/05/18', ' ');
						   

INSERT INTO Assignment values(1000, 1, 30.00),
                   (1000, 6, 50.00),
				   (1000, 10, 50.00),
				   (1000, 16, 75.00),
				   (1000, 17, 75.00),
				   (1100, 1, 30.00),
				   (1100, 6, 75.00),
				   (1100, 10, 55.00),
				   (1100, 11, 55.00),
				   (1200, 3, 20.00),
				   (1200, 6, 40.00),
				   (1200, 7, 45.00),
				   (1200, 8, 45.00),
				   (1300, 3, 25.00),
				   (1300, 6, 40.00),
				   (1300, 8, 50.00),
				   (1300, 9, 50.00),
				   (1400, 1, 30.00),
				   (1400, 6, 50.00),
				   (1400, 10, 50.00),
				   (1400, 16, 75.00),
				   (1400, 17, 75.00),
				   (1500, 1, 30.00),
				   (1500, 6, 75.00),
				   (1500, 10, 55.00),
				   (1500, 11, 55.00),
				   (1600, 3, 20.00),
				   (1600, 6, 40.00),
				   (1600, 7, 45.00),
				   (1600, 8, 45.00);


