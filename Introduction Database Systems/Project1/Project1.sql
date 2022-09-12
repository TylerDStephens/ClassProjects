CREATE DATABASE Project1;
USE Project1;
CREATE TABLE Student( StudentNumber int, LastName varchar(255),
					  FirstName varchar(255), EmailAddress varchar(255));
INSERT INTO Student Values( 1, 'Cooke', 'Sam', 'Sam.Cooke@OurU.edu'),	
						  ( 2, 'Lau'  , 'Marcia', 'Marcia.Lau@OurU.edu'),
                          ( 3, 'Harris', 'Lou', 'Lou.Harris@OurU.edu'),	
                          ( 4, 'Greene', 'Grace', 'Grace.Green@OurU.edu');

CREATE TABLE Class( ClassNumber int, ClassName varchar(255), 
					Term varchar(255), Section int);
INSERT INTO Class Values( 10, 'CHEM 101', '2017-Fall', 1),
						( 20, 'CHEM 101', '2017-Fall', 2),
                        ( 30, 'CHEM 101', '2018-Spring', 1),
                        ( 40, 'ACCT 101', '2017-Fall', 1),
                        ( 50, 'ACCT 101', '2018-Spring', 1);
                        
CREATE TABLE Grades( StudentNumber int, ClassNumber int, Grade double);
INSERT INTO Grades Values( 1, 10, 3.7),
						 ( 1, 40, 3.5), 
                         ( 2, 20, 3.7), 
                         ( 3, 30, 3.1), 
                         ( 4, 40, 3.0), 
                         ( 4, 50, 3.5);
                         
