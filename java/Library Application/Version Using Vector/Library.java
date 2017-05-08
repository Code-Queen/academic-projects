/**
 * The Library class implements individual library
 * */
import java.util.Iterator;
import java.util.Vector;
import java.util.*;

public class Library implements MaxTagValue {


    String       libraryName;
    Vector<Book> books; 
    
    public Library(String libraryName) {

        this.libraryName = libraryName;
        books = new Vector<Book>();
    }

    public int findMaximumValueTag() {

        int maxElement = -100;
        Book temporaryBook = null;
        ListIterator<Book> listIterator = this.books.listIterator();
        while (listIterator.hasNext()){
            temporaryBook = listIterator.next();
            if(temporaryBook.valueTag > maxElement){
                maxElement = temporaryBook.valueTag;
            }
        }

        return maxElement;
    }
    
    //the method takes three params: a book and two dates
    //the method returns true if the book is available in this library
    //from requestData up to dueDate
    public boolean rentRequest(Book wanted, String requestDate, String dueDate) {
        boolean resultRentRequest = false;
        try {
            Helper.checkDate(requestDate);
            Helper.checkDate(dueDate);
            
            if (Helper.timeDifference(Helper.getCurrentDate(),requestDate) >= 0) {

                seachBookCopy:
                for ( Book i : books) {
                
                        if(wanted.equals(i) && i.rs == null){
                             resultRentRequest = true;
                             i.rentBook(requestDate, dueDate, this);
                             System.out.println("Book has been borrowed: "+i);
                        
                             break seachBookCopy;
                        } else if(wanted.equals(i) && i.rs != null){

                            System.out.println(Helper.printUnavailable(wanted, requestDate)+" in "+libraryName+" library.");
                        
                        }
                }
            } else {
                System.out.println("Request date cannot be earlier than today.");
            }
            
        } catch (DateFormatException e) {  
            System.out.println(wanted + e.getMessage());
        }
        return resultRentRequest;
    }

    public String libraryName(){
      return this.libraryName;
    }
    /**
     * Equals function
     * @param object an object indicating an object to compare with 'this' object
     * @return a boolean indicating whether the libraries are equal
     * */
    @Override
    public boolean equals(Object o) { 
        if (this == o)
            return true;
        if (o == null)
            return false;
        if (getClass() != o.getClass())
            return false;
        Library other = (Library) o;
        if (this.libraryName.equals(other.libraryName) && this.books.equals(other.books)){  
            return true;
        } else{
            return false;
        }
    }

    /**
     * Unique hashCode
     * @return a unique integer hashCode
     * */
    @Override
    public int hashCode() {
        /** integer to generate hashcode */
        final int prime = 31;

        /** integer to generate hashcode */
        int result = 17;

        result = prime * result + new String(this.libraryName).hashCode();
        result = prime * result + this.books.hashCode();
      
        return result;
    }

    /**
     * Returning a string of the variables in the library
     * @return a String indicating the library name and the list of books that library contains
     * */
    @Override
    public String toString() {

        String s = "Library = "+this.libraryName+"\n[";
        ListIterator<Book> listIterator = this.books.listIterator();
    
          while (listIterator.hasNext()){
            s+="\n"+listIterator.next();
          }

        s+="\n]\n";
        
        return s;
    }
}
