CREATE DATABASE Project2;
USE Project2;

CREATE TABLE RETAIL_ORDER( OrderNumber int, StoreNumber int, StoreZip int,
						   OrderMonth varchar(255), OrderYear int, OrderTotal double);
CREATE TABLE ORDER_ITEM( OrderNumber int, SKU int, Quantity int, Price double, ExtendedPrice double);
CREATE TABLE SKU_DATA (SKU int, SKU_Description varchar(255), Department varchar(255), Buyer varchar(255));
CREATE TABLE BUYER( BuyerName varchar(255), Departement varchar(255), Position varchar(255), Supervisor varchar(255));

INSERT INTO RETAIL_ORDER VALUES( 1000, 10, 98110, 'December', 2017, 445.00),
							   ( 2000, 20, 02335, 'December', 2017, 310.00),
                               ( 3000, 10, 98110, 'January' , 2018, 480.00);
INSERT INTO ORDER_ITEM VALUES( 1000, 201000, 1, 300.00, 300.00),
							 ( 1000, 202000, 1, 130.00, 130.00),
                             ( 2000, 101100, 4,  50.00, 200.00),
                             ( 2000, 101200, 2,  50.00, 100.00),
                             ( 3000, 100200, 1, 300.00, 300.00),
                             ( 3000, 101100, 2,  50.00, 100.00),
                             ( 3000, 101200, 1,  50.00,  50.00);
INSERT INTO SKU_DATA VALUES ( 100100, 'Std. Scuba Tank, Yellow', 'Water Sports', 'Pete Hansen'),
							( 100200, 'Std. Scuba Tank, Magenta', 'Water Sports', 'Pete Hansen'),
                            ( 100300, 'Std. Scuba Tank, Light Blue', 'Water Sports', 'Pete Hansen'),
                            ( 100400, 'Std. Scuba Tank, Dark Blue', 'Water Sports', 'Pete Hansen'),
                            ( 100500, 'Std. Scuba Tank, Light Green', 'Water Sports', 'Pete Hansen'),
                            ( 100600, 'Std. Scuba Tank, Dark Green', 'Water Sports', 'Pete Hansen'),
                            ( 101100, 'Diver Mask, Small Clear', 'Water Sports', 'Nancy Meyers'),
                            ( 101200, 'Diver Mask, Med Clear', 'Water Sports', 'Nancy Meyers'),
                            ( 201000, 'Half-dome Tent', 'Camping', 'Cindy Lo'),
                            ( 202000, 'Half-dome Tent Vestibule', 'Camping', 'Cindy Lo'),
                            ( 203000, 'Half-dome Ten Vestibule- Wide', 'Camping', 'Cindy Lo'),
                            ( 301000, 'Light Fly Climbing Harness', 'Climbing', 'Jerry Martin'),
                            ( 302000, 'Locking Carabiner, Oval', 'Climbing',  'Jerry Martin');
INSERT INTO BUYER VALUES( 'Cindy Lo', 'Purchasing', 'Buyer 2', 'Mary Smith'),
						( 'Jerry Martin', 'Purchasing', 'Buyer 1', 'Cindy Lo'),
                        ( 'Mary Smith', 'Purchasing', 'Manager', ' '),
                        ( 'Nancy Meyers', 'Purchasing', 'Buyer 1', 'Pete Hansen'),
                        ( 'Pete Hansen', 'Purchasing', 'Buyer 3', 'Mary Smith');
