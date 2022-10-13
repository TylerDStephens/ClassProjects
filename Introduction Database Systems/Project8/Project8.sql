CREATE DATABASE Hotels;
USE Hotels;
CREATE TABLE ROOMS( idRoom INT, RoomNumber INT, RoomType VARCHAR(45),
					Clean_Dirty VARCHAR(45), Vaccancy VARCHAR(45), RoomStatus VARCHAR(45),
                    idGuest INT);

CREATE TABLE Guest(idGuest INT, GuestName varchar(45), GuestEmail varchar(45),
				   GuestPaymentMethod varchar(45), TotalBill INT);

CREATE TABLE Prices(idRoom int, idGuest int, PriceOfRoom int, RoomCharges int, Taxes int, TotalBill Int);

CREATE TABLE Maintenance(idRoom Int, RoomStatus varchar(45), TimeFrame varchar(45), RoomCheck varchar(45));

CREATE TABLE FrontDesk(idRoom int, AvailbleRooms varchar(45), PriceOfRooms int);

CREATE TABLE HouseKeeping(idRoom int, DoNotDisturbRooms varchar(45), Clean_Dirty varchar(45),  Vaccancy varchar(45),
						  RoomStatus varchar(45));

CREATE TABLE HotelEmployee(EmployeeID int, EmployeeName varchar(45), EmployeeDepartment varchar(45)); 

CREATE TABLE HR_Department(EmployeeID int, EmployeeSalary int, HoursWorked int);
         
                    
INSERT INTO ROOMS VALUES( 001, 101, "Standard Single Bed", "Clean", "Vaccant", "Reserved", 0), 
						( 002, 102, "Standard Single Bed", "Clean", "Occupied", "Taken", 12345),
                        ( 003, 103, "Standard Double Bed", "Dirty", "Occupied", "Taken", 12125), 
                        ( 004, 104, "Standard Double Bed", "Dirty", "Vaccant", "Out of Order", 0), 
                        ( 005, 105, "Handicap Double Bed", "Dirty", "Occupied", "Taken", 00055),
                        ( 006, 106, "Deluxe Single Bed", "Clean", "Vaccant", "Available", 0); 
INSERT INTO Guest VALUES(12345, "Bob Allen", "bobAllen@gmail.com", "Cash", 150),
						(12125, "Garry Allen", "GarryAllen@gmail.com", "Visa Card", 180),
						(00055, "Lightning McQueen", "cars@gmail.com", "Master Card", 200);
INSERT INTO Prices VALUES( 001, 0, 125, 0, 25, 0), 
						 ( 002, 12345, 125, 0, 25, 150),
                         ( 003, 12125, 140, 10, 30, 180), 
                         ( 004, 0, 140, 0, 30, 0), 
                         ( 005, 00055, 150, 20, 30, 200),
                         ( 006, 0, 200, 0, 50, 0); 
INSERT INTO Maintenance Values( 001, "Reserved", "-", "Clear"), 
						      ( 002, "Taken", "-", "Clear"),
                              ( 003, "Taken", "-", "Needs to be Checked"), 
                              ( 004, "Out of Order", "2 Weeks", "Needs to be Checked"), 
                              ( 005, "Taken", "-", "Needs to be Checked"),
                              ( 006, "Available", "-", "Clear");
INSERT INTO FrontDesk Values( 001, "Reserved", 125), 
							( 002, "Taken", 125),
							( 003, "Taken", 140), 
							( 004, "Out of Order", 140), 
							( 005, "Taken", 150),
                            ( 006, "Available", 200);
INSERT INTO HouseKeeping VALUES( 001, "Good to Enter", "Clean", "Vaccant", "Reserved" ), 
						       ( 002, "Do not Disturb", "Clean", "Occupied", "Taken" ),
                               ( 003, "Good to Enter", "Dirty", "Occupied", "Taken"), 
                               ( 004, "Good to Enter", "Dirty", "Vaccant", "Out of Order"), 
                               ( 005, "Do not Disturb", "Dirty", "Occupied", "Taken"),
                               ( 006, "Good to Enter", "Clean", "Vaccant", "Available"); 
INSERT INTO HotelEmployee VALUES(00001, "Justin Time", "Manager"),
                                (00023, "Jan Harris", "Front Desk"),
                                (00051, "Zach Watterson", "Maintenance"),
                                (00042, "Lous Griffin", "House Keeping"),
                                (00012, "Wavy Gravy", "HR Department");
INSERT INTO HR_Department VALUES(00001, 100000, 40),
                                (00023, 80000, 40),
                                (00051, 65000, 50),
                                (00042, 65000, 45),
                                (00012, 85000, 40);