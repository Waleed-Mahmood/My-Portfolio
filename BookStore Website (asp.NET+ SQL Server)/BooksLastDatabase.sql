create database hookOnBookss
go
use hookOnBookss


CREATE TABLE Users(
UserID int PRIMARY KEY IDENTITY,
FirstName nvarchar(30) NOT NULL,
LastName nvarchar(30) NOT NULL,
[Password] nvarchar(30) NOT NULL,
Gender char CHECK (Gender IN ('M','F')) NOT NULL,
Membership char CHECK (Membership IN ('1','0')) NOT NULL,
[Address] nvarchar(50) NOT NULL,
Gmail nvarchar(30) UNIQUE NOT NULL
)


CREATE TABLE Orders(
ShippingID int PRIMARY KEY,
UserID int NOT NULL FOREIGN KEY REFERENCES Users(UserID) ON DELETE 
CASCADE ON UPDATE CASCADE,
TotalAmount float NOT NULL
)

CREATE TABLE Admins(
Gmail nvarchar(30) PRIMARY KEY,
FirstName nvarchar(30) NOT NULL,
LastName nvarchar(30) NOT NULL,
[Password] nvarchar(20) NOT NULL,
CNIC nvarchar(15) UNIQUE NOT NULL
)

CREATE TABLE Categories(
CategoryID int IDENTITY PRIMARY KEY,
CategoryName nvarchar(30) UNIQUE NOT NULL
)
CREATE TABLE Authors
(
AuthorID int IDENTITY PRIMARY KEY,
FirstName nvarchar(30) NOT NULL,
LastName nvarchar(30) NOT NULL
)
CREATE TABLE Books(
BookID int IDENTITY PRIMARY KEY,
Isbn nvarchar(17) CHECK(Isbn LIKE '___-_-___-_____-_') NOT NULL UNIQUE,
Title nvarchar(30) NOT NULL,
AuthorID int FOREIGN KEY REFERENCES Authors(AuthorID) NOT NULL,
Price float NOT NULL,
CategoryID int FOREIGN KEY REFERENCES Categories(CategoryID) ON UPDATE CASCADE
ON DELETE SET NULL,
Stock int CHECK (Stock>=0),
Pictures nvarchar(120) NOT NULL UNIQUE,
Discount int 
)

CREATE TABLE Reviews(
BookID int FOREIGN KEY REFERENCES Books(BookID) ON UPDATE CASCADE ON DELETE CASCADE,
UserID int FOREIGN KEY REFERENCES Users(UserID) ON UPDATE CASCADE ON delete cascade,
Rating int CHECK( Rating IN ('1','2','3','4','5')) NOT NULL,
Comment nvarchar(70),
PRIMARY KEY(BookID,UserID)
)

INSERT INTO Categories VALUES
('Historic'),
('Fantasy'),
('Horror'),
('Classic'),
('Mystery')

insert into Authors VALUES
('Allama','Iqbal'),
('Syed','Ahmad'),
('Mirza','Galib'),
('Mirza','Saeed'),
('Akbar','Alabadi')

Insert into Books VALUES 
('123-4-567-89123-4','Book 1',1,14.56,1,100,'https://oup.com.pk/pub/media/catalog/product/cache/59fe44b3394075aec184fe835a9882ed/9/7/9780190701925.jpg',10),
('234-4-577-89923-4','Book 2',2,16.78,2,100,'https://oup.com.pk/pub/media/catalog/product/cache/59fe44b3394075aec184fe835a9882ed/9/7/9780193701925.jpg',20),
('133-4-557-89144-9','Book 3',3,20.05,2,100,'https://oup.com.pk/pub/media/catalog/product/cache/59fe44b3394075aec184fe835a9882ed/9/7/8780190701925.jpg',15),
('569-4-567-23123-4','Book 4',4,12.5,3,100,'https://oup.com.pk/pub/media/catalog/product/cache/59fe44b3394075aec184fe835a9882ed/9/7/6780190701925.jpg',5),
('890-4-567-83453-7','Book 5',4,15.69,5,100,'https://oup.com.pk/pub/media/catalog/product/cache/59fe44b3394075aec184fe835a9882ed/9/7/3780190701925.jpg',2)


Insert into Users values
( 'ali', 'ahmad', 123, 'M', 1, 'lahore', 'aliahmad@gmail.com'),
( 'alia', 'ahmad', 456, 'F', 1, 'Model town, lahore', 'alia_ahmad@gmail.com'),
( 'taha', 'farooq', 789, 'M', 0, 'karachi', 'tahafarooq@gmail.com'),
( 'hamza', 'ali', 234, 'M', 1, 'islamabad', 'hamzaali@gmail.com'),
( 'jabbar', 'khan', 123, 'M', 0, 'sindh','jabbarkhan@gmail.com')

Insert into Orders values
(10, 1, 1200),
(11, 2, 100),
(12, 3, 500),
(13,1, 3000),
(14, 2, 1500)

Insert into Admins values
('usman@gmail.com', 'usman', 'afzal', 'hehe', '35401-2345673-3'),
('aizaxx@gmail.com', 'aiza', 'farooq', 'password', '35401-4445673-3'),
('unixa@gmail.com', 'uniza', 'azhar', 'haha', '35401-6666673-3'),
('alizy1@gmail.com', 'aliza', 'ali', 'hidden', '35401-2333373-3'),
('sanaxx@gmail.com', 'sana', 'javed', 'nice', '35401-2345000-3')

