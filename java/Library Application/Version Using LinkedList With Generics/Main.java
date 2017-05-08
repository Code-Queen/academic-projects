/**
 * Java Library Application
 * Version Using LinkedList With Generics
 *
 * This program:
 *  >builds libraries from files - at least two libraries 
 *  >asks for a book that is not in any library inventory 
 *  >asks for a book that is in a library inventory
 *      issues a rent request and prints the book
 *      issues the same rent request and prints the book
 *      returns the book
 *      issues the rent request with new dates and prints the book
 *  >asks for the same book in all libraries
 *  >calculates maximum value tag for each library 
 *  >inquires about a book - it is available? when does it become available, etc. 
 *  >if a book is rented from all libraries, finds a library
 *      that has this book available closest to the requested date.
 * */

import java.util.*;

public class Main {

    public static void main(String[] args) {


        /**
         * ----------------------------------------------------------
         * TASK 1 - build libraries from files - at least two libraries 
         * */

        System.out.println("\n\n *" + " TASK 1 " + "*");
        Libraries ls = new Libraries(5);

        /* Building libraries */
        ls.libraries[0] = ls.buildLibraryFromFile("Seneca@York", "YorkLibrary.txt"); 
        ls.libraries[1] = ls.buildLibraryFromFile("Newnham", "NewnhamLibrary.txt");
        ls.libraries[2] = ls.buildLibraryFromFile("King", "KingLibrary.txt"); 
        ls.libraries[3] = ls.buildLibraryFromFile("Markham", "MarkhamLibrary.txt"); 
        ls.libraries[4] = ls.buildLibraryFromFile("Jane", "JaneLibrary.txt");  

        /* Printing libraryItems in libraries */
        System.out.println(ls);
  

        /**
         * ----------------------------------------------------------
         * TASK 2 - ask for a book that is not in any library inventory 
         * */

        System.out.println("\n *" + " TASK 2 " + "*");
        Book book = new Book("C++", 20);
        Library library = ls.isThereBookInLibraries(book);
        /* If the book is not found, prints unavaile, if found - prints the book */
        if (library == null){
          System.out.println(Helper.printNonexistent(book));
        } else{
          String rent = Helper.getCurrentDate();
          if(book.isRented(library) == true){
            rent = book.availableDate(library);
          }
          System.out.println(Helper.printAvailable(book,rent,library));
        }


        /**
         * ----------------------------------------------------------
         * TASK 3 - ask for a book that is in a library inventory
         * issue a rent request and print the bookEssentials of Database Management
         * issue the same rent request and print the book
         * return the book
         * issue the rent request with new dates and print the book
         * */
        System.out.println("\n\n *" + " TASK 3 " + "*");

        /**
         * 1. A library receives a borrow request for a book and a period of time
         * 2. The period is defined by two dates: the request date and the due date.
         * 3. If the book is part of library inventory and the book is available, then the book could be borrowed.
         * 4. If the book is not part of library inventory or the book is already borrowed, the request is sent to another library. If
         *    the request cannot be satisfied, then it is dropped.
         * 5. There are no data structures such as queues for keeping track of the requests. However, the inventory system
         *    works based on the first-come, first-served principle.
         * */
        book = new Book("Essentials of Database Management", 65);

        /* Issues a borrow request and prints the book object */
        library = ls.rentBookAvailable(book, Helper.getCurrentDate(), "05/20/2017");  
        if (library == null){
          System.out.println(Helper.printNonexistent(book));
        } 

        /* Issues the same borrow request and prints the book object; the book cannot be borrowed */
        library.rentRequest(book, Helper.getCurrentDate(), "05/30/2017"); 
        
        /* Returns the book */
        for ( Object x : library.libraryItems) {
          Book i = (Book) x;
          if(book.equals(i) && i.isRented(library)){ 
            i.returnBook(library);
            System.out.println("Book "+i+" has been returned.");                 
          }
        }

        /* Issues the borrow request with new dates and prints the book object */
        library.rentRequest(book, Helper.getCurrentDate(), "05/20/2017");


        
        /**
         * ----------------------------------------------------------
         * TASK 4 - ask for the same book in all libraries
         * if you can find a library, rent the book from that library
         * */
        System.out.println("\n\n *" + " TASK 4 " + "*");
        
        /**
         * Look for the same book in all libraries and return 
         * a library, if the book is in the library inventory
         * */
        book = new Book("Essentials of Database Management", 65);
        library = ls.isThereBookInLibraries(book);
        if (library == null){
            System.out.println(Helper.printNonexistent(book));
        } else{

            /* Prints which library holds the book */
            System.out.println("Book " + book + " exists in "+library.libraryName()+" library! ");
            String rent = Helper.getCurrentDate();
            if(book.isRented(library) == true){
              rent = book.availableDate(library);
            }

            /* Gives information when it is possible to borrow the book */
            System.out.println(Helper.printAvailable(book,rent,library));

            /* Prints the library */
            System.out.println(library);
        }
        
        /**
         * Look for the same book in all libraries and return
         * a library, if the book is available to be borrowed from that library
         * */
        book = new Book("Essentials of Database Management", 65);
        Library libraryBookAvailable = null;
        Book tempBook = null;

        /* Prints from which library it is possible to rent the book now */
        System.out.println("The book "+book+" is available to be borrowed in library:");
        search:
        for (int i = 0; i < ls.numberOfLibraries ; i++) {
            for ( Object x : ls.libraries[i].libraryItems) {
              Book j = (Book) x;
              if(book.equals(j) && j.rs == null){
                libraryBookAvailable = ls.libraries[i];
                break search;
              }
            }
        }
        if (libraryBookAvailable == null) {
            System.out.println("No libraries found.");
        } else{
            System.out.println(libraryBookAvailable.libraryName());

            /* Prints the library */
            System.out.println(libraryBookAvailable);

            /* Rents the book form the found library */
            libraryBookAvailable.rentRequest(book, Helper.getCurrentDate(), "05/10/2017");
        }



        /**
         * ---------------------------------------------------------- 
         * TASK 5 - calculate maximum value tag for each library 
         * */
        System.out.println("\n\n *" + " TASK 5 " + "*");
        Book temporaryBook = null;
        for (int i = 0; i < ls.numberOfLibraries ; i++) {
          System.out.println("Library = "+ls.libraries[i].libraryName()+", max value tag: "+ls.libraries[i].findMaximumValueTag());
        }


         /**
          * ---------------------------------------------------------- 
          * TASK 6 - inquire about a book - it is available? when does it become available, etc. 
          * */
        System.out.println("\n\n *" + " TASK 6 " + "*");
        book = new Book("Essentials of Database Management", 65);
        System.out.println("Information about the requested book " + book+":");
        Boolean existsBook = false;
        tempBook = null;

        /**
         * Prints in which libraries the book is availbale,
         * For each library it gives information about the book:
         * is it borrowed? If yes, it prints if it is overdue and when it can be availbale.
         * */
        System.out.println("The book "+book+" is in libraries:");
        for (int i = 0; i < ls.numberOfLibraries ; i++) {
            
                for ( Object x : ls.libraries[i].libraryItems) {
                Book j = (Book) x;
                 
                    if(book.equals(j)){
                        System.out.println(ls.libraries[i].libraryName()+":");
                       
                          if(j.isRented(ls.libraries[i]) == true){
                            System.out.println("The book is borrowed.");

                            try{
                              if(j.isBookOverdue() == true){
                                System.out.println("Is the book overdue: yes");
                                System.out.println("The book can be borrowed: "+j.availableDate(ls.libraries[i]));
                              } else {
                                System.out.println("Is the book overdue: no");
                                System.out.println("The book can be borrowed: "+j.availableDate(ls.libraries[i]));
                              }
                            } catch (NullPointerException e){
                                System.out.println("Is the book overdue: no");
                                System.out.println("The book is not borrowed.");  
                            }

                          } else {
                            System.out.println("The book is not borrowed.");
                          }
                        existsBook = true;
                    }
                }    
        }
        if (existsBook == false) {
            System.out.println("No libraries hold this book.");
        }


        /**
         * ---------------------------------------------------------- 
         * TASK 7 - If a book is rented from all libraries, find a library
         * that has this book available closest to the requested date.
         * */
        System.out.println("\n\n *" + " TASK 7 " + "*");
        tempBook = null;
        Library libraryBookAvailableClosest = null;
        String closest = "05/20/2117";

        /* Tested book */
        book = new Book("Database System Concepts", 20);

        /* Rents the book in the libraries for testing*/
        library = ls.rentBookAvailable(book, Helper.getCurrentDate(), "05/30/2017");  
        library = ls.rentBookAvailable(book, Helper.getCurrentDate(), "05/20/2017");  

        /* Provides information in which library the book will become available sooner */
        System.out.println("The book "+book+" is available closest to the requested date in library:"); 
           
        for (int i = 0; i < ls.numberOfLibraries ; i++) {
            for ( Object x : ls.libraries[i].libraryItems) {
              Book j = (Book) x;
        
              try{
                if(book.equals(j) && j.rs != null && Helper.timeDifference(closest,j.getDueDate()) < 0){
                  closest = j.getDueDate();
                  libraryBookAvailableClosest = ls.libraries[i];            
                }
              } catch (DateFormatException e){
                System.out.println(e.getMessage());
              }
            }
        }
        if (libraryBookAvailableClosest != null) {        
          System.out.println(libraryBookAvailableClosest.libraryName());

          /* Prints the library */
          System.out.println(libraryBookAvailableClosest);

        } else { 
          System.out.println("Libraries not found.");
        }


        /**
         * ---------------------------------------------------------- 
         * TASK 8 - Instead of using Vector<Book> in class Library a class LinkedList<T>
         * and instantiated as LinkedList<Book>
         * */
        System.out.println("\n\n *" + " TASK 8 " + "*");
        System.out.println("LinkedList<T> is implemented in the project.\n");
        
    }
}
