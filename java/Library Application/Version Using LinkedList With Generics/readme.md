## Java Library Application
Version Using LinkedList With Generics

This program:
 - builds libraries from files - at least two libraries 
 - asks for a book that is not in any library inventory 
 - asks for a book that is in a library inventory
       - issues a rent request and prints the book
       - issues the same rent request and prints the book
       - returns the book
       - issues the rent request with new dates and prints the book
 - asks for the same book in all libraries
 - calculates maximum value tag for each library 
 - inquires about a book - it is available? when does it become available, etc. 
 - if a book is rented from all libraries, finds a library that has this book available closest to the requested date.


Example output:
```
* TASK 1 *

Library = Seneca@York
[
(Java Programming Languages, 53 => Seneca@York)
(A First Course in Database Systems, 25 => Seneca@York)
(Introductory Statistics with R, -95 => Seneca@York)
(Java: The Complete Reference Ninth Edition, 45 => Seneca@York)
(Database System Concepts, 20 => Seneca@York)
]
Library = Newnham
[
(Database Management Systems, 53 => Newnham)
(Fundamentals of Database Systems (7th Edition), -55 => Newnham)
(Database System Concepts, 45 => Newnham)
(A First Course in Database Systems (3rd Edition), -20 => Newnham)
(Essentials of Database Management, 25 => Newnham)
(Database Systems Using Oracle (2nd Edition), 65 => Newnham)
(Database System Concepts, 20 => Newnham)
(Essentials of Database Management, 65 => Newnham)
]
Library = King
[
(Java Programming Languages, 53 => King)
(A First Course in Database Systems, 25 => King)
(Introductory Statistics with R, -95 => King)
(Java: The Complete Reference Ninth Edition, 45 => King)
(Essentials of Database Management, 65 => King)
]
Library = Markham
[
(Java Programming Languages, 53 => Markham)
(A First Course in Database Systems, 25 => Markham)
(Introductory Statistics with R, -95 => Markham)
(Java: The Complete Reference Ninth Edition, 45 => Markham)
(Essentials of Database Management, 65 => Markham)
]
Library = Jane
[
(Java Programming Languages, 53 => Jane)
(A First Course in Database Systems, 25 => Jane)
(Introductory Statistics with R, -95 => Jane)
(Java: The Complete Reference Ninth Edition, 45 => Jane)
(Essentials of Database Management, 65 => Jane)
]


 * TASK 2 *
Book (C++, 20) does not exist!


 * TASK 3 *
Book has been borrowed: (Essentials of Database Management, 65 => Newnham) RentSettings (05/07/2017,05/20/2017,Newnham,true)
Book (Essentials of Database Management, 65) is not availble for 05/07/2017 in Newnham library.
Book (Essentials of Database Management, 65 => Newnham) has been returned.
Book has been borrowed: (Essentials of Database Management, 65 => Newnham) RentSettings (05/07/2017,05/20/2017,Newnham,true)


 * TASK 4 *
Book (Essentials of Database Management, 65) exists in Newnham library!
Book (Essentials of Database Management, 65) is availble at 05/07/2017 from library: Newnham
Library = Newnham
[
(Database Management Systems, 53 => Newnham)
(Fundamentals of Database Systems (7th Edition), -55 => Newnham)
(Database System Concepts, 45 => Newnham)
(A First Course in Database Systems (3rd Edition), -20 => Newnham)
(Essentials of Database Management, 25 => Newnham)
(Database Systems Using Oracle (2nd Edition), 65 => Newnham)
(Database System Concepts, 20 => Newnham)
(Essentials of Database Management, 65 => Newnham) RentSettings (05/07/2017,05/20/2017,Newnham,true)
]

The book (Essentials of Database Management, 65) is available to be borrowed in library:
King
Library = King
[
(Java Programming Languages, 53 => King)
(A First Course in Database Systems, 25 => King)
(Introductory Statistics with R, -95 => King)
(Java: The Complete Reference Ninth Edition, 45 => King)
(Essentials of Database Management, 65 => King)
]

Book has been borrowed: (Essentials of Database Management, 65 => King) RentSettings (05/07/2017,05/10/2017,King,true)


 * TASK 5 *
Library = Seneca@York, max value tag: 53
Library = Newnham, max value tag: 65
Library = King, max value tag: 65
Library = Markham, max value tag: 65
Library = Jane, max value tag: 65


 * TASK 6 *
Information about the requested book (Essentials of Database Management, 65):
The book (Essentials of Database Management, 65) is in libraries:
Newnham:
The book is borrowed.
Is the book overdue: no
The book can be borrowed: 05/20/2017
King:
The book is borrowed.
Is the book overdue: no
The book can be borrowed: 05/10/2017
Markham:
The book is not borrowed.
Jane:
The book is not borrowed.


 * TASK 7 *
Book has been borrowed: (Database System Concepts, 20 => Seneca@York) RentSettings (05/07/2017,05/30/2017,Seneca@York,true)
Book (Database System Concepts, 20) is not availble for 05/07/2017 in Seneca@York library.
Book has been borrowed: (Database System Concepts, 20 => Newnham) RentSettings (05/07/2017,05/20/2017,Newnham,true)
The book (Database System Concepts, 20) is available closest to the requested date in library:
Newnham
Library = Newnham
[
(Database Management Systems, 53 => Newnham)
(Fundamentals of Database Systems (7th Edition), -55 => Newnham)
(Database System Concepts, 45 => Newnham)
(A First Course in Database Systems (3rd Edition), -20 => Newnham)
(Essentials of Database Management, 25 => Newnham)
(Database Systems Using Oracle (2nd Edition), 65 => Newnham)
(Database System Concepts, 20 => Newnham) RentSettings (05/07/2017,05/20/2017,Newnham,true)
(Essentials of Database Management, 65 => Newnham) RentSettings (05/07/2017,05/20/2017,Newnham,true)
]



 * TASK 8 *
LinkedList<T> is implemented in the project.
```