Insert into Reviews values
(4,2,5, 'recommended 100%'),
(4,4, 3,'must read, this is a good book'),
(3,1, 5,'story line is quite boring'),
(3,2, 4,'not so good'),
(5,1,4, 'ordinary book, didnt like it')



select * from Books
select * from Users
select * from Admins
select * from Reviews
select * from Orders
select * from Authors
select * from Categories

go
CREATE PROCEDURE [dbo].[Register]
(
		   @FirstName nvarchar(30),
		   @LastName nvarchar(30),
           @Password nvarchar(30),
		   @Gender char,
		   @Membership char,
		   @Address nvarchar(50),
           @Email nvarchar(30),
		   @Result int output
		   )
AS
BEGIN

	--SET NOCOUNT ON;

    -- Email Id exist or not, If Email Id already exist then result=0 else result=1

	if exists(select * from Users where Gmail = @Email)
	begin
		  set @Result = 1;
	end
	else
	begin
		INSERT INTO [dbo].[Users] ([FirstName],[lastName], [Password],[Gender],[Membership],[Address],[Gmail] )
		VALUES(@FirstName,@lastName, @Password, @Gender,@Membership, @Address,@Email);

	    set @Result = 0;
	end
END
GO
Go
create procedure [dbo].adminRegister
(
@gmail nvarchar(30),
@firstname nvarchar(30),
@lastname nvarchar(30),
@password nvarchar(20),
@cnic nvarchar(15),
@result int output
)
AS
BEGIN

if exists(select * from [Admins] where Gmail = @gmail)
	begin
		  set @Result = 1;
	end
else
  begin
  INSERT INTO [dbo].[Admins]
	VALUES(@gmail,@firstname,@lastName,@password,@cnic)
	    set @Result = 0
	end
END
select * from Admins

select * from [Users]


--declare @result1 int
--execute adminRegister
--@gmail='usman1@gmail.com',
--@firstName='usman',
--@lastName='Afzal',
--@password='usman123',
--@cnic='35401-4445673-1',
--@result=@result1 output


create procedure [UserLogIn_Procedure]
@mail nvarchar(30), @pass nvarchar(30),
@flag int OUTPUT
as 
BEGIN
	set @flag=0

--Rule1:  
	IF exists (	select *
				from Users as U
				where U.Gmail = @mail /* Case InSensitive */
				and U.[Password] =@pass COLLATE Latin1_General_CS_AS /* For Case Sensitive Check */)
				
		Begin
			set @flag=1	
		End

	ELSE
		Begin
			set @flag=-1;
		End
			
END
go


--Declare @outPutFlag int
--Execute UserLogIn_Procedure
--@mail='tahafarooq@gmail.com', @pass='789',
--@flag=@outPutFlag OUTPUT

--select @outPutFlag as FLAG
--select * from Users
--go

create procedure [AdminLogIn_Procedure]
@mail nvarchar(30), @pass nvarchar(30),
@flag int OUTPUT
as 
BEGIN
	set @flag=0

--Rule1:  
	IF exists (	select *
				from Admins as A
				where A.Gmail = @mail	/* Case InSensitive */
				and A.[Password] =@pass  COLLATE Latin1_General_CS_AS	/* For Case Sensitive Check */	)
				
		Begin
			set @flag=1	
		End

	ELSE
		Begin
			set @flag=-1;
		End
			
END
go


go
create procedure searchbooktitle
(
@title nvarchar(30),
@flag int output
)
as 
begin
if exists (select * from Books where Title=@title)
begin
set @flag=1
end
else
begin
set @flag=0
end
end
go



GO
create procedure [cart]
@id int,
@qt int,
@flag float OUTPUT
as 
BEGIN
	set @flag=0

declare @temp float;
declare @mem int;
declare @disco float;
declare @updatedStock int 

	IF exists (	select *
				from books as A
				where A.bookID = @id )									
		Begin
			 if @qt> (select stock from books where bookID=@id)  --stock < quantity user asked for
			 begin
			   set @flag=-2
			 end
			 else
			 begin
					set @temp=(select price from books where bookID= @id)
					set @disco= (select discount from books where bookID=@id)
						if @disco> 0
						   begin
							 set @disco=(@disco/100)*@temp
							 set @temp=@temp-@disco
						   end				
					set @flag= @temp   --*@qt
					--set @updatedstock = (select stock from books where bookID=@id)
					--set @updatedstock = @updatedstock-@qt
					--UPDATE books
					--SET stock = @updatedStock
					--WHERE bookID=@id; 
			end
		End
	ELSE
		Begin
			set @flag=-1;
		End			
END
go

Declare @outPutFlag float
Execute [cart]
@id=1,
@qt=10,
@flag=@outPutFlag OUTPUT

select @outPutFlag as FLAG
select * from books
go


go
create procedure [retTitle]
@id int,
@title varchar(50) OUTPUT
as 
BEGIN

set @title=(select Title from books where bookID= @id)

END
GO

go
Declare @outtitle varchar(50)
Execute retTitle
@id=1,
@title=@outtitle OUTPUT

select @outtitle as FLAG
select * from books
go

--Declare @outPutFlag int
--Execute AdminLogIn_Procedure
--@mail='usman@gmail.com', @pass='hehe',
--@flag=@outPutFlag OUTPUT

--select @outPutFlag as FLAG
--select * from Admins
--go

select * from Users
select * from books
select * from categories
select * from orders
select* from Reviews
select * from Admins
